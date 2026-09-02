/* Exercicio 2 - produtores e consumidores sobre um buffer compartilhado
 * Rode com: ./ex2 2 2      (2 produtores, 2 consumidores)
 *
 * Os usleep() alargam a janela entre ler "ocupadas" e escrever de
 * volta.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define CAPACIDADE 5
#define VOLTAS     10
#define MAX_THREADS 32

int buffer[CAPACIDADE];
int ocupadas = 0;
int proximo_item = 100;

typedef struct { char nome[16]; } arg_t;

void *produtor(void *arg) {
    arg_t *a = (arg_t *)arg;
    for (int k = 0; k < VOLTAS; k++) {
        int pos = ocupadas;              /* le */
        if (pos < CAPACIDADE) {
            usleep(1000);                /* janela */
            buffer[pos] = proximo_item++;
            ocupadas = pos + 1;          /* escreve */
            printf("%s PRODUZIU item %d na posicao %d\n", a->nome, buffer[pos], pos);
        }
        usleep(1000);
    }
    return NULL;
}

void *consumidor(void *arg) {
    arg_t *a = (arg_t *)arg;
    for (int k = 0; k < VOLTAS; k++) {
        int pos = ocupadas - 1;          /* le */
        if (pos >= 0) {
            usleep(1000);                /* janela */
            ocupadas = pos;              /* escreve */
            printf("%s CONSUMIU item %d da posicao %d\n", a->nome, buffer[pos], pos);
        }
        usleep(1000);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "uso: %s <produtores> <consumidores>\n", argv[0]);
        return 1;
    }
    int np = atoi(argv[1]), nc = atoi(argv[2]);
    if (np + nc > MAX_THREADS) return 1;

    pthread_t t[MAX_THREADS];
    arg_t args[MAX_THREADS];
    int total_threads = 0;

    /* TODO (2.4): crie np threads produtoras e nc consumidoras.
       Cada uma recebe o endereco do SEU proprio args[], preenchido com
       o nome "prod-1", "prod-2", "cons-1", ... (use snprintf).
       Acumule total_threads. Depois faca o join de todas. */

    printf("threads criadas: %d\n", total_threads);
    printf("ocupadas ao final: %d\n", ocupadas);
    return 0;
}
