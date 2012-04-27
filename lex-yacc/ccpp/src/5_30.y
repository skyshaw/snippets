%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int yylex();
int yyerror();
void error();

/*
** 0 for integer, 1 for float
*/
struct value { \
    double fval; \
    int ival; \
    int flag; \
};

%}

/*
** exp -> exp addop term | term
** addop -> + | -
** term -> term mulop factor | factor
** mulop -> * | /
** factor -> ( exp ) | number
*/

%token NUMBER
%union {
    struct value val;
    char op;
}
%type <val> command exp term factor NUMBER
%type <op>  addop mulop

%%

command : exp { 
            if ($1.flag == 0) {
                printf("%d\n", $1.ival);
            } else {
                printf("%lf\n", $1.fval);
            }
        }
        ;

exp : exp addop term {
        if ($1.flag == 0 && $3.flag == 0) {
            $$.flag = 0;
            switch ($2) {
                case '+': $$.ival = $1.ival + $3.ival; break;
                case '-': $$.ival = $1.ival - $3.ival; break;
                default: error();
            }
        } else {
            $$.flag = 1;
            switch ($2) {
                case '+': $$.fval = $1.fval + $3.fval; break;
                case '-': $$.fval = $1.fval - $3.fval; break;
                default: error();
            }
        }
    }
    | term {
        $$.flag = $1.flag;
        if ($1.flag == 0) {
            $$.ival = $1.ival;
        } else {
            $$.fval = $1.fval;
        }
    }
    ;

addop : '+' { $$ = '+'; }
      | '-' { $$ = '-'; }
      ;

term : term mulop factor {
        if ($1.flag == 0 && $3.flag == 0) {
            switch ($2) {
                case '*': { 
                    $$.flag = 0;
                    $$.ival = $1.ival * $3.ival;
                    break; 
                }
                case '/': {
                    if ($1.ival % $3.ival == 0) {
                        $$.flag = 0;
                        $$.ival = $1.ival / $3.ival;
                    } else {
                        $$.flag = 1;
                        $$.fval = (double)$1.ival / (double)$3.ival;
                    }
                    break;
                }
                default: error();
            }
        } else {
            $$.flag = 1;
            switch ($2) {
                case '*': $$.fval = $1.fval * $3.fval; break;
                case '/': $$.fval = $1.fval / $3.fval; break;
                default: error();
            }
        }
        
     }
     | factor { $$ = $1; }
     ;

mulop : '*' { $$ = '*'; }
      | '/' { $$ = '/'; }
      ;

factor : '(' exp ')' {
            $$.flag = $2.flag;
            if ($2.flag == 0)
                $$.ival = $2.ival;
            else
                $$.fval = $2.fval;
       }
       | NUMBER {
            $$.flag = $1.flag;
            if ($1.flag == 0)
                $$.ival = $1.ival;
            else
                $$.fval = $1.fval;
       }
       ;

%%

int main() {
    yyparse();
    return 0;
}

int yylex() {
    int ch = getchar();
    while (isspace(ch)) 
        ch = getchar();
    if (isdigit(ch)) {
        ungetc(ch, stdin);
        scanf("%lf", &yylval.val.fval);
        if ((int)yylval.val.fval == yylval.val.fval) {
            yylval.val.flag = 0;
            yylval.val.ival = yylval.val.fval;
        } else {
            yylval.val.flag = 1;
        }
        return NUMBER;
    } else if (ch == EOF) {
        return 0;
    } else {
        return ch;
    }
}

int yyerror(char* s) {
    fprintf(stderr, "%s", s);
    return 0; 
}

void error() {
    fprintf(stderr, "Error\n");
    exit(1);
}
