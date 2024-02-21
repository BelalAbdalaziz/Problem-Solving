/*
Write a C function that use the selection sort algorithm to sort 
an integer array in ascending order (search for the selection 
sorting algorithm).
i/p=> {5,1,4,2,8};
O/p=> {1,2,4,5,8}
*/


/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
void selection_sort(int length,int* arr);
void print_array(int length , int* arr);

/********** Start of main functions *********/
int main(void)
{
    int arr[]={5,1,4,2,8};
    print_array((sizeof(arr) / sizeof(arr[0]) ) , arr);
    selection_sort((sizeof(arr) / sizeof(arr[0]) ) , arr);
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

void selection_sort(int length,int* arr)
{
    int firstCounter = 0;
    int minIndex = 0;
    int loopCounter=0;
    for(firstCounter = 0; firstCounter < length - 1; firstCounter++)
    {
        /*Assume Min Index Is firstCounter */
        minIndex = firstCounter;
        /*Loop To Compare all element to get Final MinIndex*/
        for(loopCounter=firstCounter+1; loopCounter<length; loopCounter++)
        {
            if( arr[loopCounter] < arr[minIndex] )
            {
                minIndex = loopCounter;
            }
            else{/*Nothing*/}
        }
        /*Swap Element[Final Min Index] with firstCounter<first element in this itteration>*/
        swap(&arr[firstCounter], &arr[minIndex]);
    }
}