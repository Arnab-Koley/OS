#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define N 10
int counter=0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void * count(void *){

	printf("Thread id : %d\n", pthread_self());
	pthread_mutex_lock(&mutex1);
	counter++;
	pthread_mutex_unlock(&mutex1);
}


void main(){

	pthread_t thread[N];
	int ret, i;

	for(i=0;i<N;i++){
		ret=pthread_create(&thread[i], NULL, count, NULL);
	}
	for(i=0;i<N;i++){
		pthread_join(thread[i], NULL);
	}
	printf("Final counter = %d\n",counter);
	exit(0);
}

