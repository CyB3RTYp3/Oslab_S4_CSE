#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.id>
#include<string.h>

void main(){
    int shmid;
    void *shared_memory;
    char buff[100];

    shmid=shmget((key_t)2345,1024,0666);
    printf("the id of shared memory %d \n",shmid);

    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at %p \n",shared_memory);

    printf("data read from shared memory is %s",(char*)shared_memory);
}