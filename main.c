
#include "hash.h"

int main(){
	inicializarHash(5);
	alocaVetor();
	inicializa(&raiz);
	lerArquivo(&raiz);
	h = height(raiz);

	printf("\n\n\nCRESCENTE:");
	crescente(raiz);

	printf("\n\n\nDECRESCENTE:");
	decrescente(raiz);

	printf("\n\nQuantidade de nos na arvore: %d", qntdNos(raiz));
	printf("\n\nAltura da arvore: %d", h);

	int nivelNodo = calcularNivelNodo(raiz, 2);
	printf("\n\nNivel nodo %d: %d",2, nivelNodo);
	
	estritamenteBinariaCompleta(raiz);
	
	TNodo *n = searchR(raiz, 4);
	if(n != NULL){
		printf("\n\nPesquisa Raiz: %s", n->nome);	
	}else{
		printf("\n\nValor informado para pesquisa nao existe!");
	}
	
	TNodo *no = buscaHash(2);
	
	printf("\n\nBusca feita: %d, %s\n\n", no->id, no->nome);
    
	
	                                                           
	imprimirHash();
    //system("pause");
    getchar();
}
