/* count frequencies of digits ( 0 to 9 ), white space characters
   (' ', '\t', '\n') and others
*/

#include <stdio.h>

main() {

    int c, spacechars, others;
    int digits[10];

    spacechars = others = 0;
    // inistialize array
    for (int i = 0; i < 10; i++) {
        digits[i] = 0;
    }

    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n' || c == '\t') {
            spacechars++;
        } else if (c >= '0' && c<= '9') {
            digits[c - '0']++;
        } else {
            others++;
        }
    }

    printf("whitespace characters: %d; others: %d\n", spacechars, others);
    printf("digits:\n");
    for (int i = 0; i < 10; i++) {
        printf("num %d : %d\n", i, digits[i]);
    }
}