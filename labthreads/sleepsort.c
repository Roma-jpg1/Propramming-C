#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void* thread_func(void* arg){
    int a=*(int*)arg;
    sleep(a);
    printf("%d ",a);
}
int main(){
    
    int arr[]={4,2,5,8,2,8,9,0};
    int n=sizeof(arr)/sizeof(arr[1]);
    pthread_t threads[n];

    for (int i=0; i<n;i++){
        pthread_create(&threads[i], NULL, thread_func, &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

}