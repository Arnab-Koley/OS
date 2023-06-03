#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	
	int pid,fd;
	
	if((pid=fork())<0){
		printf("Fork failed\n");
		exit(1);
	}
	
	if(mknod("mypipe",010600,0)<0){
		perror("could not create named pipe\n");
	}
	//if(mkfifo("mypipe",0666)<0){
	//	perror("could not create named pipe\n");
	//}
	if(pid==0){
		int j,k=2;
		if((fd=open("mypipe",O_WRONLY))<0){
			printf("Failed to open named pipe");
			exit(2);
		}
		for(j=0;j<10;j++){
			write(fd,&k,sizeof(k));
			k=2*k+1;
		}
	}
	
	else{
		int k,j=0;
		sleep(1);
		if((fd=open("mypipe",O_RDONLY))<0){
			printf("Failed to open named pipe");
			exit(2);
		}
		for(j=0;j<10;j++){
			read(fd,&k,sizeof(k));
			printf("%d\n",k);
		}
	}



}