/*************************************************************************
	> File Name: getpriority.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月28日 星期四 14时34分07秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/resource.h>
int main()
{
    pid_t pid;
    
    int prioc,priop;
    if((pid=fork()) == -1){
        printf(" failure\n");
        exit(1);
    }
    switch(pid)
    {
        case 0:
        {
            prioc=getpriority(PRIO_PROCESS,getpid());
            printf("子进程　优先级为　：　%d\n",prioc);
        }
        break;
        default:{
            priop=getpriority(PRIO_PROCESS,getpid());
            printf("父进程　优先级为　：　%d\n",priop);
        }
        break;
    }
    
    return 0;
}
