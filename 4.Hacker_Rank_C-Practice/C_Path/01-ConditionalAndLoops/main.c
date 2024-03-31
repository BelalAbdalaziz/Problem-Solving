#include <stdio.h>
#include <stdlib.h>

typedef signed int sint32_t;
typedef unsigned int uint32_t;

void T1_ConditionalStatment(void);
void T2_ForLoop(void);
void T3_SumOfDigits(void);
void T4_CalculateTheMaximum(int n, int k);
void T5_PrintPattern(uint32_t n);

int main()
{

    //  T1_ConditionalStatment();
    // T2_ForLoop();
    // 3_SumOfDigits();
    // T4_CalculateTheMaximum(5, 4);
    // T5_PrintPattern(5);

    return 0;
}
/*
<<<<<<<<<< Task 1 => Conditional Statements in C >>>>>>>>>>
Given a positive integer denoting , do the following:
If 1 < N < 9, print the lowercase English word corresponding to the number (e.g., one for , two for , etc.).
If N > 9, print Greater than 9.

Sample input :    5                    |    sample output :      five
                  10                   |                         Greater than 9

*/

void T1_ConditionalStatment(void)
{
    uint32_t Num = 0;

    scanf("%i", &Num);

    if (Num > 9)
    {
        printf("Greater than 9\n");
    }
    else
    {
        switch (Num)
        {
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        case 3:
            printf("three\n");
            break;
        case 4:
            printf("four\n");
            break;
        case 5:
            printf("five\n");
            break;
        case 6:
            printf("six\n");
            break;
        case 7:
            printf("seven\n");
            break;
        case 8:
            printf("eight\n");
            break;
        case 9:
            printf("nine\n");
            break;
        default:
            break;
        }
    }
}

/*
<<<<<<<<<< Task 2 => For Loop in C >>>>>>>>>>
For each integer  in the interval[a,b]  (given as input) :
If ( 1 < N < 9 ), then print the English representation of it in lowercase. That is "one" for , "two" for , and so on.
Else if ( N > 9 ) and it is an even number, then print "even".
Else if ( N > 9 ) and it is an odd number, then print "odd".

Sample input :    8                    |    sample output : eight
                  13                   |                    nine
                                       |                    even
                                       |                    odd
                                       |                    even
                                       |                    odd
*/

void Print_Number(int a)
{
    switch (a)
    {
    case 1:
        printf("one\n");
        break;
    case 2:
        printf("two\n");
        break;
    case 3:
        printf("three\n");
        break;
    case 4:
        printf("four\n");
        break;
    case 5:
        printf("five\n");
        break;
    case 6:
        printf("six\n");
        break;
    case 7:
        printf("seven\n");
        break;
    case 8:
        printf("eight\n");
        break;
    case 9:
        printf("nine\n");
        break;
    default:
        break;
    }
}

void T2_ForLoop(void)
{
    int a, b;
    int Counter = 0;
    scanf("%d\n%d", &a, &b);
    for (Counter = a; Counter <= b; Counter++)
    {

        if (Counter <= 9)
        {
            Print_Number(Counter);
        }
        else
        { /*Counter > 9*/
            if ((Counter % 2) == 0)
            {
                printf("even\n");
            }
            else
            {
                printf("odd\n");
            }
        }
    }
}

/*
<<<<<<<<<< Task 3 => Sum of Digits of a Five Digit Number >>>>>>>>>>
Given a five digit integer, print the sum of its digits.

Sample input :    10564           |         sample output : 16

<<<<<<Explaination To My Algorithm    >>>>>>
input :12345
Ones = (Num % 10) / 1;                      --> Res=5
Tens = (Num % 100) / 10;                    --> Res=4
Hundreds = (Num % 1000) / 100;              --> Res=3
Thousands = (Num % 10000) / 1000;           --> Res=2
HundredThousands = (Num % 100000) / 10000;  --> Res=1
*/

void T3_SumOfDigits(void)
{
    int Num = 0;         /*Use to take number from user*/
    int Sum = 0;         /*To store summation of all digits*/
    int DigitsCheck = 0; /*Use it to check digit exist or not */
    int Digits = 0;      /*use it to store number of digits*/
    int Div = 1;         /*Use it into Equation to get each digit alone*/

    scanf("%i", &Num);
    DigitsCheck = Num;

    while (DigitsCheck != 0)
    {
        Sum += (Num % (Div * 10)) / Div;
        Div *= 10;
        /*Check digits */
        DigitsCheck /= 10; /*After each itteration we clear one digit from right => 123 /10=>12 /10=>1 /10 =>0*/
        Digits++;
    }
    printf("Number of digits: %i \n", Digits);
    printf("Sum= %i\n", Sum);
}

