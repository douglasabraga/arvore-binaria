
#include "arvore.h"

int main(){
	inicializa(&raiz);
	insere(&raiz,"PAULA");
	insere(&raiz,"RUAN");
	insere(&raiz,"VARLA");
	insere(&raiz,"TITO");
	insere(&raiz,"LIVIA");
	
	printf("\n\n\nCaminhamento PRE_ORDEM:");
	preOrdem(raiz);

	printf("\n\n\nCaminhamento EM_ORDEM:");
	emOrdem(raiz);

	printf("\n\n\nCaminhamento POS_ORDEM:");
	posOrdem(raiz);
	
	printf("\n\n\n");
	//system("PAUSE");
    getchar();
}