#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <unistd.h>

int main(){
    int w,x;
    printf("Proces macierzysty:%d\n",getpid());
    for(int i=0;i<3;i++){
        switch(fork()){
        case -1:
            perror("fork error");
            exit(1);
        case 0:
            execl("./program1","program1",NULL);
            exit(2);
        default:
            sleep(2);  
        }
        w=wait(&x);
        printf("Kod powrotu potomka %d = %d\n", i,x );
    }
    exit(0);
}

