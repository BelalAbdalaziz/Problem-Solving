#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define ROCK 'r'
#define PAPER 'p'
#define SCISSORS 's'
#define Error 1
#define Sec 1000

typedef unsigned int uint32;

/*Welcome screen */
void welcome_screen(void);
/*Computer Side */
void computer_choice(char *ComputerChoice);
/*User Side*/
void user_choice(char *RetChoice);
/*Game procedure*/
void game_procedure(char UserInput, char ComputerInput);

#endif