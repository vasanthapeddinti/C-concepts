/*
    escape program

    TO DO: de-escape program
*/

#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);


int main() {

    char s[MAXLINE] = "qwer\tt\ny";
    char t[MAXLINE] = "";
    escape(s,t);

    printf("\ns string is %s and t string is %s\n\n\n", s, t);
    return 0;

}

void escape(char s[], char t[]) {

    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }
    t[j] = '\0';
}