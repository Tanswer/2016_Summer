/*************************************************************************
	> File Name: my_chmod1.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 14时04分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

int main(int argc,char *argv[])
{
    int mode;
    struct stat buf;
    //检查参数个数
    if(argc!=2)
    {
        printf("Usage:my_stat <filename>\n");
        exit(1);
    }

    if(stat(argv[1],&buf) == -1) //第二个参数为要查询的文件名
    {
        perror("stat");
        exit(1);
    }

    //打印文件属性
    printf("device is : %d\n",buf.st_dev);
    printf("inode is : %d\n",buf.st_ino);
    printf("mode is : %o\n",buf.st_mode);
    printf("uid is : %d\n",buf.st_uid);
    printf("gid is : %d\n",buf.st_gid);
    printf("size in bytes is : %d\n",buf.st_size);
    
    printf("time of last access is : %s\n",ctime(&buf.st_atime));
    
    //mode=atoi(argv[1]);
    //printf("mode = %d\n",mode);

    return 0;
}
