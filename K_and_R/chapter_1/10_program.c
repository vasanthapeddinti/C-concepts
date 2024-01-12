// Count blanks, tabs and newlines

#include <stdio.h>

main() {

    int c;
    int linecount = 0;
    int blankcount = 0;
    int tabcount = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            linecount++;
        } else if (c == '\t') {
            tabcount++;
        } else if (c == ' ') {
            blankcount++;
        }
    }
    printf("line count is %d, tabcount is %d, blankcount is %d\n",
        linecount, tabcount, blankcount);
}

