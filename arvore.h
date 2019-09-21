#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNodo{
	char valor[10];
	struct tipoNodo *esq, *dir;
}TNodo;

TNodo *raiz;

void inicializa(TNodo **R);
void insere(TNodo **R, char vlr[10]);
TNodo *geraNodo(char v[10]);
void preOrdem(TNodo *R);
void emOrdem(TNodo *R);
void posOrdem(TNodo *R);