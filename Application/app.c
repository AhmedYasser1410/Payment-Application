#include "app.h"

void appStart(void)
{
	ST_transaction_t transdata;
	EN_terminalError_t expire;
	EN_terminalError_t Excced;
	ST_accountsDB_t ACCData;
	int x,y,z,u,v,w,a,b,c;
	float max = 8000;
	x = getCardHolderName(&transdata.cardHolderData);
	printf("Hello, %s\n", transdata.cardHolderData.cardHolderName);
	getchar();
	z=getCardExpiryDate	(&transdata.cardHolderData);
	printf("Card expiry date is: %s\n", transdata.cardHolderData.cardExpirationDate);
	getchar();
	y = getCardPAN(&transdata.cardHolderData);
	printf("PAN is: %s\n", transdata.cardHolderData.primaryAccountNumber);
	getchar();
	u = getTransactionDate(&transdata.terminalData);
	if (expire=isCardExpired(&transdata.cardHolderData,&transdata.terminalData)== EXPIRED_CARD)
	{
		printf("Declined Expired Card");
		return 0;
	}
	v = setMaxAmount(&transdata.terminalData, max);
	a = getTransactionAmount(&transdata.terminalData);
	if (Excced = isBelowMaxAmount(&transdata.terminalData) == EXCEED_MAX_AMOUNT) {
		printf("Declined Amount Exceed");
		return 0;
	};
	b = recieveTransactionData(&transdata);
	switch (b)
	{
	case 0:
		saveTransaction(&transdata);
		printf("Transaction was successful, looking forward to seeing you ");
		break;
	case 1:
		saveTransaction(&transdata);
		printf("Transaction was Declined, Insufficient fund ");
		break;
	case 2:
		saveTransaction(&transdata);
		printf("Transaction was declined, Stolen Card ");
		break;
	case 3:
		saveTransaction(&transdata);
		printf("Transaction was successful, Fraud Card ");
		break;
	default:
		break;
	}
}
int main() {
	appStart();
}