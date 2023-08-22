#include<stdio.h>
void main(){
    int n,fr,fault=0;
    printf("Enter the number of pages \n");
    scanf("%d",&n);
    int str[n];
    printf("Enter the number of frames \n");
    scanf("%d",&fr);
    int frame[fr];
    printf("Enter the refernce string \n");
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
      if(flag==0){
        frame[fault%fr]=str[i];
        fault++;
      }
      printf("\n");
      for(int k=0;k<fr;k++){
        printf("%d \t",frame[k]);
      }
    }
    printf("\n Page Fault : %d",fault);    
}