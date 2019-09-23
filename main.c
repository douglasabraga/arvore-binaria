
#include "arvore.h"

int main(){
	inicializa(&raiz);
	insere(&raiz, 1, "PAULA", 123.12);
	insere(&raiz, 2, "RUAN", 244.33);
	insere(&raiz, 3, "VARLA", 312.11);
	insere(&raiz, 4, "TITO", 42.12);
	insere(&raiz, 5, "LIVIA", 512.12);
	
	printf("\n\n\nCaminhamento PRE_ORDEM:");
	preOrdem(raiz);

//	printf("\n\n\nCaminhamento EM_ORDEM:");
//	emOrdem(raiz);
//
//	printf("\n\n\nCaminhamento POS_ORDEM:");
//	posOrdem(raiz);
	
	int i = count(raiz);
	int h = height(raiz);
	TNodo *n = searchR(raiz, 1);
	printf("\nRaiz: %s", n->nome);
	printf("\ncount: %d", i);
	printf("\naltura: %d", h);
	printf("\n\n\n");
	//system("PAUSE");
    getchar();
}
