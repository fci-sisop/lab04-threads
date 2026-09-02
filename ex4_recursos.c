/* Exercicio 4 - recursos escassos
 * Rode com: ./ex4
 * Duas classes de recurso, 2 unidades de cada, 6 threads que precisam
 * das duas ao mesmo tempo para concluir uma unidade de trabalho.
 *
 * Os usleep() alargam a janela entre verificar se ha unidade livre e
 * tomar essa unidade.
 */
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

int disponiveis_A = 2;
int disponiveis_B = 2;

static struct timeval inicio;

/* Formato: [ms.us] Thread N EVENTO o recurso X, restam K
   O tempo e contado desde o inicio do programa.

   No Projeto 1 o log carrega a mesma informacao, mas em campos
   separados por ';', que e o formato que o script de correcao le:
       52;t-3;SOLICITA;A;2 */
void logar(long id, const char *evento, const char *objeto, int restam) {
    struct timeval agora;
    gettimeofday(&agora, NULL);
    long us = (agora.tv_sec - inicio.tv_sec) * 1000000L
            + (agora.tv_usec - inicio.tv_usec);
    printf("[%3ld.%03ld] Thread %ld %s o recurso %s, restam %d\n",
           us / 1000, us % 1000, id, evento, objeto, restam);
}

void *trabalhador(void *arg) {
    long id = (long)arg;

    /* TODO (4.3): escreva uma chamada a logar() em cada um dos cinco
       pontos marcados abaixo.
       Vocabulario: SOLICITA, OBTEM, LIBERA. Objeto: "A" ou "B".
       O ultimo argumento e quantas unidades restam (disponiveis_A ou _B).
       Exemplo: logar(id, "SOLICITA", "A", disponiveis_A);
       imprime: [ 52.130] Thread 3 SOLICITA o recurso A, restam 2 */

    /* (1) logar SOLICITA A */
    while (disponiveis_A <= 0) usleep(1000);   /* verifica */
    usleep(2000);                              /* janela */
    disponiveis_A--;                           /* toma */
    /* (2) logar OBTEM A */

    usleep(50000);   /* segura A enquanto tenta B */

    /* (3) logar SOLICITA B */
    while (disponiveis_B <= 0) usleep(1000);
    usleep(2000);
    disponiveis_B--;
    /* (4) logar OBTEM B */

    usleep(10000);   /* unidade de trabalho concluida */

    disponiveis_B++;
    disponiveis_A++;
    /* (5) logar LIBERA A e depois LIBERA B */
    return NULL;
}

int main(void) {
    pthread_t t[6];
    gettimeofday(&inicio, NULL);
    for (long i = 0; i < 6; i++) pthread_create(&t[i], NULL, trabalhador, (void *)i);
    for (int i = 0; i < 6; i++) pthread_join(t[i], NULL);
    printf("fim. A=%d B=%d\n", disponiveis_A, disponiveis_B);
    return 0;
}
