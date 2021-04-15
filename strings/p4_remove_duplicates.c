
// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#define ASCII_VAL 256

char* remove_duplicates(char* str){
    
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
            for(int j=i;j<len;j++){
                str[j]=str[j+1];
            }
            i=i+1;
        }
    }
    return str;
}
    



int main() {
    // Write C code here
    char string[] = "Hello world";

    printf("%s\n", remove_duplicates(string));
    
    return 0;
}