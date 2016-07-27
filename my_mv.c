/*************************************************************************
	> File Name: my_mv.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 14时46分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char * argv[])
{
    if(argc!=3)
    {
        printf("my_mv <old filename> <new filename>\n");
        exit(0);
    }

    if(rename(argv[1],argv[2]) == -1)
    {
        perror("rename");
        exit(1);
    }
    else
        printf("rename success!\n");
    return 0;
}

