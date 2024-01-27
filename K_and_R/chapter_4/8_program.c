/*
Write a routine ungets(s) that will push back an entire string onto the input. 
Should ungets know about buf and bufp , or should it just use ungetch ?
*/

#include <stdio.h>
#include <string.h>

#define BUFSIZE   100
#define MAXLINE   100

char buf[BUFSIZE];
char bufp = 0;

int getch();
void ungetch(int c);

void ungets(const char s[]);
int getline(char line[], int maxline);


int main() {

    char line[MAXLINE];
    int c;

    getline(line, MAXLINE);

    ungets(line);

    while((c = getch()) != EOF) {
        putchar(c);
    }

    return 0;
}

int getline(char s[], int maxline) {

    int i, c;

    for (i = 0; i < (maxline - 1) && ((c = getchar()) != EOF) && (c != '\n'); i++) {
        s[i] = c;
    }

    if (s[i] == '\n') {
        s[i] = '\n';
        i++;
    }

    s[i] = '\0';
}

void ungets(const char s[]) {
    size_t i;

    i = strlen(s);

    while(i > 0) {
        ungetch(s[--i]);
    }
}

// unread the extra characters
void ungetch(int c) {
    // If buffer is full, print error. Else, put the char back
    if (bufp >= BUFSIZE) {
        printf("error: ungetch: too many characters");
    } else {
        buf[bufp] = c;
        bufp++;
    }
}

int getch() {

    // If buffer is not empty, read from buffer. If empty call getchar()
    if (bufp > 0) {
        //bufp--;
        return buf[--bufp];
    } else {
        return getchar();
    }
}