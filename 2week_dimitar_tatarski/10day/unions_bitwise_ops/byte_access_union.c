#include <stdio.h>
#include <inttypes.h>
#include <limits.h>

/* Using union, to read bytes 
 * of a given variable, knowing that,
 * the space allocated for a union is the space
 * of it's largest member data structure.
 *
 * All data structures share the same memory.
 * Take note of endian-ness
 */

union A {
        uint32_t u;
        uint8_t bytes[4];
};

void
printBytes(union A a)
{
        for (size_t i = 0; i < sizeof(union A); i++) {
                printf("%02x ", a.bytes[i]);
        }                
}

int
main()
{
        union A u1;

        u1.u = 0xFE;
        printBytes(u1);
        printf("\n");
        u1.u = UINT_MAX - 2;
        printBytes(u1);
        printf("\n");
        u1.u = 9;
        printBytes(u1);
        printf("\n");
        return 0;

}
