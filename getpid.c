/*************************************************************************
	> File Name: getpid.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月28日 星期四 11时06分20秒
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

    if((pid=fork()) == -1)
    {
        printf("fork error!\n");
        exit(1);
    }
    if(pid == 0 )
        printf("getpid return %d\n",getpid());
    if( pid > 0 )
    printf(" childprocess pid is %d \n",pid);
    exit(0);
}
