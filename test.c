/*************************************************************************
	> File Name: test.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月25日 星期一 14时25分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int slove(int m)
{
    if(m==0)
    return 1;
    else
    return slove(m-1)*m;

}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",slove(n));
    return 0;
}
