//Find the only missing number in a sorted array

/*
You are given a sorted array of N integers from 1 to N with one number missing
find the missing number Expected time complexity O(logn)
*/

/*
An efficient solution is to use binary search. We use the index to search for
the missing element and modified binary search. If element at mid != index+1 and
this is first missing element then mid + 1 is the missing element. Else if this
is not first missing element but ar[mid] != mid+1 search in left half. Else search
 in right half and if left>right then no element is missing.

    The solution doesnot work if 1 is missing from the array
*/

//edge cases- len of array is <=1

#include <stdio.h>

int Missing_Num(int Arr[], int len){

    int low = 0;
    int high = len-1;
    int mid = (low+high)/2;

    while(low<=high){

        mid = (low+high)/2;
        if ((mid+1 != Arr[mid])&&(Arr[mid -1]==mid)){
            return mid+1;
        }//search left side
        else if (mid+1 != Arr[mid]){
            high = mid-1;
        }
        //search in the right side
        else if (mid+1 == Arr[mid]){
            low = mid+1;
        }

    }
    return -1;

}//missing number function


int main(){

    int Arr[5] = {1,2,4,5,6};
    int len = 5;

    printf("The missing number is %d\n",Missing_Num((Arr), len));

    return 0;
}
