/* hex to integer */
/*
    A - 10
    B - 11
    C - 12
    D - 13
    E - 14
    F - 15
*/


#include <stdio.h>

#define YES    1
#define NO     0


int htoi(char s[]) {

    int hexdigit, i, inhex, n;

    n = 0;
    inhex = YES;
    for (i = 0; inhex == YES; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            hexdigit = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            hexdigit = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            hexdigit = s[i] - 'A' + 10;
            printf("%d - %c\n", hexdigit, s[i]);
        } else {
            inhex = NO;
        }
        if (inhex == YES) {
            printf("n before is %d\n", n);
            n = 16 * n + hexdigit;
            printf("n is %d\n", n);
        }
    }
    return n;
}

int main() {

    int i;
    char s[] = "12AF";

    i = htoi(s);

    printf("integer value is %d\n", i);

}
