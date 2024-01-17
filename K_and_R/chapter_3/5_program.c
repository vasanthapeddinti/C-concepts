#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

int main() {

    char s[] = "  -1234";

    printf("String is %s\n", s);
    printf("Numeric value is %d\n", atoi(s));

    return 0;
}

int atoi(char s[]) {

    int i, n , sign;

    /* skip white spaces */
    for (i = 0; isspace(s[i]); i++) {
        ;
    }

    /* skip sign */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    /* Convert char to int */
    for (n = 0; isdigit(s[i]) && s[i] != '\0'; i++) {
        n = 10 * n + (s[i] - '0');
    }

    return sign * n;
}