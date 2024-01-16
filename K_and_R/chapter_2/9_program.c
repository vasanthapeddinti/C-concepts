/* Write a function any(s1, s2), which returns the first location in the string s1 where any character
* from string s2 occures, or -1 if s1 contains no characters from s2. (strpbrk does the same job, but 
* returns pointer to the location) 
* s1 = "I am Vasantha"
* s2 = "asdf"
* n = 2
*/

#include <stdio.h>

int any(char s1[], char s2[]);

int main() {

    char s1[] = "I am Vasantha";
    char s2[] = "asdf";

    printf("first position match for s1 and s2 is %d\n", any(s1, s2));

    return 0;
}

int any(char s1[], char s2[]) {

    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}