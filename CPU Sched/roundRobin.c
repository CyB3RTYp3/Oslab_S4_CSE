#include<stdio.h>
#include<stdlib.h>
float tat=0,twt=0;
int qua;
typedef struct process{
    int pid,at,ct,tat,wt,bt,rem;
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
void display(process *p,int n){
    printf("pid\t arrival\t burst_time\t completion\t T.A.T\t Waiting_Time\n");
    for(int j=0;j<n;j++)
    { 
        printf("%d\t%d\t%d\t\t%d\t\t%d\t%d\n",p[j].pid,p[j].at,p[j].bt,p[j].ct,p[j].tat,p[j].wt);
    }
    printf("avg.tat: %f \n",tat/n);
    printf("avg.twt: %f \n",twt/n);
}
void calc(process *p,int n){
    int cp=0,time=0;
    while(cp<n){
          for(int i=0;i<n;i++){
            if(p[i].rem>0){
                p[i].rem-=qua;
                time+=qua;
                if(p[i].rem<=0){
                    time+=p[i].rem;
                    cp++;
                    p[i].ct=time;
                }
            }
          }
    }
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        tat+=p[i].tat;
        twt+=p[i].wt;
      }
}

int main(){
    int n;
    printf("enter the number of process \n");
    scanf("%d",&n);
    process *p=(process*)malloc(n*sizeof(process));
    printf("Enter the time quatum");
    scanf("%d",&qua);
    printf("enter the at and bt of process \n");    
    for(int i=0;i<n;i++){
        printf("pid:%d \n",i);
        p[i].pid=i;
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].rem=p[i].bt;
    }
    sort(p,n);
    calc(p,n);
    display(p,n);
    return 0;
}
