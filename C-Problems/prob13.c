/*
    Write a function to remove all characters in a string expect alphabet.
*/

/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
void remove_non_alphabet(char* str );

/********** Start of main functions *********/
int main() 
{
    char str[]= "Hello My 12 Bro @57 Belal";    
    printf("Before Remove Non Alphabet %s\n",str);
    remove_non_alphabet(str);
    printf("After Remove Non Alphabet %s\n",str);

    return 0;
}

/********** Functions Definations ***********/
void remove_non_alphabet(char* str )
{
    int counter = 0;
    int new_counter = 0;
    /*Loop on a string*/
    for(counter=0;str[counter] !='\0';counter++)
    {
        /*Is Character alphabet*/
        if((str[counter] >='A' && str[counter]<='Z' )|| (str[counter]>='a' &&str[counter] <='z' ))
        {
            /*in a new location<start from 0> of the same arr put this character*/
            str[new_counter] = str[counter];
            new_counter++;
        }
    }
    /*End Of String only alphabet*/
    str[new_counter]='\0';
}
