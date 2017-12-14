# Trabalho Algoritmos Paralelos

* Professor: Henrique Mongelli
* Aluno1: Gabriel Escobar Paes  | 2014.1907.021-5
* Aluno2: Lucas Barbosa Rocha   | 2014.1907.013-4
* Algoritmo: Multiplicação de matriz - FOX

# Algoritmo

Entrada: Matriz A e B com dimensões NXN
Saída: Matriz A*B multiplicada em cada nó

* Passo 0
	Envie os dados da matriz B para os p processadores
* Para stage = 0 até N Faça:
* Passo 1
	Envie o elemento (stage+linha)%N para os p processadores de cada linha
* Passo 2
	Realize a soma das multiplicações das matrizes nos p processadores
* Passo 3
	Cada p processador manda os seus dados da matriz B para o processador para o processador acima.

# Complexidade
	
* Passo 0 - Comunicação dos N dados da matriz B
* Passo 1 - Comunicação dos N dados da Matriz A (representando uma diagonal)
* Passo 2 - Computação para multiplicar os sqrt(p)*sqrt(p) para multplicar a matriz A e B
* Passo 3 - Comunicação dos N dados para rotacionar a matriz B

# Espaço

* Matriz A - N*N espaço
* Matriz B - N*N espaço
* Matriz C - sqrt(p)*sqrt(p) Espaço

# Resultados

* Tempo - TODO

