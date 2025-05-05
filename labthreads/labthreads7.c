#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 4

int is_child_turn = 1;  // 1 - очередь дочерних, 0 - очередь главного
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

char* words[] = {"cat", "dog", "bird", "fish", "apple", "tree", "house", "car"};

void clean(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("Thread %ld: cleanup before termination\n", (long)arg);
    pthread_mutex_unlock(&mutex);
}

void* thread_func(void* arg) {
    long thread_num = (long)arg;
    srand(time(NULL) + thread_num);
    
    pthread_cleanup_push(clean, arg);
    
    for (int i = 0; i < 3; i++) {
        pthread_mutex_lock(&mutex);
        
        // Ждем, пока не наступит очередь дочерних потоков
        while (!is_child_turn) {
            pthread_cond_wait(&cond, &mutex);
        }
        
        int word_index = rand() % 8; 
        printf("Thread %ld: %s\n", thread_num, words[word_index]);
        
        // Передаем очередь главному потоку
        is_child_turn = 0;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    
    pthread_cleanup_pop(0);
    pthread_mutex_lock(&mutex);
    printf("Thread %ld: finished normally\n", thread_num);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    srand(time(NULL));
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*)(long)i);
    }
    
    for (int i = 0; i < 3 * NUM_THREADS; i++) {  // Главный поток работает столько же раз
        pthread_mutex_lock(&mutex);

        // Ждем, пока не наступит очередь главного потока
        while (is_child_turn) {
            pthread_cond_wait(&cond, &mutex);
        }
        
        printf("Main thread: message %d\n", i + 1);
        
        // Передаем очередь дочерним потокам
        is_child_turn = 1;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    
    printf("Cancelling threads...\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_cancel(threads[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads finished\n");
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    
    return 0;
}