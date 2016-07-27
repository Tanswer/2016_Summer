/*************************************************************************
	> File Name: processimage.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 21时29分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char * argv[],char **environ)
{
    printf("I am a process image!\n");
    printf("My pid is %d,parentpid is %d\n",getpid(),getppid());
    printf("uid is %d,gid is %d\n",getuid(),getgid());

    for(int i=0; argv[i]!=NULL; i++)
        printf("argv[%d] is %s\n",i,argv[i]);
    for(int j=0;environ[j]!=NULL;j++)
        printf("%s\n",environ[j]);

    return 0;
}

