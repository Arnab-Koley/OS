#include<stdio.h>
#include<unistd.h>

int main(){
    
    int k;
    k=fork();

    if(k<0){
        printf("\nFork() failed\n");
    }

    if(k==0){
        printf("\nChild process : pid=%d",getpid());
        printf("\nParent process [In child block | before sleep] : pid=%d\n",getppid());
        sleep(10);
        printf("\nChild process : pid=%d",getpid());
        printf("\nParent process [In child block | after sleep] : pid=%d\n",getppid());
    }

    if(k>0){
        printf("\nParent process [In parent block] : pid=%d\n",getpid());
    }

return 0;
}