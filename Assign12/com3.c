#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){

  int p[2],ret,pid;
  char pipewmsg[20]="Hi";
  char readmsg[20];

  ret=pipe(p);

  if(ret==-1){
    printf("\nPipe creation failed\n");
    exit(0);
  }

  pid=fork();

  if(pid!=0){
    printf("In parent --> msg to pipe : %s\n",pipewmsg);
    write(p[1],pipewmsg,sizeof(pipewmsg));
  }

  else{   
    read(p[0],readmsg,sizeof(readmsg));
    printf("Child read form pipe : %s\n",readmsg);
  }
}