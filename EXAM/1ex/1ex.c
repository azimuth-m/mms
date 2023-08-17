#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>

#define ITEMS_COUNT 3

struct BankAccount {
        uint16_t number;
        char owner[100];
        double balance;
        char valuta[4];
};


unsigned COUNT; /* inicializa se v 0 */

struct Node {
        struct BankAccount *data;
        struct Node *next;
};

struct Node *
insertAfter(struct Node **cll, int skipCount, struct BankAccount bankData)
{
        struct Node *temphead = *cll;
        struct Node *newNode = malloc(sizeof(struct Node));
        while (skipCount-1) {
                temphead = (temphead)->next;
                skipCount--;
        }
        newNode->next = (temphead)->next; 
        struct BankAccount *newData = malloc(sizeof(struct BankAccount));
        *newData = bankData;
        newNode->data = newData;
        (temphead)->next = newNode;
        COUNT++;
        return newNode;
}

void
initBuffer(struct Node **cll, struct BankAccount bankData)
{
        (*cll) = malloc(sizeof(struct Node));
        struct BankAccount *newData = malloc(sizeof(struct BankAccount));
        *newData = bankData;

        (*cll)->data = newData;
        COUNT++;
        (*cll)->next = *cll;
}

void
printBuff(struct Node *cll)
{
        unsigned tempcount = COUNT;
        while (tempcount) {
                printf("%" PRIu16, cll->data->number);
                printf("\n%s  ", cll->data->owner);
                printf("\n%s  ", cll->data->valuta);
                printf("\n%lf  \n", cll->data->balance);
                cll = cll->next;
                tempcount--;
        }
        printf("\n");
}

void
freeBuff(struct Node *cll)
{
        struct Node *temp;
        while (COUNT) {
                temp = cll;
                cll = cll->next;
                free(temp->data);
                free(temp);
                COUNT--;
        }
}

int
main()
{
        srand(time(0));
        const char allowedSymbols[] = " abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ";

        struct Node *myBuf;
        
        struct BankAccount initData;
        initData.balance = 0;
        strcpy(initData.valuta, "ASD");
        strcpy(initData.owner, "Aasd Hjlkj");
        initData.number = 0;

        initBuffer(&myBuf, initData);
        printBuff(myBuf);

        for (int i = 0; i < ITEMS_COUNT; i++) {
                struct BankAccount bankData;
                /* Generate random names */
                for (int j = 1; j < 20; j++) {
                        int c;
                        c = rand() % (sizeof(allowedSymbols) - 1);
                        bankData.owner[0] = 27 + rand() % 26; /* glavna bukva purva duma */
                        bankData.owner[j] = allowedSymbols[c];
                        /* prekaleno mnogo zanimavka e da se napravi rand za broi dumi, i led tova da se generirat tezi dumi. nqmam vreme */
                }
                bankData.owner[20] = '\0';

                /* Generate random valuta */
                for (int j = 0; j < 5; j++) {
                        int c;
                        strcpy(bankData.valuta, "asd");
                }

                bankData.number = (uint16_t) i;
                bankData.balance = ((double)(rand() % 10000000) / 100);
                insertAfter(&myBuf, 1, bankData);
                printBuff(myBuf);
        }

        freeBuff(myBuf);
        printBuff(myBuf);

        return 0;
}

