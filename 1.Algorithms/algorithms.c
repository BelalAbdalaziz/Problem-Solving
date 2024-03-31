#include "algorithms.h"
static void swap(uint32_t *Num1, uint32_t *Num2);

sint32_t linear_search(uint32_t List[], uint32_t Length, uint32_t Search_Val)
{
    sint32_t Ret_Pos = NOT_EXIST;
    uint32_t Index_Counter = 0;

    for (Index_Counter = 0; Index_Counter < Length; Index_Counter++)
    {
        if (Search_Val == List[Index_Counter])
        {
            Ret_Pos = Index_Counter;
            break;
        }
    }
    return Ret_Pos;
}
/* Binary Search*/
// Search Val = 55
// 7,11,12,22,33,44,55,66
//

int binary_search(int List[], int Length, int Search_Val)
{
    int Ret_Pos = NOT_EXIST;
    int First_Index = 0;
    int Last_Index = Length - 1;

    /*Sort an array*/
    sort_array(List, Length);
    /*Binary search algorithm */
    /*(1) Looping to an array till first and last meet eachother */
    while (First_Index <= Last_Index)
    {
        int Mid_Of_List = (First_Index + Last_Index) / 2; // same : (First_Index + ((Last_Index - First_Index) / 2))

        if (Search_Val == List[Mid_Of_List])
        {
            // mid element is search value

            if (0 == Length % 2)
            {
                // Length is even value
                Ret_Pos = (Mid_Of_List + 1);
            }
            else
            {
                // Length is odd value
                Ret_Pos = Mid_Of_List;
            }
            break;
        }
        else if (Search_Val > List[Mid_Of_List])
        {
            // Remove left part of list
            First_Index = Mid_Of_List + 1;
        }
        else // if (Search_Val < List[Mid_Of_List])
        {
            // Remove right part of list
            Last_Index = Mid_Of_List - 1;
        }
    }
    return Ret_Pos;
}

void selection_sort(int List[], int Length)
{
    int Location_Counter = 0;
    int Comparison_Counter = 0;
    int Min_Location = 0;

    for (Location_Counter = 0; Location_Counter < Length - 1; Location_Counter++)
    {
        /*Set Min Location For Compare*/
        Min_Location = Location_Counter;
        /*Looping For Comparison*/
        for (Comparison_Counter = Location_Counter + 1; Comparison_Counter < Length; Comparison_Counter++)
        {
            if (List[Comparison_Counter] < List[Min_Location])
            {
                Min_Location = Comparison_Counter;
            }
        }
        /*Swap Min Value To Min Location*/
        swap(&List[Location_Counter], &List[Min_Location]);
    }
}
void bubble_sort(int List[], int Length)
{
    int Counter = 0;
    int Adjacent_Counter = 0;
    int Swap_Flag = 0;
    /*Bubble sort counter*/
    for (Counter = 0; Counter < Length; Counter++)
    {
        /*Compare And Swap Loop "Between 2 adjacent elements" */
        for (Adjacent_Counter = 0; Adjacent_Counter < Length - 1 - Counter; Adjacent_Counter++)
        {
            if (List[Adjacent_Counter] > List[Adjacent_Counter + 1])
            {
                swap(&List[Adjacent_Counter], &List[Adjacent_Counter + 1]);
                Swap_Flag = 1;
            }
        }
        if (0 == Swap_Flag)
        {
            /*No swap occur so Listi sorted*/
            break;
        }
    }
}
void insertion_sort(int List[], int Length)
{
    int List_Counter = 0;  /*sorted list counter*/
    int Shift_Counter = 0; /*un sorted list counter*/
    int Key = 0;

    /*Looping into List by List_Counter*/
    for (List_Counter = 1; List_Counter < Length; List_Counter++)
    {
        /*Value from un sorted list to compare with sorted list*/
        Key = List[List_Counter];
        /*Looping to doing Shift under conditions  "Ascending Sorting"*/
        for (Shift_Counter = List_Counter - 1; ((Shift_Counter >= 0) && (Key < List[Shift_Counter])); Shift_Counter--)
        {
            /*Shifting Right to a sorted list */
            List[Shift_Counter + 1] = List[Shift_Counter];
        }
        /*Insert Key in the valid position into sorted list  */
        List[Shift_Counter + 1] = Key;
    }
}

/***************** Helper Functions ******************/
/*Sorting Array Like Selection Sort */
// Array : 11, 22, 66, 33, 7, 12, 44, 55
// After 1st itteration -> 7 |,22,66,33,,11,12,44,55
// After 2nd itteration -> 7,11 |,66,33,,22,12,44,55
// After 3rd itteration -> 7,11,12 |,66,33,22,44,55
// After 4th itteration -> 7,11,12,22 |,66,33,44,55
// After 5th itteration -> 7,11,12,22,33 |,66,44,55
// After 6th itteration -> 7,11,12,22,33,44 |,66,55
// After 7th itteration -> 7,11,12,22,33,44,55 |,66
void sort_array(uint32_t Arr[], uint32_t Length)
{
    uint32_t Counter_1 = 0;
    uint32_t Counter_2 = 0;

    for (Counter_1 = 0; Counter_1 < Length - 1; Counter_1++)
    {
        for (Counter_2 = Counter_1 + 1; Counter_2 < Length; Counter_2++)
        {
            if (Arr[Counter_1] > Arr[Counter_2])
            {
                swap(&Arr[Counter_1], &Arr[Counter_2]);
            }
        }
    }
}

void print_array(uint32_t Arr[], uint32_t Length)
{
    uint32_t Counter = 0;

    for (Counter = 0; Counter < Length; Counter++)
    {
        printf("%i  ", Arr[Counter]);
    }
    printf("\n");
}

static void swap(uint32_t *Num1, uint32_t *Num2)
{
    uint32_t Temp;
    Temp = *Num1;
    *Num1 = *Num2;
    *Num2 = Temp;
}
