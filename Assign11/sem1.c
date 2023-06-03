#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>

void main(){

        int semid, shmid, msgid, key, flag=IPC_CREAT|0666;

        key=(key_t)0x40;

        semid=semget(key,1,flag);
        shmid=shmget(key,1024,flag);
        msgid=msgget(key,flag);

        if(semid==-1){
            perror("\nSemget\n");
            exit(1);
        }
        if(shmid==-1){
            perror("\nShmget\n");
            exit(1);
        }
        if(msgid==-1){
            perror("\nMsgge\n");
            exit(1);
        }
        else{
            printf("\nCreated semaphore with id : %d\nCreated shared memory with id : %d\nCreated message segment with id : %d\n",semid,shmid,msgid);
        }
}