
#include "arvore.h"

int main(){
	inicializa(&raiz);
	insere(&raiz, 1, "TITO", 42.12);
	insere(&raiz, 2, "RUAN", 244.33);
	insere(&raiz, 5, "PAULA", 123.12);
	insere(&raiz, 4, "LIVIA", 512.12);
	insere(&raiz, 3, "VARLA", 312.11);
	
	printf("\n\n\nCaminhamento CRESCENTE:");
	crescente(raiz);
	
	printf("\n\n\nCaminhamento DECRESCENTE:");
	decrescente(raiz);
	
	int i = count(raiz);
	int h = height(raiz);
	
	int nivelNodo = calcularNivelNodo(raiz, 2);
	printf("\nNivel nodo %d: %d",2, nivelNodo);
	
	nivelNodo = calcularNivelNodo(raiz, 5);
	printf("\nNivel nodo %d: %d",5, nivelNodo);
	
	TNodo *n = searchR(raiz, 1);
	printf("\nRaiz: %s", n->nome);
	printf("\ncount: %d", i);
	printf("\naltura: %d", h);
	
	printf("\nRemoveu 2");
	remover(&raiz, 2);
	
	printf("\n\n\nCaminhamento CRESCENTE:");
	crescente(raiz);
	
	i = estritamente_bin(&raiz);
	
	if(i){
		printf("\nEstritamente");
	}else{
		printf("\nnao Estritamente");
	}

	printf("\n\n\n");

	//system("PAUSE");
    getchar();
}
