/* basic crossreferencer */

/*
 * Write a cross-referencer that prints a list of all words in a document, and
 * for each word, a list of the line numbers on which it occurs. Remove noise
 * words like "the" and "and" so on.
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define IN 1
#define OUT 0
#define BUFSIZE     100
#define MAXWORD     20

struct linklist {  /* linked list of line numbers */
    int lnum;
    struct linklist *ptr;
};

struct tnode {
    char *word;
    struct linklist *lines;
    struct tnode *left;
    struct tnode *right;
};

static char buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;   /* next free position in buf */

struct tnode *addtree(struct tnode *root, char *word, int linenum);
void treeprint(struct tnode *root);

struct tnode *talloc();
char *strdup(char *word);

struct linklist *lalloc();
void addln(struct tnode *p, int linenum);

int getword(char *word, int lim, int *lineno_addr);
int getch();
void ungetch(int);

int noiseword(char * w);

int main() {

    struct tnode *root;
    char word[MAXWORD];
    int linenum = 1;

    root = NULL;
    while (getword(word, MAXWORD, &linenum) != EOF) {
        if (isalpha(word[0]) && (noiseword(word) == -1)) {
            root = addtree(root, word, linenum);
        }
    }
    treeprint(root);

    return 0;
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
int getword(char *new_word, int max_word_len, int *lineno_addr) {
    int c;
    char *w = new_word;
    int c_next;

    while (isspace(c = getch())) {
        if (c == '\n') {
            *lineno_addr += 1;
        }
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


struct tnode *addtree(struct tnode *p, char *word, int linenum) {
    struct tnode *talloc();
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(word);
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(word, p->word)) == 0) {
        addln(p, linenum);
    } else if (cond < 0) {
        p->left = addtree(p->left, word, linenum);
    } else {
        p->right = addtree(p->right, word, linenum);
    }
    return (p);
}

void treeprint(struct tnode *p) {
    struct linklist *temp;
    if (p != NULL) {
        treeprint(p->left);
        printf("\n");
        printf("%10s", p->word);
        for (temp = p->lines; temp != NULL; temp = temp->ptr) {
            printf("%4d ", temp->lnum);
        }
        printf("\n");
        treeprint(p->right);
    }
}

struct tnode *talloc() {
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/* add a line number to the linked list */
// if a word is repeated twice in a line, ignore it
void addln(struct tnode *p, int linenum) {
    struct linklist *temp;

    temp = p->lines;

    while (temp->ptr != NULL && temp->lnum != linenum) {
        temp = temp->ptr;
    }

    if (temp->lnum != linenum) {
        temp->ptr = lalloc();
        temp->ptr->lnum = linenum;
        temp->ptr->ptr = NULL;
    }
}

struct linklist *lalloc() {
    return ((struct linklist *)malloc(sizeof(struct linklist)));
}

char *strdup(char *word) {
    char *p;
    p = (char *)malloc(strlen(word) + 1); // 1 for /0
    if (p != NULL) {
        strcpy(p, word);
    }

    return p;
}

/* noiseword: identify word as noise word */
int noiseword(char * w) {

    static char *nw[] = {
        "a",
        "an",
        "and",
        "are",
        "is",
        "of",
        "or",
        "that",
        "this",
        "to"
    };

    // low, high, mid are rows in the 2-d array
    int cond, mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(char *) - 1; // like 

    while(low <= high) {
        mid = (low + high) / 2;
        cond = strcmp(w, nw[mid]);
        if (cond < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}