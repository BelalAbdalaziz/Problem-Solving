/*The sum of an array is the sum of its individual elements. 
For example, if an array is numbers = {1, 2, 3, 4}, the sum of the array
is 1+2+3+4 = 10.
Function Description: Complete the function summation. The
function must return the integer sum of the numbers array.*/

/************ Includes ***********************/
#include <stdio.h>
/********** Functions Declarations ***********/
int summation(int arr_length, int* numbers_array);

/********** Start of main functions *********/
int main (void)
{
    int arr[] = {1,2,3,4,5};
    printf("summation is %i",summation( ( sizeof(arr)/sizeof(arr[0]) ) , arr ) );

    return 0;
}

/********** Functions Definations ***********/
int summation(int arr_length, int* numbers_array)
{
    int counter = 0;
    int ret_sum=0;
    for(counter =0;counter<arr_length;counter++)
    {
        ret_sum += numbers_array[counter];
    }

    return ret_sum;
}
