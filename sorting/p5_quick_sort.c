#include <stdio.h>


void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
1. Pivot is taken as last index
2. partition and sort
3. Partition: Put all the integers less than Pivot to the left and move the pivot in the middle
4. Repeat the partiotion and quick sort

*/
int Partition (int A[], int leftIndex, int rightIndex){

    int pivot = A[rightIndex];
    int pIndex = leftIndex;

    for (int i=leftIndex; i<=rightIndex-1; i++){
        if(A[i]<=pivot){
            swap(&A[i], &A[pIndex]);
            pIndex++;
        }
    }
    swap(&A[pIndex], &A[rightIndex]);
    return pIndex;
}

void quickSort(int A[], int leftIndex, int rightIndex){

    if (leftIndex <= rightIndex){
        int pIndex = Partition (A, leftIndex, rightIndex);
        quickSort(A, leftIndex, pIndex-1);
        quickSort(A, pIndex+1, rightIndex);
    }
}



int main() {


    int UnsortedArr[] = {2,3,5,5,6,7,8,1,4};
    int len = (sizeof(UnsortedArr)/sizeof(UnsortedArr[0]));


    quickSort(UnsortedArr, 0, len-1);

    for(int i=0; i<len; i++){
        printf("%d\n",UnsortedArr[i]);
    }



    return 0;
}
