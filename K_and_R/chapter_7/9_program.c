/* ./a.out chapter_7/dummy1.txt chapter_7/dummy2.txt */

#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *input_file_pointer, FILE *output_file_pointer);

int main(int argc, char *argv[]) {

    FILE *fp;

    char *prog = argv[0];

    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            // invalid file
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open the file %s\n", prog, *argv);
                exit(1);
            } else {  // valid file
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }


    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing to stdout\n", prog);
        exit(2);
    }

    exit(0);
}

void filecopy(FILE *ifp, FILE *ofp) {

    int c;

    while((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
    printf("\n");
}
