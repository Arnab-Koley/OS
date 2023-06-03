#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void inthandler(int sig_no){
    signal(SIGINT,inthandler);
    printf("\n interrupt signal handled by child");
}

void quithandler(int sig_no){
    signal(SIGQUIT,quithandler);
    printf("\n quit signal handled by child");
}

void huphandler(int sig_no){
    signal(SIGHUP,huphandler);
    printf("\n hang up signal handled by child");
}


void main(){

    int pid;
    if((pid=fork())<0){
        perror("Child process could not be created");
        exit(1);
    }
    if(pid==0){
        signal(SIGINT,inthandler);
        signal(SIGQUIT,quithandler);
        signal(SIGHUP,huphandler);
        for(;;);
    }
    else{

        printf("pid is=%d\n",pid);

        printf("Sending SIGINT Signal\n");
        kill(pid,SIGINT);
        sleep(5);

        printf("Sending SIGQUIT Signal\n");
        kill(pid,SIGQUIT);
        sleep(5);

        printf("Sending SIGHUP Signal\n");
        kill(pid,SIGHUP);
        sleep(5);

        printf("Sending SIGSTOP Signal\n");
        kill(pid,SIGSTOP);
        sleep(5);

    }
}