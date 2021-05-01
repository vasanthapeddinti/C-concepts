// Compute Linear Search and Binary Search
#include <stdio.h>

int LinearSearch(int *Arr, int ArrLen, int x){

    for (int i=0; i<ArrLen;i++){
        if(x==Arr[i])
            return x;
    }
    return -1;
}

int BinarySearch(int *Arr, int ArrLen, int x){

    int start=0;
    int end=ArrLen-1;
    int mid = ((start+end)/2);

    while(start<=end){
        mid = ((start+end)/2);
        if(x == Arr[mid]){
            return x;
        }
        else if(x>Arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}



int main() {

    int UnsortedArr[] = {2,3,5,23,6,7,12,1};
    int len1 = (sizeof(UnsortedArr)/sizeof(UnsortedArr[0]));

    int SortedArr[] = {1,2,3,4,5,6,7,8,9};
    int len2 = (sizeof(SortedArr)/sizeof(SortedArr[0]));

    printf("Searching for 3 in unsorted array using linear search: %d", LinearSearch(UnsortedArr, len1, 3));

    printf("\nSearching for 3 in sorted array using binary search: %d", BinarySearch(SortedArr, len2, 3));

    return 0;
}
