#include <stdio.h>

main() {

    int fahr = 0;
    int upper_limit = 300;
    int step = 10;
    float celsius = 0;

    printf("\n   Fahrenhiet - Celsius Table \n\n\n");

    while (fahr <= upper_limit) {
        celsius = 5 * (fahr - 32) / 9;
        printf("Fahr is %3d : Celsius is %6.2f\n", fahr, celsius);
        fahr += step;
    }
}