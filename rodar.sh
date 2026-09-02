#!/bin/bash
# Roda os quatro exercicios e resume. Nao e preciso contar nada a mao.
make >/dev/null || exit 1

echo "=== ex1: 10 execucoes com 5 threads (esperado: 0 1 2 3 4) ==="
for i in $(seq 10); do ./ex1 5 | awk '{printf "%s ", $4}'; echo; done | sort | uniq -c | sort -rn

echo
echo "=== ex2: ./ex2 2 2, 3 execucoes (esperado 20 e 20) ==="
for i in 1 2 3; do
  ./ex2 2 2 > /tmp/ex2.out 2>/dev/null
  rep=$(grep CONSUMIU /tmp/ex2.out | awk '{print $3}' | sort | uniq -d | wc -l)
  echo "PRODUZIU $(grep -c PRODUZIU /tmp/ex2.out)  CONSUMIU $(grep -c CONSUMIU /tmp/ex2.out)  itens consumidos 2x: $rep  $(grep 'ocupadas ao final' /tmp/ex2.out)"
done

echo
echo "=== ex3: 10 execucoes (esperado 4000000 nos dois) ==="
for i in $(seq 10); do ./ex3; done > /tmp/ex3.out
echo "total compartilhado -> menor $(grep 'total' /tmp/ex3.out | awk '{print $3}' | sort -n | head -1)  maior $(grep 'total' /tmp/ex3.out | awk '{print $3}' | sort -n | tail -1)  exatos $(grep -c 'total compartilhado: 4000000' /tmp/ex3.out) de 10"
echo "soma dos locais     -> valores distintos: $(grep 'locais' /tmp/ex3.out | awk '{print $4}' | sort -u | tr '\n' ' ')"

echo
echo "=== ex4: 3 execucoes ==="
for i in 1 2 3; do
  ./ex4 > /tmp/ex4.out
  echo "linhas de log: $(grep -c 'Thread' /tmp/ex4.out)  OBTEM com restante negativo: $(grep -c 'OBTEM.*restam -' /tmp/ex4.out)"
done
