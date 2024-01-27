#include <stdio.h>
#include <stdbool.h>
#include "calc.h"

#define MAXVAL  100  /* max depth of stack */

static int sp = 0;   /* next poition in the stack */
static double val[MAXVAL]; /* stack */

void push(double f) {
    // check if stack is not full or array is not full
    if (sp < MAXVAL) {
        val[sp] = f;
        sp++;
    } else {
        printf("error: stack is full\n");
    }
}

double pop() {
    // check if stack is empty
    if (sp > 0) {
        sp--;
        return val[sp];
    } else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}
