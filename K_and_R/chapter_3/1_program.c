/* binary search */

#include <stdio.h>

int binarysearch(int arr[], int num, int n);

int main() {

    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int search = -1;
    int len = sizeof(arr)/sizeof(arr[0]);

    search = binarysearch(arr, 7, len);
    printf("position is %d\n", search);

    return 0;
}

int binarysearch(int arr[], int num, int n) {

    // indexes of array
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (high + low) / 2;
        if (arr[mid] == num) {
            return mid;
        }
        else if (arr[mid] < num) {
            low = mid+1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}