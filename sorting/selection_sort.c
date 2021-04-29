// Online C compiler to run C program online
#include <stdio.h>


void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}



void SelectionSort(int Arr[], int ArrLen){
    int i,j,min_index;
    for(i=0; i<ArrLen-1; i++){
        j=i+1;
        min_index=i;
        while(j<ArrLen){
         if (Arr[j]<Arr[min_index]){
             min_index = j;
         }   
        j++;
        }//while
        swap(&Arr[i], &Arr[min_index]);
    }

}


int main() {
    
    int ArrLen=6;
    int Arr[6] = {4,2,3,5,6,3};

    SelectionSort(Arr, ArrLen);

    for (int i=0; i<ArrLen;i++){
        printf("%d\n",Arr[i]);
    }
    
    return 0;
}
