/*
Write a function that prints the frequency of a certain 
character in a string.  (Frequency : How Mnay This Character is repeated)

*/

/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
int print_frequencyOfCharacter(char* str , char target);


/********** Start of main functions *********/
int main() 
{
    char str[]= "Hello My Bro Belal";    
    printf("Frequency of character is %i\n",print_frequencyOfCharacter(str,'o'));

    return 0;
}

/********** Functions Definations ***********/
int print_frequencyOfCharacter(char* str , char target)
{
    int counter = 0;
    int char_freq = 0;
    while(str[counter] != '\0')
    {
        if(str[counter] == target)
        {
            char_freq++;
        }
        counter++;
    }
    return char_freq;
}
