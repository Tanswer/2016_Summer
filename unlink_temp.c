/*************************************************************************
	> File Name: unlink_temp.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 14时54分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void my_error(const char *err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

int main()
{
    int fd;
    char buf[32];

    if((fd=open("temp",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU))<0)
        my_error("open",__LINE__);

    if(unlink("temp") < 0)
        my_error("unlink",__LINE__);
    printf("file unlinked\n");

    if((write(fd,"temp",5))<0)
        my_error("write",__LINE__);

    if(lseek(fd,0,SEEK_SET) == -1)
        my_error("lseek",__LINE__);

    if(read(fd,buf,5)<0)
        my_error("read",__LINE__);

    printf("%s\n",buf);
    return 0;
}
