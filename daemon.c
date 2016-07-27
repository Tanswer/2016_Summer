/*************************************************************************
	> File Name: daemon.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 19时58分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/param.h>
#include <syslog.h>
#include <sys/stat.h>
#include <signal.h>

int init_daemon()
{
    pid_t pid;

    pid=fork();

    /*结束父进程，使得子进程成为后台进程*/
    if(pid>0)
        exit(0);
    else
        return -1;
    /*建立一个新的进程组，使进程成为一个新的会话组长*/
    setsid();
    
    /*再次建立一个进程，退出父进程，禁止进程重新打开控制终端*/
    pid=fork();
    if(pid>0)
        exit(0);
    else
        return -1;
    /*关闭所有从父进程继承的不再需要的文件描述符*/
    for(int i=0;i<NOFILE;i++)
        close(i);

    /*改变工作目录，使得进程不与任何文件系统联系*/
    chdir("/");

    /*将文件屏蔽字设置为零*/
    umask(0);

    /*忽略SIGCHLD信号*/
    signal(SIGCHLD,SIG_IGN);

    return 0;
}

int main()
{
    time_t now;
    init_daemon();
    syslog(LOG_USER|LOG_INFO,"测试守护进程！\n");
    while(1)
    {
        sleep(8);
        time(&now);
        syslog(LOG_USER|LOG_INFO,"系统时间:\t%s\t\t\n",ctime(&now));
    }
}
