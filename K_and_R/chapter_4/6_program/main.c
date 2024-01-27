/*
Reverse Polish notation: 
(1 - 2) * (4 + 5)
12-45+*
*/

/*
sin, exp, pow
*/

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP  100


int main() {

    int type;
    char s[MAXOP];
    double op2;

    while((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case MATH:
                math(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0){
                    push(pop()/op2);
                } else {
                    printf("zero division error!\n");
                }
                break;
            case '\n':
                printf("\t%.4g\n", pop()); // print the final result
                break;
            default:
                printf("invalid character\n");
                break;
        }
    }
    return 0;
}
