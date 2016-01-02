#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <matrici.h>
int main()
{
	
	Matrice* A = alloca_matrice(2, 2);
	imposta_valori(A, 0, 0, 1);
	imposta_valori(A, 0, 1, 2);
	imposta_valori(A, 1, 0, 3);
	imposta_valori(A, 1, 1, 4);
	stampa_matrice(A);
	getch();
}