#include<stdio.h>
int main(){
    
    if(fork()>0){
    printf("\nParent");
    sleep(20);
    }

return 0;
}