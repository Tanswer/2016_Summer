/*************************************************************************
	> File Name: my_cdvc.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 15时18分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <Linux/limits.h>

void my_err(const char *err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror("err_string");
    exit(1);
}

int main(int argc,char *argv[])
{
    char buf[1024];
    if(argc<2)
    {
        printf("my_cd <target path>\n");
        exit(1);
    }
    /*设置工作目录*/
    if(chdir(argv[1])<0)
        my_err("chdir",__LINE__);

    /*获取当前目录*/
    if(getcwd(buf,512)<0)
        my_err("getcwd",__LINE__);

    printf("%s\n",buf);

    return 0;

}
