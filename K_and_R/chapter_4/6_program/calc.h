#include <stdbool.h>

#define NUMBER  '0'
#define MATH    's'

void push (double f);
double pop();

int getop(char s[]);

int getch();
void ungetch(int c);

void math(char s[]);