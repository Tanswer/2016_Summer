/*************************************************************************
	> File Name: simple_read.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 10时17分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main()
{
    char buf[128];
    int nread;

    nread=read(0,buf,128);
    if( nread==-1 )
        write(2,"A read error has occured\n",26);

    if((write(1,buf,nread))!=nread)
        write(2,"A write error has occured\n",27);

    return 0;
        
}
