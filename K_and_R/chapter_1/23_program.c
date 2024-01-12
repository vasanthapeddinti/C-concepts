/* reverse(s) string fuction */

#include <stdio.h>
#include <string.h>

void reverse_string (char s[], int len);

int main() {

    char s[10] = "bhanu";
    int len = strlen(s);
    reverse_string(s, len);
    printf("Reversed String is %s\n", s);
    return 0;
}

void reverse_string (char s[], int len) {
    char temp;
    int i = 0;
    int j = len;

    for (i = 0, j = len-1; i <= j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    printf("Reverseddd String is %s\n", s);
}

