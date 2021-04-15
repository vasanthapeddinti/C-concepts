/*
basically searching the highest element
Corner cases
1. empty string or length of array is zero
2. negative numbers
3. dupliacte elements
4. Invalid elements
*/
#include <stdio.h>

int highest_element(int a[], int len){
    int max;

    for(int i=0; i<len; i++){
        if(a[i]>=max){
            max = a[i];
        }
    }   

    return max;
}


int main() {
    // Write C code here
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    int array[length];
    int sum = 0;
    
    printf("Initialize the array:\n ");
    for (int i=0; i<length; i++){
        printf("Enter the element: ");
        scanf("%d", &array[i]);
    }
    
    printf("highest element in array is %d", highest_element(array, length));
    
    return 0;
}