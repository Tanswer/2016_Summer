/*************************************************************************
	> File Name: copy_blocks.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 11时56分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char blocks[1024];
    int in,out;
    int nread;
    in=open("file.in",O_RDONLY);
    out=open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);

    while((nread=read(in,blocks,sizeof(blocks))) >0 )
        write(out,blocks,nread);
    return 0;
}
