#include <matrici.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

//Allocazione dinamica del tipo matrice
Matrice* alloca_matrice(int colonne, int righe)
{
	Matrice* output = (Matrice*)malloc(sizeof(Matrice));
	output->colonne = colonne;
	output->righe	= righe;

	//Allocazione dei puntatori a colonne
	output->buffer = (double**)malloc(sizeof(double*)*colonne);

	//Allocazione delle colonne
	for (int i = 0; i < colonne; ++i)
	{
		output->buffer[i] = calloc(sizeof(double), righe);
	}

	return output;
}

//Copia matrice
Matrice* copia_matrice(Matrice* in)
{
	Matrice* output = alloca_matrice(in->colonne, in->righe);
	for (int x = 0; x != in->colonne; ++x)
	{
		memcpy(output->buffer[x], in->buffer[x], sizeof(double)*in->righe);
	}
	return output;
}

//Restituisce i valori della matrice
double rest_val(const Matrice* in, int x, int y){
	return in->buffer[x][y];
}

//Imposta tutti i valori della matrice
void imposta_valori(const Matrice* in, int x, int y, double valore)
{
	in->buffer[x][y] = valore;
}

//Moltiplicazione Matrice x Matrice
Matrice* moltiplica_matrici(const Matrice* a, const Matrice* b)
{
	if (a->colonne != b->righe)
	{
		return NULL;
	}

	Matrice* output = alloca_matrice(a->righe, b->colonne);

	for (int y = 0; y != output->righe; ++y){
		for (int x = 0; x != output->colonne; ++x)
		{
			double somma = 0.0;
			for (int k = 0; k != b->righe; ++k)
			{
				somma += rest_val(a, k, y) * rest_val(b, x, k);
			}

			imposta_valori(output, x, y, somma);
		}
	}
	return output;
}

//Somma Matrice + Matrice
Matrice* somma_matrici(const Matrice* a, const Matrice* b)
{
	if (a->colonne != b->colonne) return NULL;
	if (a->righe != b->righe) return NULL;

	Matrice* output = alloca_matrice(a->colonne, a->righe);

	double somma = 0.0;

	for (int y = 0; y != output->righe; ++y)
		for (int x = 0; x != output->colonne; ++x)
		{
		somma = rest_val(a, x, y) + rest_val(b, x, y);
		imposta_valori(output, x, y, somma);
		somma = 0.0;
		}
	return output;
}

//Moltiplicazione Matrice x Scalare
Matrice* matrice_per_scalare(const Matrice* a, double scalare)
{
	Matrice* output = alloca_matrice(a->colonne, a->righe);

	for (int y = 0; y != output->righe; ++y)
	{
		for (int x = 0; x != output->colonne; ++x)
		{
			imposta_valori(output, x, y, rest_val(a, x, y) * scalare);
		}

	}
	return output;
}

//Somma Matrice + Scalare
Matrice* matrice_piu_scalare(const Matrice* a, double scalare)
{
	Matrice* output = alloca_matrice(a->colonne, a->righe);

	for (int y = 0; y != output->righe; ++y)
	{
		for (int x = 0; x != output->colonne; ++x)
		{
			imposta_valori(output, x, y, rest_val(a, x, y) + scalare);
		}

	}
	return output;
}

//Trasposta Matrice
Matrice* trasposta_matrice(const Matrice* in)
{
	Matrice* output = alloca_matrice(in->colonne, in->righe);

	for (int x = 0; x != output->colonne; ++x)
	{
		for (int y = 0; y != output->righe; ++y)
		{
			imposta_valori(output, x, y, rest_val(in, y, x)); 
		}
	}

	return output;
}

//Inversa Matrice 2x2
Matrice* inverti_matrice_2x2(const Matrice* in)
{
	if (in->colonne != 2 || in->righe != 2) return NULL;
	 
	Matrice* output = alloca_matrice(2, 2);

	double det_d1 = rest_val(in, 0, 0) * rest_val(in, 1, 1);
	double det_d2 = rest_val(in, 1, 0) * rest_val(in, 0, 1);

	double det = det_d1 - det_d2;

	imposta_valori(output, 0, 0, (rest_val(in, 1, 1) / det));
	imposta_valori(output, 0, 1, -(rest_val(in, 0, 1) / det));
	imposta_valori(output, 1, 0, -(rest_val(in, 1, 0) / det));
	imposta_valori(output, 1, 1, (rest_val(in, 0, 0) / det));

	return output;
}

//Trasforma matrice in vettore colonna
Matrice* trasforma_in_vettore(const Matrice* in)
{
	//trasforma semplicemente una matrice in un array w*h x 1
	Matrice* output = alloca_matrice(1, (in->righe * in->colonne));

	for (size_t x = 0; x != in->colonne; ++x)
	{
		for (size_t y = 0; y != in->righe; ++y)
		{
			imposta_valori(output, 0, y + (x*in->righe), rest_val(in, x, y));
		}
	}

	return output;
}

//Stampa elementi della matrice
void stampa_matrice(const Matrice* in)
{
	for (int y = 0; y != in->righe; ++y)
	{
		for (int x = 0; x != in->colonne; ++x)
		{
			printf("%0.3f \t", rest_val(in, x, y));
		}
		printf("\n");
	}
}

//Libera memoria allocata
void libera_memoria(Matrice* in)
{
	for (int i = 0; i < in->colonne; ++i)
	{
		free(in->buffer[i]);
	}
	free(in->buffer);
	free(in);
}