/* Use conditional expression to write lower funstion */

/* atoi example function implementation */
/* A - 67 */
/* a - 99 */
#include <stdio.h>

int lower(char c);

int main ()
{

    char c = 'A';

    printf("lower of  %c is %c\n", c, lower(c));

    return 0;
}

int lower(char c) {

    /*
        if char c is >= 'a' and <= 'z', return c
        if char c is >= 'A' and <= 'Z', return c + 32
    */

    return ((c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c );

}
