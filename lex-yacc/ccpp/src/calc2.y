%{
#include <stdio.h>
#include <ctype.h>

int yylex();
int yyerror();
%}

/*
** exp -> exp addop term | term
** addop -> + | -
** term -> term mulop factor | factor
** mulop -> * | /
** factor -> ( exp ) | number
*/

%token NUMBER

%%

command : exp { printf("%d\n", $1); }
        ;

exp : exp '+' term { $$ = $1 + $3; }
    | exp '-' term { $$ = $1 - $3; }
    | term { $$ = $1; }
    ;

term : term '*' factor { $$ = $1 * $3; }
     | term '/' factor { $$ = $1 / $3; }
     | factor { $$ = $1; }
     ;

factor : '(' exp ')' { $$ = $2; }
       | NUMBER { $$ = $1; }
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
        scanf("%d", &yylval);
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


