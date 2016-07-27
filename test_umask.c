/*************************************************************************
	> File Name: test_umask.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 14时37分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    umask(0);
    if((open("umask1",O_CREAT,S_IRWXU|S_IRWXG|S_IRWXO))==-1)
        perror("open");

    umask(S_IRWXO); //屏蔽其他用户的所有权限

    if(open("umask2",O_CREAT,S_IRWXU|S_IRWXG|S_IRWXO)==-1)
        perror("open");

    return 0;
}

