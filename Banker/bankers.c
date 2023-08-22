#include<stdio.h>

      int n=5, m=3, i, j, k;
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } };

    int alloc[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4
    int avail[3]={3,3,2};
    int need[5][3];
    int f[5];
    int ans[5];
    void needFind(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              need[i][j]=max[i][j]-alloc[i][j];  
            }
            f[i]=0;
        }
    }

    void compare(){
        int ind=0;
       for(int i=0;i<n;i++){
        if(!f[i]){
          int canAlloc=1;
         for(int j=0;j<m;j++){
             if(need[i][j]>avail[j]){
              canAlloc=0;
              break;
             }
         }
         if(canAlloc){
            ans[ind++]=i;
            for(int j=0;j<m;j++)
                avail[j]+=alloc[i][j];
            f[i]=1;
            i=-1;
         }
        }
       }  
    }

    void main(){
        needFind();
        compare();
        printf("Safe sequence \n");
        for(int i=0;i<n;i++){
           printf("p%d",ans[i]);
           if(i<n-1)
            printf("-->");
        }
    }