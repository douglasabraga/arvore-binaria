
#include "arvore.h"

void inicializa(TNodo **R){
    (*R) = NULL;
}
//=================================================
void insere(TNodo **R, int id, char nome[50], float saldo){
    if((*R) == NULL){
    	(*R) = geraNodo(id, nome, saldo);
    } else if (strcmp((*R)->nome, nome) < 0){
    	 if((*R)->dir == NULL){
    	 	(*R)->dir = geraNodo(id, nome, saldo);
    	 } else {
    	 	insere(&(*R)->dir, id, nome, saldo);
    	 }
    } else {
    	if((*R)->esq == NULL){
    		(*R)->esq = geraNodo(id, nome, saldo);
    	} else {
    		insere(&(*R)->esq, id, nome, saldo);
    	}
    }
}
//=================================================
TNodo *geraNodo(int id, char nome[50], float saldo){
   TNodo *novo = (TNodo *)malloc(sizeof(TNodo));
   novo->id = id;
   strcpy(novo->nome,nome);
   novo->saldo = saldo;
   novo->esq = NULL;
   novo->dir = NULL;
   return novo;
}
//=================================================
void preOrdem(TNodo *R){
	if(R != NULL){
		printf("\t%s %d",R->nome, R->id);
		preOrdem(R->esq);
		preOrdem(R->dir);
	}//if
}
//================================================
void emOrdem(TNodo *R){
	if(R != NULL){
    	emOrdem(R->esq);
		printf("\t%s",R->nome);
		emOrdem(R->dir);
	}//if
}
//=================================================
void posOrdem(TNodo *R){
	if(R != NULL){
    	posOrdem(R->esq);
		posOrdem(R->dir);
		printf("\t%s",R->nome);
	}//if
}
//================================================

// Esta função devolve o número de nós
// da árvore binária cuja raiz é R.
int count(TNodo *R){
    if (R == NULL) return 0;
    return count(R->esq) + count(R->dir) + 1;
}

// Devolve o altura de um nó R em uma árvore binária.

int height(TNodo *R){
    int u, v;
    if (R == NULL) return -1;
    u = height(R->esq);
    v = height(R->dir);
    if (u > v) return u + 1;
    else return v + 1;
}

// Recebe uma árvore de busca h e um inteiro v.
// Devolve um nó cuja chave é igual a v. 
// Devolve NULL se tal nó não existe.
//
TNodo *searchR(TNodo *R, int v) {
    int t;
    if (R == NULL) return NULL;
    t = R->id;
    if (v == t) return R;
    if (v < t) 
       return searchR(R->esq, v);
    else 
       return searchR(R->dir, v);
}
