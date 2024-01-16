/* Write a function to invert(x, p, n) that returns x with n bits that
* begin at position p inverted, leaving the others unchanged
*/
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void) { printf("%u\n", (unsigned) invert((unsigned) 8, (int) 3, (int) 3)); }

unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}


/*
x ^ (~(~0 << n) << (p + 1 - n)) = 0000 1000 ^ 0000 1111
                                                                = 0000 1111
                                                                = 15
*/