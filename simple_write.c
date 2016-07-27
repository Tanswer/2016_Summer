/*************************************************************************
	> File Name: 1.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 08时09分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main()
{
    if(write(1,"here is some data\n",18) != 18)
        write(2,"A write error has occurred on file descriptor 1\n",46);
    return 0;
}

