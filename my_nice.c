/*************************************************************************
	> File Name: my_nice.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月28日 星期四 14时47分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int stat_val;
    int oldpri,newpri;

    printf("study nice:\n");

    pid=fork();
    switch(pid)
    {
        case 0:
            printf("childprocess is running,curpid = %d,parentpid = %d \n",pid,getppid());
            oldpri=getpriority(PRIO_PROCESS,0);
            printf("old priority = %d\n",oldpri);

            newpri=nice(2);
            printf("New priority = %d\n",newpri);
            exit(0);
        case -1:
            printf("process creation failed!\n");
            break;
        default:
            printf("parent process is running,childpid = %d ,parentpid = %d \n",pid,getpid());
            break;
    }
    wait(&stat_val);
    exit(0);
}
