/* To understand the extern variables */

#include <stdio.h>
#include <string.h>

#define MAXLINE   100

    // defined as external varibles
    // The functions that use them add extern keyword before type to use
   int max;
   char line[MAXLINE];
   char longest[MAXLINE];

// getline needs an array and limit of line it can read
int getline();

// copy needs destination char array, source char array
void copy();

int main() {

    /*
        while(there is a new line)
            if current line is greater than max line available
                save the current line
                save the length
        print longest line
    */


   int len = 0;
   extern int max;
   extern char longest[MAXLINE];

    max = 0;
    while ((len = getline()) > 0) {
        if (len > max) {
            max = len;
            copy();
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
int getline() {

    int c, i;
    extern char line[];
    i = 0;

    while(((c = getchar()) != EOF) && (c != '\n') && (i < MAXLINE-1)) {
        line[i] = c;
        i++;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

/*
    copy the current line to longest line
    dest array (from[]) is passed as char array (address of first element in array)
    src array (to[]) is passed as an array terminated with /0 which becomes a string
*/
void copy() {
    int i;
    extern char line[];
    extern char longest[];

    i = 0;

    while (line[i] != '\0') {
        longest[i] = line[i];
        i++;
    }
    //to[i] = '\0';
}