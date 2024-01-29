#include <stdio.h>

void swap(int *num1, int *num2);

int main() {

    int a = 10, b = 20;
    printf("before swap: a and  b are %d, %d\n", a, b);

    swap(&a, &b);

    printf("after swap: a and  b are %d, %d\n", a, b);
    return 0;
}

void swap(int *num1, int *num2) {

    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}