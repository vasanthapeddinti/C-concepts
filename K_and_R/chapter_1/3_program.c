#include <stdio.h>

main() {

    float fahr = 0;
    int celsius = 0;
    int upper_limit = 300;
    int step = 10;

    printf("\n    Fahrneheit - Celsius Table\n\n\n");

    while(celsius <= upper_limit) {
        fahr = ((9.0 * celsius) / 5.0) + 32.0;
        printf("celsius is %3d : fahrenhiet is %6.2f\n", celsius, fahr);
        celsius += step;
    }
}