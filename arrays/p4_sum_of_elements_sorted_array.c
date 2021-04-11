/*
Given an unsorted array, find two elements that add upto the sum
Corner cases
1. empty string or length of array is zero
2. dupliacte elements
3. Invalid elements

1 2 3 4 5 - numbers
0 1 2 3 4 - indices

*/
#include <stdio.h>
#include <stdbool.h>

void find_elements_of_sum(int a[], int length, int sum){

    int i=0; 
    int j=length-1;
    int flag=0;
    
    while(i<j){
        if (a[i]+a[j] == sum){
            printf("elements are %d %d\n", a[i], a[j]);
            i++;
            j--;
            flag++;
        }
        else if (a[i]+a[j] > sum){
            j--;
        }
        else{
            i++;
        }
    }
    if(flag==0){
        printf("Elemenrs are not present");
        return 0;
    }
    return 0;
}


int main() {

    // Write C code here
    int length=5;
    int array[5] = {1,2,3,4,5};
    int sum = 9;

    find_elements_of_sum(array, length, sum);

    return 0;

}