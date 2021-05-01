// Compute Binary Search using recursion
#include <stdio.h>


int BinarySearchRecursive(int *Arr, int low, int high, int x){
    int mid = low + (high-low)/2;

    if(low>high)
        return -1;

    if (x>Arr[mid])
        BinarySearchRecursive(Arr, mid+1, high, x);
    else if(x<Arr[mid])
        BinarySearchRecursive(Arr, low, mid-1, x);
    else if(x==Arr[mid])
        return Arr[mid];
}


int main() {

    int SortedArr[] = {1,2,3,4,5,6,7,8,9};
    int len2 = (sizeof(SortedArr)/sizeof(SortedArr[0]));


    printf("\nSearching for 3 in sorted array using binary search recursively: %d", BinarySearchRecursive(SortedArr, 0, len2-1, 9));
    return 0;
}
