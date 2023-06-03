#include<stdio.h>
#include<unistd.h>

int main(){
    int pid;
    pid=fork();
    if(pid==0){
        printf("I am child and my pid is %d\n", getpid());
        printf("I am parent and my pid is %d\n", getppid());
    }
    
return 0;
}