/* get n bits at poition p counting from the right in x (the farthest right bit being position 0)
* You want to generate a "mask" that pulls only the bits we want to see. 
*/

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main() {

    int x = 63892;
    int p = 4;
    int n = 3;

    printf("x is %d, bits are %d\n", x, getbits(x, p, n));
    return 0;
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}