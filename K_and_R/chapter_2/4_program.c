/*

Psuedo random number generator

1. Accept some initial input number, that is a seed or key.
2. Apply that seed in a sequence of mathematical operations 
   to generate the result. That result is the random number.
3. Use that resulting random number as the seed for the next iteration.
4. Repeat the process to emulate randomness.

*/
#include <stdio.h>

unsigned long int next = 1;

/* set seed for rand*/
void srand(unsigned int seed);

/* returns psuedo random number integer */
int rand();

int main() {

    while(1) {
        printf("random number is %ld\n", rand());
    }


return 0;
}

void srand(unsigned int seed) {
    next = seed;
}

int rand() {

    next = next * 1103515255 + 12345;
    return (unsigned int)(next/65536) % 32768;

}