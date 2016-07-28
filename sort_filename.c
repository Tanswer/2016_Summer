/*************************************************************************
	> File Name: sort_filename.c
	> Author: Tanswer_
	> Mail: 98duxm@gmail.com
	> Created Time: 2016年07月27日 星期三 14时04分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int *index,t;
    char filename[5][32]={"bcda","asfds","zcdfg","dczx","cgdf"};
    index=(int *)malloc(sizeof(int)*10);

    for(int i=0;i<5;i++)
        index[i]=i;

    for(int k=0; k<5; k++)
        printf("%s \n",filename[k]);
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if( strcmp(filename[i],filename[j] ) > 0){
                t=index[j];
                index[j]=index[i];
                index[i]=t;
            }
            else
                continue;
         }
    }
    
    for(int i=0;i<5;i++)
        printf("%d \n",index[i]);

    for(int k=0; k<5; k++)
        printf("%s \n",filename[index[k]]);


    return 0;
}
