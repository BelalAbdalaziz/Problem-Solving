
/*	terminal.h	*/
#ifndef TERMINAL_FILE
#define TERMINAL_FILE

#include <stdio.h>
#include<time.h>
#include "../Card/card.h"

typedef unsigned char uint8_t ;
typedef struct ST_terminalData_t
{
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
	 WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;


EN_terminalError_t getTransactionDate(ST_terminalData_t * termData);
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData);

//void getTransactionDate(int* transDate);
//int compareDates(int* date1, int* date2);
//int isCardExpired(int* transDate, int* expDate);
//void getTransactionAmount(int* transAmo);
//int isBelowMaxAmount(int* transAmo);
//void setMaxAmount(int *transAmo);
//void teminalProcess(void);


#endif // End Of TERMINAL_FILE
