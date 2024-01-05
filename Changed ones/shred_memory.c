#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<sys/shm.h>
 
void main(){

    void *shared;
    char a[100];
    int shmid;
    shmid=shmget((key_t)8796,1024,0666);
    printf("key of shared memory %d \n",shmid);
    shared=shmat(shmid,NULL,0);
    printf("memory attached %p/n",shared);
    printf("data ouput is : %s",(char *)shared);
    }