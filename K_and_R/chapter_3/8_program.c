#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int expand(char s1[], char s2[]);

int main() {

    char s1[] = "e-g0-9";
    char s2[MAXLEN] = "";

    if (expand(s1, s2) == 0) {
        printf("expanded string is %s\n", s2);
    }

    return 0;
}

int expand(char s1[], char s2[]) {

    int i;
    int from, to;
    int last = strlen(s1) - 1;
    int err = 0;
    int j = 0;

    for (i = 0; i <= last; i++) {
        if (s1[i] != '-') {

            from = s1[i];
            // now calculate to
            if (i+2 > last) { // "a-"
                to = -1;
            } else if (s1[i+2] == '-') { // "a--"
                to = -1;
            } else if (s1[i+1] != '-') { // "ab"
                to = -1;
            } else { // "a-b"
                i = i+2;
                to = s1[i]; // at this point we got "a-b", from = 'a' and to = 'b'
            }
        } else {
            if (i == 0 || i == last) { // invalid cases of "-a-b" or "a-b-"
                from = to = -1;
            }
            // TO DO: parse a-b-c
        }
        if (from > to) {
            err = -1;
        } else {
            // since we got valid from and to, we can expand the string
            while (from <= to) {
                s2[j] = from;
                from++;
                j++;
            }
        }
    }
    return err;
}