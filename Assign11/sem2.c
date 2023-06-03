// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<sys/ipc.h>


// void main(){
//         int semid,key,nsem,i;
//         key=(key_t)0x30;
//         for(i=0;;i++){
//                 nsem=i+1;
//                 semid=semget(key,nsem,IPC_CREAT|0666);
//                 if(semid>0){
//                         printf("\nCreated semaphore with id : %d",semid);
//                 }
//                 else{
//                         printf("\nMaximum number of sub-semaphore : %d\n",i);
//                         exit(0);
//                 }
//                 semctl(semid,0,IPC_RMID,0);
//         }     
// }


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    int semid, nsem, i;
    key_t key;

    key = ftok(".", 'A'); // Generate a unique key

    for (i = 0;; i++) {
        nsem = i + 1;
        semid = semget(key, nsem, IPC_CREAT | 0666);
        if (semid > 0) {
            printf("\nCreated semaphore with id: %d", semid);
        } else {
            printf("\nMaximum number of sub-semaphore: %d\n", i);
            exit(0);
        }
        semctl(semid, 0, IPC_RMID, 0);
    }

    return 0;
}
