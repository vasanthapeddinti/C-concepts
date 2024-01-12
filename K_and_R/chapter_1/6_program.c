#include <stdio.h>

main() {

    int c;

    do {
        c = getchar();
        printf("getchar() != EOF: %d\n", c != EOF);
    } while (c != EOF);
}