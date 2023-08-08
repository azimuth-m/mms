#include <stdio.h>
#include <stdlib.h>

unsigned COUNT; /* inicializa se v 0 */

struct Node {
        int data;
        struct Node *next;
};

struct Node *
insertAfter(struct Node **cll, int skipCount, int d)
{
        struct Node *temphead = *cll;
        struct Node *newNode = malloc(sizeof(struct Node));
        while (skipCount-1) {
                temphead = (temphead)->next;
                skipCount--;
        }
        newNode->next = (temphead)->next; 
        newNode->data = d;
        (temphead)->next = newNode;
        COUNT++;
        return newNode;
}

void
initBuffer(struct Node **cll, int d)
{
        (*cll) = malloc(sizeof(struct Node));
        (*cll)->data = d;
        COUNT++;
        (*cll)->next = *cll;
}

void
printBuff(struct Node *cll)
{
        unsigned tempcount = COUNT;
        while (tempcount) {
                printf("%d  ", cll->data);
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
                free(temp);
                COUNT--;
        }
}

int
main()
{
        /* razbiram che se ochakva da se napravi variadic scanf no nqmam vreme da potursq kak stava  */

        struct Node *myBuf;
        initBuffer(&myBuf, 1);
        printBuff(myBuf);
        insertAfter(&myBuf, 1, 2); /* Ako skip count > nalichen broi elementi,
                                    * slaga v kraq na nalichniq broi   
                                    */
        /* Realizirano e taka, che scipAfter vzima stoinost
         * na poziciqta na koqto shte se dobavi noviq element.
         * skipAfter == 0, se opitva da prezapishe 1viq element
         * i se sguva programata.
         * Prochetoh go prekaleno kusno che range-a vkluchva i nula i
         * zatova sum go realiziral taka.
         */

        printBuff(myBuf);
        insertAfter(&myBuf, 2, 3);
        printBuff(myBuf);
        insertAfter(&myBuf, 1, 4);
        printBuff(myBuf);
        insertAfter(&myBuf, 2, 5);
        printBuff(myBuf);
        /* Funkciite po dobavqne, izglejda che rabotqt korektno */

        freeBuff(myBuf);
        printBuff(myBuf);
        /* Compilirano s -fsanitize=address -g,
         * izglejda nqma memory leakove =],
         * vupreki che pri premahvane na freeBuff(),
         * pak ne dava greshki sanitizera
         * ¯\_(ツ)_/¯
         */

        return 0;
}
