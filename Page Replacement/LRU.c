#include<stdio.h>

int frame[10],str[100];

int findIndex(int fr,int ind){
    int i;
    for(i=ind-1;i>=0;i--){
        int flag=1;
        for(int j=0;j<fr;j++){
            if(frame[j]==str[i]){
                flag=0;
            }
        }
        if(flag)
           break;
    }
    return i+1;
}

void LRU(int fr,int ind){
 for(int i=0;i<fr;i++){
    if(frame[i]==-1){
        frame[i]=str[ind];
        return;
    }  
 }

 int index=findIndex(fr,ind);

for(int i=0;i<fr;i++){
    if(frame[i]==str[index]){
        frame[i]=str[ind];
        index=-1;
        return;
    }
}
}

void main(){
   int fr,n,fault=0;
   printf("Enter the number of pages \n");
   scanf("%d",&n);
   printf("Enter the number of Frames \n");
   scanf("%d",&fr); 
   printf("Enter the referance string\n");
   for(int i=0;i<n;i++){
    scanf("%d",&str[i]);
   }
   for(int i=0;i<fr;i++){
    frame[i]=-1;
   }
   for(int i=0;i<n;i++){
    int flag=0;
    for(int j=0;j<fr;j++){
        if(frame[j]==str[i]){
            flag=1;
            break;
        }
    }
    if(!flag){
        LRU(fr,i);
        fault++;
    }
    
    printf("\n");
    for(int i=0;i<fr;i++){
        printf("%d\t",frame[i]);
    }
   }
   printf("\n page fault:%d",fault);
}