/*
<<<<<<<<< Task 4 => Bitwise Operator >>>>>>>>>>
Complete the calculate_the_maximum function in the editor below.
calculate_the_maximum has the following parameters:
int n: the highest number to consider
int k: the result of a comparison must be lower than this number to be considered

Sample input :    5 4               |         sample output : 2
                                    |                         3
                                    |                         3

<<<<<<Explaination To My Algorithm    >>>>>>
Inputs : n =5 , k=4

=>So S={1,2,3,4,5} all possible values of <a> and <b>
1-  a=1 , b=2 , a&b =0  , a|b=3 , a^b =3
2-  a=1 , b=3 , a&b =1  , a|b=3 , a^b =2
3-  a=1 , b=4 , a&b =0  , a|b=5 , a^b =5
4-  a=1 , b=5 , a&b =1  , a|b=5 , a^b =4

5-  a=2 , b=3 , a&b =2  , a|b=3 , a^b =1
6-  a=2 , b=4 , a&b =0  , a|b=6 , a^b =6
7-  a=2 , b=5 , a&b =0  , a|b=7 , a^b =7

8-  a=3 , b=4 , a&b =0  , a|b=7 , a^b =7
9-  a=3 , b=5 , a&b =1  , a|b=7 , a^b =6

10- a=4 , b=5 , a&b =4  , a|b=5 , a^b =1

The maximum possible value of ( a & b ) that is also < (K = 4) is , so we print 2 on first line.
The maximum possible value of ( a | b ) that is also  < (K = 4) is , so we print 3 on second line.
The maximum possible value of ( a ^ b ) that is also  < (K = 4) is , so we print 3 on third line.
*/
void T4_CalculateTheMaximum(int n, int k)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t Max_AandB = 0;
    uint32_t Max_AorB = 0;
    uint32_t Max_AxorB = 0;
    for (a = 1; a < n; a++)
    {
        for (b = a + 1; b <= n; b++)
        {
            // printf("a=%i , b=%i , a&b =%i  , a|b=%i , a^b =%i\n",
            //        a, b, (a & b), (a | b), (a ^ b));
            if (((a & b) > Max_AandB) && ((a & b) < k))
            {
                Max_AandB = (a & b);
            }
            else
            {
                /*Do Nothing*/
            }
            if (((a | b) > Max_AorB) && ((a | b) < k))
            {
                Max_AorB = (a | b);
            }
            else
            {
                /*Do Nothing*/
            }
            if (((a ^ b) > Max_AxorB) && ((a ^ b) < k))
            {
                Max_AxorB = (a ^ b);
            }
            else
            {
                /*Do Nothing*/
            }
        }
        // printf("\n");
    }
    printf("%i\n", Max_AandB);
    printf("%i\n", Max_AorB);
    printf("%i\n", Max_AxorB);
}
/*
<<<<<<<<< Task 5  => Printing Pattern Using Loops >>>>>>>>>>
Print a pattern of numbers from 1 to n  as shown below.
Each of the numbers is separated by a single space.

Sample input :    3                 |       sample output: 3 3 3 3 3
                                    |                      3 2 2 2 3
                                    |                      3 2 1 2 3
                                    |                      3 2 2 2 3
                                    |                      3 3 3 3 3
<<<<<<Explaination To My Algorithm    >>>>>>
# NoOfRows -> 1:(2N+1)
# NoOfCols -> 1:(2N+1)
# Print
  Element of any cell in this pattern is (minimum distance of < Right , Left , Up , Down >)
  LeftDistance = Columns
  RightDistance = (2N)-Columns
  UpDistance = Rows
  DownDistance = (2N)-Rows
  EX
  (R,C)
  (1,1) -> L =1 ,R =9 ,up=1 , down=9    MinVal==>1
  (1,2) -> L =2 ,R =8 ,up=1 , down=8

*/
static uint32_t MinVal(uint32_t Num1, uint32_t Num2)
{
    uint32_t RetMin = 0;
    if (Num1 <= Num2)
    {
        RetMin = Num1;
    }
    else
    {
        RetMin = Num2;
    }

    return RetMin;
}
void T5_PrintPattern(uint32_t N)
{
    uint32_t Rows = 0;
    uint32_t Columns = 0;
    uint32_t LeftDistance = 0;
    uint32_t RightDistance = 0;
    uint32_t UpDistance = 0;
    uint32_t DownDistance = 0;

    for (Rows = 1; Rows < (2 * N); Rows++)
    {
        for (Columns = 1; Columns < (2 * N); Columns++)
        {
            LeftDistance = Columns;
            UpDistance = Rows;
            RightDistance = (2 * N) - Columns;
            DownDistance = (2 * N) - Rows;
            /*From Lowes to Bigest*/
            printf("%i ", MinVal(MinVal(LeftDistance, RightDistance), MinVal(UpDistance, DownDistance)));
            /*From Bigest to lowest*/
            // printf("%i ", (N +1)- (MinVal(MinVal(LeftDistance, RightDistance), MinVal(UpDistance, DownDistance))));
        }
        printf("\n");
    }
}