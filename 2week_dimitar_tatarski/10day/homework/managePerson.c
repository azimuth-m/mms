#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#define ID_LEN 3 /* Beign odd does not requre more space than odd-1
                  * 3 has same space as 2;
                  * 5 has same space as 4;
                  */

/* Struct is padded to a size%2 Bytes == 0 */
struct Person {
        uint16_t birthYear  :  12; /* [0: 4095] */
        uint16_t birthMonth :   4; /* [0:   16] */
                /* 2 Bytes */
        char name[100];
        char id[ID_LEN];
                /* 100 + ID_LEN Bytes */

        uint8_t birthDay    :   5; /* [0:   31] */
        uint8_t gender      :   1; /* [0:    1] */
                /* 1 Byte */
};

void *
initArray(size_t capacity) /* Remember to free allocated space */
{
        return (malloc(capacity * sizeof(struct Person)));
}

int
main()
{
        printf("%ld ", sizeof(struct Person));
        return 0;
}
