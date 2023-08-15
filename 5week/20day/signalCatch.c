#include <stdio.h>
#include <signal.h>

void
onTerm(int sigNum)
{
        printf("CANNOT BE TERM\n");
        return;
}

int main()
{
        signal(SIGTERM, onInterupt);
        while (1)
                printf("Hi =]\n");
        return 0;
}
