#include <stdio.h>
#include <pthread.h>

typedef struct {
    double balance;
    pthread_mutex_t lock;
} BankAccount;

BankAccount account;

void withdraw(double amount) {
    pthread_mutex_lock(&account.lock);
    if (account.balance >= amount) {
        account.balance -= amount;
        printf("Saque de %.2f realizado com sucesso. Saldo restante: %.2f\n", amount, account.balance);
    } else {
        printf("Saque de %.2f falhou. Saldo insuficiente: %.2f\n", amount, account.balance);
    }
    pthread_mutex_unlock(&account.lock);
}

void deposit(double amount) {
    pthread_mutex_lock(&account.lock);
    account.balance += amount;
    printf("Depósito de %.2f realizado com sucesso. Novo saldo: %.2f\n", amount, account.balance);
    pthread_mutex_unlock(&account.lock);
}

void *thread_function(void *arg) {
    for (int i = 0; i < 5; i++) {
        withdraw(10.0); 
        deposit(5.0);  
    }
    pthread_exit(NULL);
}

int main() {
    account.balance = 100.0;
    pthread_mutex_init(&account.lock, NULL);

    pthread_t threads[2];

    for (int i = 0; i < 2; i++) {
        int status = pthread_create(&threads[i], NULL, thread_function, NULL);
        if (status != 0) {
            printf("Erro ao criar a thread %d\n", i);
            return 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&account.lock);

    printf("Saldo final da conta: %.2f\n", account.balance);

    return 0;
}

