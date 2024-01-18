#include <stdio.h>
#include <ctype.h>

#define MAXLINE   10
/*
basic idea: 

a = "10.4"
f  = 104/10

a = "2.56"
f = 256/(10^2)
*/

/* string to double */
double atof(char s[]);

int getline(char line[], int max);

int main() {
    double sum, atof(char[]);
    char line[MAXLINE];
    int getline(char line[], int max);

    sum = 0;
    while(getline(line, MAXLINE) > 0) {
        printf("\t%g\n", sum += atof(line));
    }

    return 0;
}

double atof(char s[]) {
    int i;
    int sign;
    double num;
    int pow;

    /* skip any white spaces in the begining of the string 
    for (i = 0; s[i] != '\0'; i++) {
        if (!isspace(s[i])) {
            break;
        }
    }
    */
    for (i = 0;isspace(s[i]); i++) {
        ;
    }

    /* calculate sign */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    /* calculate integral part of number */
    for (num = 0.0; isdigit(s[i]); i++) {
        num = (s[i] - '0') + 10.0 * num;
    }

    /* check if decimal is present */
    if (s[i] == '.') {
        i++;
    }

    /* Calulate fractional part */
    for (pow = 1.0; isdigit(s[i]); i++) {
        num = (s[i] - '0') + 10.0 * num;
        pow *= 10;
    }
    return (sign * num / pow);
}

int getline(char s[], int lim) {

    int c, i;

    i = 0;
    while ((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n')) { /* get line */
        s[i] = c;
        i++;
    }

    if (s[i] == '\n') { /* add new line escape sequence */
        s[i] = '\n';
        i++;
    }

    s[i] = '\0'; /* add \0 at the end */

    return i; /* return the length of the string or line till /n */
}