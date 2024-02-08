/* minicat - min version of cat */
// ./a.out chapter_8/original.txt 
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/file.h>
#include <stdlib.h>

void error(char *fmt, ...);

int main(int argc, char *argv[]) {

    int f1;
    int f2;
    int n;
    char buf[BUFSIZ];

    f2 = 1; // stdout fd

    if (argc != 2) {
        error("Usage: cat file.txt");
    }
    /* open the file */
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
        error("cat: can't open the file %s", argv[1]);
    }

    /* read the file and store in the buffer */
    /* write from the buffer to stdout */
    while ((n = read(f1, buf, BUFSIZ)) > 0) {
        if (write(f2, buf, n) != n) {
            error("cat: write error on file stdout: read characters %d", n);
        }
    }
    printf("\n");

    /* close file */
    close(f1);

    
    return 0;
}


void error(char *fmt, ...) {
    va_list args;

    va_start(args, fmt);

    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    va_end(args);

    exit(1);
}
