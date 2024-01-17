/* Shell Sort algorithm - an improvisation of insertion sort */

#include <stdio.h>

void shellsort(int arr[], int n);

int main() {

    int i;
    int arr[] = {2,5,8,1,4,9};

    shellsort(arr, 6);

    printf("Sorted array is \n");
    for (i = 0; i < 6; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    return 0;
}

void shellsort(int arr[], int n) {

    int i, j, gap, temp;

    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >=0 && arr[j] > arr[j+gap]; j -= gap) {
                temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
            }
        }
    }
}