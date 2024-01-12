#include <stdio.h>
#include <string.h>

#define MAXLINE   100
// getline needs an array and limit of line it can read
int getline(char line[], int maxline);

// copy needs destination char array, source char array
void copy(char to[], char from[]);

int main() {

    /*
        while(there is a new line)
            if current line is greater than max line available
                save the current line
                save the length
        print longest line
    */

   int max;
   int len = 0;
   char line[MAXLINE];
   char longest[MAXLINE];

    max = 0;
    while (len = getline(line, MAXLINE)) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("longest line is %s\n",longest);
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

/*
    copy the current line to longest line
    dest array (from[]) is passed as char array (address of first element in array)
    src array (to[]) is passed as an array terminated with /0 which becomes a string
*/
void copy(char to[], char from[]) {
    int i;
    
    i = 0;
    
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    //to[i] = '\0';
}