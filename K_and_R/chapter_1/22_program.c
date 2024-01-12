/* program to remove trailing blanks and tabs from each line of input 
 * and to delete entirely blank lines */

/*
1. Remove trailing blanks (' ')
2. Remove trailing tabs ('\t')
3. Delete blank lines ('\n')
*/

/*
    problem 1 and 2 are taken care of remove function
    problem 3 is taken care based on output of getline
        which returns the length of the line
*/

#include <stdio.h>

#define  MAXLINE   1000
#define  YES       1
#define  NO        0


int remove_trails_blanks_nl(char s[]) {

    int i, nl;
    /* ===== begin find nl = YES or NO && remove tabs and blanks ====== */

    // find end of character and the traverse from back
    while (s[i] != '\0') {
        i++;
    }
    i--;       // skip since last charcater is '\0'

    if (s[i] == '\n') {
        nl = YES;
        i--;
    } else {
        nl = NO;
    }

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        // since it is checking for trailing blanks and tabs
        // we decrease the index and later add a \n and \0
        i--;
    }
    
    /* ===== end find nl = YES or NO && remove tabs and blanks ====== */
    
    if (i >= 0) {
        i++;
        if (nl == YES) {
            s[i] = '\n';
            i++;
        }
        s[i] = '\0';
    }
    return(i);
}


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


int main() {

   int len = 0;
   char line[MAXLINE];

    /*
        while(there is a new line)
            if line is valid after cleaning up the tabs, blanks, blank lines
                print line
    */
    while (len = getline(line, MAXLINE)) {
        if (remove_trails_blanks_nl(line) > 0) {     // If it is a valid line: not tabs, blank lines
            printf("line: %s-THEEND-",line);
        }
    }

    return 0;
}
