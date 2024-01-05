#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h> 


int main(){

  char a[100];
  void *shared_memory; 
  int shmid;
  shmid=shmget((key_t)8734,1024,0666|IPC_CREAT);
  printf("key of shared memory segment is %d \n",shmid);
  shared_memory=shmat(shmid,NULL,0);
  printf("memory attached is %p \n",shared_memory);
  printf("Enter the data");
  scanf("%[^\n]",a);
  strcpy(shared_memory,a);
  printf("data in : %s \n",(char *)shared_memory);
}