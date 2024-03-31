#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creat_array(void ** retArrPtr, int Arr_Length);
void resize_array(void ** retArrPtr, int Arr_Length);
void print_array(const int Arr[],unsigned int Len);
void fill_array(const int Arr[],unsigned int Len);

void T1_sum_array(const int Arr[],unsigned int Len);
void T2_print_reversal_array(const int Arr[],unsigned int Len);
void T3_print_tokens(void);
void T4_print_digit_frequency(void);

int main() 
{

    T4_print_digit_frequency();
 
    return 0;
}

/*Helper Functions*/
void creat_array(void ** retArrPtr, int Arr_Length)
{
    /*Take array size from the user*/
    //unsigned int Arr_Size = 0;
    
    /*Creating Dynamic Array*/
    //int * Arr_Ptr = (int*)malloc(Arr_Size * sizeof(int));
    *retArrPtr = (void*)malloc(Arr_Length * sizeof(int));  
}
void resize_array(void ** retArrPtr, int Arr_Length)
{
    /*Take array size from the user*/
    //unsigned int Arr_Size = 0;
    
    /*Creating Dynamic Array*/
    //int * Arr_Ptr = (int*)malloc(Arr_Size * sizeof(int));
    *retArrPtr = (void*)realloc(*retArrPtr, Arr_Length); 
}
void fill_array(const int Arr[],unsigned int Len)
{
    int Counter =0;
    /*Take input from user*/
    for(Counter =0 ;Counter < Len ;Counter ++ )
    {
        //scanf_s("%d",Arr+Counter);
        scanf_s("%d",&Arr[Counter]);
    }
}
void print_array(const int Arr[],unsigned int Len)
{
    int Counter =0;
    /*print reversal*/
    for(Counter =0 ;Counter < Len ;Counter ++ )
    {
        //scanf_s("%d",Arr+Counter);
        printf("%d ",Arr[Counter]);
    }
    printf("\n");
}
/*
<<<<<<<<<< Task 1 => 1D Arrays in C >>>>>>>>>>
create an array of size  dynamically, and read the values from stdin.
Iterate the array calculating the sum of all elements.
Print the sum and free the memory where the array is stored.
*/

void T1_sum_array(const int Arr[],unsigned int Len)
{
    int Counter =0;
    int sum = 0;
    for(Counter =0 ;Counter < Len ;Counter ++ )
    {
        /*Store Sum */
        //Sum += *(Arr+Counter);
        sum += (Arr[Counter]);
    }
    /*print sum*/
    printf("Sum = %d\n",sum);

}
/*
<<<<<<<<<< Task 2 => Array Reversal >>>>>>>>>>
create an array of size  dynamically, and read the values from stdin.
Given an array, n of size , reverse it.
Print the reverse and free the memory where the array is stored.
*/
void T2_print_reversal_array(const int Arr[],unsigned int Len)
{
    int Counter =0;
    /*print reversal*/
    for(Counter =Len-1 ;Counter >= 0 ;Counter -- )
    {
        //scanf_s("%d",Arr+Counter);
        printf("%d ",Arr[Counter]);
    }
    printf("\n");
}
/*
<<<<<<<<<< Task 3 => Printing Tokens >>>>>>>>>>
Given a sentence, str , print each word of the sentence in a new line.
*/
void T3_print_tokens(void)
{
    char *Str;
    int Str_Lenght=0;
    /*creat big array of characters*/
    creat_array(&Str,1024); //Str =(char *) malloc(1024 * sizeof(char));
    /*take input string from user*/
    scanf("%[^\n]", Str);
    /*input string length*/
    Str_Lenght = strlen(Str);
    /*edit length of array of charecrer based on input string length*/
    resize_array(&Str,Str_Lenght); //Str = realloc(Str, strlen(Str) + 1);
    /*Parsing to print Tokens*/
    for (int Counter = 0; Counter < strlen(Str);Counter++)
    {   
        if(' ' == ( Str[Counter]))
        {
            printf("\n");
        }
        else
        {
            printf("%c",Str[Counter]);
        }
    }
}
/*<<<<<<<<<< Task 4 => Printing Digit Frequency >>>>>>>>>>
Given a sentence, str , print each word of the sentence in a new line.

Sample Input 0
a11472o5t6

Sample Output 0
0 2 1 0 1 1 1 1 0 0 

Explanation 0
In the given string:
1 occurs two times.
2,4,5,6 and 7 occur one time each.
The remaining digits 0,3,8  and 9 don't occur at all.
*/
void T4_print_digit_frequency(void)
{
    char *Str;
    int Str_Lenght=0;
    int Counter = 0; /*To iteirate on input string */
    int Freq_Array[10]={0};/* To increment each digit based on digit freq*/
    int StrToNum = 0;
    /*creat big array of characters*/
    creat_array(&Str,1024); //Str =(char *) malloc(1024 * sizeof(char));
    /*take input string from user*/
    scanf("%[^\n]", Str);
    /*input string length*/
    Str_Lenght = strlen(Str);
    /*edit length of array of charecrer based on input string length*/
    resize_array(&Str,Str_Lenght); //Str = realloc(Str, strlen(Arr_Lenght) + 1);
    /*Parsing to print Digit Freq*/
    for ( Counter = 0; Counter < Str_Lenght ;Counter++)
    { 
            if((Str[Counter] >= '0' )&&(Str[Counter] <= '9' ))
            {
                /*Convert String to Number */
                StrToNum = Str[Counter] -'0';
                Freq_Array[StrToNum]++;
            }
            else{/*Nothing*/}  
    }
    print_array(&Freq_Array,10);

}
