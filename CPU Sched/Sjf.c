#include<stdio.h>
#include<stdlib.h>
float tat=0,twt=0;
typedef struct process{
    int pid,at,ct,tat,wt,bt,flag;
}process;
void swap(process *p,int i,int j){
  process temp=p[i];
  p[i]=p[j];
  p[j]=temp;
}
void sort(process *p,int n)
{
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(p[j].at>p[j+1].at)
              swap(p,j,j+1);
        }
    }
}
int minburst(process *p,int n, int time){
   int k=-1,min=9999;
   for(int i=0;i<n&&p[i].at<=time;i++){
        if(p[i].flag==0){
              if(p[i].bt<min){
                min=p[i].bt;
                k=i;
              }
        }
   }
  return k;
}
int nxtarrival(process *p,int n,int time){
    for(int i=0;i<n;i++){
       if(p[i].at>time){
         time=p[i].at;
         break;
       }
    }
    return time;
}
void calc(process *p,int n){
    int time=0; 
    for(int i=0;i<n;i++){
     int min=minburst(p,n,time);
     if(min==-1){
        time=nxtarrival(p,n,time);
        min=minburst(p,n,time);
     }
    p[min].ct=time+p[min].bt;
    p[min].tat=p[min].ct-p[min].at;
    p[min].wt=p[min].tat-p[min].bt;
    tat+=p[min].tat;
    twt+=p[min].wt;
    p[min].flag=1;
    time=p[min].ct; 
    printf("%d\t%d\t%d\t\t%d\t\t%d\t%d\n",p[min].pid,p[min].at,p[min].bt,p[min].ct,p[min].tat,p[min].wt);
    }
    printf("avg.tat: %f \n",tat/n);
    printf("avg.twt: %f \n",twt/n);
}
int main(){
    int n;
    printf("enter the number of process \n");
    scanf("%d",&n);
    process *p=(process*)malloc(n*sizeof(process));
    printf("enter the at and bt of process \n");    
    for(int i=0;i<n;i++){
        printf("pid:%d \n",i);
        p[i].pid=i; p[i].flag=0;
        scanf("%d %d",&p[i].at,&p[i].bt);
    }
    sort(p,n);
    printf("pid\tarrival\tburst_time\tcompletion\tT.A.T\tWaiting_Time\n");
    calc(p,n);
    return 0;
}




