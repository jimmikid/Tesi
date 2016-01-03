#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <matrici.h>

void main()
{
	Matrice* A = alloca_matrice(2, 2);
	Matrice* B = alloca_matrice(2, 2);
	Matrice* C = alloca_matrice(4, 4);
	//Matrice A
	imposta_valori(A, 0, 0, 1); imposta_valori(A, 1, 0, 2);
	imposta_valori(A, 0, 1, 3); imposta_valori(A, 1, 1, 4);

	//Matrice B
	imposta_valori(B, 0, 0, 4); imposta_valori(B, 1, 0, 8); 
	imposta_valori(B, 0, 1, 6); imposta_valori(B, 1, 1, 12);
	
	//Matrice C
	imposta_valori(C, 0, 0, 18); imposta_valori(C, 1, 0, 22); imposta_valori(C, 2, 0, 54); imposta_valori(C, 3, 0, 42);
	imposta_valori(C, 0, 1, 22); imposta_valori(C, 1, 1, 70); imposta_valori(C, 2, 1, 86); imposta_valori(C, 3, 1, 62);
	imposta_valori(C, 0, 2, 54); imposta_valori(C, 1, 2, 86); imposta_valori(C, 2, 2, 174); imposta_valori(C, 3, 2, 134);
	imposta_valori(C, 0, 3, 42); imposta_valori(C, 1, 3, 62); imposta_valori(C, 2, 3, 134); imposta_valori(C, 3, 3, 106);
	
	Matrice* fattorizzata = cholesky(C);
	printf("Fattorizzazione di cholesky\n");
	stampa_matrice(fattorizzata);

	Matrice* moltiplicazione = moltiplica_matrici(A, B);
	printf("\nLe due matrici moltiplicate\n");
	stampa_matrice(moltiplicazione);

	Matrice* sommata = somma_matrici(A, B);
	printf("\nLe due matrici sommate\n");
	stampa_matrice(sommata);
	libera_memoria(A);
	libera_memoria(B);
	libera_memoria(moltiplicazione);
	libera_memoria(sommata);
	libera_memoria(C);
	libera_memoria(fattorizzata);
	printf("\n\n\n\nPremere un tasto per terminare...");
	//SERVE SOLO PER BLOCCARE L'ESECUZIONE DEL PROGRAMMA PER VEDERE L'OUTPUT
	getch();
}