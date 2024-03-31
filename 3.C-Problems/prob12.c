/*
    Write a function to find the length of a string.
*/

/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
int get_string_length(char* str );

/********** Start of main functions *********/
int main() 
{
    char str[]= "Hello My Bro Belal";    
    printf("Frequency of character is %i\n",get_string_length(str));
    return 0;
}

/********** Functions Definations ***********/
int get_string_length(char* str )
{
    int counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}
