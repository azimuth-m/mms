#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>

struct Car {
        char model[20];
        uint8_t maxspeed;
        double price;
};

void
printCars(struct Car *arr, size_t n)
{
        printf("======================\n");
        for (size_t i = 0; i < n; i++) {
                printf("%s\n", arr[i].model);
                printf("%u\n", arr[i].maxspeed);
                printf("%.2lf\n", arr[i].price);
        }
}

int
descLexCmp(const void *first, void const *second)
{
        return 6;
}

int
ascLexCmp(const void *first, void const *second)
{
        return -(strcmp((char *)first, (char *)second)); /* NE e dobra praktika,
                                                          * NO, tui kato e v
                                                          * nachaloto na struct
                                                          * mojem da si pozvolim
                                                          * da castnem param
                                                          * direktno
                                                          * kum (char *)
                                                          */
}

int
ascSpeedCmp(const void *first, const void *second)
{
        if ( ((struct Car *)first)->maxspeed > ((struct Car *)second)->maxspeed ) 
                return 1;
        else
                return -1; /* Ako sa ravni se priema che 2riq e po golqm */
}

int
descSpeedCmp(const void *first, const void *second)
{
        if ( ((struct Car *)first)->maxspeed > ((struct Car *)second)->maxspeed ) 
                return -1;
        else
                return 1; /* Ako sa ravni se priema che 2riq e po golqm */
}

int
descPriceCmp(const void *first, const void *second)
{
        if ( ((struct Car *)first)->price > ((struct Car *)second)->price ) 
                return -1;
        else
                return 1;
}

int
ascPriceCmp(const void *first, const void *second)
{
        if ( ((struct Car *)first)->price > ((struct Car *)second)->price ) 
                return 1;
        else
                return -1;
}

int
(*getComparator(int n))(const void *, const void *)
{
        switch (n) {
        case 1:
                return ascLexCmp;
                break;
        case 2:
                return descLexCmp;
                break;
        case 3:
                return ascSpeedCmp;
                break;
        case 4:
                return descSpeedCmp;
                break;
        case 5:
                return ascPriceCmp;
                break;
        case 6:
                return descPriceCmp;
                break;
        default:
                return NULL;
        }
}

int
main()
{
        srand(time(NULL));
        struct Car cars[10];
        for (size_t i = 0; i < 10; i++) {
                cars[i].maxspeed = 100 + rand() % (300 - 100);
                cars[i].price = ((double)(100000 + rand() % (10000000 - 100000))/100);
                /* pesvdo-proizvolno ime moje da se generira,
                 * kato se generirat celi chisla v range ['A'-'Z'] i se castnat kum char
                 */
        }
        strcpy(cars[0].model, "AAAA\0");
        strcpy(cars[1].model, "Aaaa\0");
        strcpy(cars[2].model, "Baaa\0");
        strcpy(cars[3].model, "baaa\0");
        strcpy(cars[4].model, "bbba\0");
        strcpy(cars[5].model, "Cbba\0");
        strcpy(cars[6].model, "CBBa\0");
        strcpy(cars[7].model, "ZBBa\0");
        strcpy(cars[8].model, "ZBBb\0");
        strcpy(cars[9].model, "ZBBB\0");

        printCars(cars, 10);
        qsort(cars, 10, sizeof(struct Car), getComparator(4));
        /* ascLexCmp sum go polzval za testove i zatova neraboti.
         * (getComparator(1)) - ne raboti
         * bi imal pochti sushtiq izhod kato descLexCmp
         */
        printCars(cars, 10);

        /* Izvikvaneto na cmp funkciq prez getComparator raboti
         * po tozi nachin
         *
         *  const void *p1 = NULL , *p2 = NULL;
         *  printf("%d", getComparator(1)(p1, p2));
         */
            return 0;
}
