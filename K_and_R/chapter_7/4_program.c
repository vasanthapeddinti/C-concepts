#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int maxof(int, ...);
int minof(int, ...);

int main(void){
        // first arg is the variable for number of arguments, followed by arguments
        printf("max number is %d\n", maxof(3, 4, 42, 0));
        printf("min number is %d\n", minof(5, 4, 42, 0, -1, 6));
}

int maxof(int n_args, ...){
        int i;
        int max, a;

        printf("debug max: %d\n", n_args);
        /* step 1 */
        va_list ap;

        /* step 2 */
        va_start(ap, n_args);

        /* step 3 */
        max = va_arg(ap, int);
        for(i = 2; i <= n_args; i++) {
                if((a = va_arg(ap, int)) > max)
                        max = a;
        }

        /* step 4 */
        va_end(ap);
        return max;
}

int minof(int n_args, ...) {
    int min, local_min;
    int i;

    va_list ap;

    printf("debug min: %d\n", n_args);
    va_start(ap, n_args);

    min = va_arg(ap, int);
    for (i = 1; i < n_args; i++) {
        if ((local_min = va_arg(ap, int)) < min) {
            min = local_min;
        }
    }

    va_end(ap);
    return min;
}