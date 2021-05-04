// Find the only missing number in a sorted array starting from any natural number
/*

The underlying concept is:

2+0. 2+1 2+2 2+3 2+4 2+5 2+6?
{2,  3,  4,  5,  6,  7,  9}
0.   1.  2.  3.  4.  5.  6


So, if 9-6 == 0-2, there is no missong element

else search the missing element using binary search
adjusting high and low indices accordingly

*/

#include <stdio.h>

int Missing_Num(int Arr[], int len){

    int low = 0;
    int high = len-1;
    int mid;

    while((high-low)>1){

        mid = low + (high - low)/2;
        //search left
        if ((Arr[low]-low)!=(Arr[mid]-mid)){
            high = mid;
        }
        //search right
        else if ((Arr[high]-high)!=(Arr[mid]-mid)){
            low = mid;
        }
        else if ((Arr[low]-low)==(Arr[mid]-mid) && (Arr[high]-high)==(Arr[mid]-mid)){
            printf("No missing number\n");
            return -1;
        }

    }//while

    return (Arr[low]+1);
}



int main(){


    int Arr[6] = {17,18,19,20,22,23};
    int len = 6;

    printf("The missing number is %d",Missing_Num((Arr), len));

    return 0;
}
