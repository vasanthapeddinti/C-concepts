/* atoi example function implementation */
/* A - 67 */
/* a - 99 */
#include <stdio.h>

int atoi(char s[]);
int lower(char c);
int upper(char c);

int main ()
{

    char s[] = "12345";

    printf("String value is %s, integer value is %d\n", s, atoi(s));
    printf("lower of S is %c\n",lower('S'));
    printf("upper of s is %c\n",upper('s'));

    return 0;
}

int atoi(char s[]) {

    int n = 0;

    for (int i = 0; s[i] >= '0' && s[i] <='9'; i++) {
        n = 10 * n + (s[i] - '0');
    }

    return n;
}

int lower(char c) {

    /*
        if char c is >= 'a' and <= 'z', return c
        if char c is >= 'A' and <= 'Z', return c + 32
    */

   if (c >= 'a' && c <= 'z') {
       return c;
   }

    if (c >= 'A' && c <= 'Z') {
        return (c + 'a' - 'A');
    }

}

int upper(char c) {

    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    return c;
}