#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNodo{
	int id;
	char nome[50];
	float saldo;
	struct tipoNodo *esq, *dir;
}TNodo;

TNodo *raiz;

void inicializa(TNodo **R);
void insere(TNodo **R, int id, char nome[50], float saldo);
void remover(TNodo **R, int numero);
TNodo *MaiorDireita(TNodo **no);
TNodo *geraNodo(int id, char nome[50], float saldo);
void crescente(TNodo *R);
int height(TNodo *R);
int count(TNodo *R);
TNodo *searchR(TNodo *R, int v);
int calcularNivelNodo(TNodo *R, int k);
void decrescente(TNodo *R);
int estritamente_bin(TNodo *no);
