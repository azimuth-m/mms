#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 5

struct Book {
        char title[150];
        char author[100];
        unsigned pages;
        float price;
};

void
printBooks(struct Book *arr)
{
        for (size_t i = 0; i < COUNT; i++) {
                printf("\n Book [%ld]\n", i);
                printf("%s\n", arr[i].title);
                printf("%s\n", arr[i].author);
                printf("%u\n", arr[i].pages);
                printf("%.2f\n", arr[i].price);
        }
}

void
initBooks(struct Book *books)
{
        const char ALLOWED_SYMBOLS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (size_t i = 0; i < COUNT; i++) {

                /* Init Title and Author to random string */
                for (size_t j = 0; j < 10; j++) {
                        int c;
                        c = rand() % (sizeof(ALLOWED_SYMBOLS)-1);
                        books[i].title[j] =  ALLOWED_SYMBOLS[c];
                        c = rand() % (sizeof(ALLOWED_SYMBOLS)-1);
                        books[i].author[j] = ALLOWED_SYMBOLS[c];
                }
                        books[i].author[10] = '\0';
                        books[i].title[10] = '\0';

                /* Init pages and price */
                books[i].pages = 5 + rand() % (2000 - 5 + 1);
                books[i].price = ((float)(100 + rand() % (100000 - 100 + 1))/100);
        }
}

int
ascLexCmpTitle(const void *first, const void *second)
{
        char *str1;
        char *str2;
        str1 = ((struct Book *)first)->title;
        str2 = ((struct Book *)second)->title;
        return strcmp(str1, str2);
}

int
descLexCmpAuthor(const void *first, const void *second)
{
        char *str1;
        char *str2;
        str1 = ((struct Book *)first)->title;
        str2 = ((struct Book *)second)->title;
        return -(strcmp(str1, str2));
}

int
ascPageCmp(const void *first, const void *second)
{
        if ( ((struct Book *)first)->pages > ((struct Book *)second)->pages)
                return 1;
        else
                return -1;
}

int
descPriceCmp(const void *first, const void *second)
{
        if ( ((struct Book *)first)->price > ((struct Book *)second)->price)
                return -1;
        else
                return 1;
}

int
(*selector(int n))(const void *, const void *)
{
        switch (n) {
                case 1:
                        return ascLexCmpTitle;
                case 2:
                        return descLexCmpAuthor;
                case 3:
                        return ascPageCmp;
                case 4:
                        return descPriceCmp;
                default:
                        return NULL;
        }
}

int
main()
{
        srand(time(NULL));
        struct Book books[COUNT];
        initBooks(books);
        printBooks(books);


        int n;
        printf("Enter a sorting number\n");
        printf("\n 1 - Ascending title Lex");
        printf("\n 2 - Descending Author Lex");
        printf("\n 3 - Ascending Page COunt");
        printf("\n 4 - Descending price\n");

        scanf("%d", &n);
//        printf("\n\n[%d]\n\n", ascLexCmpTitle( (void *)(&(books[0].title)), (void *)(&(books[1].title)) ));
        qsort(books, COUNT, sizeof(struct Book), selector(n));
        printBooks(books);
        return 0;
}
