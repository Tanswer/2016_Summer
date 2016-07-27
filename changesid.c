/*************************************************************************
	> File Name: changesid.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 22时03分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    pid_t pid;
    if(pid=fork()<0 )
    {
        perror("fork");
        exit(1);
    }

    else if(pid == 0)
    {
        printf("The children pid is %d\n",getpid());
        printf("the parent pid is %d\n",getppid());
        printf("the group id is %d\n",getpgid(0));
        printf("the session id is %d\n",getsid(0));
        sleep(10);
        setsid();
        printf("changed:\n");
        printf("The children pid is %d\n",getpid());
        printf("the parent pid is %d\n",getppid());
        printf("the group id is %d\n",getpgid(0));
        printf("the session id is %d\n",getsid(0));
        sleep(15);
        exit(0);
    }

    return 0;
}
