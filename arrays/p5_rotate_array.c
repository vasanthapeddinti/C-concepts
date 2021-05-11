/*

A : [1 2 3 4 5 6]
B : 1
*/

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* rotateArray(int* A, int n1, int B, int *len) {
    int *ret = (int *)malloc(n1 * sizeof(int));
    *len = n1;
    int i,j;
    int x = B%n1;

    for (i = 0; i < (n1-x); i++) {
        ret[i] = A[i + x];

    }

    j=0;
    while(j<x){
        ret[i]= A[j];
        j++;
        i++;
    }
    return ret;
}
