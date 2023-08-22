#include<stdio.h>
#include<math.h>
int track[50];
void fcfs(int head,int t){
    int curr_position,distance,seek_count=0;
    for(int i=0;i<t;i++){
         curr_position=track[i];
         distance=fabs(head-curr_position);
         seek_count+=distance;
         head=curr_position;
    }
    printf("Total number of seek : %d",seek_count);

}

void main(){
    int t,head,ind;
    printf("Enter the no of tracks\n");
    scanf("%d",&t);
    printf("Enter the head position\n");
    scanf("%d",&head);
    printf("Enter the tracks\n");
    for(int i=0;i<t;i++){
        scanf("%d",&track[i]);
    }
    fcfs(head,t);
}