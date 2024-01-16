/* Write an alternate version of squeeze(s1, s2) that deletes each character 
*  in s1 that matches any character in the string s2
*/

/*
* If there are repeated characters in s2, try to get all the unique characters
* If s2 has unique characters, this step is not necessary
*
* Once s2 has unique, iterate over s1 with 2 for loops.
*   for each letter1 in s2
*       for each letter2 in s1
*           check if letter1 == letter2
*               remove the letter using 2 pointers
* s1 = "abcdef"
* s2 = "ace"
* s1 = "bdf"
*/

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {

    char s1[] = "my name is vasantha";
    char s2[] = "iy";

    squeeze(s1, s2);

    printf("Strings after squeeze is %s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[]) {

    int i, j, k;

    for (i = 0; s2[i] != '\0'; i++) {
        for (k = 0, j = 0; s1[j] != '\0'; j++) {
            if (s1[j] != s2[i]) {
                s1[k] = s1[j];
                k++;
            }
        }
        // we copy all the letters that are not 'i' in first iterationa and add delimitter in the end
        // similarly, we copy all the letters that are not 'y' in first iterationa and add delimitter in the end
        // adding delimitter here removes the repetiotion of last character in the end
        s1[k] = '\0';
    }
}
