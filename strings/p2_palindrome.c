// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

    int palindrome_check(char s[], int length){
        int i=0;
        int j=length - 1;
        
        while(i<j){
            if (s[i] == s[j]){
                i++;
                j--;
            }
            else 
                return -1;
        }
        return 1;
    }
    


int main() {
    
    char s[] = "seaes";
    int length = strlen(s);

    int x =  palindrome_check(s, length);    
    
    printf("%d", x);
    
    return 0;
}