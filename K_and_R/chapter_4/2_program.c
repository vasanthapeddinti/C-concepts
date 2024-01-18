/* Very loose implementation of grep - version 2 to return right most occurence index */

/*
When there is a new line
    check if pattern exists
    print line
*/
#include <stdio.h>

#define MAXLINE  1000


int getline(char line[], int max);
int strindex(char source[], char searchfor[]); /* function to search pattern */

char pattern[] = "ould";   /* pattern to search for */

int main() {

    char line[MAXLINE];
    int found = 0;
    int temp;

    while(getline(line, MAXLINE)) {
        temp = strindex(line, pattern);
        if (temp >= 0) {
            printf("index: %d\n", temp);
            printf("%s\n",line);
            found++;
        }
    }

    return found;
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

int strindex(char s[], char t[]) {

    int i, j , k;
    int last_index = -1;

    for (i = 0; s[i] != '\0'; i++) {
        // comparing two strings with two pointer j, k parallely
        for (j = i, k = 0; ((s[j] == t[k]) && (t[k] != '\0')); j++, k++) {
            ;
        }
        // If the match succeeded, index k will be at \0 and have a value(to make sure search string is not empty)
        if (k > 0 && t[k] == '\0') {
            last_index = i; /* return the index of the match in original string s[] */
        }
    }
    return last_index; // If not present, return -1 as negative index does not exist
}