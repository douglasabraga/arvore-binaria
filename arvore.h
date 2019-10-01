#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct tipoNodo{
	int id;
	char nome[50];
	float saldo;
	struct tipoNodo *esq, *dir;
}TNodo;

TNodo *raiz;
TNodo *vetor;
int h;
int tamanhoVetor;

void lerArquivoArvore(TNodo **R);
void separarDadosDaLinhaArvore(TNodo **R, char linha[50]);
void inicializaArvore(TNodo **R);
void insere(TNodo **R, int id, char nome[50], float saldo);
void removerArvore(TNodo **R, int numero);
TNodo *MaiorDireita(TNodo **no);
TNodo *geraNodo(int id, char nome[50], float saldo);
void crescente(TNodo *R);
int alturaArvore(TNodo *R);
int qntdNos(TNodo *R);
TNodo *buscaArvore(TNodo *R, int v);
int calcularNivelNodo(TNodo *R, int k);
void decrescente(TNodo *R);
int estritamente_bin(TNodo *no);
int contaNosFolhas(TNodo *no);
void estritamenteBinariaCompleta(TNodo *no);
/*--------------------- VETOR ----------------------------*/
void insereVetor(int id, char nome[50], float saldo);
void inicializarVetor();
TNodo *alocaVetor();
void lerArquivoVetor();
void separarDadosDaLinhaVetor(char linha[50]);
int isEspelho(TNodo *R, int i);
