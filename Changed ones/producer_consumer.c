#include<stdio.h>
int mutex=1,full=0,empty=0;

int wait(int s){
    while(s>=0)
     return --s;
}

int signal(int s){
     return ++s;
}

void producer()
{
    mutex=wait(mutex);
    empty=wait(empty);
    full=signal(full);
    printf("produced \n");
    mutex=signal(mutex);
}


void consumer(){
  mutex=wait(mutex);
  full=wait(full);
  empty=signal(empty);
  printf("consumed \n");
  mutex=signal(mutex);
}


int main(){
    int i;
  printf("Enter the size of the buffer\n");
  scanf("%d",&empty);
    do{
        printf("choose one 1)produce 2)consume 3)exit \n");
        scanf("%d",&i);
        switch(i){
          case 1:
              if(mutex==1 && empty!=0)
                producer();
              else
               printf("producer waiting \n");
               break;
          case 2:
               if(mutex==1 && full!=0)
                 consumer();
                else
                 printf("consumer is waiting.... \n");
                 break;
           default :
               printf("exitted \n");
               break;
         }
               
    }while(i<3);
}