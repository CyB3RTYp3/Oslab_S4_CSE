#include<stdio.h>
int mutex=1,empty=0,full=0;
int wait(int s){
    while(s>=0)
     return --s;
}
int signal(int s){
    return ++s;
}
void produce(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);   
    printf("Produced \n");
    mutex=signal(mutex);
}
void consume(){
  mutex=wait(mutex);
  empty=signal(empty);
  full=wait(full);
  printf("consumed \n");
  mutex=signal(mutex);
}
int main(){
    int ch;
  printf("Enter the size of the buffer\n");
  scanf("%d",&empty);
    do{
        printf("choose one 1)produce 2)consume 3)exit \n");
        scanf("%d",&ch);
        switch(ch){
          case 1:
              if(mutex==1 && empty!=0)
                produce();
              else
               printf("producer waiting \n");
               break;
          case 2:
               if(mutex==1 && full!=0)
                 consume();
                else
                 printf("consumer is waiting.... \n");
                 break;
           default :
               printf("exitted \n");
               break;
         }
               
    }while(ch<3);
    return 0;
}