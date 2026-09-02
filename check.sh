#!/bin/bash
# Verificacao de entrega: compila e confere o conserto do exercicio 1.
falhas=0

make clean >/dev/null 2>&1
if make >/dev/null 2>&1; then echo "OK   compilacao dos quatro exercicios"
else echo "FALHA compilacao"; exit 1; fi

saida=$(./ex1 8 | grep -o '[0-9]*$' | sort -n | tr '\n' ' ')
if [ "$saida" = "0 1 2 3 4 5 6 7 " ]; then
  echo "OK   ex1 imprime os oito indices exatamente uma vez"
else
  echo "FALHA ex1 com 8 threads imprimiu: $saida"; falhas=1
fi

if [ "$(./ex2 2 2 | grep -c 'threads criadas: 4')" = "1" ]; then
  echo "OK   ex2 cria as threads a partir dos argumentos"
else echo "FALHA ex2 nao criou 4 threads com './ex2 2 2'"; falhas=1; fi

if [ "$(./ex3 | grep -c 'soma dos locais:     4000000')" = "1" ]; then
  echo "OK   ex3 recolhe os contadores locais pelo join"
else echo "FALHA ex3: soma dos locais nao deu 4000000"; falhas=1; fi

if [ "$(./ex4 | grep -c 'SOLICITA o recurso')" -ge 12 ]; then
  echo "OK   ex4 emite o log no vocabulario do projeto"
else echo "FALHA ex4: faltam linhas SOLICITA no log"; falhas=1; fi

if [ -s LAB04.md ]; then echo "OK   LAB04.md presente"
else echo "FALHA LAB04.md ausente ou vazio"; falhas=1; fi

exit $falhas
