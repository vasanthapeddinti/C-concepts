#include <stdio.h>

#define   STEP   20
#define   LOWER  0
#define   UPPER  300

void convert_fahr_celsius(float fahr);

main() {

    convert_fahr_celsius(43);
}

void convert_fahr_celsius(float fahr) {

    float celsius;
    celsius = 5.0 * (fahr - 32.0) / 9.0;
    printf("Fahr is %3f : Celsius is %6.2f\n", fahr, celsius);

}