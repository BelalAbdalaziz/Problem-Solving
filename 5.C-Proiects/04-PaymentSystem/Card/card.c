/*
 * Project Name: Payment System
 * File: card.c
 * Author: Belal Abdalaziz
 * Created August 2022
 */
#include "card.h"
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{	
	printf("Please enter your holder name without spaces and (20:24 Charecters): \n");
	scanf("%s",cardData->cardHolderName);
	int length = strlen(cardData->cardHolderName);

	if (length <20 || length >24 || length==NULL )
	{
		//printf("#########################################################################\n");
		printf("Wrong Name,Try Again!! \n");
		//printf("#########################################################################\n");

		return WRONG_NAME;
	}
	else
	{
		//printf("#########################################################################\n");
		printf("your Name is %s \n", cardData->cardHolderName);
		//printf("#########################################################################\n");

		return OK;
	}
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("Please enter your primary account number (16:19 numbers): \n");
	scanf("%s", cardData->primaryAccountNumber);
	int length = strlen(cardData->primaryAccountNumber);

	if (length < 16 || length >19 || length == NULL)
	{
		//printf("#########################################################################\n");
		printf("Wrong Primary Account Number ,Try Again!!  \n");
		//printf("#########################################################################\n");

		return WRONG_PAN;
	}
	else
	{
		printf("#########################################################################\n");
		printf("	your Primary Account Number is %s \n", cardData->primaryAccountNumber);
		printf("#########################################################################\n");

		return OK;
	}
}

/*
EN_cardError_t formatTest(ST_cardData_t* cardData)
{
	if (isdigit(cardData->cardExpirationDate[0])) return WRONG_EXP_DATE;
	if (isdigit(cardData->cardExpirationDate[1])) return WRONG_EXP_DATE;
	if (cardData->cardExpirationDate[2]=='/'    ) return WRONG_EXP_DATE;
	if (isdigit(cardData->cardExpirationDate[3])) return WRONG_EXP_DATE;
	if (isdigit(cardData->cardExpirationDate[4])) return WRONG_EXP_DATE;
}
*/

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	//int	d,m,year,date[3];
	printf("Enter expire date (dd/mm/yyyy): \n");
	scanf("%s", cardData->cardExpirationDate);
	int length = strlen(cardData->cardExpirationDate);
	if (length <10 || length >10 || length == NULL )//|| formatTest(cardData->cardExpirationDate)==WRONG_EXP_DATE)
	{
		printf("#########################################################################\n");
		printf("			Wrong Expiration Date \n");
		printf("#########################################################################\n");
		return  WRONG_EXP_DATE;
	}
	else
	{
		printf("#########################################################################\n");
		printf("	your Card Expiration Date is %s \n", cardData->cardExpirationDate);
		printf("#########################################################################\n");

		return OK;
	}
	
}

void cardProcess(ST_cardData_t* cardData)
//void main(void)
{
	
	getCardHolderName(&cardData->cardHolderName);
	getCardPAN(&cardData->primaryAccountNumber);
	getCardExpiryDate(&cardData->cardExpirationDate);
}