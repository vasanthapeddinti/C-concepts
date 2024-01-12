#include <stdio.h>

main() {

    long count=0;

    while (getchar() != EOF) {
        ++count;
    }
    printf("\nlength of stream  is %ld\n", count);
}