/*
 * Project Name: Payment System
 * File: terminal.c
 * Author: Belal Abdalaziz
 * Created August 2022
 */

//#include "card.h"
#include "terminal.h"


//void getTransactionDate(int *transDate)
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //printf("\nCurrent day's date : %d-%02d-%02d \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    sprintf(termData->transactionDate, "%d/%02d/%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf("The transaction date is : %s \n", termData->transactionDate);
    
}

int compareDates(int* date1, int* date2)            //compareDates( expireDate, currentDate);
{
    if (date1[2] < date2[2])            // Compare Years
        return -1;

    else if (date1[2] > date2[2])       // Compare Years
        return 1;

    if (date1[2] == date2[2])           // Compare Years
    {
        if (date1[1] < date2[1])        // Compare Months
            return -1;
        else if (date1[1] > date2[1])   // Compare Months
            return 1;
        else if (date1[0] < date2[0])   // Compare Days
            return -1;
        else if (date1[0] > date2[0])   // Compare Days
            return 1;
        else
            return 0;
    }
}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t terminalData)
{
    char* currentDay;
    char* currentMonth;
    char* currentYear;
    strcpy(&currentDay, &terminalData.transactionDate[0]);
    strcpy(&currentMonth, &terminalData.transactionDate[3]);
    strcpy(&currentYear, &terminalData.transactionDate[6]);
    int currentDate[3] = { (atoi(&currentDay)) ,(atoi(&currentMonth)),(atoi(&currentYear)) };
    printf("Current Date : %d / %d / %d \n", currentDate[0], currentDate[1], currentDate[2]);

    char* expDay ;
    char* expMonth ;
    char* expYear ;
    strcpy(&expDay, &cardData.cardExpirationDate[0]);
    strcpy(&expMonth, &cardData.cardExpirationDate[3]);
    strcpy(&expYear, &cardData.cardExpirationDate[6]);
    int expireDate[3] = { (atoi(&expDay)) ,(atoi(&expMonth)),(atoi(&expYear)) };
    printf("expiry Date : %d / %d / %d \n", expireDate[0], expireDate[1], expireDate[2]);
    int i = compareDates(expireDate, currentDate);
    if (i == -1 || i == 0)
    {
        printf("Card Is Expired		\n");
        return EXPIRED_CARD;
    }
    else
    {
        printf("Card Not  Expired	\n");
        return OK;
    }
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
    printf("Please Enter Your Traansaction Amount less than 8000 lE : \n ");
    scanf("%f", &termData->transAmount);
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
    // The largest amount that can be taken is 8000 LE
      if ( termData->transAmount <= 8000)
    {
        printf(" Lower than Max Amount of terminal. operation succesed \n ");
        return 1;

    }
    else
    {
        printf("Greater than max amount of terminal 8000 LE . Operation failed!! \n");
        return -1;
    }
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
    static int     maxAmount = 24000;  //max money can taken in one day from terminal
    //8000 LE For one operation and in one day 24000LE
         maxAmount=maxAmount- termData->transAmount;
        printf("Current max amount for terminal to use in other usage : %d  \n", maxAmount);
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{
    

}




void teminalProcess(int* transDate,int* expDate , int* transAmo)
////void main()
{
   /* getTransactionDate(transDate);
    if (isCardExpired(transDate, expDate) > 0)
    {
        getTransactionAmount(transAmo);
        if (isBelowMaxAmount(transAmo) == 1)
        {
            setMaxAmount(transAmo);
        }
    }*/
}
