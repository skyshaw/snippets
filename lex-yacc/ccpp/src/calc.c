/*
 * Simple Integer arithmetic calculator
 * according to the EBNF:
 *
 * <expr> -> <term> { <addop> <term> }
 * <addop> -> + | -
 * <term> -> <factor> { <mulop> <factor> }
 * <mulop> -> *
 * <factor> -> ( <expr> ) | Number
 *
 * Input a line of text from stdin
 * Output "Error" or the result
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int token;

int match(int ch) {
    return ch == token;
}

void lookahead() {
    token = getchar();
    while (isspace(token))
        token = getchar();
}

void error() {
    fprintf(stderr, "Error");
    exit(1);
}

int expr();

/* <factor> -> ( <expr> ) | Number */
int factor() {
    int ret = 0;
    if (match('(')) {
        lookahead();
        ret = expr();
        if (match(')')) {
            lookahead();
        } else {
            error();
        }
    } else if (isdigit(token)) {
        ungetc(token, stdin);
        scanf("%d", &ret);
        lookahead();
    } else {
        error();
    }
    return ret;
}

/* <term> -> <factor> { <mulop> <factor> } */
int term() {
    int ret = factor();
    while (1) {
        if (match('*')) {
            lookahead();
            ret *= factor();
        } else if (match('/')) {
            lookahead();
            ret /= factor();
        } else {
            break;
        }
    }
    return ret;
}

/* <expr> -> <term> { <addop> <term> } */
int expr() {
    int ret = term();
    while (1) {
        if (match('+')) {
            lookahead();
            ret += term();
        } else if (match('-')) {
            lookahead();
            ret -= term();
        } else if (match(EOF)) {
            break;
        }
    }
    return ret;
}


int main() {
    lookahead();
    int res = expr();
    printf("%d\n", res);
    return 0;
}
