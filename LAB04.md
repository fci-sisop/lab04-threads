# Lab 4 - Threads

Cada exercício tem um `TODO` de cinco a dez linhas. O script `rodar.sh`
executa tudo e imprime o resumo que as perguntas usam.

```
make
bash rodar.sh
```

Escreva as respostas **neste arquivo mesmo**, nos campos abaixo. 

---

## 1. Identidade da thread (`ex1_identidade.c`)

`./ex1 5` deveria imprimir os índices 0 a 4, um por thread, em qualquer ordem.

**TODO 1** As cinco threads recebem o endereço da mesma variável `i`, que o
`main` continua alterando. Faça cada uma receber o seu próprio valor.

**1.1** No resumo do `rodar.sh` aparece um índice que não deveria existir.
Qual é, e de onde ele vem?

> 

---

## 2. Produtores e consumidores (`ex2_papeis.c`)

Dois produtores e dois consumidores sobre um vetor de 5 posições, sem nenhuma
proteção de acesso.

**TODO 2** No `main`, crie as threads a partir dos dois argumentos da linha de
comando, dando a cada uma o nome do seu papel (`prod-1`, `cons-1`, ...).

**2.1** O resumo mostra itens consumidos duas vezes. Se cada posição foi
escrita uma vez só, como o mesmo item sai duas vezes?

> 

---

## 3. O contador (`ex3_contador.c`)

Quatro threads somando 1 um milhão de vezes cada.

**TODO 3** Faça cada thread contar também num contador local seu e devolvê-lo
no `return`. No `main`, recolha os quatro retornos pelo segundo argumento do
`pthread_join` e some em `soma_dos_locais`.

**3.1** O total compartilhado varia entre execuções e a soma dos locais não.
Por quê?

> 

**3.2** Por que nenhuma execução dá **mais** que 4000000?

> 

---

## 4. Recursos escassos (`ex4_recursos.c`)

Duas classes de recurso, duas unidades de cada, seis threads. Cada thread
precisa de A **e** B ao mesmo tempo para concluir uma unidade de trabalho.

**TODO 4** Preencha os cinco pontos marcados no `trabalhador()` com chamadas
a `logar()`, que já está pronta. Vocabulário: `SOLICITA`, `OBTEM`, `LIBERA`.
É o mesmo vocabulário do Projeto 1, que registra os eventos num formato de
campos separados por `;`.

**4.1** O log mostra linhas `OBTEM ... restam -1`. O que significa restarem
-1 unidades de um recurso que tem 2?

> 

**4.2** Entre pegar A e pegar B a thread espera 50 ms segurando A. Se metade
das threads pegasse B antes de A, o que poderia acontecer?

> 

---

## Glossário

Complete com uma frase por termo, com base no comportamento observado nos exercícios.

- **thread**:
- **dado compartilhado**:
- **produtor e consumidor**:
- **condição de corrida**:
- **seção crítica**:
- **recurso escasso**:

---

## Entrega

Este arquivo preenchido e os quatro `TODO` implementados.

Nota sobre os `usleep()` dos exercícios 2 e 4: eles alargam a janela entre ler
um valor compartilhado e escrevê-lo de volta, onde o defeito já existe. Sem
eles o erro aparece uma vez a cada muitas execuções, o que explica bugs de
concorrência que passam pelo teste e aparecem em produção, que vimos em aula.
