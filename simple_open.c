/*************************************************************************
	> File Name: simple_open.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 10时33分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
    char path[128];
    int num;
    scanf("%s",path);
    num=open(path,O_RDONLY);
    if(num==-1)
        write(2,"A error has occured\n",20);
    else
        printf("%d\n",num);
    return 0;

}

