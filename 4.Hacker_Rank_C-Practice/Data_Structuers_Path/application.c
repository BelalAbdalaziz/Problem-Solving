#include "std_types.h"

/*Reverse Array */
uint32_t *Revers_Array(uint32_t *Array, uint32_t Lenghth);
void Fill_Array(uint32_t *Array, uint32_t Lenghth);
void Print_Array(uint32_t *Array, uint32_t Lenghth);
uint32_t *Creat_Array(uint32_t Lenght);

uint32_t *Array_2;
int main()
{
    uint32_t *PtrArr = NULL;
    uint32_t Length = 0;
    uint32_t Counter = 0;

    printf("Enter Number of elements \n");
    scanf("%i", &Length);

    PtrArr = Creat_Array(Length);
    Fill_Array(PtrArr, Length);
    printf("Forward : \n");
    Print_Array(PtrArr, Length);
    Print_Array(Revers_Array(PtrArr, Length), Length);
}
uint32_t *Creat_Array(uint32_t Length)
{
    uint32_t *RetArr = NULL;
    RetArr = (uint32_t *)calloc(Length, sizeof(uint32_t));

    return RetArr;
}
void Fill_Array(uint32_t *Array, uint32_t Length)
{
    uint32_t Counter = 0;
    for (Counter = 0; Counter < Length; Counter++)
    {
        scanf("%i", &Array[Counter]);
        fflush(stdin);
    }
}
void Print_Array(uint32_t *Array, uint32_t Lenghth)
{
    uint32_t Counter = 0;
    for (Counter = 0; Counter < Lenghth; Counter++)
    {
        printf("<%i>\t", Array[Counter]);
    }
    printf("\n");
}
uint32_t *Revers_Array(uint32_t *Array, uint32_t Length)
{
    uint32_t *RetArray = (uint32_t *)calloc(Length, sizeof(uint32_t));
    uint32_t Counter = 0;
    for (Counter = 0; Counter < Length; Counter++)
    {
        RetArray[Counter] = Array[Length - 1 - Counter];
    }
    return RetArray;
}
