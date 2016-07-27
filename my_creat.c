/*************************************************************************
	> File Name: my_creat.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 14时46分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    char *path;
    int fd;
   // scanf("%s",path);
    
    fd=open("test1", O_CREAT|O_EXCL, S_IRUSR|S_IWUSR);
    if(fd == -1)
        printf("open error!\n");
    else
        printf("creat successful!\n");

    close(fd);
    return 0;
}
