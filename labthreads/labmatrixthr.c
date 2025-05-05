#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<time.h>

#define MAX_SIZE 2500

int N;
int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
int threads;  // Количество потоков

void* multiply(void* arg) {
    long thread_id = (long)arg;
    int rows_per_thread = N / threads;
    int start_row = thread_id * rows_per_thread;
    int end_row = (thread_id == threads - 1) ? N : start_row + rows_per_thread;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return NULL;
}

int main(int argc, char* argv[]) {


 
    printf("Введите размер матрицы \n");
    scanf("%d", &N);

    printf("Введите количество потоков \n");
    scanf("%d", &threads);
    time_t t0=time(0);


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = B[i][j] = 1;
        }
    }


    pthread_t thread_ids[threads];

    for (long i = 0; i < threads; i++) {
        pthread_create(&thread_ids[i], NULL, multiply, (void*)i);
    }

    for (int i = 0; i < threads; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    time_t t1=time(0);
    if (N < 5) {
        printf("Матрица A:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) printf("%d ", A[i][j]);
            printf("\n");
        }
        
        printf("\nМатрица B:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) printf("%d ", B[i][j]);
            printf("\n");
        }
        
        printf("\nРезультат C:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) printf("%d ", C[i][j]);
            printf("\n\n\n");
        }
    }
    double time_in_seconds = difftime(t1, t0);
    printf("%lf", time_in_seconds);

    return 0;
}