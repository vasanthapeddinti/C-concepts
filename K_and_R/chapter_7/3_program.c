#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt, ...);

int main() {

    int a = 10, b = 40;

    //minprintf("The numbers are %d and %d\n", a, b);
    minprintf("The numbers are %d and %d", a, b);

    return 0;
}

void minprintf(char *fmt, ...) {
    va_list ap; /* pointer points to each unnamed arg in turn */
    char *p;

    char *sval;
    int ival;
    double dval;

    /* ap - argument pointer */
    va_start(ap, fmt); /* ap points to first unnamed arg*/
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        // va_arg returns one argument and steps ap to the next
        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}