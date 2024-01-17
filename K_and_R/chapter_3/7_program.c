/* Reverse a string using two pointers */
#include <stdio.h>
#include <string.h>

void reverseString(char s[]);

int main() {

    char s[] = "vasantha";

    reverseString(s);

    printf("Reversed string is %s\n", s);

    return 0;
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