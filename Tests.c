#include "../Payment Application/Card/card.h"
#include "../Payment Application/Terminal/terminal.h"
#include "../Payment Application/Server/server.h"
#include "../Payment Application/Application/app.h"
void getCardHolderNameTest(void) {
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: getCardHolderName\nTest Case 1:\nInput Data:Ahmed Yasser Farouk Is\nExpected Result: 0\n");
	struct ST_cardData_t User1, User2, User3,User4,User5,User6,User7;
	int x, y, z,u,v,w,a;
	char c = "\n";
	x = getCardHolderName(&User1);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : Ahmed Yasser Farouk \nExpected Result : 1\n");// PLease Copy this to the card holder name input
	getchar();
	y = getCardHolderName(&User2);
	printf("Actual Result: %d\n", y);
	printf("Test Case 3:\nInput Data : 123345687989795566778 \nExpected Result : 1\n");
	getchar();
	z = getCardHolderName(&User3);
	printf("Actual Result: %d\n", z);	
	printf("Test Case 4:\nInput Data : Ahmed Yasser Farouk Ismail \nExpected Result : 1\n");
	getchar();
	u = getCardHolderName(&User4);
	printf("Actual Result: %d\n", u);		
	printf("Test Case 5:\nInput Data : Ahmed Yasser Farouk Isma\nExpected Result : 0\n");
	getchar();
	getchar();
	w = getCardHolderName(&User6);
	printf("Actual Result: %d\n",w);
	printf("Test Case 6:\nInput Data : Ahmed Yasser Farouk I\nExpected Result : 0\n");
	getchar();
	v = getCardHolderName(&User5);
	printf("Actual Result: %d\n", v);
	printf("Test Case 7:\nInput Data : Null \nExpected Result : 1\n");
	getchar();
	a = getCardHolderName(&User7);
	printf("Actual Result: %d\n", a);
};
void getCardExpiryDateTest(void) 
{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: getCardExpiryDate\nTest Case 1:\nInput Data:05/22\nExpected Result: 0\n");
	struct ST_cardData_t User1, User2, User3, User4, User5, User6, User7;
	int x, y, z, u, v, w, a;
	char c = "\n";
	x = getCardExpiryDate(&User1);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : 05/2022 \nExpected Result : 2\n");// PLease Copy this to the card holder name input
	getchar();
	y = getCardExpiryDate(&User2);
	printf("Actual Result: %d\n", y);
	printf("Test Case 3:\nInput Data : ABCDE \nExpected Result : 2\n");
	getchar();
	z = getCardExpiryDate(&User3);
	printf("Actual Result: %d\n", z);
	printf("Test Case 4:\nInput Data : 05?93 \nExpected Result : 2\n");
	getchar();
	u = getCardExpiryDate(&User4);
	printf("Actual Result: %d\n", u);
	printf("Test Case 5:\nInput Data : 05/3 \nExpected Result : 2\n");
	getchar();
	v = getCardExpiryDate(&User5);
	printf("Actual Result: %d\n", v);

};
void getCardPANTest(void)
{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: getCardPAN\nTest Case 1:\nInput Data:1234567894561236\nExpected Result: 0\n");
	struct ST_cardData_t User1, User2, User3, User4, User5, User6, User7;
	int x, y, z, u, v, w, a;
	char c = "\n";
	x = getCardPAN(&User1);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : 1236547896321456987 \nExpected Result : 0\n");// PLease Copy this to the card holder name input
	getchar();
	y = getCardPAN(&User2);
	printf("Actual Result: %d\n", y);
	printf("Test Case 3:\nInput Data : 236987450156987456 \nExpected Result : 0\n");
	getchar();
	z = getCardPAN(&User3);
	printf("Actual Result: %d\n", z);
	printf("Test Case 4:\nInput Data : 123654 \nExpected Result : 3\n");
	getchar();
	u = getCardPAN(&User4);
	printf("Actual Result: %d\n", u);
	printf("Test Case 5:\nInput Data : AhmedYaserFarouk14 \nExpected Result : 3\n");
	getchar();
	w = getCardPAN(&User6);
	printf("Actual Result: %d\n", w);
	printf("Test Case 6:\nInput Data : Null \nExpected Result : 3\n");
	getchar();
	a = getCardPAN(&User7);
	printf("Actual Result: %d\n", a);
	printf("Test Case 7:\nInput Data : 693525214864566898978452252 \nExpected Result : 3\n");
	getchar();
	v = getCardPAN(&User5);
	printf("Actual Result: %d\n", v);

};
void getTransactionDateTest(void) 
{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: getTransactionDate\nTest Case 1:\nInput Data:14/10/2022\nExpected Result: 0\n");
	struct ST_terminalData_t User1, User2, User3, User4, User5, User6, User7;
	int x, y, z, u, v, w, a;
	char c = "\n";
	x = getTransactionDate(&User1);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : 14/10/202 \nExpected Result : 1\n");// PLease Copy this to the card holder name input
	getchar();
	y = getTransactionDate(&User2);
	printf("Actual Result: %d\n", y);
	printf("Test Case 3:\nInput Data : 14/10/20255 \nExpected Result : 1\n");// PLease Copy this to the card holder name input
	getchar();
	z = getTransactionDate(&User3);
	printf("Actual Result: %d\n", z);
	printf("Test Case 4:\nInput Data : 14/10?2025 \nExpected Result : 1\n");// PLease Copy this to the card holder name input
	getchar();
	u = getTransactionDate(&User4);
	printf("Actual Result: %d\n", u);
	printf("Test Case 5:\nInput Data : 14?10/2025 \nExpected Result : 1\n");// PLease Copy this to the card holder name input
	getchar();
	v= getTransactionDate(&User5);
	printf("Actual Result: %d\n",v);
	printf("Test Case 6:\nInput Data : lgjuhgdksh \nExpected Result : 1\n");// PLease Copy this to the card holder name input
	getchar();
	w= getTransactionDate(&User6);
	printf("Actual Result: %d\n",w);
	printf("Test Case 7:\nInput Data : Null \nExpected Result : 1\n");// PLease Copy this to the card holder name input
	getchar();
	a= getTransactionDate(&User7);
	printf("Actual Result: %d\n",a);

};
void isCardExpriedTest(void)
{
	struct ST_cardData_t User1_c;
	struct ST_terminalData_t User1, User2, User3, User4, User5, User6, User7;
	int x, y, z, u, v, w, a;
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: isCardExpired\n");
	printf("Before testing this function, an expiry date of the card has to be set to: 05/22\n");// PLease Copy this to the card holder name input
	a = getCardExpiryDate(&User1_c);
	printf(" Test Case 1:\nInput Data : 14/05/2012 \nExpected Result : 0\n");
	getchar();
	u = getTransactionDate(&User1);
	x = isCardExpired(&User1_c, &User1);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : 14/04/2022 \nExpected Result : 0\n");
	getchar();
	v = getTransactionDate(&User2);
	y = isCardExpired(&User1_c, &User2);
	printf("Actual Result: %d\n", y);
	printf("Test Case 3:\nInput Data : 14/05/2023 \nExpected Result : 2\n");
	getchar();
	w= getTransactionDate(&User3);
	z = isCardExpired(&User1_c, &User3);
	printf("Actual Result: %d\n", z);
	printf("Test Case 4:\nInput Data : 14/10/2022 \nExpected Result : 2\n");
	getchar();
	w= getTransactionDate(&User4);
	z = isCardExpired(&User1_c, &User4);
	printf("Actual Result: %d\n", z);
	printf("Test Case 5:\nInput Data : 14/06/2022 \nExpected Result : 2\n");
	getchar();
	w= getTransactionDate(&User5);
	z = isCardExpired(&User1_c, &User5);
	printf("Actual Result: %d\n", z);

};
void getTransactionAmountTest(void)
{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: getTransactionAmount\nTest Case 1:\nInput Data:10000\nExpected Result: 0\n");
	struct ST_terminalData_t User1, User2, User3, User4, User5, User6, User7;
	int x, y, z, u, v, w, a;
	char c = "\n";
	x = getTransactionAmount(&User1);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : 0 \nExpected Result : 4\n");// PLease Copy this to the card holder name input
	getchar();
	y = getTransactionAmount(&User2);
	printf("Actual Result: %d\n", y);
	printf("Test Case 3:\nInput Data : -1000 \nExpected Result : 4\n");// PLease Copy this to the card holder name input
	getchar();
	z = getTransactionAmount(&User3);
	printf("Actual Result: %d\n", z);
};
void isBelowMaxAmountTest(void)
{
printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: isBelowMaxAmount\nTest Case 1:\nInput Data:trans amount is 5000 & max amount is 8000\nExpected Result: 0\n");
struct ST_terminalData_t User1, User2, User3;
int x;
User1.maxTransAmount = 8000;
User1.transAmount = 5000;
x = isBelowMaxAmount(&User1);
printf("Actual Result: %d\n", x);
printf("Test Case 2:\nInput Data : trans amount is 8000 & max amount is 8000 \nExpected Result : 0\n");
User2.maxTransAmount = 8000;
User2.transAmount = 8000;
x = isBelowMaxAmount(&User2);
printf("Actual Result: %d\n", x);
printf("Test Case 3:\nInput Data : trans amount is 10000 & max amount is 8000 \nExpected Result : 5\n");
User3.maxTransAmount = 8000;
User3.transAmount = 10000;
x = isBelowMaxAmount(&User3);
printf("Actual Result: %d\n", x);
	

};
void setMaxAmountTest(void)
{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: setMaxAmount\nTest Case 1:\nInput Data:1000\nExpected Result: 0\n");
	struct ST_terminalData_t User1, User2, User3, User4, User5, User6, User7;
	float max1 = 1000;
	float max2=0;
	float max3=-1000;
	int x, y, z, u, v, w, a;
	char c = "\n";
	x = setMaxAmount(&User1,max1);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : 0 \nExpected Result : 6\n");
	y = setMaxAmount(&User2,max2);
	printf("Actual Result: %d\n", y);
	printf("Test Case 3:\nInput Data : -1000 \nExpected Result : 6\n");// PLease Copy this to the card holder name input
	z = setMaxAmount(&User3,max3);
	printf("Actual Result: %d\n", z);

};
void recieveTransactionDataTest(void)
{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: recieveTransactionData\nTest Case 1:\nInput Data:Pan number = 6547893214569856324\nExpected Result: 0 &29000\n");
		int x, y,z;
		ST_transaction_t  transData,transData1,transData2,transData3;
		y = getCardPAN(&transData.cardHolderData);
		//transData.cardHolderData.primaryAccountNumber == "6547893214569856324";
		transData.terminalData.transAmount= 10000;
		//saveTransaction(&transData);
		x = recieveTransactionData(&transData);
		printf("Actual Result: %d\n", x);
		printf("Test Case 2:\nInput Data : Pan number = 1234893214569856324 \nExpected Result : 3\n");
		getchar();
		z= getCardPAN(&transData1.cardHolderData);
		y = recieveTransactionData(&transData1);
		printf("Actual Result: %d\n", y);		
		printf("Test Case 3:\nInput Data : Pan number = 8989374615436851 \nExpected Result : 1\n");
		getchar();
		z= getCardPAN(&transData2.cardHolderData);
		y = recieveTransactionData(&transData2);
		printf("Actual Result: %d\n", y);
		printf("Test Case 4:\nInput Data : Pan number = 8989374615437891 \nExpected Result : 2\n");
		getchar();
		z= getCardPAN(&transData3.cardHolderData);
		y = recieveTransactionData(&transData3);
		printf("Actual Result: %d\n", y);
};
void isValidAccountTest(void)

