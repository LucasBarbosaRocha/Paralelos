# Trabalho Algoritmos Paralelos

* Professor: Henrique Mongelli
* Aluno1: Gabriel Escobar Paes  | 2014.1907.021-5
* Aluno2: Lucas Barbosa Rocha   | 2014.1907.013-4
* Algoritmo: Multiplicação de matriz - FOX

# Algoritmo

Entrada: Matriz A e B com dimensões N por N, com N >= 2
Saída: Matriz A*B multiplicada em cada nó, e também escrita em um arquivo "saida.txt"

* Passo 0
	Envie os dados da matriz B para os p processadores
* Para stage = 0 até N Faça:
* Passo 1
	Envie o elemento (stage+linha)%N para os p processadores de cada linha
* Passo 2
	Realize a soma das multiplicações das matrizes nos p processadores
* Passo 3
	Cada p processador manda os seus dados da matriz B para o processador acima.
* Passo 4
	Cada p processaor envia seus dados para o processador 0 e o processador 0 escreve os resultantes no arquivo "saida.txt", representando a matriz C

# Complexidade
	
* Passo 0 - Comunicação dos N*N dados da matriz B
* Passo 1 - Comunicação dos N dados da Matriz A (representando uma diagonal) para p processadores
* Passo 2 - Computação para multiplicação dos dados nos p processadores
* Passo 3 - Comunicação dos N dados para rotacionar a matriz B
* Passo 4 - Comunicação dos dados nos P processadores para o processador 0
* Passo 4 - Computação no processador 0 para escrever os dados recebidos no arquivo de saida

# Espaço

* Matriz A - N*N espaço
* Matriz B - N*N espaço
* Matriz C - sqrt(p)*sqrt(p) Espaço para processamento CGM, mas nesse programa funciona para um elemento, então a matriz C tem o tamanho de um float

# Resultados

* Tempo

* 2x2 - 4 processadores

Matriz A

```
1.0 2.0
3.0 4.0
```

Matriz B

```
4.0 3.0
2.0 1.0
```

Matriz C (resultado do programa)

```
8.00   5.00
20.00  13.00
```

Tempo em milisegundos

Teste 1

```
my_rank 0 Tempo:0.000309
my_rank 1 Tempo:4.668263
my_rank 2 Tempo:4.669016
my_rank 3 Tempo:4.630237
```

Teste 2

```
my_rank 0 Tempo:0.000337
my_rank 1 Tempo:3.014637
my_rank 2 Tempo:3.014686
my_rank 3 Tempo:3.013326

```

Teste 3

```
my_rank 0 Tempo:0.000312
my_rank 1 Tempo:5.436815
my_rank 2 Tempo:5.454038
my_rank 3 Tempo:5.452379

```

* 3x3 - 9 processadores


Matriz A

```
1.0 2.0 3.0
4.0 5.0 6.0
7.0 8.0 9.0
```

Matriz B

```
2.0 2.0 2.0
3.0 3.0 3.0
1.0 3.0 2.0
```

Matriz C (resultado do programa)

```
11.00 17.00 14.00
29.00 41.00 35.00
47.00 65.00 56.00
```

Tempo em milisegundos

Teste 1

```
my_rank 0 Tempo:0.015265
my_rank 1 Tempo:4.119996
my_rank 2 Tempo:4.081252
my_rank 3 Tempo:4.088579
my_rank 4 Tempo:4.000684
my_rank 5 Tempo:4.126090
my_rank 6 Tempo:4.071070
my_rank 7 Tempo:4.001786
my_rank 8 Tempo:3.987092
```

Teste 2

```
my_rank 0 Tempo:0.017556
my_rank 1 Tempo:6.116106
my_rank 2 Tempo:6.232290
my_rank 3 Tempo:6.175569
my_rank 4 Tempo:6.116046
my_rank 5 Tempo:6.192252
my_rank 6 Tempo:6.186414
my_rank 7 Tempo:6.170671
my_rank 8 Tempo:6.160474
```

Teste 3

```
my_rank 0 Tempo:0.037726
my_rank 1 Tempo:5.357163
my_rank 2 Tempo:5.234567
my_rank 3 Tempo:5.284559
my_rank 4 Tempo:5.346505
my_rank 5 Tempo:5.483498
my_rank 6 Tempo:5.357879
my_rank 7 Tempo:5.428872
my_rank 8 Tempo:5.237102
```

* 4x4




