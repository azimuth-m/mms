#include <stdio.h>
#include <inttypes.h>

#define clearBit(field, n) field&(~(1UL << n))
#define setBit(field, n) field|(1UL << n)
#define checkBit(field, n) (!!(field&(1UL << n)))

int
clearBits(uint32_t *maskArr, size_t nitems, size_t bit_index)
{
        if (bit_index > 31)
                return -1;
        for (size_t i = 0; i < nitems; i++)
                maskArr[i] = clearBit(maskArr[i], bit_index);
        return 0;
}

int
setBits(uint32_t *maskArr, size_t nitems, size_t bit_index)
{
        if (bit_index > 31)
                return -1;
        for (size_t i = 0; i < nitems; i++)
                maskArr[i] = setBit(maskArr[i], bit_index);
        return 0;
}

int
checkBits(uint32_t *maskArr, size_t len, size_t bit_index)
{
        /* Veroqtno moje da se napravi
         * po po-optimalen nachin,
         * s po-malko branch-ove
         */

        if (bit_index > 31)
                return -1;
        size_t k = 0;
        size_t j = 0;
        for (size_t i = 0; i < len; i++) {
                if (checkBit(maskArr[i], bit_index) == 1)
                        k++;
                else
                        j++;
        }
        if (k == len)
                return 1;
        else if (j == len)
                return 0;
        return -1;
}

int
main()
{
        uint32_t arr[] = {0xFF, 0xFF, 0xFF, 0xFF};
        int n = sizeof(arr)/sizeof(uint32_t);
/*-----------------------------------------------*/ 
        for (size_t i = 0; i < n; i++)
                printf("0x%X ", arr[i]);
        clearBits(arr, n, 7);
        printf("\n\n");
        for (size_t i = 0; i < n; i++)
                printf("0x%X ", arr[i]);
        printf("\n");
        printf("\tBit %d of every member is %d\n", 1, checkBits(arr, n, 1));
/*-----------------------------------------------*/ 
        setBits(arr, n/2, 7);
        printf("\n");
        for (size_t i = 0; i < n; i++)
                printf("0x%X ", arr[i]);
        printf("\n");
        printf("\tBit %d of every member is %d\n", 31, checkBits(arr, n, 31));
        printf("\tBit %d of every member is %d\n\n", 7, checkBits(arr, n, 7));

        return 0;
}
