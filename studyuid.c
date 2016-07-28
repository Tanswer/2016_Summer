/*************************************************************************
	> File Name: studyuid.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月28日 星期四 11时35分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern int errno;

int main()
{
    int fd;
    printf("uid study:\n\n");
    printf("Process's uid = %d,euid = %d \n",getuid(),geteuid());

    /*strerror函数获取指定错误码的提示信息*/
    if((fd=open("test.cpp",O_RDWR)) == -1){
        printf("open failure,error is %d : %s \n",errno,strerror(errno));
        exit(1);
    }

    else
        printf("open success!\n");

    close(fd);
    
    exit(0);
}
