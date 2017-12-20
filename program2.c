#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <unistd.h>

int main()
{
    int i, id, w, x, mpid;
    char cmd[50];
    mpid = getpid();
    printf("Proces macierzysty: %d\n\n", mpid);
    sprintf(cmd, "pstree -p %d", getppid());
    for(i=1; i<4; i++)
    {
        printf("\nfork() !\n");
       
        switch(fork())
        {
            case -1:
                perror("fork error!");
                exit(1);
                break;
            case 0:
                printf("\nUID=%d\nGID=%d\nPID=%d\nPPID=%d\n\n", getuid(), getgid(), getpid(), getppid());
                break;
            default:

                break;
        }

    }

    system(cmd);
//for(i=0;i<3;i++) wait();
    exit(0);
}
