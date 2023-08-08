#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 40

struct Product {
        double old_price;
        double new_price;
        unsigned int id;
        char product_type;
        char product_name[3]; /* Pri 3 byte-a product_name, nqma padding
                               * (padva na kratni na sizeof(double) == 8.
                               * Pri sizeof(product_name) == 3,
                               * sizeof(struct Product) == 24
                               * Sledvashtiqt razmer na product_name,
                               * pri koito nqma da ima
                               * padding == 11; (sizeof(struct Product) == 32
                               */
};
int
main()
{
        srand(time(0));
        printf("Sizeof Product: %ldB\n", sizeof(struct Product));

        struct Product products[N];
        const char allowed[] = "ABCD";
        
        for (size_t i = 0; i < N; i++) {
                int c;
                /* Generate random product name */
                for (size_t j = 0; j < 3; j++) {
                        c = rand() % (sizeof(allowed)-1);
                        products[i].product_name[j] = allowed[c];

                }
                products[i].product_name[2] = '\0';
                c = rand() % (sizeof(allowed)-1);
                products[i].product_type = allowed[c];
                
                products[i].id = i+1;

                products[i].old_price = ((double) (499 + rand() % (10045 - 499 +1))/100);
                products[i].new_price = ((double) (499 + rand() % (10045 - 499 +1))/100);
        }

        for (size_t i = 0; i < N; i++) {
                printf("Old price: %.2lf\n", products[i].old_price);
                printf("Old price: %.2lf\n", products[i].new_price);
                printf("ID: %u\n", products[i].id);
                printf("Product Type: %c\n", products[i].product_type);
                printf("Name: %s\n", products[i].product_name);
                printf("===========================\n");
        }
        return 0;
}
