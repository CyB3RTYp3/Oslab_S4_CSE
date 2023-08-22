#include<stdio.h>
#include<stdlib.h>

void main(){
    int pro,blo;
    printf("Enter the number of process\n");
    scanf("%d",&pro);
    printf("Enter the number of blocks\n");
    scanf("%d",&blo);
    int process[pro],block[blo];
    printf("Enter the processes\n");
    for(int i=0;i<pro;i++){
        scanf("%d",&process[i]);
    }
    printf("Enter the block\n");
    for(int i=0;i<blo;i++){
        scanf("%d",&block[i]);
    }

    printf("Process no. \t Process size \t Block no.\n");

    for(int i=0,j=0;i<pro;i++){
        int flag=0;
        for(j=0;j<blo;j++)
        if(block[j]>=process[i]){
            printf("%d\t\t%d\t\t%d(%d)\n",i+1,process[i],j+1,block[j]);
            block[j]-=process[i];
            flag=1;
            break;
        }
        if(!flag){
           printf("%d\t\t%d\t\tNot allocated\n",i+1,process[i]); 
        }
    }
}
