#include <stdio.h>
#include <string.h> /* For strlen */
#include <mpi.h> /* For MPI functions, etc */
const int MAX_TAM = 8;

/*
* Aluno1: Gabriel Escobar Paies | 2014.1907.
* Aluno2: Lucas Barbosa Rocha   | 2014.1907.013-4
* Algoritmos Paralelos - Henrique Mongelli
* Algoritmo: Multiplicação de matriz - FOX
*/

int main(void) {
	int comm_sz; /* Number of processes */
	int my_rank; /* My process rank */
	int r, i, j, subVetor[MAX_TAM/2];
	int vetor[MAX_TAM];
	int z = 0, S = 0;
	float d = 0;


	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);


	/* Código aqui */


	MPI_Finalize();
	return 0;
} /* main */
