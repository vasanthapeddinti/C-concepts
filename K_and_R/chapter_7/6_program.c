/* sscanf and sprintf examples */

#include <stdio.h>

#define MAXLINE   100

// defined as external varibles
// The functions that use them add extern keyword before type to use
char line[MAXLINE];

void readunformattedline();
int getline();

int main() {

    int a = 10;
    char buffer1[50]; // cannot declare char *buffer1 as it needs the space to store at compilation

    int b;
    char buffer2[50] = "2345";

    sprintf(buffer1, "Number stored in buffer is %d\n", a); /* stores in buffer instead of writing to stdout */
    printf("%s", buffer1);

    sscanf(buffer2, "%d", &b); /* scans from buffer instead of stdin */
    printf("The number scanned from buffer is %d\n", b);

    readunformattedline();

    return 0;
}

void readunformattedline() {

    /*
     Formats supported:
     1. 25 Dec 1988 
     2. mm/dd/yy
     */
    char monthname[20];
    int day, year, month;

    while(getline(line, sizeof(line)) > 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {
            printf("valid input: %d %s %d\n", day, monthname, year);
        } else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
            printf("valid input: %d %d %d", month, day, year);
        } else {
            printf("Invalid input: %s", line);
        }
    }
}

int getline() {

    int c, i;
    extern char line[];
    i = 0;

    while(((c = getchar()) != EOF) && (c != '\n') && (i < MAXLINE-1)) {
        line[i] = c;
        i++;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}