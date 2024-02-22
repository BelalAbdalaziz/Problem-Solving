/*
    Write a function to remove all characters in a string expect alphabet.
*/

/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
void reverse_string(char* str );

/********** Start of main functions *********/
int main() 
{
    char str[]= "Hello My 12 Bro @57 Belal";    
    printf("Before Reverse %s\n",str);
    reverse_string(str);
    printf("After Reverse  %s\n",str);

    return 0;
}

/********** Functions Definations ***********/
static void swap_twoCharacters(char *character1,char *character2)
{
    char temp = 0;
    temp = *character1;
    *character1 = *character2;
    *character2 = temp;
}
static int get_string_length(char* str )
{
    int counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}
void reverse_string(char* str )
{
    int first = 0;
    int last = 0;
    /*Get String length from user or by implemented function or librarry */
    int strLength =  get_string_length(str);
    /*Loop on a string*/
    for(first= 0 , last= strLength-1 ; first < last ; first++,last--)
    {  
        swap_twoCharacters(&str[first],&str[last]);
    }
}
