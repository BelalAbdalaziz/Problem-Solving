#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include "std_types.h"

#define NOT_EXIST -1

sint32_t linear_search(uint32_t Arr[], uint32_t Length, uint32_t SearchVal);
int binary_search(int List[], int Length, int Search_Val);

void selection_sort(int List[], int Length);
void bubble_sort(int List[], int Length);
void insertion_sort(int List[], int Length);

void sort_array(uint32_t Arr[], uint32_t Length);
void print_array(uint32_t Arr[], uint32_t Length);

#endif /*_ALGORITHMS_H_*/