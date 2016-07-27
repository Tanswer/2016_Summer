/*************************************************************************
	> File Name: diffork.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 17时36分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>


int globvar=5;

int main()
{
    int var=1,i;
    pid_t pid;
    //pid=fork();
    pid=vfork();
  //      printf("....%d\n",pid);
    switch(pid)
    {
        case 0:
            i=3;
            //printf("...%d....%d\n",pid,i);
            while(i-- > 0)
            {
                printf("...%d....%d\n",pid,i);
                printf("Child process is running\n");
                globvar++;
                var++;
                sleep(1);
            }
            printf("Child's globvar= %d,var= %d \n",globvar,var);
            break;
        case -1:
            perror("Process creation failed\n");
            exit(0);

        default:
            i=5;
            //printf("...%d....%d\n",pid,i);
            while(i-- > 0)
            {
                printf("...%d....%d\n",pid,i);
                printf("Parent's process is running\n");
                globvar++;
                var++;
                sleep(1);
            }
            printf("Parent's globvar = %d,var= %d \n",globvar,var);
            exit(0);
    }
    return 0;
}
