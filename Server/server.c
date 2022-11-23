#include"server.h"

struct ST_accountsDB_t accountsDB[255] = { {2000.0, RUNNING, "8989374615436851"} ,{100000.0, BLOCKED, "5807007076043875"} ,{30000.0,RUNNING,"6547893214569856324"},{20000.0,BLOCKED,"8989374615437891"},{3200.0,RUNNING,"5807097076043875"} };
struct ST_transaction_t transaction[255] = { 0 };
int index;
int transactionnum = 0;
EN_transStat_t recieveTransactionData(ST_transaction_t* transData)
{
	EN_serverError_t Avaliable_R;
	EN_serverError_t Blocked_R;
	EN_serverError_t Amount_R;
	EN_serverError_t Saved_R;
	ST_accountsDB_t ACCData;
	//ACCData = accountsDB;
	if (Avaliable_R=isValidAccount(&transData->cardHolderData,&ACCData)== ACCOUNT_NOT_FOUND)
	{
		transData->transState = FRAUD_CARD;
		return FRAUD_CARD;
	}
	if (Avaliable_R= isAmountAvailable(&transData->terminalData,&ACCData)== LOW_BALANCE)
	{
		transData->transState = DECLINED_INSUFFECIENT_FUND;
		return DECLINED_INSUFFECIENT_FUND;
	}
	if (Blocked_R = isBlockedAccount( &accountsDB)== BLOCKED_ACCOUNT)
	{
		transData->transState = DECLINED_STOLEN_CARD;
		return DECLINED_STOLEN_CARD;
	}
	//if (Saved_R = saveTransaction(&transData)== SAVING_FAILED)
	//{
	//	transData->transState = INTERNAL_SERVER_ERROR;
	//	return INTERNAL_SERVER_ERROR;
	//}
	printf("Balance before transaction: %f\n", accountsDB[index].balance);
	accountsDB[index].balance = (accountsDB[index].balance - transData->terminalData.transAmount);
	printf("Balance after transaction: %f\n", accountsDB[index].balance);
	transData->transState = APPROVED;
	return APPROVED;
   
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
{

	//strcpy(accountRefrence->primaryAccountNumber , cardData->primaryAccountNumber);
	accountRefrence = accountsDB;
		
	for (int i = 0; i < 255; i++)
	{
		if (strcmp(cardData->primaryAccountNumber, accountRefrence[i].primaryAccountNumber) == 0)
		{
			//printf("The index is %d\n", i);
			index = i;
			return SERVER_OK;
		}
	}
	//accountRefrence = NULL;
	return ACCOUNT_NOT_FOUND;
	
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	
//	printf("Please enter the index of the account: ");
//#pragma warning(suppress : 4996)
//	scanf("%d",&index );
	accountRefrence = accountsDB;
	if (accountRefrence[index].state==RUNNING)
	{
		return SERVER_OK;
	}
	return BLOCKED_ACCOUNT;
	
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	accountRefrence = accountsDB;
	if (termData->transAmount<accountRefrence[index].balance)
	{
		return SERVER_OK;
	}
	return LOW_BALANCE;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	transData->transactionSequenceNumber = transactionnum;
	if (transData->transactionSequenceNumber<255)
	{
		transaction[transData->transactionSequenceNumber].cardHolderData = transData->cardHolderData;
		transaction[transData->transactionSequenceNumber].terminalData = transData->terminalData;
		transaction[transData->transactionSequenceNumber].transState = transData->transState;
		transaction[transData->transactionSequenceNumber].transactionSequenceNumber = transactionnum;
		transactionnum++;
		return SERVER_OK;
	}
	return SAVING_FAILED;
}
void listSavedTransactions(void)
{
	printf("#########################\n");
	for (int i = 0; i < transactionnum; i++)
	{
		printf("Transaction Sequence Number: %d\n", transaction[i].transactionSequenceNumber);
		printf("Transaction Date: %s\n", transaction[i].terminalData.transactionDate);
		printf("Transaction Amount: %f\n", transaction[i].terminalData.transAmount);
		printf("Transaction State: %d\n", transaction[i].transState);
		printf("Terminal Max Amount: %f\n", transaction[i].terminalData.maxTransAmount);
		printf("Transaction Cardholder Name: %s\n", transaction[i].cardHolderData.cardHolderName);
		printf("PAN: %s\n", transaction[i].cardHolderData.primaryAccountNumber);
		printf("Card Expiration Date: %s\n", transaction[i].cardHolderData.cardExpirationDate);
		printf("#########################\n");

	}





}