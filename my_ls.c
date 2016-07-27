/*************************************************************************
	> File Name: my_ls.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月27日 星期三 08时00分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <linux/limits.h>
#include <dirent.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>



#define PARAM_NONE 0
#define PARAM_A    1
#define PARAM_L    2
#define MAXROWLEN  80 //一行显示的最多字符数

int g_leave_len = MAXROWLEN;
//一行剩余长度，用于输出对齐
int     g_maxlen;  //存放　目录下最长文件名的长度

/*错误处理函数*/
void my_error(const char *err_string,int line)
{
    fprintf(stderr,"line:%d\n",line);
    perror(err_string);
    exit(1);
}

/*获取文件属性，并打印*/
void display_attribute(struct stat buf,char *name)
{
    char buf_time[32];  //打印文件的时间信息
    struct passwd *psd; //从此结构体获取文件所有着的用户名
    struct group *grp;  //文件所有者所属组的用户名
    
    /*获取并打印文件类型*/
    if( S_ISLNK(buf.st_mode) )  //连接
        printf("l");
    
    else if(S_ISREG(buf.st_mode)) //常规文件
        printf("-");

    else if(S_ISDIR(buf.st_mode)) //目录
        printf("d");

    else if(S_ISCHR(buf.st_mode))  //字符设备
        printf("c");

    else if(S_ISBLK(buf.st_mode))  //块设备
        printf("b");

    else if(S_ISFIFO(buf.st_mode))  //FIFO文件
        printf("f");

    else if(S_ISSOCK(buf.st_mode)) //SOCKET文件
        printf("s");

    /*获取并打印文件所有者的权限*/
    if(buf.st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");
    
    if(buf.st_mode & S_IWUSR)
        printf("w");
    else
        printf("-");
    if(buf.st_mode & S_IXUSR)
        printf("x");
    else
        printf("-");
    if(buf.st_mode & S_IRGRP)
        printf("r");
    else
        printf("-");
    if(buf.st_mode & S_IWGRP)
        printf("w");
    else
        printf("-");
    if(buf.st_mode & S_IXGRP)
        printf("x");
    else
        printf("-");
    if(buf.st_mode & S_IROTH)
        printf("r");
    else
        printf("-");
    if(buf.st_mode & S_IWOTH)
        printf("w");
    else
        printf("-");
    if(buf.st_mode & S_IXOTH)
        printf("x");
    else
        printf("-");

    printf("      ");

    printf("%4d ",buf.st_nlink);
    /*根据uid与gid 获取文件所有着的用户名与组名*/

    psd = getpwuid(buf.st_uid);
    grp = getgrgid(buf.st_gid);
    
    printf("%-8s",psd->pw_name); 
    printf("%-8s",grp->gr_name);

    printf("%6d",buf.st_size);//打印文件大小

    strcpy(buf_time,ctime(&buf.st_mtime));
    buf_time[strlen(buf_time)-1]; //去掉换行符
    printf("  %s",buf_time);

    printf("  %-s\n",name);
}

/*没有选项，打印一个文件名,打印时上下对齐*/
void display_single(char *name)
{
    int i,len;

    if(g_leave_len < g_maxlen){
        printf("\n");
        g_leave_len = MAXROWLEN;
    }
    len = strlen(name);
    len = g_maxlen - len;
    printf("%-s",name);

    for(i=0;i<len;i++)
        printf(" ");
    printf("  ");

    g_leave_len-=(g_maxlen + 2);
}


/*
 * 根据命令行参数和完整路径名显示目标文件
 * 参数 path_name,包含了文件名的路径名
 * */

 void display(int flag,char *path_name)
 {
    int i,j;
    struct stat buf;
    char name[PATH_MAX + 1];

    /*从路径名解析出文件名*/
    for(i=0,j=0; i<strlen(path_name); i++){
        if(path_name[i] == '/'){
            j=0;
            continue;
        }
        name[j++]=path_name[i];
    }
    name[j]='\0';

    /*用lstat　而不是stat以方便解析链接文件*/
    if( lstat(name,&buf) == -1)
       my_error("lstat",__LINE__);


    switch( flag ){
        case PARAM_NONE: //没有-a 和-l　选项
            if( name[0] != '.' )
                display_single(name);
            break;
        case PARAM_A: //-a
            display_single(name);
            break;
        case PARAM_L: //-l 无-a
            if(name[0] != '.')
                display_attribute(buf,name);
            break;
        case PARAM_A + PARAM_L: //-a + -l
            display_attribute(buf,name);
            break;
        default:break;
     } 
 }


void display_dir(int flag_param,char *path)
{
    DIR *dir;
    struct dirent *ptr;
    int count=0;
    char filename[256][PATH_MAX + 1],temp[PATH_MAX + 1];

    /*获取该目录下文件总数和最长的文件名*/
    dir=opendir(path);
    if(dir == NULL)
        my_error("opendir",__LINE__);

    while((ptr=readdir(dir)) != NULL){
        if(g_maxlen < strlen(ptr->d_name))
            g_maxlen = strlen(ptr->d_name);
        count++;
    }
    closedir(dir);

    if(count > 256)
        my_error("too many files undet this dir",__LINE__);

    /*获取该目录下所有文件名*/
    int i,j,len=strlen(path);
    dir = opendir(path);
    for(i=0; i<count; i++){
        ptr = readdir(dir);
        if( ptr == NULL )
            my_error("readdir",__LINE__);
        strncpy(filename[i],path,len);
        filename[i][len]='\0';
        strcat(filename[i],ptr->d_name);
        filename[i][len+strlen(ptr->d_name)]='\0';
    }

    /*使用冒泡法对文件名排序*/
    int *index,t;
    index = (int *)malloc(sizeof(int) * count);
    for(int n=0; n<count; n++)
        index[n]=n;

    for(i=0; i<count-1; i++)
        for(j=0; j<count-1-i; j++){
            if(strcmp(filename[j],filename[j+1]) > 0){
                t=index[j];
                index[j]=index[j+1];
                index[j+1]=t;
            }
        }

    for(i=0; i<count; i++)
        display(flag_param,filename[index[i]]);

    closedir(dir);
    
    //如果没有-l 选项，打印一个换行符
    if( (flag_param & PARAM_L ) == 0)
        printf("\n");
}



int main(int argc,char *argv[])
{
    int i,j,k,num;
    char param[32]; //保存命令行参数
    int flag_param = PARAM_NONE;  //参数种类，默认无参数
    char path[PATH_MAX + 1];  //保存目标文件名和目录名
    struct stat buf;
    
    j=0;
    num=0;
    for(i=0;i<argc;i++){
        if(argv[i] == '-'){
            for(k=1;k<strlen(argv[i]);k++,j++)
                param[j] = argv[i][k]; 
                /*将'-'后面的参数保存到数组param中*/
                num++;//保存'-'的个数
        }
    }
    param[j]='\0';

    /*如果没有输入文件名或目录，就显示当前目录*/
    if(num+1 == argc)
    {
        strcpy(path,"./");
        path[2]='\0';

        display_dir(flag_param,path);
        return 0;
    }
    
}
