
#include "hash.h"
void menu();
int main(){
	inicializarHash(5);
	//alocaVetor();
	inicializa(&raiz);
	lerArquivo(&raiz);
	
	h = height(raiz);
	printf("\nAltura da Arvore: %d", h);
	
	int i = qntdNos(raiz);
	
	printf("\nQuantidade de nos na arvore: %d", i);
	
	estritamenteBinariaCompleta(raiz);
    
    menu();
    
    getchar();
}

void menu(){
	int op;
	int aux;
	do{
		printf("\n=============================================");
		printf("\n0 - SAIR");
		printf("\n1 - Imprimir hash");
		printf("\n2 - Imprimir elementos em ordem crescente");
		printf("\n3 - Imprimir elementos em ordem decrescente");
		printf("\n4 - Calcular nivel de determinado no");
		printf("\n5 - Buscar um elemento pela chave");
		printf("\n6 - Remover um elemento da arvore pela chave");
		printf("\n=============================================");
		printf("\n->");
		scanf("%d", &op);
		printf("\n");
	}while(op < 0 || op > 6);
	
	switch(op){
		case 1:
			imprimirHash();
			menu();
			break;
		case 2:
			crescente(raiz);
			menu();
			break;
		
		case 3:
			decrescente(raiz);
			menu();
			break;
		
		case 4:
			printf("\nInsira a chave:");
			scanf("%d", &aux);
			aux = calcularNivelNodo(raiz, aux);
			if(aux < 0){
				printf("\nChave informada nao foi encontrada!");
			}else{
				printf("\n\nNivel da chave %d", aux);
			}
			menu();
			break;
		
		case 5:
			printf("\nInsira a chave:");
			scanf("%d", &aux);
			TNodo *n = searchR(raiz, aux);
			if(n != NULL){
				printf("\n\nPesquisa Raiz: %s", n->nome);	
			}else{
				printf("\n\nValor informado para pesquisa nao existe!");
			}
			
			TNodo *no = buscaHash(aux);
			if(no != NULL){
				printf("\n\nBusca feita: %d, %s\n\n", no->id, no->nome);	
			}else{
				printf("\n\nValor informado para pesquisa nao existe!");
			}

			menu();
			break;
		
		case 6:
			printf("\nInsira a chave:");
			scanf("%d", &aux);
			
			remover(&raiz, aux);
			
			menu();
			break;	
	}
}
