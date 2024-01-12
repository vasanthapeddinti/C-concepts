#include <stdio.h>

#define   STEP   20
#define   LOWER  0
#define   UPPER  300
main() {

    float celsius = 0;
    
    printf("\n   Fahrenhiet - Celsius Table \n\n\n");
    
    for (int fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        celsius = 5 * (fahr - 32) / 9;
        printf("Fahr is %3d : Celsius is %6.2f\n", fahr, celsius);
    }
}