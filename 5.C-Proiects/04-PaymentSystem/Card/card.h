
/*	card.h	*/
#ifndef CARD_FILE
#define CARD_FILE
//###################	OLD	######################
//#include <stdio.h>
// char							holderName[50];
// int 							expiryDate[3];
// long long int					cardPAN;
//
//void getCardHolderName(char* name);
//void getCardExpiryDate(int* date);
//void getCardPAN(long long int * pan);
//void cardProcess(char* name, int* date, long long int * pan);

//###################	NEW		######################
#include <stdio.h>
#include <string.h>
#include <ctype.h> //For String  Format Check to use isalpha And isdigit
#include <stdlib.h>
typedef unsigned char uint8_t;
typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[11];
}ST_cardData_t;

typedef enum EN_cardError_t
{
	OK, WRONG_NAME =-1, WRONG_EXP_DATE=-1, WRONG_PAN=-1
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);
EN_cardError_t formatTest(ST_cardData_t* cardData);
void cardProcess(ST_cardData_t* cardData);



#endif // End Of CARD_FILE

