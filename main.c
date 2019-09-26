
#include "hash.h"

int main(){
	inicializarHash(10);
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
	
	 percorrerArvoreInserirHash(raiz);
	 printf("\n\nAASAA");
	 printf("\nINSERINDO MANUALMENTE");
	 insereHash(7,"silva", 23.123);
	 insereHash(2,"falko", 1.23);
	 insereHash(1,"dani", 56.123);
	 insereHash(3,"dodo", 23.444);
	 //printf("\nValor id: %d", HASH[1].id);                                                                               
	 imprimirHash();
                 
    getchar();
}
