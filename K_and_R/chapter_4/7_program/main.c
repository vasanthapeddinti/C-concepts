/*
Reverse Polish notation: 
(1 - 2) * (4 + 5)
12-45+*
*/

// adding variables support
// 26 variables (alphabets) with single letter names
// operations: store, update, (delete can be added too), a variable for most recently printed value
// So, operations for store(=), history(H)
// 5 x =
// H

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP  100


int main() {

    int var = 0;
    int type = 0; // var to store previous char 
    char s[MAXOP];
    double op2, H;
    double variables[26]; // variables array stores a to z variables from 0 to 25
    double x, y;

    while((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '=':
                pop(); // the stack looks like 5 x, we popped x as var stores the previous type
                if (var >= 'a' && var <= 'z') {
                    variables[var - 'a'] = pop(); // x = 5
                } else {
                    printf("error: invalid variable name");
                }
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
            case '%':
                op2 = pop();
                if (op2 != 0){
                    push((int) pop() % (int) op2);
                } else {
                    printf("zero division error!\n");
                }
                break;
            case '\n':
                H = pop();
                printf("\t%.4g\n", H); // store and print the final result
                break;
            default:
                if (type >= 'a' && type <= 'z') {
                    push(variables[type - 'a']);
                } else if (type == 'H') {
                    push(H);
                } else {
                    printf("error: invalid character\n");
                }
        }
        var = type;
    }

    return 0;
}
