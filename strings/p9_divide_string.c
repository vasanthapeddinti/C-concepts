// Write a program to print N equal parts of a given string.
#include <stdio.h>
#include <string.h>

void divide_string(char s[], int n){
    int str_size = strlen(s);
    int part_size;
    
    if (str_size%n != 0){
        printf("Length is not a mulltiple of n");
        return;
    }
        
    part_size = str_size/n;

    
    for (int i=0; i<str_size; i++){
        if (i%part_size == 0){
            printf("\n");
        }
        printf("%c",s[i]);
    } 
}

int main() {
    // Write C code here
    char s[]= "HelloWorld";
    int n = 5;
    
    divide_string(s, n);
    
    
    return 0;
}