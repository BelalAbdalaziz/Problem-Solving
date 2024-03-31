/*
 * Project Name: Payment System
 * File: server.c
 * Author: Belal Abdalaziz
 * Created August 2022
 */



//#include "card.h"
//#include "terminal.h"
#include "server.h"

static int userValidNum = -1;
static int check;

void recieveTransactionData()
{
	//we don't need it cause we use global varibles
}
int isValidAccount( long long int * recPAN) //using linear search
{
	int i, found = 0;
	printf("rec Pan : %lld \n", *recPAN);
	for (i = 0; i < 12; i++)
		if (usersData[i].panD == *recPAN)
		{
			 userValidNum = i;
			 found = 1;  break;
		}

	if (found == 1)
	{
	 printf("%lld : valid Account \n", *recPAN);
	 return 1;
	}
	else 
	{
		printf("%lld : invalid Account \n ", *recPAN);
		return -1;
	}
}


int isAmountAvailable(int *transAmo)
{
	if (*transAmo <= usersData[userValidNum].AmountD)
	{
		printf("Below  Amount you have\" %d \" . operation sucessed \n ", usersData[userValidNum].AmountD);
		check = 1;
		return 1;
	}
	else
	{
		printf("Greater Amount you have\" %d \" . Operation failed!! \n", usersData[userValidNum].AmountD);
		return -1;
	}
}

void saveTransaction(int* transAmo)
{
	if (check == 1)
	{
		usersData[userValidNum].AmountD -= *transAmo;
		printf("After Operation Current amount you have : %d  \n", usersData[userValidNum].AmountD);
	}
	else
		printf(" Error !!");
}
void serverProcess( long long int * recPAN,int* transAmo)
{
	
	if (isValidAccount(recPAN) == 1)
	{
		if (isAmountAvailable(transAmo) == 1)
			saveTransaction(transAmo);
	}
}

