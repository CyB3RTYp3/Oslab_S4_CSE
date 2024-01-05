#include<stdio.h>
#include<stdlib.h>


typedef struct process
{
  int pid;
//   int priority;
  int burst_time;
  int arrival_time;
  int tat;
  int wt;
  int ct;
}process;


void swap(process at[],int i,int j)
{
  process temp;
  temp = at[i];
  at[i] = at[j];
  at[j] = temp;
}

void sort(process at[],int n)
{
  int i,j;
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(at[i].arrival_time > at[j].arrival_time)
      {
        swap(at,i,j);
      }
    }
  }
}

void turnaourdTime(process p[],int n){
      p[0].tat=0;
    int j;
    for(j=0;j<n;j++)
    {
        p[j].tat = p[j].ct - p[j].arrival_time;
   
    }
}

void waitndTime(process at[],int n){
    int i;
    for(i=0;i<n;i++)
    {
        at[i].wt = at[i].tat - at[i].burst_time;
    }
}

void completionTime(process at[],int n){
    at[0].ct=0;
    int j;
    for(j=0;j<n;j++)
    {
        if(j == 0)
			at[j].ct = at[j].arrival_time + at[j].burst_time;
		else
			at[j].ct = at[j].burst_time + at[j-1].ct;
    }
}

void avgTime(process at[],int n){
    int i;
    at[0].wt=0;
    float avg_wt=0,avg_tat=0;
    for(i=0;i<n;i++)
    {
        avg_wt = avg_wt + at[i].wt;
        avg_tat = avg_tat + at[i].tat;
    }
    printf("Average Waiting Time:%f\n",avg_wt/n);
    printf("Average Turn Around Time:%f\n",avg_tat/n);
}

void main()
{
    int n,i=0,j=0;
    process at[50];
    printf("Enter no.of processes to excecute in fcfs");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("%dth Process:\n",i);
        printf("pid:");
        scanf("%d",&at[i].pid);
        printf("arrival:");
        scanf("%d",&at[i].arrival_time);
        printf("burst time:");
        scanf("%d",&at[i].burst_time);
    }
 
    printf("pid\t");
    printf("arrival\t");
    printf("burst_time\t");
    printf("completion\t");
    printf("T.A.T\t");
    printf("Waiting_Time\n");
    sort(at,n);
    completionTime(at,n);
    turnaourdTime(at,n);
    waitndTime(at,n);
    for(j=0;j<n;j++)
    { 
        printf("%d\t%d\t%d\t\t%d\t\t%d\t%d\n",at[j].pid,at[j].arrival_time,at[j].burst_time,at[j].ct,at[j].tat,at[j].wt);
    }
    avgTime(at,n);
}