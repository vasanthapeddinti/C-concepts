/* atoi example function implementation */
#include <stdio.h>

int atoi(char s[]);

int main ()
{

    char s[] = "12345";

    printf("String value is %s, integer value is %d\n", s, atoi(s));

    return 0;
}

int atoi(char s[]) {

    int n = 0;

    for (int i = 0; s[i] >= '0' && s[i] <='9'; i++) {
        n = 10 * n + (s[i] - '0');
    }

    return n;
}