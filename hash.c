#include "hash.h"

TNodo* aloca(int valor){
	tam = valor;
	return (TNodo*) calloc(tam, sizeof(TNodo));
}

void insereHash(int id, char nome[50], float saldo){
	int chave = funcaohash(id);
	//TNodo *aux = &HASH[chave];
	
	//printf("\nid->%d nome->%s saldo->%.2f", aux->id, aux->nome, aux->saldo);
	
    if(HASH[chave].id == 0){
    	HASH[chave].id = id;
    	strcpy(HASH[chave].nome, nome);
    	HASH[chave].saldo = saldo;
    /*if(aux == NULL){
    	aux->id = id;
    	strcpy(aux->nome, nome);
    	aux->saldo = saldo;*/
    }else{
    	if(HASH[chave].id > id){
    		insere(&HASH[chave].esq, id, nome, saldo);
		}else{
			insere(&HASH[chave].dir, id, nome, saldo);
		}
        	
        //printf("\n\naaa id: %d nome: %s saldo: %.2f",aux->id, aux->nome, aux->saldo );
    }
}

int funcaohash(int chave) {
	return chave % tam;
}

void imprimirHash(){
    int i;

    for(i = 0; i < tam; i++){
        TNodo *temp = &HASH[i];
        printf("hash[%d]-->",i);
        while(temp){
        	if(HASH[i].id > 0){
            	printf("%d %s -->",temp->id, temp->nome);
        	}else{
        		printf("NULL -->");
			}
        	
			temp = temp->dir;
        }
        printf("NULL\n");
    }
}

TNodo* buscaHash(int chave) {
	int pos = funcaohash(chave);
	TNodo *no = &HASH[pos];
	while (no != NULL){  // n+1
		if (chave == no->id) return no; // Se encontrou retorna verdadeiro // n
		no = no->dir;
	}
	return no;
}

void inicializarHash(int tamanho){
	tam = tamanho;
	HASH = aloca(tamanho);
    int i;
    for(i = 0; i < tam; i++){
        HASH[i].id = 0;
        strcpy(HASH[i].nome, "");
        HASH[i].saldo = 0.0;
    }
}

