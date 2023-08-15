#include <stdio.h>
#include <unistd.h>

int
main()
{
        int curNum;
        unsigned long long sum = 0;
        int num_read;
        do {
                curNum = 0;
                num_read = read(STDIN_FILENO, &curNum, sizeof(curNum));
                sum += curNum;
        } while (num_read == sizeof(curNum));
        printf("%lld", sum);
        return 0;
}
