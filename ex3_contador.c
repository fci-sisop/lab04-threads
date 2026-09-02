/* Exercicio 3 - o contador
 * Rode com: ./ex3
 * Esperado: 4000000 em total. Rode varias vezes e compare.
 */
#include <stdio.h>
#include <pthread.h>

#define THREADS 4
#define INCREMENTOS  1000000

long total = 0;          /* compartilhado por todas as threads */

void *soma(void *arg) {
    (void)arg;
    /* TODO (3.4): declare um contador LOCAL desta thread, inicializado em 0.
       Incremente os dois dentro do laco: o local e o total compartilhado.
       Devolva o contador local com: return (void *)local; */
    for (long k = 0; k < INCREMENTOS; k++) {
        total = total + 1;
    }
    return NULL;
}

int main(void) {
    pthread_t t[THREADS];
    long soma_dos_locais = 0;

    for (int i = 0; i < THREADS; i++) pthread_create(&t[i], NULL, soma, NULL);

    for (int i = 0; i < THREADS; i++) {
        /* TODO (3.4): recolha o retorno da thread com o segundo argumento
           do pthread_join e acumule em soma_dos_locais. */
        pthread_join(t[i], NULL);
    }

    printf("total compartilhado: %ld\n", total);
    printf("soma dos locais:     %ld\n", soma_dos_locais);
    return 0;
}
