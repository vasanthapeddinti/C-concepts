// C program to reverse a string using recursion
# include <stdio.h>

/* Function to print reverse of the passed string */
void reverse_string_rec(char *string){
    if(*string){
        reverse_string_rec(string+1);
        printf("%c",*string);
    }
}

/* Driver program to test above function */
int main()
{
    char string[] = "Hello World";
    
    reverse_string_rec(string);
}
