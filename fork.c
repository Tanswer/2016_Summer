/*************************************************************************
	> File Name: fork.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 16时13分38秒
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

    printf("Process Creation Study!\n");

    pid=vfork();
    
    printf("......%d\n",pid);
    switch(pid)
    {
        case 0:
        printf("Child process is running,CurPid is %d,ParentPid is %d\n",pid,getppid());
        /*getppid() 得到该进程的父进程pid*/
        break;
        case -1:
        perror("Process creation failed\n");
        break;
        default:
        printf("ParentPid process is running,ChildPid is %d,ParentPid is %d\n",pid,getpid());
        /*getpid()得到该进程的pid*/
        break;
    }

    return 0;
}
