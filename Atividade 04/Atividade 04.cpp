#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void *calculate_factorial(void *arg) {
    int n = *((int *)arg);
    long long result = factorial(n);
    printf("Fatorial de %d = %lld\n", n, result);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int numbers[NUM_THREADS] = {5, 7, 3, 8};

    for (int i = 0; i < NUM_THREADS; i++) {
        int *arg = (int *)malloc(sizeof(int));
        *arg = numbers[i];
        int status = pthread_create(&threads[i], NULL, calculate_factorial, arg);
        if (status != 0) {
            printf("Erro ao criar a thread %d\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
    return 0;
}

