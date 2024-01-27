#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {

    int i, c;
    static int lastc = 0; // keeps the value after invocation, my little private memory inside function

    if (lastc == 0) {
        c = getch();
    } else {
        c = lastc;
        lastc = 0;
    }

    //skip spaces and get the character
    while ((s[0] = c) == ' ' || c == '\t') {
        c = getch();
    }
    s[1] = '\0';

    // not a number case (like +, -, * etc)
    if (!isdigit(c) && c != '.') {
        return c;
    }

    i = 0;
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
        lastc = c;
    }
    return NUMBER;
}