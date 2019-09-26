
#include "arvore.h"

int main(){
	
	inicializa(&raiz);

	insere(&raiz, 1, "TITO", 42.12);
	insere(&raiz, 4, "LIVIA", 512.12);
	insere(&raiz, 2, "RUAN", 244.33);
	insere(&raiz, 5, "PAULA", 123.12);
	insere(&raiz, 3, "VARLA", 312.11);

	h = height(raiz);

	printf("\n\n\nCRESCENTE:");
	crescente(raiz);

	printf("\n\n\nDECRESCENTE:");
	decrescente(raiz);

	printf("\ncount: %d", count(raiz));
	printf("\naltura: %d", h);

	int nivelNodo = calcularNivelNodo(raiz, 2);
	printf("\nNivel nodo %d: %d",2, nivelNodo);

	TNodo *n = searchR(raiz, 4);
	if(n != NULL){
		printf("\nPesquisa Raiz: %s", n->nome);	
	}else{
		printf("\nValor informado para pesquisa nao existe!");
	}

	printf("\n\n\nCaminhamento CRESCENTE:");
	crescente(raiz);

	estritamenteBinariaCompleta(raiz);

	int contFolhas = contaNosFolhas(raiz);
	printf("\nQntd Folhas: %d", contFolhas);
	printf("\naltura: %d", h);
	printf(   "\n %.0f", pow(2, h)   );

	//system("PAUSE");
    getchar();
}
