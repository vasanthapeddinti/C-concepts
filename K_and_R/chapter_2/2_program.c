#include <stdio.h>

int lenstr(char s[]);

int main() {

    // vertical tab example
    printf("Hello \vWorld!\n");

    char s[] = "Hello World!\n";
    // strlen function from string.h
    printf("Length of string is %d\n", lenstr(s));

    return 0;
}

int lenstr(char s[]) {

    int i;

    i = 0;

    while (s[i] != '\0') {
        i++;
    }

    return i;
}

