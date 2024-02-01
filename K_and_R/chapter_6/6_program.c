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
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *root, char *word);
void treeprint(struct tnode *root);

struct tnode *talloc();
char *strdup(char *word);

int getword(char *new_word, int max_array_len);
int getch();
void ungetch(int);

int main() {

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
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

/* addtree: adds a node if the word is not present, increments the count if already present*/
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {    /* a new word has arrived */
        p = talloc();   /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) { /* word is present in the tree */
        p->count++;   /* repeated word */
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

/* treeprint: inorder traversal of tree - print all left nodes, root, right nodes */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%10s : %4d\n", p->word, p->count);
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