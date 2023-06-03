#include<stdio.h>
#include<unistd.h>
#define MSGSIZE 17

void main(){

  int p[2],i;

  char* msg1="This is message 1";
  char* msg2="This is message 2";
  char* msg3="This is message 3";

  char buffer[MSGSIZE];
  pipe(p);

  write(p[1],msg1,MSGSIZE);
  write(p[1],msg2,MSGSIZE);
  write(p[1],msg3,MSGSIZE);

  for(i=0;i<3;i++){
    read(p[0],buffer,MSGSIZE);
    printf("The message from inside buffer is : %s\n",buffer);
  }
}