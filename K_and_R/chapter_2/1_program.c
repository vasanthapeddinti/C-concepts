/* Ranges of char, short, int, long
 * for both signed and unsigned
 * So, the combinations are 
 * 1. signed char 2. unsigned char
 * 3. signed short 4. unsigned short
 * 5. signed int 6. unsigned int
 * 7. signed long 4. unsigned long
 */

#include <stdio.h>
#include <limits.h>

int main() {

    // char max min ranges
    printf("Range of signed char is [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char is [%u, %u]\n", 0, UCHAR_MAX);
    printf("Range of char is [%d, %d]\n", CHAR_MIN, CHAR_MAX);

    // short max min ranges
    printf("Range of signed short is [%hd, %hd]\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short is [%hu, %hu]\n", SHRT_MIN, SHRT_MAX);

    // int max min ranges
    printf("Range of signed int is [%d, %d]\n", INT_MIN, INT_MAX);
    printf("Range of unsigned int is [%u, %u]\n", 0, UINT_MAX);

    // long max min ranges
    printf("Range of signed long is [%ld, %ld]\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long is [%lu, %lu]\n", 0, ULONG_MAX);

    return 0;
}