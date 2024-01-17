/* Simple variation of binary search */


#include <stdio.h>

int binarysearch(int arr[], int num, int n);
//int binsearch(int x, int v[], int n);

int main() {

    int arr[10] = {1,2,3,4,5,6,7,8,9};

    printf("%d\n", binarysearch(arr, 3, 9));
    return 0;
}

int binarysearch(int arr[], int num, int n) {

    // indexes of array
    int low, high, mid;

    low = 0;
    high = n - 1;

    while ((low <= high) && (arr[mid] != num)) {

        mid = (high + low) / 2;

        if (arr[mid] < num) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    return ((arr[mid] == num) ? mid : -1);
}
