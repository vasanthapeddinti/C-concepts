/* count C keywords */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS       sizeof(keytab)/sizeof(keytab[0])
#define MAXWORD     100
#define BUFSIZE     100

static char buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;   /* next free position in buf */

/* List of keywords must be in sorted in increasing order */
struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int getch();
void ungetch(int);
int getword(char *new_word, int max_word_len);
int binsearch(char *word, struct key *tab, int array_len);


int main() {

    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
                keytab[n].count++;
            }
        }
    }

    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }

    return 0;
}

/* binary search in the array of structures */
/* 
    strcmp("zyx", "abc") - positive 
    strcmp("abc", "zyx") - negative
    strcmp("test", "test") - 0 
*/
int binsearch(char *word, struct key tab[], int array_len) {
    int cond;
    int low, high, mid;

    low = 0;
    high = array_len - 1;
    while (low <= high) {

        mid = (low + high) / 2;
        cond = strcmp(word, tab[mid].word);

        if (cond > 0) {
            low = mid + 1;
        } else if (cond < 0) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
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

// unread the character
void ungetch(int c) {
    // If buffer is full, print error. Else, put the char back
    if (bufp >= BUFSIZE) {
        printf("error: ungetch: too many characters");
    } else {
        buf[bufp] = c;
        bufp++;
    }
}

/* getword: get next word or character from input */
int getword(char *new_word, int max_word_len) {
    int c;
    char *w = new_word;
    int c_next;

    while (isspace(c = getch())) {
        ;
    }

    if (c != EOF) {
        *w++ = c;// copy each character and write it to char *w (string)
        // *w = c;
        // w++;
    }

    if (!isalpha(c)) {
        // string constants look like "hello", \ is the escape sequence
        if (c == '\"') {
            for (c = getch(); c != '\"'; c = getch()) {
                ; // basically skip the string constant
            }
        } else if (c == '#') {// handle preprocessor directives
            for (c = getch(); c != '\n'; c = getch()) {
                ; // skip the preprocessor directives
            }
        } else if (c == '/') { // comment
            if ((c = getch()) == '/') { // single line comment
                for (c = getch(); c != '\n'; c = getch()) {
                    ; // skip the comment
                }
            } else if (c == '*') { // block comment
                for (c = getch(), c_next = getch(); c != '*' && c_next != '/'; c = getch(), c_next = getch()) {
                    ungetch(c_next);
                }
            } else {
                ungetch(c);
            }
        } else { // underscore
            for ( ; !isspace(c) && c != EOF; c = getch()) {
                ;
            }
        }
        if (c != '\"' && c != '\n' && c != '/') {
            ungetch(c);
        }
        *w = '\0';
        return c; // return the last character?
    }

    for ( ; --max_word_len; w++) {
        if (!isalnum(*w = getch())) {
            if (!isspace(*w)) {
                ungetch(*w);
                return (*w);
            } else {
                ungetch(*w);
                break;
            }
        }
    }

    *w = '\0';
    return new_word[0];
}