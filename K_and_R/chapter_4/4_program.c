/*
Extend atof to handle scientific notation of the form 123.45e-6 where a
floating-point number may be followed by e or E and an optionally signed exponent. 
*/

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
    char line[MAXLINE];
    int getline(char line[], int max);

    while(getline(line, MAXLINE) > 0) {
        printf("\t%g\n", atof(line));
    }

    return 0;
}

double atof(char s[]) {
    int i;
    int sign;
    double num;
    int pow;
    int exp;

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
    num = sign * num / pow;

    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        /* calculate sign*/
        sign = 1;
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }

        /* calculate exponent after e/E */
        for (exp = 0; isdigit(s[i]); i++) {
            exp = (s[i] - '0') + 10 * exp;
        }

        if (sign == 1) {
            while (exp > 0) {
                num *= 10;
                exp--;
            }
        } else {
            // It is just while ((x--) > 0)
            while (exp--> 0) { /* https://stackoverflow.com/questions/1642028/what-is-the-operator-in-c-c */
                num /= 10;
            }
        }
    }

    return num;
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