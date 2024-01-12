// The code has a bug, needs to be fixed

/* print horizontal histogram with lengths of words as its input */

#include <stdio.h>
#include <ctype.h>

#define   MAXWIDTH    15      /* screen width available for bars */
#define   MAXLEN      10      /* max number of bars */


main() {

    int c, c_prev, letters, i;
    int words[MAXLEN];

    letters = 0;

    for (i = 0; i < MAXLEN; i++) {
        words[i] = 0;
    }

    i = 0;
    
    while (((c = getchar()) != EOF) && (i <= MAXLEN) && (letters <= MAXWIDTH)) {

        // find begining of the character
        if (c_prev == ' ' && c_prev == '\t' && c_prev == '\n' && isalnum(c)) {
            words[i] = 1;
        }

        if (c == ' ' || c == '\t' || c == '\n') {
            i++;
        } else {
            words[i]++;
            
            
        }
    }

    for (i = 0; i < MAXLEN; i++) {
        printf("%3d | ", i);
        for (int j = 0; j < words[i]; j++) {
            if (j > 0)
                printf("*");
        }
        printf("\n");
    }
}