/*************************************************************************
	> File Name: execve.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 21时37分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
int main(int argc,char * argv[],char **environ)
{
    pid_t pid;
    int stat_val;
    pid=fork();
    switch(pid)
    {
        case 0:
            printf("Child process is running!\n");
            printf("pid = %d,parentprocess pid = %d\n",getpid(),getppid());
            printf("uid = %d,gid = %d\n",getuid(),getgid());
            execve("processimage",argv,environ);
            printf("process never go to here!\n");
            exit(0);
        case -1:
            perror("process Creation failed!\n");
            exit(1);
        default:
            printf("parent process is running!\n");
            break;
    }
    
    wait(&stat_val);
    exit(0);

}
