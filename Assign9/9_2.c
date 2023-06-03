#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *with_loop(void *n){
	int a= *((int *)n),i,sum=0;
	for(i=1;i<=a;i++){
		sum += i;
	}
	printf("\nSum of first %d natural numbers : %d (Thread-1/ Using loop)", a, sum);
}

void *without_loop(void *n){
	int a = *((int*)n), sum=0;
	sum = (a*(a+1))/2;
	printf("\nSum of first %d natural numbers : %d (Thread-2/ Without using loop)", a, sum);
}


void main(){

	pthread_t thread1, thread2;
	int n,ret1, ret2;

	printf("\nEnter the n-th natural number : ");
	scanf("%d", &n);

	ret1 = pthread_create(&thread1, NULL, with_loop, (void*)&n);
	ret2 = pthread_create(&thread2, NULL, without_loop, (void*)&n);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("\n\nThread1 returns : %d\n", ret1);
	printf("Thread2 returns : %d\n", ret2);

	exit(0);
}

