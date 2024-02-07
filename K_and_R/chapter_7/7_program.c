/*
    Private version of scanf
*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


void minscanf(char *fmt, ...);

int main() {

    int a;
    minscanf("%d", &a);
    printf("Number scanned is %d\n", a);

    float b;
    minscanf("%f", &b);
    printf("Number scanned is %f\n", b);

    /* There is a bug in the code. If character is scanned first or alone, it works. In other cases, it fails */
    char c = 'a';
    minscanf("%c", &c);
    printf("character scanned is %c\n", c);

    return 0;
}

void minscanf(char *fmt, ...) {
    va_list ap;
    char *p;

    int *iaddr;
    float *daddr;
    char *caddr;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            continue;
        }

        ++p; // skip modulo
        switch(*p) {     /* same as *++p */
            case 'd':
                iaddr = va_arg(ap, int *);
                scanf("%d", iaddr);
                break;
            case 'f':
                daddr = va_arg(ap, float *);
                scanf("%f", daddr);
                break;
            case 'c':
                caddr = va_arg(ap, char *);
                scanf("%c", caddr);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}