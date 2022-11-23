#ifndef Card_H
#define Card_H
#define MAXCH 24 //Max Card Holder
#define MinCH 20 //Max Card Holder
#define ExpiryLimit 5 // Expiry date limit
#define MAXPAN 19 // Expiry date limit
#define MINPAN 16 // Expiry date limit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef unsigned char uint8_t;
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
}ST_cardData_t;
typedef enum EN_cardError_t
{
    CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN //0,1,2,3
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);

#endif // !Card_H
