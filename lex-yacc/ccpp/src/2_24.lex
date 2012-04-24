%{

#include <stdio.h>
#include <string.h>

int nchar = 0;
int nword = 0;
int nline = 0;

%}

%%

[A-Za-z0-9]+ {
    nword++;
    nchar += strlen(yytext);
}

\n {
    nchar++;
    nline++;
}

. {
    nchar++;
}

%%

int main() {
    yylex();
    printf("%d %d %d\n", nchar, nword, nline);
    return 0;
}

