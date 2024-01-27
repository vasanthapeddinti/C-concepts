/* Define a macro swap(t,x,y) that interchanges two arguments of type t */
#include <stdio.h>
#define SWAP(t, x, y) { t _temp;    \
                        _temp = x;  \
                        x = y;      \
                        y = _temp;  }

int main() {

    int num1 = 10;
    int num2 = 20;

    SWAP(int, num1, num2);
    printf("num1 is %d, num2 is %d\n",num1, num2);
    return 0;
}