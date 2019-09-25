
#include "arvore.h"

void inicializa(TNodo **R){
    (*R) = NULL;
}
//=================================================
void insere(TNodo **R, int id, char nome[50], float saldo){
    if((*R) == NULL){
    	(*R) = geraNodo(id, nome, saldo);
    } else if ((*R)->id < id){
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
		printf("\t%s %d",R->nome, R->id);
		emOrdem(R->dir);
	}//if
}

void decrescente(TNodo *R){
	if(R != NULL){
    	emOrdem(R->dir);
		printf("\t%s %d",R->nome, R->id);
		emOrdem(R->esq);
	}//if
}
//=================================================
void posOrdem(TNodo *R){
	if(R != NULL){
    	posOrdem(R->esq);
		posOrdem(R->dir);
		printf("\t%s %d",R->nome, R->id);
	}//if
}
//================================================


// Devolve a altura de um nó R em uma árvore binária.

int height(TNodo *R){
    int u, v;
    if (R == NULL) return -1;
    u = height(R->esq);
    v = height(R->dir);
    if (u > v) return u + 1;
    else return v + 1;
}

// Esta função devolve o número de nós
// da árvore binária cuja raiz é R.
int count(TNodo *R){
    if (R == NULL) return 0;
    return count(R->esq) + count(R->dir) + 1;
}


int calcularNivelNodo(TNodo *R, int k){
    TNodo *aux = R;
    int nivel = 0;
    while (aux != NULL && aux->id != k){
        if(k < aux->id){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }
       nivel++;
    }
    return nivel;
}


// Recebe uma árvore de busca R e um inteiro v.
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
