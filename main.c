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

int main(){
	inicializa(&raiz);
	insere(&raiz,"PAULA");
	insere(&raiz,"RUAN");
	insere(&raiz,"VARLA");
	insere(&raiz,"TITO");
	insere(&raiz,"LIVIA");
	
	printf("\n\n\nCaminhamento PRE_ORDEM:");
	preOrdem(raiz);

	printf("\n\n\nCaminhamento EM_ORDEM:");
	emOrdem(raiz);

	printf("\n\n\nCaminhamento POS_ORDEM:");
	posOrdem(raiz);
	
	printf("\n\n\n");
	//system("PAUSE");
    getchar();
}
//=================================================
void inicializa(TNodo **R){
    (*R) = NULL;
}
//=================================================
void insere(TNodo **R, char vlr[10]){
    if((*R) == NULL){
    	(*R) = geraNodo(vlr);
    } else if (strcmp((*R)->valor, vlr) < 0){
    	 if((*R)->dir == NULL){
    	 	(*R)->dir = geraNodo(vlr);
    	 } else {
    	 	insere(&(*R)->dir, vlr);
    	 }
    } else {
    	if((*R)->esq == NULL){
    		(*R)->esq = geraNodo(vlr);
    	} else {
    		insere(&(*R)->esq,vlr);
    	}
    }
}
//=================================================
TNodo *geraNodo(char v[10]){
   TNodo *novo = (TNodo *)malloc(sizeof(TNodo));
   strcpy(novo->valor,v);
   novo->esq = NULL;
   novo->dir = NULL;
   return novo;
}
//=================================================
void preOrdem(TNodo *R){
	if(R != NULL){
		printf("\t%s",R->valor);
		preOrdem(R->esq);
		preOrdem(R->dir);
	}//if
}
//================================================
void emOrdem(TNodo *R){
	if(R != NULL){
    	emOrdem(R->esq);
		printf("\t%s",R->valor);
		emOrdem(R->dir);
	}//if
}
//=================================================
void posOrdem(TNodo *R){
	if(R != NULL){
    	posOrdem(R->esq);
		posOrdem(R->dir);
		printf("\t%s",R->valor);
	}//if
}
//================================================