{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: isValidAccount\nTest Case 1:\nInput Data:8989374615437891\nExpected Result: 0\n");
	struct ST_cardData_t User1, User2;
	struct ST_accountsDB_t ACCData;
	int x, y,z;
	z = getCardPAN(&User1);
//	User1.primaryAccountNumber == 8989374615437891;
	x = isValidAccount(&User1, &ACCData);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : 55645464654644646 \nExpected Result : 3\n");
//	User2.primaryAccountNumber == "55645464654644646";
	getchar();
	z = getCardPAN(&User2);
	y = isValidAccount(&User2, &ACCData);
	printf("Actual Result: %d\n", y);
};
void isBlockedAccountTest(void)

{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: isBlockedAccount\nTest Case 1:\nInput Data: 8989374615436851\nExpected Result: 0\n");
	struct ST_cardData_t User1, User2;
	struct ST_accountsDB_t ACCData;
	int x, y,z,u;
	//User1.primaryAccountNumber == "8989374615437891";
	z = getCardPAN(&User1);
	u = isValidAccount(&User1, &ACCData);
	x = isBlockedAccount(&User1, &ACCData);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : 8989374615437891 \nExpected Result : 5\n");
	//User1.primaryAccountNumber == "55645464654644646";
	getchar();
	z = getCardPAN(&User2);
	u = isValidAccount(&User2, &ACCData);
	y = isBlockedAccount(&User2, &ACCData);
	printf("Actual Result: %d\n", y);
};
void isAmountAvailableTest(void)

