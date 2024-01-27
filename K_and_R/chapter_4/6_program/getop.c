#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {

    int i, c;

    //skip spaces and get the character
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';

    i = 0;
    // for math
    if (isalpha(c)) {
        while(isalpha(s[++i] = c = getch())) {
            ;
        }
        s[i] = '\0';
        if (c != EOF) {
            ungetch(c);
        }
        return MATH;
    }

    // not a number case (like +, -, * etc)
    if (!isdigit(c) && c != '.') {
        return c;
    }

    // if it is number, collect integeral and fractional parts
    if (isdigit(c)) {
        while(isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if (c == '.') {
        while(isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}