/* Squeeeze characters */
#include <stdio.h>

void squeeze(char s[], char c);

int main() {

    char s[] = "aaabsaagaa";

    squeeze(s, 'a');

    printf("string after squuezed is %s\n", s);

    return 0;
}

void squeeze(char s[], char c) {

    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}