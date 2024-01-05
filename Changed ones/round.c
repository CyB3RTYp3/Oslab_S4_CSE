#include<stdio.h>
int n ,quantum;


void read(int bt[])
{
    printf("\nEnter Burst Time of each process\n");
    for(int i=0;i<n;i++)
    {
        printf(" \n process %d ",i);
        scanf("%d",&bt[i]);
    }
}

void findWaitingtime(int bt[],int wt[])
{
    int bt_rem[20];int time=0;
    for(int i=0;i<n;++i)
    {
        bt_rem[i]=bt[i];
    }


    while(1){
        int flag=0;

       for(int i=0;i<n;++i){

        if(bt_rem[i]>0){
              flag=1;
            if(bt_rem[i]>quantum){
                time+=quantum;
                bt_rem[i]-=quantum;

            }
            else{
                time+=bt_rem[i];
                bt_rem[i]=0;
                wt[i]=time-bt[i];
            }
        }
       }
       if(flag==0){
        break;
       }
    }
}

void findTurnAroundtime(int bt[],int wt[],int tat[])
{
   for(int i=0;i<n;i++){
    tat[i]=wt[i]+bt[i];
   }
}
void display(int b[], int wt[], int tat[]) {
    int wtSum = 0, tatSum = 0;
    printf("\n-------------------------------------------------\n");
    printf("Process\tBurstTime WaitingTime  TurnAroundTime\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < n; ++i) {
        wtSum += wt[i];
        tatSum += tat[i];
        printf("%3d\t%6d\t\t%d\t%5d\n", i, b[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %.3f", (float)wtSum / n);
    printf("\naverage turnaround time: %.3f", (float)tatSum / n);
    printf("\n");
}

void calcTime(int b[], int wt[], int tat[]) {
    findWaitingtime(b, wt);
    findTurnAroundtime(b, wt,tat);
    display(b, wt, tat);
}

void main()
{
    int bt[20], tat[20], wt[20];
    printf("Enter Number of Processes:");
    scanf("%d", &n);
    read(bt);
    printf("\nEnter time quantum:");
    scanf("%d", &quantum);
    calcTime(bt, wt, tat);
}
