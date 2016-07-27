/*************************************************************************
	> File Name: fork3.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 16时36分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    pid=fork();
    printf("....%d\n",pid);
    switch(pid)
    {
        case 0:
            while(1)
            {
                printf("A background process,PID:%d\n,ParentPid:%d\n",getpid(),getppid());
                sleep(1);
      
            }
     
        case -1:
            perror("Failed\n");
            exit(-1);
        default:
            printf("I am Parent process,my pid is %d\n",getpid());
            exit(0);
    }
    
    return 0;
}
