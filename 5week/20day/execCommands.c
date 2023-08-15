#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main()
{
        char *argv[] = {"ls", "-la", NULL};
        //execl("./signalLoop", "./signalLoop", NULL); //tursi v CD
        //execlp("ls", "ls", "-lah", NULL); //tursi v PATH
        execvp("ls", argv);
        return 0;
}
