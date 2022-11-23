#include "terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	char Transaction[11];
	printf("Please enter the Transaction date: ");
	scanf_s("%s", termData->transactionDate, MAXTrans + 1);
	strcpy_s(Transaction, sizeof(Transaction), termData->transactionDate, sizeof(termData->transactionDate) - 1);//to avoid problems in the'/'
	if ((strlen(termData->transactionDate) != MAXTrans || (termData->transactionDate) == NULL))
	{
		//printf("The transaction date is Wrong\n");
		return WRONG_DATE;
	}
	if (Transaction[2] != '/' || Transaction[5] != '/')
	{
		//printf("The transaction date is Wrong\n");
		return WRONG_DATE;
	}
	if ((!isdigit(Transaction[0])) || (!isdigit(Transaction[1])) || (!isdigit(Transaction[3])) || (!isdigit(Transaction[4])) || (!isdigit(Transaction[6])) || (!isdigit(Transaction[7])) || (!isdigit(Transaction[8])) || (!isdigit(Transaction[9])))
	{
		//printf("The transaction date is Wrong\n");
		return WRONG_DATE;
	}
	if ((Transaction[1] == '0' && Transaction[0] == '0') || (Transaction[3] == '0' && Transaction[4] == '0') || Transaction[6] == '0')
	{
		//printf("The transaction date is Wrong\n");
		return WRONG_DATE;
	}	
	if ((Transaction[6] == '9' && Transaction[7] == '9'  && Transaction[8] == '9' && Transaction[9] == '9'))
	{
		//printf("The transaction date is Wrong\n");
		return WRONG_DATE;
	}
	if (Transaction[3] > '1' || (Transaction[4] > '2' && Transaction[3] > '0')) // to prevent the mistake in monthes 
	{
		//printf("The transaction date is Wrong\n");
		return WRONG_DATE;
	}
	if (Transaction[0] == '3' && Transaction[1] > '1'||Transaction[0]>'3') // to prevent the mistake in days 
	{
		//printf("The transaction date is Wrong\n");
		return WRONG_DATE;
	}
	else
	{
		//printf("The transaction date:%s\n", termData->transactionDate);
		return TERMINAL_OK;
	}

}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	char expire[6];
	char Transaction[11];
	strcpy_s(expire, sizeof(expire), cardData->cardExpirationDate, sizeof(cardData->cardExpirationDate) - 1);
	strcpy_s(Transaction, sizeof(Transaction), termData->transactionDate, sizeof(termData->transactionDate) - 1);
	//puts(*(expire+3));
	//puts(*(Transaction+8));
	if ((expire[3]) < (Transaction[8])||((expire[3]) == Transaction[8])&&(expire[4]<Transaction[9]))//for years
	{
		//printf("the card is expired\n");
		return EXPIRED_CARD;
	}
	if ((expire[0]==Transaction[3]&& expire[1]<Transaction[4]) || expire[0]<Transaction[3])
	{
		//printf("the card is expired\n");
		return EXPIRED_CARD;
	}
	else
	{
		return TERMINAL_OK;
	}
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("Please enter the Transaction Amount: ");
#pragma warning(suppress : 4996)
	scanf("%f", &termData->transAmount);
	if (termData->transAmount<=0)
	{
		return INVALID_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount>termData->maxTransAmount||termData->transAmount<=0)
	{
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	if (maxAmount<=0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		termData->maxTransAmount = maxAmount;
		//printf("%f\n", termData->maxTransAmount);
		return TERMINAL_OK;
	}
	

}
