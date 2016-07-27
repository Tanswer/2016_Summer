/*************************************************************************
	> File Name: my_rwl.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 08时21分31秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

void my_error(const char *err_string, int line)
{
    fprintf(stderr,"line:%d ",line);
    perror(err_string);
    exit(1);
}

int my_read(int fd)
{
    int len;
    int ret;
    int i;
    char read_buf[64];

    if(lseek(fd,0,SEEK_END)==-1)
        my_error("lseek",__LINE__);
    if((len=lseek(fd,0,SEEK_CUR))==-1)
        my_error("lseek",__LINE__);
    if(lseek(fd,0,SEEK_SET)==-1)
        my_error("lseek",__LINE__);

    printf("len=:%d\n",len);

    if( (ret=read(fd,read_buf,len)) <0)
        my_error("read",__LINE__);

    /*打印数据*/
    for(i=0;i<len;i++)
        printf("%c",read_buf[i]);
    printf("\n");

    return ret;
}

int main()
{
    int fd;
    char write_buf[32]="hello world!";
    /*创建文件*/
    if((fd=open("test",O_CREAT|O_RDWR|O_TRUNC,S_IRWXU))==-1)
        my_error("open",__LINE__);
    else
        printf("creat file success!\n");

    /*写数据*/
    if(write(fd,write_buf,strlen(write_buf)) != strlen(write_buf))
        my_error("write",__LINE__);

    my_read(fd);
    
    /*演示文件的间隔*/
    printf("----------------\n");
    
    if(lseek(fd,10,SEEK_END)==-1)
        my_error("lseek",__LINE__);

    if(write(fd,write_buf,strlen(write_buf)) != strlen(write_buf))
        my_error("write",__LINE__);
    
    my_read(fd);

    close(fd);
    return 0;
}
