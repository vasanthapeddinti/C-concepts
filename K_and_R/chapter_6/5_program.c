/* find C keywords using pointers to structures */
/* https://stackoverflow.com/questions/25946706/comparing-two-binsearches-from-kr-array-indices-vs-pointers */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS     sizeof(keytab)/sizeof(keytab[0])
#define MAXWORD   100
#define BUFSIZE     100

static char buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;   /* next free position in buf */

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
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int getch();
void ungetch(int);
int getword(char *new_word, int max_word_len);
struct key *binsearch(char *word, struct key *tab, int array_len);

int main() {

    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            p = binsearch(word, keytab, NKEYS);
            if (p != NULL) {
                p->count++;
            }
        }
    }

    // keytab - array(implies the address of the first element a[0])
    // NKEYS - total no of array elements
    // keytab + NKEYS --> total size of array in bytes 
    for (p = keytab; p < keytab + NKEYS; p++) {
        if (p->count > 0) {
            printf("%4d %s\n", p->count, p->word);
        }
    }// pointer  based dereference


    return 0;
}

/* find word in tab[0]....tab[array_len-1] */
struct key *binsearch(char *word, struct key *tab, int array_len) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[array_len];
    struct key *mid;

    // since array of structure pointers is still contiguous,
    // this condition is still valid
    while(low < high) {
        mid = low + (high - low)/2;
        cond = strcmp(word, mid->word);

        // low, high and mid are addresses of array elements
        // each element is a structure
        // mid + 1 or mid - 1 will increment or decrement the address of tab accordingly
        if (cond > 0) {
            low = mid + 1;
        } else if (cond < 0) {
            high = mid;
        } else {
            return mid;
        }
    }
    return NULL;
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

    while (isspace(c = getch())) {
        ;
    }

    if (c != EOF) {
        *w++ = c;// copy each character and write it to char *w (string)
        // *w = c;
        // w++;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c; // return the last character?
    }

    for ( ; --max_word_len; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return new_word[0];
}