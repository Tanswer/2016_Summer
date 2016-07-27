/*************************************************************************
	> File Name: my_chmod.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 14时15分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <sys/types.h>
#include <sys/stat.h>
int main(int argc,char ** argv)
{
    int mode;
    int mode_u;
    int mode_g;
    int mode_o;
    char *path;

    if(argc<3)
    {
        printf("%s <mode num> <target file>\n",argv[0]);
        return 0;
    }

    mode=atoi(argv[1]);
    
    if(mode>777 || mode < 0)
    {
        printf("mode num error!\n");
        return 0;
    }
    mode_o=mode%10;
    mode_g=mode/10%10;
    mode_u=mode/100%10;
    
    printf("%d\n",mode_o);
    printf("%d\n",mode_g);
    printf("%d\n",mode_u);

    mode=(mode_u*8*8)+(mode_g*8)+mode_o; //八进制转换
    printf("%d\n",mode);
    path=argv[2];
    printf("%s\n",path);

    if(chmod(path,mode)==-1)
        perror("chmod error!");
    
    return 0;
}

