/*************************************************************************
	> File Name: env.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 21时09分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <malloc.h>

extern char ** environ;

int main(int argc,char ** argv)
{
    int i;
    printf("Argument:\n");
    for(i=0;i<argc;i++)
        printf("argv[%d] is %s \n",i,argv[i]);
    printf("Environment:\n");

    for(i=0;environ[i]!=NULL;i++)
        printf("%s\n",environ[i]);
    return 0;
}
