/*
The sequence of numbers 1, 1, 2, 3, 5, 8, 13, … is called 
Fibonacci numbers; each is the sum of the preceding 2.
Write a program which given n, returns the nth Fibonacci number.
- with for/while
- with recursion
*/

/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
void print_fibonacci_series(int nth_term);

/********** Start of main functions *********/
int main (void)
{
    int n_terms = 7;
    print_fibonacci_series(n_terms);
    return 0;
}

/********** Functions Definations ***********/
void print_fibonacci_series(int nth_term)
{
    int counter=0;
    int prev_value =0;
    int present_value = 1;
    int next_value =0;
    if(0 == nth_term)
    {
        printf("%i",prev_value);
    }
    else if(1 == nth_term)
    {
        printf("%i",present_value);
    }
    else
    {
        printf("%i ,",present_value);    //1
        for(counter = 2 ; counter <= nth_term ; counter++ )
        {             
            next_value = prev_value + present_value;
            prev_value = present_value;
            present_value = next_value;
           //Printing Value
           if(nth_term != counter)
           {
             printf("%i ,",present_value);
           }
           else
           {
             printf("%i",present_value);
           }
        }            
        printf("\n");               
    }
        
}