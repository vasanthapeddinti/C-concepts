/* ./a.out chapter_7/dummy1.txt chapter_7/dummy2.txt */

#include <stdio.h>

void filecopy(FILE *input_file_pointer, FILE *output_file_pointer);

int main(int argc, char *argv[]) {

    FILE *fp;

    /* No file pointer arguments, as in no ifp and ofp. So, just copy stdin and print in stdout */
    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            // invalid file
            ++argv;
            if ((fp = fopen(*argv, "r")) == NULL) {
                printf("cat: can't open file %s\n", *argv);
                return 1;
            } else {  // valid file
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
}

void filecopy(FILE *ifp, FILE *ofp) {

    int c;

    while((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
    printf("\n");
}