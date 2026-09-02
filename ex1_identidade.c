/* Exercicio 1 - identidade da thread
 * Compile com: make
 * Rode com:    ./ex1 5
 * Este codigo tem um bug. Rode varias vezes antes de olhar o codigo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *tarefa(void *arg) {
    int id = *(int *)arg;
    printf("sou a thread %d\n", id);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "uso: %s <numero de threads>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    pthread_t t[64];

    for (int i = 0; i < n; i++) {
        /* TODO (1.3): o argumento entregue aqui é o endereco de i, o
           mesmo para todas as threads. Corrija esse bug. */
        pthread_create(&t[i], NULL, tarefa, &i);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}
