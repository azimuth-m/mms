#include <stdio.h>
#include <stdint.h>

unsigned
onesCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4)
{
        unsigned cnt = 0;
/*
        for(unsigned i = 0; i < (sizeof(uint64_t)*8); i++) {
                if (mask1 & (1 << i))
                        total_ones_count++;
                if (mask2 & (1 << i) && (i < (sizeof(uint32_t)*8)))
                        total_ones_count++;
                if (mask3 & (1 << i) && (i < (sizeof(uint16_t)*8)))
                        total_ones_count++;
                if (mask4 & (1 << i) && (i < (sizeof(uint8_t)*8)))
                        total_ones_count++;
        }
                return total_ones_count;
*/
                for (size_t i = 0; i < 64; i++) {
                        cnt += !!(mask1 & (1ULL << i));
                        cnt += !!(mask2 & (1ULL << i));
                        cnt += !!(mask3 & (1ULL << i));
                        cnt += !!(mask4 & (1ULL << i));
                }
                return cnt;
}

void
flipOddBits(uint64_t *mask)
{
        /*
        for (unsigned i = 1; i < (sizeof(uint64_t)*8); i += 2) {
                if (*mask & (1 << i))
                        *mask &= ~(1 << i);   
                else
                        *mask |= (1 << i); 
        }
        */
        *mask = *mask ^ 0xAAAAAAAAAAAAAAAA;

}

void
swap_bits(uint16_t *mask, size_t i, size_t j)
{
        int i_val = !!(*mask & (1ULL) << i),
            j_val = !!(*mask & (1ULL) << j);

        if ((i_val && j_val) || (!i_val && !j_val) )
                return;
        if(i_val && !j_val) {
                *mask = *mask | (1ULL << j);
                *mask = *mask & ~(1ULL << j);
        }
        if(!i_val && j_val) {
                *mask = *mask | (1ULL << j);
                *mask = *mask & ~(1ULL << j);
        }
}

void
mirrorBits(uint16_t *mask)
{
        for (size_t i = 0; i < 8; i++)
                swap_bits(mask, i, 15-i);
}

int
main()
{
/* Test onesCount() */
        unsigned total_count = 0;
        printf("%u\n", total_count);
        total_count = onesCount(0, 0, 1, 0xFF);
                /*Expected count of 9 (1 + 1*8)*/
        printf("%u\n", total_count); /* Expected (64+32+16+8) ones */
        total_count = onesCount(0xFFFFFFFFFFFFFFFF, 0xFFFFFFFF, 0xFFFF, 0xFF);
        printf("%u\n", total_count); /* Expected (64+32+16+8) ones */

/* Test flipOddBits() */
        uint64_t mask = 0x5F;
        printf("0x%lX\n", mask);
        flipOddBits(&mask);
        printf("0x%lX\n", mask);
        return 0;
}
