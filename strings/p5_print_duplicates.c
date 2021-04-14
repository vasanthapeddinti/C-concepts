
// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#define ASCII_VAL 256

char print_duplicates(char* str){
    
    if (str==NULL)
        return;
    int len = strlen(str);
    if (len<2)
        return;   
    
    int ascii_count[ASCII_VAL]={0};
    int i;
    
    for (i=0; i<len; i++){
        ascii_count[str[i]]++;
        if (ascii_count[str[i]] > 1){
            printf("%c\n",str[i]);
        }
    }
}


int main() {
    // Write C code here
    char string[] = "Hello wwworrrld";

    print_duplicates(string);
    
    return 0;
}