/*************************************************************************
	> File Name: show_files.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 15时37分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

int my_readdir(const char *path)
{
    DIR * dir;
    struct dirent *ptr;
    int i=0;
    if((dir=opendir(path)) == NULL)
    {
        perror("opendir");
        return -1;
    }

    while((ptr=readdir(dir)) != NULL)
    {
        i++;
        printf("%-s",ptr->d_name);
        if(i%5==0)
        printf("\n");
    }
    closedir(dir);
    return 0;
}

int main(int argc,char *argv[])
{
    if(argc<2)
    {
        printf("show_files <current dir\n>");
        exit(1);
    }

    if(my_readdir(argv[1])<0)
    {
        exit(1);
    }

    return 0;
}
