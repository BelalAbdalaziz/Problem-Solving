#include <stdio.h>
#include <stdlib.h>

#define BIT_MASK 0b00000111 /*Read 3 BIts*/
#define READ_BIT(VALUE, POS) ((VALUE >> POS) & BIT_MASK)

typedef signed int sint32_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

void T1_HelloWorld(void);
void T2_PrintCharStrSen(void);
void T3_SumDifferenceTwo_Numbers(void);
int T4_MaxOfFour(int a, int b, int c, int d);
void T5_Update(int *a, int *b);

// T1,T2
char character;
char str[50];
char sentence[100];
// T3 , T4 ,T5
sint32_t Num1 = 0;
sint32_t Num2 = 0;
float Num3 = 0;
float Num4 = 0;

sint32_t Num5 = 0;
sint32_t Num6 = 0;
sint32_t Result = 0;

uint8_t Val = 0b01101000; /*0x68*/
uint8_t ReadVal = 0;
int main()
{
    // T1_Hello_World();
    // T2_Print_Char_Str_Sen();
    // T3_SumDifferenceTwoNumbers();
    /*  scanf("%i %i %i %i", &Num1, &Num2, &Num5, &Num6);
      Result = T4_MaxOfFour(Num1, Num2, Num5, Num6);
      printf("%i", Result);
    */
    // scanf("%i %i", &Num1, &Num2);
    // T5_Update(&Num1, &Num2);
    // printf("%i \n%i", Num1, Num2);
    ReadVal = READ_BIT(Val, 3);
    printf("0x%X\n", Val);     /* 0x68*/
    printf("0x%X\n", ReadVal); /* 0x05*/
    return 0;
}
/*
<<<<<<<<<< Task 1 => "Hello World!" in C  >>>>>>>>>>
print <Hello World > on a single line, and then print the already provided input string

Sample input :    Welcome to C programming.   |    sample output :      Hello, World!
                                              |                         Welcome to C programming.
                                              |
*/

void T1_HelloWorld(void)
{
    scanf(" %[^\n]s", sentence);
    printf("Hello, World!\n");
    printf("%s\n", sentence);
}

/*
<<<<<<<<<< Task 2 => Playing With Characters  >>>>>>>>>>
You have to print the <character> in the first line.
Then print <String>  in next line.
In the last line print the <sentence>,

Sample input :  C                             |  sample output :    C
                Language                      |                     Language
                Welcome c programming !!      |                     Welcome c programming !!
*/

void T2_PrintCharStrSen(void)
{
    scanf("%c", &character);
    scanf("%s", str);
    scanf(" %[^\n]s", sentence);

    printf("%c\n", character);
    printf("%s\n", str);
    printf("%s\n", sentence);
}

/*
<<<<<<<<<< Task 3 => Sum and Difference of Two Numbers  >>>>>>>>>>
Take two numbers of int data type,
two numbers of float data type as input and output their sum.

Sample input :  10  4                      |  sample output :    14 6
                4.0 2.0                    |                     6.0 2.0
*/

void T3_SumDifferenceTwoNumbers(void)
{
    // printf("Enter 2 integers numbers \n");
    scanf("%i", &Num1);
    scanf("%i", &Num2);
    fflush(stdin);
    // printf("Enter 2 float numbers \n");
    scanf("%f", &Num3);
    scanf("%f", &Num4);
    printf("Output\n");
    printf("%i %i\n", (Num1 + Num2), (Num1 - Num2));
    printf("%0.1f %0.1f\n", (Num3 + Num4), (Num3 - Num4));
}

/*
<<<<<<<<<<      Task 3 => Functions in C       >>>>>>>>>>
Write a function int max_of_four(int a, int b, int c, int d)
which reads four arguments and returns the greatest of them.

Sample input : 3 4 6 5                       |  sample output :  6

*/

int T4_MaxOfFour(int a, int b, int c, int d)
{
    int RetVal = 0;
    if ((a > b) && (a > c) && (a > d))
    {
        RetVal = a;
    }
    else if ((b > a) && (b > c) && (b > d))
    {
        RetVal = b;
    }
    else if ((c > a) && (c > b) && (c > d))
    {
        RetVal = c;
    }
    else
    {
        RetVal = d;
    }
    return RetVal;
}

/*
<<<<<<<<<<      Task 5 => Pointers in C        >>>>>>>>>>
Complete the function void update(int *a,int *b).
It receives two integer pointers, int* a and int* b.
Set the value of  to their sum, and  to their absolute difference.
There is no return value, and no return statement is needed.


Sample input :  4                       |  sample output :    9
                5                       |                     1
*/

void T5_Update(sint32_t *a, sint32_t *b)
{
    (*a) += (*b);
    (*b) = (*a) - (2 * (*b));
    *b = abs(*b);
}