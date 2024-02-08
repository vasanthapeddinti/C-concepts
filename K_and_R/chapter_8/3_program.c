#include <unistd.h>
#include <stdio.h>

int getchar();

int main() {

    int c;

    while ((c = getchar()) != EOF) {
        printf("%c", c);
    }
    return 0;
}

int getchar() {

    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {
        n = read(0, buf, sizeof(buf));
        bufp = buf;
    }

    if (--n >= 0) {
        return (unsigned char) *bufp++;
    } else {
        return EOF;
    }
    //return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}