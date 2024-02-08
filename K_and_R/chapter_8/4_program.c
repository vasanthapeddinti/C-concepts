/* cp f1 f2 */


/* ./a.out chapter_8/original.txt copy.txt */
#include <sys/file.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define PERMS   0666 // permissions for the new file created for f2

void error(char *fmt, ...);

int main(int argc, char *argv[]) {

    int f1, f2, n; // copy f1 to f2 : cp f1 f2
    char buf[BUFSIZ];

    if (argc != 3) {
        error("Usage: cp from to");
    }
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
        error("cp: can't open %s", argv[1]);
    }
    if ((f2 = creat(argv[2], PERMS)) == -1) {
        error("cp: can't create %s, mode %03o", argv[2], PERMS);
    }

    while ((n = read(f1, buf, BUFSIZ)) > 0) {
        if (write(f2, buf, n) != n) {
            error("cp: write error on file %s", argv[2]);
        }
    }

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

