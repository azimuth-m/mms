#include <stdio.h>
#include <time.h>

struct MyTime {
        unsigned int year    : 14; /* [0: 16 383] */
        unsigned int month   :  4; /* [0:     15] */
        unsigned int day     :  5; /* [0:     31] */
        unsigned int hour    :  5; /* [0:     31] */
        unsigned int minute  :  6; /* [0:     63] */
        unsigned int second  :  6; /* [0:     63] */

        /*                     41bit total. sizeof(uint)*8 = 32.
         *                     Req Space = 41b. -> Allocate 2*sizeof(uint)B
         */
};

int
isLeapYear(struct MyTime t)
{
        if (!(t.year&3UL) && ((t.year % 25UL) || !(t.year&15UL)))
                return 1;
        return 0;
}

int
totalDaysInYear(struct MyTime t)
{
        return isLeapYear(t) ? 366 : 365;
}

void
printMonth(struct MyTime t)
{
        switch (t.month) {
        case 1:
                printf("Jan\n");
                break;
        case 2:
                printf("Feb\n");
                break;
        case 3:
                printf("Mar\n");
                break;
        case 4:
                printf("Apr\n");
                break;
        case 5:
                printf("May\n");
                break;
        case 6:
                printf("Jun\n");
                break;
        case 7:
                printf("Jul\n");
                break;
        case 8:
                printf("Aug\n");
                break;
        case 9:
                printf("Sep\n");
                break;
        case 10:
                printf("Oct\n");
                break;
        case 11:
                printf("Nov\n");
                break;
        case 12:
                printf("Dec\n");
                break;
        default:
                printf("Not a valid month integer passed\n");
        }
}

int
secondsPassed(struct MyTime t)
{
}

int
main()
{
        struct MyTime t1;
        t1.year = 2001;
        t1.month = 11;
        printf("%d\n", totalDaysInYear(t1));
        printMonth(t1);
        return 0;
}
