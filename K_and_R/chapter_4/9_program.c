/*
Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.
*/

#include <stdio.h>

char buf = 0;

int getch();
void ungetch(int c);

int main() {

    int c = '*';

    ungetch(c);
    printf("after ungetch\n");

    while ((c = getch()) != EOF) {
        printf("inside while\n");
        putchar(c);
    }

    return 0;
}


// unread the extra characters
void ungetch(int c) {
    // If buffer is full, print error. Else, put the char back
    if (buf != 0) {
        printf("error: ungetch: too many characters");
    } else {
        printf("inside ungetch\n");
        buf = c;
    }
}

int getch() {

    int c;

    // If buffer is not empty, read from buffer. If empty call getchar()
    if (buf != 0) {
        printf("inside if\n");
        c = buf;
    } else {
        printf("inside else\n");
        c = getchar();
    }
    buf = 0;
    return c;
}