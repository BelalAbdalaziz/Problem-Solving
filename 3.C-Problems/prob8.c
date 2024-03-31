/*
Write a program that computes the nth term of the geometric 
series:
1, 3, 9, 27, …
Run the program to compute the 10th term of the given series.
*/

/************ Includes ***********************/
#include <stdio.h>

/********** Functions Declarations ***********/
int sum_geometric_series(int nth_term);

/********** Start of main functions *********/
int main (void)
{
    int n_terms = 10;
    printf("Result of (%ith) terms is : %i",n_terms,sum_geometric_series(n_terms));
    return 0;
}

/********** Functions Definations ***********/
int sum_geometric_series(int nth_term)
{
    int counter=0;
    int temp_series =1;
    int ret_sum = 0;
    for(counter = 1 ; counter <= nth_term ; counter++ )
    { 
        ret_sum +=  temp_series;  
        temp_series = temp_series*3;   
    }
    return ret_sum;
}