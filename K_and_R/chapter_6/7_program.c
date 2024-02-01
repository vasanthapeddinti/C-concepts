/* 
    Print in alphabetical order each group of variable names that 
    are identical in the first n characters but different somewhere
    there after. Don't count words with srrings and comments. Make n
    a parameter that can be set from command line
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD   100
#define BUFSIZE     100

static char buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;   /* next free position in buf */

struct tnode {
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *root, char *word, int found, int num);
void treeprint(struct tnode *root);

struct tnode *talloc();
char *strdup(char *word);

int getword(char *new_word, int max_array_len);
int getch();
void ungetch(int);

int main(int argc, char *argv[]) {

    struct tnode *root;
    char word[MAXWORD];
    int num = 6; // set default match as 6

    if (argc == 3) {
        if (strcmp("-n", argv[1]) == 0) {
            num = atoi(argv[2]);
        } else {
            printf("Invalid arguments\n");
            return 1;
        }
    }

    root = NULL;
    while(getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word, 0, num);
        }
    }

    treeprint(root);
    printf("\n");

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

/* addtree: adds a node if the word is not present, increments the count if already present*/
struct tnode *addtree(struct tnode *p, char *w, int found, int num) {
    int cond;

    if (p == NULL) {    /* a new word has arrived */
        p = talloc();   /* make a new node */
        p->word = strdup(w);
        p->match = (found) ? 1 : 0;
        p->left = NULL;
        p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) < 0) {
        if (strncmp(w, p->word, num) == 0) {
            found = p->match = 1;
        }
        p->left = addtree(p->left, w, found, num);
    } else if (cond > 0) {
        if (strncmp(w, p->word, num) == 0) {
            found = p->match = 1;
        }
        p->right = addtree(p->right, w, found, num);
    }

    return p;
}

/* treeprint: inorder traversal of tree - print all left nodes, root, right nodes */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        if (p->match) {
            printf("%10s \n", p->word);
        }
        treeprint(p->right);
    }
}

struct tnode *talloc() {
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdup(char *word) {
    char *p;
    p = (char *)malloc(strlen(word) + 1); // 1 for /0
    if (p != NULL) {
        strcpy(p, word);
    }

    return p;
}