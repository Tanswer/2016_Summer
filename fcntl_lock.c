/*************************************************************************
	> File Name: fcntl_lock.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月26日 星期二 10时28分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void my_error(const char *err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror("err_string");
    exit(1);
}

/*设置或释放锁*/
int lock_set(int fd,struct flock * lock)
{
    if(fcntl(fd,F_SETLK,lock) == 0)//执行成功
    {
        if(lock->l_type == F_RDLCK)
        {
            printf("set read lock,pid = %d\n",getpid());
        }
        else if(lock->l_type == F_WRLCK)
        {
            printf("set write lock,pid = %d\n",getpid());
        }
        else if(lock->l_type == F_UNLCK)
        {
            printf("release lock,pid = %d\n",getpid());
        }
    }
    else // 执行失败，返回-1
    {
        my_error("lock",__LINE__);
    }
    return 0;
}

/*测试锁，只有当测试发现参数lock指定的锁能被设置时，返回0*/
int lock_test(int fd,struct flock * lock)
{
    if(fcntl(fd,F_GETLK,lock)==0)//执行成功
    {
        if(lock->l_type == F_UNLCK)
        {
            printf("lock can be set in fd!\n");
            return 0;
        }
        else //有不兼容的锁　存在，打印出设置该锁的进程ID
        {
            if(lock->l_type == F_RDLCK)
            {
                printf("can't set lock,read lock has been set by pid:%d\n",lock->l_pid);
            }
            else if(lock->l_type == F_WRLCK)
            {
                printf("can't set lock,write lock has been set by pid:%d\n",lock->l_pid);
            }
            return -2;
        }
    }
    else  //执行失败
        my_error("fcntl",__LINE__);
}
int main()
{
    int fd;
    int ret;
    struct flock lock;
    char read_buf[32];

    /*打开或创建文件*/
    if((fd=open("test2",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU))==-1)
        my_error("open",__LINE__);

    /*写数据*/
    if((write(fd,"test lock",10))!=10)
        my_error("write",__LINE__);

    /*初始化lock结构*/
    memset(&lock,0,sizeof(struct flock));
    lock.l_start = SEEK_SET;
    lock.l_whence = 0;
    lock.l_len = 0;

    /*设置读锁*/
    lock.l_type=F_RDLCK;
    if(lock_test(fd,&lock) == 0) //测试可以设置锁
    {
        lock.l_type=F_RDLCK;
        lock_set(fd,&lock);
    }

    /*读数据*/
    lseek(fd,0,SEEK_SET);//将文件指针移动到文件开头
    if((ret=read(fd,read_buf,10))<0)
    my_error("read",__LINE__);
    read_buf[ret]='\0';
    printf("%s\n",read_buf);

    getchar();

    /*设置写锁*/
    lock.l_type=F_WRLCK;
    if((lock_test(fd,&lock)) ==0 )
    {
        lock.l_type=F_WRLCK;
        lock_set(fd,&lock);
    }

    /*释放锁*/
    lock.l_type=F_UNLCK;
    lock_set(fd,&lock);
    close(fd);
    return 0;
}
