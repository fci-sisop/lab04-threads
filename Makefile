CFLAGS = -Wall -O0 -pthread

all: ex1 ex2 ex3 ex4

ex1: ex1_identidade.c
	gcc $(CFLAGS) -o ex1 ex1_identidade.c
ex2: ex2_papeis.c
	gcc $(CFLAGS) -o ex2 ex2_papeis.c
ex3: ex3_contador.c
	gcc $(CFLAGS) -o ex3 ex3_contador.c
ex4: ex4_recursos.c
	gcc $(CFLAGS) -o ex4 ex4_recursos.c

clean:
	rm -f ex1 ex2 ex3 ex4
