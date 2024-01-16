/* bit count - count 1 bits in x */

#include <stdio.h>

int bitcount(unsigned x);

int main() {

    int x = 7;
    int bit_count;

    bit_count = bitcount(x);

    printf("bit count of x is %d\n", bit_count);

    return 0;
}

int bitcount(unsigned x) {

    int count;

    for (count = 0; x != 0; x >>= 1) {
        if (x & 01) {
            count++;
        }
    }
    return count;

}