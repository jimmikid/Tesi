#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <matrici.h>

void main()
{
	Matrice* A = alloca_matrice(2, 2);
	Matrice* B = alloca_matrice(2, 2);
	//Matrice A
	imposta_valori(A, 0, 0, 1); imposta_valori(A, 1, 0, 2);
	imposta_valori(A, 0, 1, 3); imposta_valori(A, 1, 1, 4);

	//Matrice B
	imposta_valori(B, 0, 0, 4); imposta_valori(B, 1, 0, 8); 
	imposta_valori(B, 0, 1, 6); imposta_valori(B, 1, 1, 12);
	
	Matrice* moltiplicazione = moltiplica_matrici(A, B);
	printf("Le due matrici moltiplicate\n");
	stampa_matrice(moltiplicazione);

	Matrice* sommata = somma_matrici(A, B);
	printf("\nLe due matrici sommate\n");
	stampa_matrice(sommata);
	libera_memoria(A);
	libera_memoria(B);
	libera_memoria(moltiplicazione);
	libera_memoria(sommata);
	printf("\n\n\n\nPremere un tasto per terminare...");
	//SERVE SOLO PER BLOCCARE L'ESECUZIONE DEL PROGRAMMA PER VEDERE L'OUTPUT
	getch();
}