#include <time.h>
#include "hash.h"
void menu();

int main(){
	
	inicializaArvore(&raiz);
	
	inicializarHash(50);
	
	lerArquivoArvore(&raiz);
	h = alturaArvore(raiz);
	
	vetor = alocaVetor();
	
	lerArquivoVetor();
	
	printf("\nAltura da Arvore: %d", h);
	
	int i = qntdNos(raiz);
	
	printf("\nQuantidade de nos na arvore: %d", i);
	
	estritamenteBinariaCompleta(raiz);
	
	i = isEspelho(raiz, 0);
    
    if(i)
    	printf("\nEspelho Similar: TRUE");
    else
    	printf("\nEspelho Similar: FALSE");


    menu();
    
    getchar();
}

void menu(){
	int op;
	int aux;
	float tempoArvore, tempoHash;
	clock_t inicioArvore, fimArvore, inicioHash, fimHash;
	
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
			
			inicioArvore = clock();
			TNodo *n = buscaArvore(raiz, aux);
			
			fimArvore = clock();
			
			if(n == NULL){
				printf("\nValor Informado Nao Encontrado!");	
			}else{
				printf("\n\nRegistro Encontrado na Arvore:\nId: %d\nNome: %s\nSaldo: %.2f", n->id, n->nome, n->saldo);
			}
			
			inicioHash = clock();
			TNodo *no = buscaHash(aux);
			fimHash = clock();
			
			if(no == NULL){
				printf("\nValor Informado Nao Encontrado!");
			}else{
				printf("\n\nRegistro Encontrado na HASH:\nId: %d\nNome: %s\nSaldo: %.2f", no->id, no->nome, no->saldo);
			}
			
			tempoArvore = ((float)fimArvore - (float) inicioArvore) /CLOCKS_PER_SEC;
			tempoHash = ((float)fimHash - (float) inicioHash) /CLOCKS_PER_SEC;
			printf("\n\nTempo Arvore: %f", tempoArvore);
			printf("\nTempo Hash: %f", tempoArvore);
			printf("\nRazao do Tempo: %d%%",(tempoArvore/tempoHash));
			
			menu();
			break;
		
		case 6:
			printf("\nInsira a chave:");
			scanf("%d", &aux);
			
			removerArvore(&raiz, aux);
			
			menu();
			break;	
	}
}
