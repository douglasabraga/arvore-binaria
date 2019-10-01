
#include "hash.h"

void lerArquivoArvore(TNodo **R){
	char linha[50]; // string armazenara a linha
    FILE *arq;

    arq = fopen("DadosBancoPulini.txt","r"); // Abre o arquivo
    if (arq == NULL){  // Se houve erro na abertura
		printf("Problemas na abertura do arquivo\n");
	}else{
		while(fgets(linha, sizeof(linha)-1, arq) != NULL) { // Loop para ler cada linha do arquivo enquanto houver linhas
			separarDadosDaLinhaArvore(&(*R),linha);
		}
	}
    fclose(arq);
}


void separarDadosDaLinhaArvore(TNodo **R, char linha[50]){
	char delimitador[] = "|"; // Caracter delimitador
    char *info; // Ponteiro para armazenar as informacoes

	int id;
	char nome[50];
	float saldo;

	info = strtok(linha, delimitador); // info recebe a primeira string antes do primeiro delimitador da primeira linha

	while(info != NULL) { // Enquanto houver linhas no arquivo

		id = atoi(info); // Copia info para id

		info = strtok(NULL, delimitador); // Separa o nome da linha
		strcpy(nome, info);

		info = strtok(NULL, delimitador); // Separa o saldo da linha
		saldo = atof(info);

		info = strtok(NULL,delimitador); // Separa o codigo da linha

		insere(&(*R), id, nome, saldo);
		insereHash(id, nome, saldo);
	}
}


void inicializaArvore(TNodo **R){
    (*R) = NULL;
}



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


TNodo *geraNodo(int id, char nome[50], float saldo){
   TNodo *novo = (TNodo *)calloc(1,sizeof(TNodo));
   novo->id = id;
   strcpy(novo->nome,nome);
   novo->saldo = saldo;
   novo->esq = NULL;
   novo->dir = NULL;
   return novo;
}


void crescente(TNodo *R){
	if(R != NULL){
    	crescente(R->esq);
		printf("\n id: %d\t nome: %s\t saldo: %f ",R->id, R->nome, R->saldo);
		crescente(R->dir);
	}
}


void decrescente(TNodo *R){
	if(R != NULL){
    	decrescente(R->dir);
		printf("\n id: %d\t nome: %s\t saldo: %f ",R->id, R->nome, R->saldo);
		decrescente(R->esq);
	}
}


int alturaArvore(TNodo *R){
    int u, v;
    if (R == NULL) return -1;
    u = alturaArvore(R->esq);
    v = alturaArvore(R->dir);
    if (u > v) return u + 1;
    else return v + 1;
}


int qntdNos(TNodo *R){
    if (R == NULL) return 0;
    return qntdNos(R->esq) + qntdNos(R->dir) + 1;
}


int calcularNivelNodo(TNodo *R, int k){
    TNodo *aux = R;
    int nivel = 0;

    while (aux != NULL){
        if(k < aux->id){
            aux = aux->esq;
        }else if(aux->id == k){
        	return nivel;
        }else{
            aux = aux->dir;
        }
       nivel++;
    }
    return -1;
}


TNodo *buscaArvore(TNodo *R, int v) {
    if (R == NULL){
    	return NULL;
	}else{
		if(v > R->id){
			return buscaArvore(R->dir, v);
		}else if(v < R->id){
			return buscaArvore(R->esq, v);
		}else return R;
	}
}


void removerArvore(TNodo **R, int id){
    if(*R == NULL){   // esta verificacao serve para caso o id nao exista na arvore.
       printf("\n\nNumero %d nao existe na arvore!", id);
       //getch();
       return;
    }
    if(id < (*R)->id){
       removerArvore(&(*R)->esq, id);
    }else{
       	if(id > (*R)->id){
          removerArvore(&(*R)->dir, id);
       	}else{    // se nao eh menor nem maior, logo, eh o id que estou procurando!
          TNodo *pAux = *R;     
          if(((*R)->esq == NULL) && ((*R)->dir == NULL)){// se nao houver filhos
                free(pAux);
                (*R) = NULL;   
          	}else{     // filho da direita
             if((*R)->esq == NULL){
                (*R) = (*R)->dir;
                pAux->dir = NULL;
                free(pAux); pAux = NULL;     
            }else{            //filho da esquerda
                if((*R)->dir == NULL){
                    (*R) = (*R)->esq;
                    pAux->esq = NULL;
                    free(pAux); pAux = NULL;
                }else{       
                   pAux = MaiorDireita(&(*R)->esq);
                   pAux->esq = (*R)->esq;
                   pAux->dir = (*R)->dir;
                   (*R)->esq = (*R)->dir = NULL;
                   free((*R));  *R = pAux;  pAux = NULL;   
                   }
                }
             }
          }
      }
}


