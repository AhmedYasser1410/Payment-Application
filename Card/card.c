#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	//int MAXCH = 24;
	//int MinCH = 20;
	printf("Please enter the card holder name: ");
	scanf_s("%[^\n]s", cardData->cardHolderName, MAXCH + 1);
	if ((strlen(cardData->cardHolderName)) < MinCH || (cardData->cardHolderName) == NULL || (strlen(cardData->cardHolderName)) > MAXCH)
	{
		//printf("Expected Result(CARD HOLDER NAME): Wrong Name\n");
		return WRONG_NAME;
	}
	

	for (int i = 0; i < strlen(cardData->cardHolderName); i++) // all alphapti check
	{
		if (!isalpha(cardData->cardHolderName[i])&& cardData->cardHolderName[i]!=' ')
		{
			//printf("Expected Result(CARD HOLDER NAME): Wrong Name\n");
			return WRONG_NAME;
		}
	}
	//printf("Actual Result(CARD HOLDER NAME): %s\n", cardData->cardHolderName);
	return CARD_OK;
	
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	char expire[6];
	printf("Please enter the card holder Expiry date: ");
	scanf_s("%s", cardData->cardExpirationDate, ExpiryLimit + 1);
	strcpy_s(expire,sizeof(expire), cardData->cardExpirationDate,sizeof(cardData->cardExpirationDate)-1);//to avoid problems in the'/'
	//puts(expire);
	if ((strlen(cardData->cardExpirationDate)) != ExpiryLimit || (cardData->cardExpirationDate) == NULL)
	{

		//printf("Actual Result (EXPIRY DATE): %s\n", cardData->cardExpirationDate);
		return WRONG_EXP_DATE;
	}
	
	if (expire[2] != '/')
	{
		//printf("Actual Result (EXPIRY DATE): %s\n", cardData->cardExpirationDate);
		return WRONG_EXP_DATE;
	}
	if (!isdigit(expire[0]) || !isdigit(expire[1]) || !isdigit(expire[3]) || !isdigit(expire[4])) //tocheck tha the written is integers
	{
		//printf("Actual Result (EXPIRY DATE): %s\n", cardData->cardExpirationDate);
		return WRONG_EXP_DATE;
	}	
	if ((expire[1] == '0' && expire[0] == '0')|| (expire[3] == '0' && expire[4] == '0')) // to prevent all zeros
	{
		//printf("Actual Result (EXPIRY DATE): %s\n", cardData->cardExpirationDate);
		return WRONG_EXP_DATE;
	}	
	if (expire[0]>'1' || (expire[1]>'2'&&expire[0]>'0')) // to prevent the mistake in monthes 
	{
		//printf("Actual Result (EXPIRY DATE): %s\n", cardData->cardExpirationDate);
		return WRONG_EXP_DATE;
	}	
	if (expire[3]>'9' && (expire[4]>'9')|| expire[3]<'2') // to prevent the mistake in years 
	{
		//printf("Actual Result (EXPIRY DATE): %s\n", cardData->cardExpirationDate);
		return WRONG_EXP_DATE;
	}

	else
	{
		//printf("Actual Result (EXPIRY DATE): %s\n", cardData->cardExpirationDate);
		return CARD_OK;
	}


}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("Please enter the card Pan Number: ");
	scanf_s("%[^\n]s", cardData->primaryAccountNumber, MAXPAN + 1);
	if ((strlen(cardData->primaryAccountNumber)) < MINPAN || (cardData->primaryAccountNumber) == NULL || (strlen(cardData->primaryAccountNumber)) > MAXPAN)
	{
		//printf("Actual Result(PAN NUMBER): %s\n", cardData->primaryAccountNumber);
		return WRONG_PAN;
	}
	for (int i = 0; i < strlen(cardData->primaryAccountNumber); i++) // all numbers check
	{ 
		if (!isdigit(cardData->primaryAccountNumber[i]))
		{
			//printf("Actual Result (PAN DATE): %s\n", cardData->primaryAccountNumber);
			return WRONG_PAN;
		}
	}
	//printf("Actual Result(PAN NUMBER): %s\n", cardData->primaryAccountNumber);
	return CARD_OK;
	

}


