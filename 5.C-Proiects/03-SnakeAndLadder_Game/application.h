#ifndef _APPLICATION_H_
#define _APPLICATION_H_
/*************** Includes ***************/
#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
// #include <time.h>
#include <windows.h>
/********** Macro Declarations **********/
#define E_OK 0
#define E_NOT_OK 1
#define SEC 1000
#define SmileFace "\u263A"
/******** Data Types Declarations *******/
typedef unsigned int uint32;
typedef signed int sint32;
typedef char Std_ReturnType;

/******* Functions Declarations *********/
Std_ReturnType display_snake_ladder(uint32 *Player1_Pos, uint32 *Player2_Pos);
Std_ReturnType dice_select_value(uint32 *DiceValue);

#endif