/*
Write a program that will print arbitrary input in a sensible way. As a minimum,
it should print non-graphic characters in octal or hexadecimal according to local
custom, and break long text lines. 
*/

/*
The Non graphic characters are the characters which cannot be typed directly through the keyboard.
A graphic character, also known as printing character (or printable character), is any character
intended to be written, printed, or otherwise displayed in a form that can be read by humans.
*/


// iscntrl is false => graphic chars


#include <stdio.h>
#include <ctype.h>

#define MAXLINE  30
#define OCTLEN    6   /* Length of octal value */

int inc(int pos, int n);


int main() {

    int c, pos;
    pos = 0;

    while((c = getchar()) != EOF) {
        if (iscntrl(c) || c == ' ') {
            // non-graphic character or blank character
            pos = inc(pos, OCTLEN);
            printf(" \\%03o ", c);

            // reset the position if user gave '\n'
            if (c == '\n') {
                pos = 0;
                putchar('\n');
            }
        } else {
            // graphic character
            pos = inc(pos, 1);
            putchar(c);
        }
    }

    return 0;
}


/*
Sometimes, non-graphic characters contain muliple characters. Ex: a tab can contain 4 blanks.
We compute the final position and see if it is less than MAXLINE
If it is greater than MAXLEN, put the character in next line
*/
int inc(int pos, int n) {
    if ((pos + n) < MAXLINE) {
        return (pos + n);
    } else {
        putchar('\n');
        return n;
    }
}