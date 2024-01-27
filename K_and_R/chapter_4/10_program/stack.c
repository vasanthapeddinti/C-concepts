// contains push, pop, top, swap and clear

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

bool top() {
    // check if stack is empty
    if (sp > 0) {
        printf("top of stack is %f\n", val[sp - 1]);
        return true;
    } else {
        printf("top of stack is empty\n");
        return false;
    }
}

void swap() {

    double temp;
    // check if stack has atleast 2 elements
    if (sp > 0) {
        top();
        temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
        top();
    } else {
        printf("Unable to swap the last two elements of stack\n");
    }
}

void clear() {
    while(sp >= 0) {
        val[sp] = 0.0;
        sp--;
    }
    sp = 0;
}