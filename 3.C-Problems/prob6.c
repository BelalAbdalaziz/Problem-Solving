/*
Write a C function to return the index of LAST occurrence of a 
number in a given array. Array index start from 0. If the item is not 
in the list return -1. (Linear Search Algorithm)
Example:
Array = {1,2,3,4,4,4} 
The required number is 4 it should return 5

*/

/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
int linear_search (int length , int* arr,int required_number);

/********** Start of main functions *********/
int main (void)
{
    int arr[]={1,2,3,4,4,4};
    int ret_value=0;
    ret_value = linear_search(( sizeof(arr) / sizeof(arr[0]) ), arr , 4);
    if(-1 ==ret_value)
    {
        printf("Value Doesn't exist in a list !!\n");
    }
    else
    {
        printf("Value existed in a list in index {%i} !!\n",ret_value);
    }
    return 0;
}

/********** Functions Definations ***********/
int linear_search (int length , int* arr,int required_number)
{
    int counter=0;
    signed int ret_index=0;
    int flag = 0;
    for(counter =0 ; counter <length ; counter ++)
    {
        if(required_number == arr[counter])
        {
            ret_index = counter;
            flag = 1;
        }
    }
    if(0 == flag)
    {
        ret_index = -1;
    }
    return ret_index;
}