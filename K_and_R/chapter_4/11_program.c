/* print number as a character string */
/*
itoa generates the chars and stores in reverse order. Then we print the array in reverse order.
This is a recursive approach
*/

#include <stdio.h>

void printd(int n);

int main() {

    printd(-123);
    return 0;
}

void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n/10) {
        printd(n/10);
    }
    putchar(n % 10 + '0');
}