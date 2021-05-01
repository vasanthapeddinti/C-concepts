// Compute last and first occurence of an element in an array using binary Search
#include <stdio.h>


int BinarySearch_LastOccurence(int *Arr, int ArrLen, int x){

    int start=0;
    int end=ArrLen-1;
    int mid = ((start+end)/2);
    int result = -1;

    while(start<=end){
        mid = ((start+end)/2);
        if(x == Arr[mid]){
            result = mid;
            start = mid+1;
        }
        else if(x>Arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    if(result!=-1)
        return result;
    return -1;
}

int BinarySearch_FirstOccurence(int *Arr, int ArrLen, int x){

    int start=0;
    int end=ArrLen-1;
    int mid = ((start+end)/2);
    int result = -1;

    while(start<=end){
        mid = ((start+end)/2);
        if(x == Arr[mid]){
            result = mid;
            end = mid -1;
        }
        else if(x>Arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    if(result!=-1)
        return result;
    return -1;
}



int main() {


    int SortedArr[] = {1,2,3,3,3,4,5,6,7,8,9,9};
    int len2 = (sizeof(SortedArr)/sizeof(SortedArr[0]));

    printf("\nFirst occurence of 3 in sorted duplicate array using binary search is at index: %d", BinarySearch_FirstOccurence(SortedArr, len2, 3));


    printf("\nLast occurence of 3 in sorted duplicate array using binary search is at index: %d", BinarySearch_LastOccurence(SortedArr, len2, 3));

    return 0;
}