{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: isAmountAvailable\nThe amount in the card is 2000\nTest Case 1:\nInput Data:5000\nExpected Result: 0\n");
	struct ST_terminalData_t User1, User2;
	struct ST_accountsDB_t ACCData;
	int x, y;
	User1.transAmount = 1000;
	x = isAmountAvailable(&User1, &ACCData);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : 600000 \nExpected Result : 4\n");
	User2.transAmount =600000;
	y = isAmountAvailable(&User2, &ACCData);
	printf("Actual Result: %d\n", y);
};
void saveTransactionTest(void) 
{	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: saveTransactionTest\nTest Case 1:\nInput Data:transaction num<255\nExpected Result: 0\n");
	int x, y;
	ST_transaction_t  transData;
	ST_transaction_t  transData1;
	ST_transaction_t  transData2;
	x = saveTransaction(&transData);
	printf("Actual Result: %d\n", x);
	printf("Test Case 2:\nInput Data : transaction num=255 \nExpected Result : 1\n");
	for (int i = 0; i < 255; i++)
	{
		y = saveTransaction(&transData1);
	}
	y = saveTransaction(&transData1);
	printf("Actual Result: %d\n", y);	
	printf("Test Case 3:\nInput Data : transaction num>255 \nExpected Result : 1\n");
	for (int i = 0; i < 265; i++)
	{
		y = saveTransaction(&transData2);
	}
	y = saveTransaction(&transData2);
	printf("Actual Result: %d\n", y);


};
void listSavedTransactionsTest(void) 
{
	printf("Tester Name: Ahmed Yaser Abdalla\nFunction Name: listSavedTransactions\nTest Case 1:\nInput Data:No \nExpected Result: \nTransaction Sequence Number:0 \nTransaction Date :14/04/2022\nTransaction Amount :1000\nTransaction State :0 \nTerminal Max Amount :8000\nCardholder Name :Ahmed Yasser Farouk is\n PAN: 8989374615436851\nCard Expiration Date : 05/22\n");
	int x, y,z,u,v,w,a,b;
	int max =8000 ;
	ST_transaction_t  transData;
	
	//for (int i = 0; i < 2; i++)
	//{
		x = getCardHolderName(&transData.cardHolderData);
		getchar();
		y = getCardPAN(&transData.cardHolderData);
		getchar();
		z = getCardExpiryDate(&transData.cardHolderData);
		getchar();
		w = getTransactionDate(&transData.terminalData);
		getchar();
		u = getTransactionAmount(&transData.terminalData);
		getchar();
		v = setMaxAmount(&transData.terminalData, max);
		//getchar();
		b = recieveTransactionData(&transData);
		//getchar();
		a = saveTransaction(&transData);
	//}
	printf("Actual Result: \n"); listSavedTransactions();	
	printf("\nTest Case 2:\nInput Data:No \nExpected Result: \nTransaction Sequence Number:1 \nTransaction Date :06/06/2006\nTransaction Amount :2000\nTransaction State :3 \nTerminal Max Amount :8000\nCardholder Name :Ahmed Yasser abdalla i\n PAN: 8989378664615436851\nCard Expiration Date : 05/22\n");
		x = getCardHolderName(&transData.cardHolderData);
		getchar();
		y = getCardPAN(&transData.cardHolderData);
		getchar();
		z = getCardExpiryDate(&transData.cardHolderData);
		getchar();
		w = getTransactionDate(&transData.terminalData);
		getchar();
		u = getTransactionAmount(&transData.terminalData);
		getchar();
		v = setMaxAmount(&transData.terminalData, max);
		//getchar();
		b = recieveTransactionData(&transData);
		//getchar();
		a = saveTransaction(&transData);
	//}
	printf("Actual Result: \n"); listSavedTransactions();

};


/*int main() {
	getCardHolderNameTest();
	getCardExpiryDateTest();
	getCardPANTest();
	getTransactionDateTest();
	isCardExpriedTest();
	getTransactionAmountTest();
	setMaxAmountTest();
	isBelowMaxAmountTest();
	isValidAccountTest();
	getchar();
	isAmountAvailableTest();
	getchar();
	isBlockedAccountTest();
	getchar();
	recieveTransactionDataTest();
	getchar();
	saveTransactionTest();
	getchar();
	listSavedTransactionsTest();
}*/