#include<stdio.h>
#include<unistd.h>

void main(){
  int p[2],i,ret;
  for(i=0;;i++){
    ret=pipe(p);
    if(ret==-1){
      break;
    }
  }
  printf("Maximum no. of pipe : %d\n",i);
}