#include <stdio.h>

int main() {

    const int x = 9;
    int y = 10;

    int *p1 = &y;
    int *p2 = &x;

    printf("Initial values: *p1 is %d and *p2 is %d\n", *p1, *p2);
    printf("p1 is %p and p2 is %p\n", p1, p2);

    // warning: initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
    // This occurs because register variables and const can't provide pointers, but it is implementation specific

    p1 = p1 + 1;
    printf("*p1 is  is %d\n", *p1); // prints garbage

    p1 = p1 - 1;
    printf("*p1 is %d\n", *p1);  // prints value of y

    *p1 = *p1 + 1;
    printf("*p1 is %d\n", *p1);  // prints value of y

    ++*p1;
    printf("*p1 is %d\n", *p1);  // prints value of y

    (*p1)++; // the parentheses is necessary, *p1++ increments the pointer
    printf("*p1 is %d\n", *p1);  // prints value of y

    return 0;
}