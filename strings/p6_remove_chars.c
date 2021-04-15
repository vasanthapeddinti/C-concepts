/*
Write an efficient C function that takes two strings
 as arguments and removes the characters from first 
 string which are present in second string (mask string). 
 algorithm link - https://www.tutorialcup.com/interview/string/remove-characters-string-second.htm
*/

#include <stdio.h>
#include <string.h>
#define ASCII_VAL 256

char* remove_chars(char* str1, char* str2){
    
    if (str1==NULL)
        return;

    if (str2==NULL)
        return str1;
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int ascii_count[ASCII_VAL]={0};
    int i;
    
    for (i=0; i<len2; i++){
        ascii_count[str2[i]]++;
    }
    
    int j=0;
    for(i=0; i<len1; i++){
        if(ascii_count[str1[i]] >=1){
            continue;
        }
        else{
            str1[j]= str1[i];
            j++;
        }
    }
    str1[j]='\0';
    return str1;
}


int main() {
    // Write C code here
    char string1[] = "Computer";
    char string2[] = "camp";

    printf("%s",remove_chars(string1, string2));
    
    return 0;
}