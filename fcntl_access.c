/*************************************************************************
	> File Name: fcntl_access.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 09时07分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void my_err(const char *string,int line)
{
    fprintf(stderr,"line:%d ",line);
    perror("string");
    exit(1);
}

int main()
{
    int ret;
    int fd;
    int access_mode;
    
    if((fd=open("test1",O_CREAT|O_RDWR|O_TRUNC,S_IRWXU)) == -1)
       my_err("open",__LINE__);
    
       /*设置文件打开的方式*/
    if((ret=fcntl(fd,F_SETFL,O_APPEND))<0)
       my_err("fcntl",__LINE__);

    /*获取文件打开的方式*/
    if((ret=fcntl(fd,F_GETFL,0))<0)
       my_err("fcntl",__LINE__);

    access_mode = ret & O_ACCMODE;
       /*O_ACCMODE取得文件打开方式的掩码*/
    
    if(access_mode == O_RDONLY)
       printf("test1 access mode:read only");

    else if(access_mode == O_WRONLY)
       printf("test1 access mode:write only");

    else if(access_mode == O_RDWR)
       printf("test1 access mode:read + write");
    
    if(ret & O_APPEND)
       printf(",append");
    if(ret & O_NONBLOCK)
       printf(",nonblock");
    if(ret & O_SYNC)
       printf(",sync");
    
    printf("\n");
    return 0;
}
