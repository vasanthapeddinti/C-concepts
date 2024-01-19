/* itob(n,s,b) that converts the integer n into a base b character representation
*  in the string s. In particular, itob(n,s,16) forms n as a hexadecimal integer in s
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLIMIT 100

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {

    int n = 1234;
    int b = 16;
    char s[MAXLIMIT];

    itob(n, s, b);

    printf("inreger is %d\n conversion to base %d is %s\n", n, b, s);

    return 0;
}

void itob(int n, char s[], int b) {

    int i, j, sign;
    i = 0;
    j = strlen(s) - 1;

    if (n < 0) {
        sign = '-';
        n = -n;
    }

    do {
        j = n % b;
        if (j <= 9) {
            s[i] = j + '0'; // has to be converted to character numbers like '1'
            i++;
        } else {
            // hexdigit = s[i] - 'a' + 10; /* htoi logic */
            s[i] = j - 10 + 'a'; // ex: if 15 - 10 + 'a' => f (observation is j will be 11 to 15 ?)
            i++;
        }
    } while((n /= b)> 0);

    if (sign == '-') {
        s[i] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[]) {

    int i,j;
    char c;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}