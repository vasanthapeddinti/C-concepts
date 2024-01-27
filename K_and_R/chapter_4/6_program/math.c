#include <math.h>
#include <string.h>
#include <stdio.h>
#include "calc.h"

void math(char s[]) {
    double op2;

    if (strcmp(s, "sin") == 0) {
        push(sin(pop()));
    } else if (strcmp(s, "cos") == 0) {
        push(cos(pop()));
    } else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        pow(pop(), op2);
    } else {
        printf("error: %s unknown command\n", s);
    }
}