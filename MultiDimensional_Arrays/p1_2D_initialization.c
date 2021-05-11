//2-D array initialization

#include <stdio.h>

int main(){

    int A[2][3];
    int B[2][3]= {{1,2,3},{4,5,6}};
    int C[2][3] = {1,2,3,4,5,6};

    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            printf("Enter the element:");
            scanf("%d", &A[i][j]);
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0; j<3; j++){
            printf("%d\n", C[i][j]);
        }
    }
}
