/* Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough. 
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN    1000
#define MINWIDTH  8


void itoa(int n, char s[], int min_width);

void reverseString(char s[]);


int main() {

    int i = -123;
    char s[MAXLEN];

    itoa(i, s, MINWIDTH);

    printf("The integer is %d\nThe string is %s\n", i, s);

    return 0;
}


void itoa(int n, char s[], int min_width) {

    int i, sign;

    if ((sign = n) < 0) {   /* save the original sign */
        n = -n;             /* make n positive to convert to string */
    }

    i = 0;
    do {            /* generate digits in reverse order */
        s[i] = n % 10 + '0';        /* extract the last digit and add it to char '0' */
        i++;
    } while((n /= 10) > 0);         /* remove the last digit and extract the remaining number */

    /* add the sign if it is negative */
    if (sign < 0) {
        s[i] = '-';
        i++;
    }

    if (i < (min_width)) {
        while (i != min_width) {
            s[i] = ' ';
            i++;
        }
    }

    s[i] = '\0';

    /* finally reverse the string ex: from "321-" to "-123" */
    reverseString(s);
}

void reverseString(char s[]) {

    int i, j;
    char c;
    size_t n = strlen(s);

    for (i = 0, j = n-1; i <= j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}