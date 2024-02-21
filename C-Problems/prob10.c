/*
Write a function which, given a string, converts all uppercase 
letters to lowercase, leaving the others unchanged.
*/

/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
void convert_upperCase_to_lowerCase(char* str);


/********** Start of main functions *********/
int main() 
{
    char str[]= "Hello My Bro Belal";
    printf("Before Conversion : %s \n",str);
    
    convert_upperCase_to_lowerCase(str);
    printf("After Conversion : %s \n",str);

    return 0;
}

/********** Functions Definations ***********/
void convert_upperCase_to_lowerCase(char* str)
{
    int counter =0;
    while (str[counter] !='\0')
    {
        if ( (str[counter] >='A') && (str[counter] <='Z'))
        {
            // 'A' = 65  ,, 'a' = 97 
            str[counter] = str[counter] + ('a' - 'A');
        }
        else {/*Nothing*/}   
        counter++;
    }
    
}