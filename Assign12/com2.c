#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void main(){

  int p1[2],p2[2],ret1,ret2,pid;

  char pipe1wmsg[20]="Hi";
  char pipe2wmsg[20]="Hello";
  char readmsg[20];

  ret1=pipe(p1);
  if(ret1==-1){
    printf("\n1st pipe creation failed\n");
    exit(0);
  }
  ret2=pipe(p2);
  if(ret2==-1){
    printf("\n2nd pipe creation failed\n");
    exit(0);
  }

  pid=fork();

  if(pid!=0){

    close(p1[0]);
    close(p2[1]);
    printf("In parent --> msg to pipe1 : %s\n",pipe1wmsg);
    write(p1[1],pipe1wmsg,sizeof(pipe1wmsg));
    read(p2[0],readmsg,sizeof(readmsg));
    printf("Parent read form pipe2 : %s\n",readmsg);

  }

  else{

    close(p1[1]);
    close(p2[0]);
    printf("In Child --> msg to pipe2 : %s\n",pipe2wmsg);
    write(p2[1],pipe2wmsg,sizeof(pipe2wmsg));
    read(p1[0],readmsg,sizeof(readmsg));
    printf("Child read form pipe1 : %s\n",readmsg);
  }
}