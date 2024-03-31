
/*	server.h	*/
#ifndef SERVER_FILE
#define SERVER_FILE

#include <stdio.h>
#include <string.h>


#define DB_USERS 12
int userNumber;
int existedAmount;


/*Server Side Accounts Database & Transactions Database*/

struct transactionData
{
	char			accountNameD[50];
	int				AmountD;
	long long int	panD;

};
typedef struct transactionData S_dataBase;

volatile static S_dataBase usersData[DB_USERS] = {
								{"Belal Abadalaziz"		,100000	,	567845620122},
								{"Gamal Magdy"			,20000	,	425848963248},
								{"Gerges Hedia"			,12000	,	502525897123},
								{"George Atia"			,50000	,	506070868921},
								{"Hossam Mamdouh"		,10000	,	430252887923},
								{"Hassan Mohamed"		,2200	,	478963214569},
								{"Hossam Maged"			,2222	,	299010101025},
								{"Body Osam"			,1111	,	520741369874},
								{"Abdallah Abdalaziz"	,1200	,	225036978521},
								{"Hossam Adel"			,3500	,	123648962575},
								{"Mohamed Mahdy"		,4800	,	987123456952},
								{"Momen Kamel"			,8000	,	225047896352},

};

//void recieveTransactionData();
int isValidAccount(long long int* recPAN);
int isAmountAvailable(int* transAmo);
void saveTransaction(int* transAmo);
void serverProcess(long long int* recPAN, int* transAmo);

#endif // End Of SERVER_FILE
