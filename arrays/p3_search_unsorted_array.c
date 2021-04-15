/*
searching the unsorted array
Corner cases
1. empty string or length of array is zero
2. dupliacte elements
3. Invalid elements

56 4 7 8 34

*/
#include <stdio.h>

int recSearch(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     if (arr[r] == x)
        return r;
     return recSearch(arr, l+1, r-1, x);
}

int main() {
    // Write C code here
    int length;
    int element;
    int left =0;
    int output=0;
    
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    int array[length];
    int sum = 0;
    int right = length-1;

    
    printf("Initialize the array:\n ");
    for (int i=0; i<length; i++){
        printf("Enter the elements of array: ");
        scanf("%d", &array[i]);
    }
    
    printf("Enter the element to find: ");
    scanf("%d", &element);
    

    output = recSearch(array, left, right, element);
    
    if(output == -1){
        printf("Element is not present");
        printf("%d", output);
    }
    else
        printf("Element is present at the index %d", output);
    
    
    return 0;
}