TNodo *MaiorDireita(TNodo **no){
    if((*no)->dir != NULL) 
       return MaiorDireita(&(*no)->dir);
    else{
       TNodo *aux = *no;
       if((*no)->esq != NULL)
          *no = (*no)->esq;
       else
          *no = NULL;
       return aux;
    }
}


int estritamente_bin(TNodo *no){
    if(!no->dir && !no->esq){
        return 1;
    }

    if(no->dir && no->esq){
        return estritamente_bin(no->esq) && estritamente_bin(no->dir);
    }

    return 0;
}


void estritamenteBinariaCompleta(TNodo *no){
	
	if(estritamente_bin(no)){
		printf("\nArvore Estritamente Binaria: TRUE");
		if(contaNosFolhas(no) == pow(2, h)){
			printf("\nArvore Estritamente Binaria e Completa: TRUE");
		}else{
			printf("\nArvore Estritamente Binaria e Completa: FALSE");
		}
	}else{
		printf("\nArvore Estritamente Binaria: FALSE");
		printf("\nArvore Estritamente Binaria e Completa: FALSE");
	}
}


int contaNosFolhas(TNodo *no){
    if(!no){
    	return 0;
    }else if(no->esq == NULL && no->dir == NULL){
    	return  1;
    }
	return(contaNosFolhas(no->esq) + contaNosFolhas(no->dir)); 
}


/*================================   VETOR   ========================================*/


void lerArquivoVetor(){
	char linha[50]; // string armazenara a linha
    FILE *arq;

    arq = fopen("DadosBancoPulini.txt","r"); // Abre o arquivo
    if (arq == NULL){  // Se houve erro na abertura
		printf("Problemas na abertura do arquivo\n");
	}else{
		while(fgets(linha, sizeof(linha)-1, arq) != NULL) { // Loop para ler cada linha do arquivo enquanto houver linhas
			separarDadosDaLinhaVetor(linha);
		}
	}
    fclose(arq);
}


void separarDadosDaLinhaVetor(char linha[50]){
	char delimitador[] = "|"; // Caracter delimitador
    char *info; // Ponteiro para armazenar as informacoes

	int id;
	char nome[50];
	float saldo;

	info = strtok(linha, delimitador); // info recebe a primeira string antes do primeiro delimitador da primeira linha

	while(info != NULL) { // Enquanto houver linhas no arquivo

		id = atoi(info); // Copia info para id

		info = strtok(NULL, delimitador); // Separa o nome da linha
		strcpy(nome, info);

		info = strtok(NULL, delimitador); // Separa o saldo da linha
		saldo = atof(info);

		info = strtok(NULL,delimitador); // Separa o codigo da linha

		insereVetor(id, nome, saldo);
	}
}


void insereVetor(int id, char nome[50], float saldo){
	int cont = 0;
	int aux = 1;
	if(vetor[cont].id == 0){
		vetor[cont].id = id;
		vetor[cont].saldo = saldo;
		strcpy(vetor[cont].nome,nome);
	}else{
		while(aux){
			if(vetor[cont].id > 0){
				if(vetor[cont].id > id){
					cont = (cont*2) + 2;
				}else{
					cont = (cont*2) + 1;
				}
			}else{
				aux = 0;
			}
		}
		vetor[cont].id = id;
		vetor[cont].saldo = saldo;
		strcpy(vetor[cont].nome,nome);
	}
}


TNodo *alocaVetor(){
	int cont = h;
	while(cont > 0){
		tamanhoVetor += pow(2,cont);
		cont--;
	}
	return (TNodo*) calloc(tamanhoVetor*2, sizeof(TNodo));
}


int isEspelho(TNodo *R, int i){

    if (R == NULL && vetor[i].id == 0) 
        return 1; 

    if (R && vetor[i].id > 0 && R->id == vetor[i].id) 
        return isEspelho(R->esq, ((2*i)+2)) && isEspelho(R->dir, ((2*i)+1)); 

    return 0; 
}



