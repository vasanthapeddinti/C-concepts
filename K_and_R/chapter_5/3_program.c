#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch();
void ungetch(int c);

int getint(int *pn);


int main() {

    int num = 0;

    // It can read only integers
    getint(&num);
    printf("The number is %d\n", num);

    return 0;
}

int getch() {

    if (bufp > 0) {
        return buf[--bufp];
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("error: ungetch: too many characters");
    } else {
        buf[bufp] = c;
        bufp++;
    }
}

//The function skips any spaces in the begining
// If it is not a digit, skip
int getint(int *pn) {

    int c, sign;

    /* skip white space */
    while(isspace(c = getch())) {
        ;
    }

    /* not number */
    if (!isdigit(c) && c!= EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }

    if (!isdigit(c)) {
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * (*pn) + (c - '0');
    }
    *pn *= sign;

    if (c != EOF) {
        printf("Debug: ungetch: %c\n", c);
        ungetch(c);
    }
    return c;
}