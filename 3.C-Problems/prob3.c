/*Write a C function that use the bubble sort algorithm to sort 
an integer array in ascending order (search for the bubble sorting 
algorithm).
*/

/************ Includes ***********************/
#include <stdio.h>
#include <stdbool.h>

/********** Functions Declarations ***********/
void buble_sort(int length,int* arr);
void print_array(int length , int* arr);

/********** Start of main functions *********/
int main(void)
{
    int arr[]={5,1,4,2,8};
    print_array((sizeof(arr) / sizeof(arr[0]) ) , arr);
    buble_sort((sizeof(arr) / sizeof(arr[0]) ) , arr);
    print_array((sizeof(arr) / sizeof(arr[0]) ) , arr);

    return 0 ;
}

/********** Functions Definations ***********/
static void swap(int* num1, int* num2)
{
    int temp= 0;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void print_array(int length , int* arr)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ",arr[i]);
    }
    printf("\n");
    
}

void buble_sort(int length,int* arr)
{
    int counter = 0;
    int adjCounter=0;
    bool isSortedflag = true;
    for(counter = 0; counter < length - 1; counter++)
    {
        /*The bigest value in the bottom(last element)*/
        for(adjCounter=0; adjCounter<length-counter-1;adjCounter++)
        {
            if(arr[adjCounter] > arr[adjCounter+1])
            {
                swap(&arr[adjCounter] , &arr[adjCounter+1]);
                isSortedflag = false;
            }
            else{/*Nothing*/}
        }
        if(true == isSortedflag)
        {
            /* the array is already sorted so we dont need to continue other itterations*/
            printf("array is already sorted\n");
            break;
        }
        else{/*Nothing*/}
    }
}