%{

#include <stdio.h>

%}

%%

"/*" {
    char ch;
    int done = 0;
    ECHO;
    do {
        while ((ch = input()) != '*')
            putchar(toupper(ch));
        putchar(ch);
        while ((ch = input()) == '*')
            putchar(ch);
        putchar(toupper(ch));
        if (ch == '/') done  = 1;
    } while (!done);
}

%%

int main() {
    yylex();
    return 0;
}
