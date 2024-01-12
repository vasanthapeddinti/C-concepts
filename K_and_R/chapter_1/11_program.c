/* replace string of blanks with a single blank */

#include <stdio.h>

#define NONBLANK 'a'

main() {

    int c_prev, c;

    c_prev = NONBLANK;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || c_prev != ' ') {
            putchar(c);
        }
        c_prev = c;
    }
}