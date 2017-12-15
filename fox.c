#include <stdio.h>
#include <string.h> /* For strlen */
#include <mpi.h> /* For MPI functions, etc */
#include <time.h>
const int MAX_TAM = 8;

/*
* Aluno1: Gabriel Escobar Paes  | 2014.1907.021-5
* Aluno2: Lucas Barbosa Rocha   | 2014.1907.013-4
* Algoritmos Paralelos - Henrique Mongelli
* Algoritmo: Multiplicação de matriz - FOX
* Entrada: Duas matrizes A e B com dimensão N*N, com N >= 2
* Saida: Uma matriz C no arquivo saida.txt
*/

int main(void) {
	int comm_sz; /* Number of processes */
	int my_rank; /* My process rank */
	int i, j;
	int linha, destino, n = 0, stage = 0, value, lixo, cont;
	float A[MAX_TAM][MAX_TAM], B[MAX_TAM][MAX_TAM], VB, VA, VC = 0, aux;
	FILE *arq;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	/*clock_t tempo;
	tempo = clock();*/


	/* Passo 0 - Enviar cada elemento da matriz B para n processadores */
	if (my_rank == 0)
	{

		/* Leitura das matrizes A e B e do n */
		lixo = scanf("%d", &n);
		for (i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				lixo = scanf("%f", &aux);
				A[i][j] = aux;
			}
		}
		for (i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				lixo = scanf("%f", &aux);
				B[i][j] = aux;
			}
		}
		/* Fim leitura */

		/* Enviando cada elemento */
		linha = j = 0;
		VB = B[linha][j];
		j++;
		for (i = 1; i < comm_sz; i++)
		{
			MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			MPI_Send(&B[linha][j], 1, MPI_FLOAT, i, 0, MPI_COMM_WORLD);
			if (j == n-1)
			{
				linha++;
				j = 0;
			}else
				j++;

		}
	}else
	{
		MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);		
		MPI_Recv(&VB, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
	/* Passo 0 - Fim */

	for (stage = 0; stage < n; stage++)
	{
		/* Passo 1 - Para cada stage distribuir as diagonais */
		linha = 0;

		if (my_rank == 0)
		{
			j = 0;
			destino = (stage + linha) % n;
			VA = A[linha][destino];
			j++;
			for (i = 1; i < comm_sz; i++)
			{
				MPI_Send(&A[linha][destino], 1, MPI_FLOAT, i, 0, MPI_COMM_WORLD);
				if (j == n-1)
				{
					linha++;
					destino = (stage + linha) % n;
					j = 0;
				}else
					j++;

			}
		}else
		{
			MPI_Recv(&VA, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
		/* Fim passo 1*/


		/* Passo 2 - Realizar a soma das multiplicacoes */
		VC += VA * VB; 
		/* Fim passo 2 */

		/* Passo 3 - Reorganizar a matriz B */
        if(my_rank >= 0 && my_rank < n) /* Estou na borda e preciso mandar para ultima borda*/
        {
			value = (n*n)+my_rank;	/* Envio para o (fim + my_rank) Ex. (3*3) + 1 = 10, 10-3 envia para 7*/
			MPI_Send(&VB, 1, MPI_FLOAT, value-n, 0, MPI_COMM_WORLD);
			MPI_Recv(&VB, 1, MPI_FLOAT, my_rank+n, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }else if(my_rank >= ((n-1)*n) && my_rank < (n*n)) /* Estou na ultima borda e preciso receber da primeira */
        {
			MPI_Send(&VB, 1, MPI_FLOAT, my_rank-n, 0, MPI_COMM_WORLD);
			MPI_Recv(&VB, 1, MPI_FLOAT, my_rank%n, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        else
        {
			MPI_Send(&VB, 1, MPI_FLOAT, my_rank-n, 0, MPI_COMM_WORLD);
			MPI_Recv(&VB, 1, MPI_FLOAT, my_rank+n, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		}
		/* Fim passo 3 */
	}
	/* Respostas distribuidas nos processadores */
	printf("C[%d][%d] = %.2f\n", my_rank/n, my_rank%n, VC);


	/*  Passo 4 - Cada processo envia seus dados para o processo 0. 
		O processo 0 escreve a matriz C em um arquivo de texto: saida.txt */
	if (my_rank == 0)
	{
		arq = fopen("saida.txt", "w");
		fprintf(arq, "%.2f", VC);
		cont = 1;		
		for (i = 1; i < comm_sz; i++)
		{
			MPI_Recv(&aux, 1, MPI_FLOAT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			if (cont == 0)
				fprintf(arq, "%.2f", aux);
			else
				fprintf(arq, "%*.2f", 10, aux);
			if (cont == n-1)
			{
				fprintf(arq, "\n");	
				cont = 0;			
			}else {
				cont++;
			}
		}
		fclose(arq);
	} else {
		MPI_Send(&VC, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);		
	}
	
    /*printf("my_rank %d Tempo:%f\n\n", my_rank,(clock() - tempo) / (double)CLOCKS_PER_SEC);*/

	MPI_Finalize();
	return 0;
} /* main */
