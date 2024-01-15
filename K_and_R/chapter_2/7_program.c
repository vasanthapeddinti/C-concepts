#include <stdio.h>

void custom_strcat(char s[], char t[]);

int main() {

    char s[] = "vasantha";
    char t[] = "peddinti";

    printf("string1 is %s\nstring2 is %s\n", s, t);

    custom_strcat(s, t);

    printf("string1 + string2 is %s\n", s);

    return 0;
}

void custom_strcat(char s[], char t[]) {
    int i = 0;
    int j = 0;

    while (s[i] != '\0') {
        i++;
    }

    while (t[j] != '\0') {
        s[i] = t[j];
        i++;
        j++;
    }
}