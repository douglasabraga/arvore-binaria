
#include "arvore.h"

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
