//Count occurrences of a number in a sorted array with duplicates using Binary Search
//count first and last occurence and then count total number of duplicates
#include <stdio.h>
#include <stdbool.h>

int Count_Duplicates(int *Arr, int ArrLen, int x, bool SearchFrirst){

    int start=0;
    int end=ArrLen-1;
    int mid = ((start+end)/2);
    int result = -1;

    while(start<=end){
        mid = ((start+end)/2);
        if(x == Arr[mid]){
            result = mid;
            if(SearchFrirst)
                end = mid -1;
            else
                start = mid+1;
        }
        else if(x>Arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    if(result!=-1)
        return result;
    return -1;
}



int main() {


    int SortedArr[] = {1,2,3,3,3,4,5,6,7,8,9,9};
    int len2 = (sizeof(SortedArr)/sizeof(SortedArr[0]));

    int FirstIndex = Count_Duplicates(SortedArr, len2, 3, true);


    if(FirstIndex != -1){

        int LastIndex = Count_Duplicates(SortedArr, len2, 3, false);
        printf("Total count is %d",(LastIndex - FirstIndex + 1));
    }
    else{
        printf("Number not found!");
    }



    return 0;
}
