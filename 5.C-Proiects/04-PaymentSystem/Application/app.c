/*
 * Project Name: Payment System
 * File: app.c
 * Description:
 * Author: Belal Abdalaziz
 * Created August 2022
 */

#include "app.h"

void main()
{
	

	int x=1 ;
	while (x != 0)
	{
	
		//cardProcess(&cardData);
		getCardExpiryDate(&cardData);
		getTransactionAmount(&terminalData);
		//getTransactionDate(&terminalData);
		//isCardExpired(cardData, terminalData);
		//##########################		OLD		################
		/*cardProcess(&holderName, &expiryDate, &cardPAN);
		teminalProcess(transactionDate, expiryDate, &transactionAmount);
		serverProcess(&cardPAN, &transactionAmount);*/
		printf("if you want to close preess '0' continue press '1' \n ");
		scanf("%d", &x);
	} 
	printf("Thanks For Using This Application (: <3 \n");
}