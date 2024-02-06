// make
// ./a.out -u r

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int c;
    if (argc > 1) {
        if (strcmp(argv[1], "-u") == 0) {
            c = toupper(*argv[2]);
        } else if (strcmp(argv[1], "-l") == 0) {
            c = tolower(*argv[2]);
        } else {
            printf("Need an argument.\n Valid arguments are -l, -u");
            exit(-1);
        }
    } else {
        printf("Need an argument.\n Valid arguments are -l, -u");
        exit(-1);
    }

    printf("The converted character of %c is %c\n",*argv[2], c);
    return 0;
}