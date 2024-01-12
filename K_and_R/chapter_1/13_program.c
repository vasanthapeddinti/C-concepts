/* count lines, words, characters */

#include <stdio.h>

#define IN   1 
#define OUT  0


main() {

    int c, state, lines, words, chars;

    lines = words = chars = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        chars++;

        if (c == '\n') {
            lines++;
        }

        // detect the word
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            words++;
        }

    }
    printf("lines : %d; words : %d; chars : %d\n", lines, words, chars);
}
