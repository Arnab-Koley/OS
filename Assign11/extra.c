#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <errno.h>

int main() {
    int semid, shmid, msgid, key, flag = IPC_CREAT | 0666;

    key = (key_t) 0x40;

    semid = semget(key, 1, flag);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }
    printf("Created semaphore with id: %d\n", semid);

    shmid = shmget(key, 1024, flag);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    printf("Created shared memory with id: %d\n", shmid);

    msgid = msgget(key, flag);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }
    printf("Created message queue with id: %d\n", msgid);

    return 0;
}
