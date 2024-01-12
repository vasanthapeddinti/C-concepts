#include <stdio.h>

int power (int base, int exponent);


int main() {

    printf("result is %d\n", power(2, 0));

    return 0;
}

int power (int base, int n) {
    int i, result;

    i = 0;
    result = 1;

    while (i < n) {
        result *= base;
        i++;
    }

    return result;
}