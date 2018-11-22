# Trabalho Algoritmos Paralelos

* Professor: Henrique Mongelli
* Aluno1: Gabriel Escobar Paes  | 2014.1907.021-5
* Aluno2: Lucas Barbosa Rocha   | 2014.1907.013-4
* Algoritmo: Multiplicação de matriz - FOX

# Algoritmo

* Entrada: Matriz A e B com dimensões N por N, com N >= 2
* Saída: Matriz A*B multiplicada em cada nó, e também escrita em um arquivo "saida.txt"

# Passos

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
my_rank 0 Tempo:0.000262
my_rank 1 Tempo:0.919602
my_rank 2 Tempo:0.916202
my_rank 3 Tempo:0.919730

```

Teste 2

```
my_rank 0 Tempo:0.000251
my_rank 1 Tempo:0.703180
my_rank 2 Tempo:0.702366
my_rank 3 Tempo:0.703756


```

Teste 3

```
my_rank 0 Tempo:0.000276
my_rank 1 Tempo:1.302438
my_rank 2 Tempo:1.302913
my_rank 3 Tempo:1.303631

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
my_rank 0 Tempo:0.017231
my_rank 1 Tempo:0.541772
my_rank 2 Tempo:0.572907
my_rank 3 Tempo:0.590376
my_rank 4 Tempo:0.534576
my_rank 5 Tempo:0.665428
my_rank 6 Tempo:0.526846
my_rank 7 Tempo:0.561853
my_rank 8 Tempo:0.551429
```

Teste 2

```
my_rank 0 Tempo:0.028347
my_rank 1 Tempo:2.271966
my_rank 2 Tempo:2.275882
my_rank 3 Tempo:2.219697
my_rank 4 Tempo:2.278901
my_rank 5 Tempo:2.250439
my_rank 6 Tempo:2.265455
my_rank 7 Tempo:2.282048
my_rank 8 Tempo:2.273138

```

Teste 3

```
my_rank 0 Tempo:0.036523
my_rank 1 Tempo:1.351665
my_rank 2 Tempo:1.298476
my_rank 3 Tempo:1.337190
my_rank 4 Tempo:1.298160
my_rank 5 Tempo:1.337135
my_rank 6 Tempo:1.330457
my_rank 7 Tempo:1.342602
my_rank 8 Tempo:1.344474

```

* 4x4

Matriz A

```
1.0 2.0 3.0 4.0
5.0 5.0 5.0 5.0
6.0 6.0 6.0 6.0
4.0 3.0 2.0 1.0
```

Matriz B

```
2.0 2.0 2.0 2.0
3.0 3.0 3.0 3.0
4.0 4.0 5.0 5.0
6.0 7.0 8.0 9.0
```

Matriz C (resultado do programa)

```
44.00  48.00   55.00   59.00
75.00  80.00   90.00   95.00
90.00  96.00  108.00  114.00
31.00  32.00   35.00   36.00
```

Tempo em milisegundos

Teste 1

```
my_rank 0  Tempo:0.032814
my_rank 1  Tempo:0.214414
my_rank 2  Tempo:0.219117
my_rank 3  Tempo:0.214498
my_rank 4  Tempo:0.216768
my_rank 5  Tempo:0.216181
my_rank 6  Tempo:0.216065
my_rank 7  Tempo:0.209774
my_rank 8  Tempo:0.215035
my_rank 9  Tempo:0.219867
my_rank 10 Tempo:0.206416
my_rank 11 Tempo:0.212619
my_rank 12 Tempo:0.196677
my_rank 13 Tempo:0.217168
my_rank 14 Tempo:0.211556
my_rank 15 Tempo:0.201466
```

Teste 2

```
my_rank 0  Tempo:0.033356
my_rank 1  Tempo:1.503657
my_rank 2  Tempo:1.489452
my_rank 3  Tempo:1.468415
my_rank 4  Tempo:1.478522
my_rank 5  Tempo:1.510344
my_rank 6  Tempo:1.420252
my_rank 7  Tempo:1.448079
my_rank 8  Tempo:1.486566
my_rank 9  Tempo:1.465156
my_rank 10 Tempo:1.399998
my_rank 11 Tempo:1.489101
my_rank 12 Tempo:1.403494
my_rank 13 Tempo:1.441555
my_rank 14 Tempo:1.460551
my_rank 15 Tempo:1.479373
```
Teste 3

```
my_rank 0  Tempo:0.038590
my_rank 1  Tempo:0.220730
my_rank 2  Tempo:0.185485
my_rank 3  Tempo:0.191070
my_rank 4  Tempo:0.191790
my_rank 5  Tempo:0.207255
my_rank 6  Tempo:0.188730
my_rank 7  Tempo:0.193289
my_rank 8  Tempo:0.193238
my_rank 9  Tempo:0.219896
my_rank 10 Tempo:0.182279
my_rank 11 Tempo:0.200736
my_rank 12 Tempo:0.203801
my_rank 13 Tempo:0.181487
my_rank 14 Tempo:0.202386
my_rank 15 Tempo:0.209306
```
