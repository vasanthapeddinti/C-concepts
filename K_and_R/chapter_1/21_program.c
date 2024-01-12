#include <stdio.h>
#include <string.h>

#define MINLINE   8
#define MAXLINE   20

// getline needs an array and limit of line it can read
int getline(char line[], int maxline);


int main() {

    /*
        while(there is a new line)
            if current line is greater than MINLINE
                print longest line
    */

   int len = 0;
   char line[MAXLINE];

    while (len = getline(line, MAXLINE)) {
        if (len > MINLINE) {
            printf("line: %s\n",line);
        }
    }

    return 0;
}

/*
    until a /n is encountered, read the line
    add a /0 null char at the end of the line to make it string
*/
int getline(char s[], int lim) {

    int c, i;

    i = 0;

    while(((c = getchar()) != EOF) && (c != '\n') && (i < lim-1)) {
        s[i] = c;
        i++;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
