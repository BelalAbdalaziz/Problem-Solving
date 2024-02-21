/*
    Write a program that computes the nth term of the arithmetic 
series:
1, 3, 5, 7, 9, …
Run the program to compute the 100th term of the given series.
*/

/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
int sum_odd_series(int nth_term);

/********** Start of main functions *********/
int main (void)
{
    int n_terms = 3;
    printf("Result of (%ith) terms is : %i",n_terms,sum_odd_series(n_terms));
    return 0;
}

/********** Functions Definations ***********/
int sum_odd_series(int nth_term)
{
    int counter=0;
    int ret_sum = 0;
    for(counter = 1 ; counter <= (2*nth_term) ; counter++)
    {
        if(counter %2 !=0)
        {
            /*Odd Number*/
            ret_sum += counter;
        }
        else{/*even Nothing*/}
    }
    return ret_sum;
}