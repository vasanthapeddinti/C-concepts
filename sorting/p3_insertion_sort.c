//Insertion sort


#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int *Arr, int ArrLen){
    int j;

    for(int i=1; i<ArrLen; i++){
        j = i;
        while((j>0)&&(Arr[j]<=Arr[j-1])){
                swap(&Arr[j-1], &Arr[j]);
                j--;
        }
    }
}



int main() {
    // Write C code here
    int Arr[] = {56,9,5,4,2,2,1,7,78};

    int Arrlen = sizeof(Arr)/sizeof(Arr[0]);

    InsertionSort(Arr, Arrlen);

    for(int i=0; i<Arrlen; i++){
        printf("%d\n",Arr[i]);
    }


    return 0;
}
