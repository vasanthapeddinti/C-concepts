/* print it's input one word per line */

#include <stdio.h>

main() {

    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            putchar('\n');
        } else {
            putchar(c);
        }
        
    }
}