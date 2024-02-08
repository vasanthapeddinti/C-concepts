#include <unistd.h>
#include <stdio.h>

int getchar();

int main() {

    if (getchar() != EOF) {
        printf("Got a char!\n");
    }
    return 0;
}

int getchar() {
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}