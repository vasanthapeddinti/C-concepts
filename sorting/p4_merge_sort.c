/*
Divide and Conquer Algorithm
Recursive
Stable
Not in-place
O(n) - space Complexity
O(n*log n) - time Complexity
*/

#include <stdio.h>

//merge two arrays [l..m] and [m+1,..r]
void merge(int Arr[], int LeftIndex, int RightIndex, int MidIndex){
    /*
    1. Calculate the length of the left and right subarrays
    2. Create new left sub array and right sub array
    3. Merge tha arrays
    */
    int i, j, k;
    int leftlen = MidIndex - LeftIndex + 1;
    int rightlen = RightIndex - MidIndex; //r-m-1+1

    int LeftSubArr[leftlen];
    int RightSubArr[rightlen];

    for (i=0; i<leftlen; i++){
        LeftSubArr[i] = Arr[LeftIndex+i];
    }

    for (j=0; j<rightlen; j++){
        RightSubArr[j]=Arr[MidIndex+1+j];
    }

    i=0;
    j=0;
    k=LeftIndex;

    while(i<leftlen && j<rightlen){
        if(LeftSubArr[i]<=RightSubArr[j]){
            Arr[k] = LeftSubArr[i];
            i++;
        }
        else if (LeftSubArr[i]>RightSubArr[j]){
            Arr[k] = RightSubArr[j];
            j++;
        }
        k++;
    }

    while(i<leftlen){
        Arr[k] = LeftSubArr[i];
        i++;
        k++;
    }

    while(j<rightlen){
        Arr[k] = RightSubArr[j];
        j++;
        k++;
    }

}

void mergeSort(int Arr[], int LeftIndex, int RightIndex){
    if (LeftIndex<RightIndex){
        int MidIndex = LeftIndex + (RightIndex - LeftIndex)/2;

        mergeSort(Arr, LeftIndex, MidIndex);
        mergeSort(Arr, MidIndex+1, RightIndex);
        merge(Arr, LeftIndex, RightIndex, MidIndex);
    }
}


int main() {


    int UnsortedArr[] = {2,3,5,6,7,8,1,4};
    int len = (sizeof(UnsortedArr)/sizeof(UnsortedArr[0]));


    mergeSort(UnsortedArr, 0, len-1);

    for(int i=0; i<len; i++){
        printf("%d\n",UnsortedArr[i]);
    }



    return 0;
}
