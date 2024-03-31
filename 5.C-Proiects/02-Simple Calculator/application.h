#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define E_OK 0
#define E_NOT_OK 1
#define Sec 1000

typedef unsigned int uint32;
typedef signed int sint32;
typedef char Std_ReturnType;

Std_ReturnType add(double *Num1, double *Num2, double *Result);
Std_ReturnType sub(double *Num1, double *Num2, double *Result);
Std_ReturnType multiply(double *Num1, double *Num2, double *Result);
Std_ReturnType division(double *Num1, double *Num2, double *Result);
Std_ReturnType logarithm(double *Num, double *Result);
Std_ReturnType sq_root(double *Num, double *Result);

#endif