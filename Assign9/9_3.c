#include <windows.h>
#include <stdio.h>

DWORD Sum;

DWORD Summation(LPVOID num){

    DWORD Upper = *(DWORD*)num;
    for(DWORD i=1;i<=Upper;i++){
        Sum+=i; 
    }
    printf("\nInside Summation(), Sum of %d natural numbers = %d",Upper, Sum);
    return 0;
} 

void main(){
    
    DWORD ThreadId;
    HANDLE ThreadHandle;
    int number;

    printf ("Enter number : ");
    scanf("%d",&number);
    ThreadHandle = CreateThread(NULL,0,Summation,&number,0, &ThreadId);

    if(ThreadHandle!=NULL){
        WaitForSingleObject(ThreadHandle,INFINITE);
        CloseHandle(ThreadHandle); 
        printf("\nInside main(), Sum of %d natural numbers = %d\n\n",number, Sum); 
    }
} 