#include <stdio.h>
#include <inttypes.h>
#include <string.h>

void
swapBytes(uint16_t *word)
{
        uint8_t tmp;
        uint8_t *one;
        uint8_t *two;

        one = (uint8_t *) word;
        two = one + 1;

        tmp = *one;
        *one = *two;
        *two = tmp;
}

int
main()
{
        uint16_t ui = 0x11FF;
        printf("0x%X\n", ui);
        swapBytes(&ui);
        printf("0x%X\n", ui);
        return 0;
}
