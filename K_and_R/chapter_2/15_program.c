/* Write a faster version of bit count using 2's complement system */

#include <stdio.h>

int bitcount(unsigned x);

int main() {

    unsigned int x = 7;
    int bit_count;

    bit_count = bitcount(x);

    printf("bit count of x is %u\n", bit_count);

    return 0;
}

int bitcount(unsigned x) {

    int count;

    for (count = 0; x != 0; x &= (x-1)) {
        count++;
    }

    return count;
}