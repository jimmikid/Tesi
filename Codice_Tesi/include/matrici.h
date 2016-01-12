//inclusione del tipo bool perchè in c non è riconosciuto di default

#ifndef matrici_h
#define matrici_h

#include <stdbool.h>

//Definizione della struttura matrice
typedef struct Matrice
{
	int colonne;		//numero di colonne
	int righe;			//numero di righe
	double **buffer;	//Contiene i valori della matrice
}
Matrice;

//Definizione della struttura autovalori
typedef struct Autovalori2x2
{
	bool successo;
	double lambda1;
	double lambda2;
}Autovalori2x2;

//Prototipo funzione di allocazione di una matrice
Matrice* alloca_matrice(int colonne, int righe);

//Prototipo funzione di copia di una matrice
Matrice* copia_matrice(Matrice* in);

//Prototipo della funzione di restituzione dei valori della matrice
double rest_val(const Matrice* in, int x, int y);

//Prototipi della funzione che imposta i valori di una matrice
void imposta_valori(const Matrice* in, int x, int y, double val);

//Prototipo funzione moltiplicazione Matrice x Matrice
Matrice* moltiplica_matrici(const Matrice* a, const Matrice* b);

//Prototipo funzione somma Matrice + Matrice
Matrice* somma_matrici(const Matrice* a, const Matrice* b);

//Prototipo funzione moltiplicazione Matrice x Scalare
Matrice* matrice_per_scalare(const Matrice* a, double scalare);

//Prototipo funzione somma Matrice + Scalare
Matrice* matrice_piu_scalare(const Matrice* a, double scalare);

//Prototipo Trasposta Matrice
Matrice* trasposta_matrice(const Matrice* in);

//Prototipo Inversa Matrice 2x2
Matrice* inverti_matrice_2x2(const Matrice* in);

//Prototipo funzione trasforma matrice in vettore colonna
Matrice* trasforma_in_vettore(const Matrice* in);

//Prototipo funzione calcolo autovalori di una 2x2
Autovalori2x2 autovalori_matrice(Matrice* in);

//Prototipo funzione Fattorizzazione Cholesky
Matrice* cholesky(const Matrice* in);

//Prototipo funzione di stampa elementi
void stampa_matrice(const Matrice* in);

//Prototipo funzione di deallocazione della memoria
void libera_memoria(Matrice* in);
#endif 