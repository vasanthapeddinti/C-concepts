//count set bits

#include <stdio.h>

//O(n) complexity
int count_set_bits(int num){

    int count=0;
    while(num){
        count+=(num & 1);
        num = num>>1;
    }
    return count;
}

/*
    // Brian Kernighan’s Algorithm
   1  Initialize count: = 0
   2  If integer n is not zero
      (a) Do bitwise & with (n-1) and assign the value back to n
          n: = n&(n-1)
      (b) Increment count by 1
      (c) go to step 2
   3  Else return count

    O(log n) is time complexity
*/
int efficient_count_set_bits(int num){

    int count=0;
    while(num){
        num = num & (num-1);
        count += 1;
    }
    return count;
}

int main(){

    int num = 9;
    int count =  efficient_count_set_bits(num);
    printf("The number of set bits in %d: %d\n", num, count);

    return 0;
}
