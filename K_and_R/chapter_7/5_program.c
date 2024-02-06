#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt, ...);

int main() {

    int a = 10, b = 40;

    minprintf("The numbers are %d and %d\n", a, b);

    minprintf("The minprintf address is %p\n", &a);
    printf("address is %p\n", &a);
    
    char *word = "vasantha";
    minprintf("String is %s\n", word);

    /*
        Integer constants written with a leading 0 are interpreted
        as octal (base-8), not decimal (base-10). This is analogous
        to 0x triggering hexadecimal (base-16) interpretation.
    */
    int c1 = 011;
    minprintf("b in octal: %o, and in decimal: %d\n", c1, c1);

    int h1 = 0x10;
    minprintf("h in hex: %x, and in decimal: %d\n", h1, h1);

    int c2 = 11;
    minprintf("b in octal: %o, and in decimal: %d\n", c2, c2);

    int h2 = 10;
    minprintf("h in hex: %x, and in decimal: %d\n", h2, h2);

    return 0;
}

void minprintf(char *fmt, ...) {
    va_list ap; /* pointer points to each unnamed arg in turn */
    char *p;

    char *sval;
    int ival;
    double dval;
    int *pval;

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
            case 'x':
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;
            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            case 'p':
                pval = va_arg(ap, int *);
                printf("%p", pval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}