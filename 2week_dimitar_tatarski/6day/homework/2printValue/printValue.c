#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define         TINT            1
#define         TCHAR           2
#define         TDOUBLE         3
#define         TFLOAT          4
#define         TUINT8          5
#define         TUINT16         6
#define         TUINT32         7
#define         TUINT64         8

void
printValue(const void *valuePtr, uint8_t flag)
{
        switch (flag) {

        case TINT:    
                printf("TINT: %d\n", *((int *) valuePtr));
                break;
        case TCHAR:
                printf("TCHAR: %c\n", *((char *) valuePtr));
                break;
        case TDOUBLE:
                printf("TDOUBLE: %lf\n", *((double *) valuePtr));
                break;
        case TFLOAT:
                printf("TFLOAT: %f\n", *((float *) valuePtr));
                break;
        case TUINT8:
                printf("TUINT8: %" PRIu8 "\n", *((uint8_t *) valuePtr));
                break;
        case TUINT16:
                printf("TUINT16: %" PRIu16 "\n", *((uint16_t *) valuePtr));
                break;
        case TUINT32:
                printf("TUINT32: %" PRIu32 "\n", *((uint32_t *) valuePtr));
                break;
        case TUINT64:
                printf("TUINT64: %" PRIu64 "\n", *((uint64_t *) valuePtr));
                break;
        default:
                printf("Illegal Flag\n");
                break;
        }
}

int
main()
{
        char c = 'C';
        double d = 2.71;
        float f = 0.00001;
        uint64_t ull = 0xFFFFFFFFFFFFFFFF;
        printValue(&ull,  TINT);
        printValue(&c,    TCHAR);
        printValue(&d,    TDOUBLE);
        printValue(&f,    TFLOAT);
        printValue(&ull,  TUINT8);
        printValue(&ull,  TUINT16);
        printValue(&ull,  TUINT32);
        printValue(&ull,  TUINT64);
        printValue(&ull,  66);

        return 0;
}
