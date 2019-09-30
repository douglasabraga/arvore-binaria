
#include "hash.h"

void lerArquivo(TNodo **R){
	char linha[50]; // string armazenara a linha
    FILE *arq;

    arq = fopen("DadosBancoPulini.txt","r"); // Abre o arquivo
    if (arq == NULL){  // Se houve erro na abertura
		printf("Problemas na abertura do arquivo\n");
	}else{
		while(fgets(linha, sizeof(linha)-1, arq) != NULL) { // Loop para ler cada linha do arquivo enquanto houver linhas
			separarDadosDaLinha(&(*R),linha);
		}
	}
    fclose(arq);
    //return hash;
}

void separarDadosDaLinha(TNodo **R, char linha[50]){
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
		//insereVetor(id, nome, saldo);
	}
//	return hash;
}

void inicializa(TNodo **R){
    (*R) = NULL;
}
//=================================================
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
//=================================================
TNodo *geraNodo(int id, char nome[50], float saldo){
   TNodo *novo = (TNodo *)calloc(1,sizeof(TNodo));
   novo->id = id;
   strcpy(novo->nome,nome);
   novo->saldo = saldo;
   novo->esq = NULL;
   novo->dir = NULL;
   return novo;
}

//================================================
void crescente(TNodo *R){
	if(R != NULL){
    	crescente(R->esq);
		printf(" %s %d",R->nome, R->id);
		crescente(R->dir);
	}//if
}

void decrescente(TNodo *R){
	if(R != NULL){
    	decrescente(R->dir);
		printf(" %s %d",R->nome, R->id);
		decrescente(R->esq);
	}//if
}
//=================================================

//================================================


// Devolve a altura de um no R em uma arvore binaria.

int height(TNodo *R){
    int u, v;
    if (R == NULL) return -1;
    u = height(R->esq);
    v = height(R->dir);
    if (u > v) return u + 1;
    else return v + 1;
}

// Esta funcao devolve o numero de nos
// da arvore binaria cuja raiz e R.
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


/* Recebe uma arvore de busca R e um inteiro v.
* Devolve um no cuja chave e igual a v. 
* Devolve NULL se tal no nao existe.
*/
TNodo *searchR(TNodo *R, int v) {
    int t;
    if (R == NULL){
    	return NULL;
	}
    t = R->id;
    
    if(v == t){
    	return R;	
	}else if (v < t){
       return searchR(R->esq, v);
	}else{
       return searchR(R->dir, v);
   }
}

//https://pt.stackoverflow.com/questions/192974/como-funciona-a-remo%C3%A7%C3%A3o-de-%C3%A1rvore-bin%C3%A1ria-em-c

void remover(TNodo **R, int id){
    if(*R == NULL){   // esta verificacao serve para caso o id nao exista na arvore.
       printf("\n\nNumero %d nao existe na arvore!", id);
       //getch();
       return;
    }
    if(id < (*R)->id){
       remover(&(*R)->esq, id);
    }else{
       	if(id > (*R)->id){
          remover(&(*R)->dir, id);
       	}else{    // se nao eh menor nem maior, logo, eh o id que estou procurando! :)
          TNodo *pAux = *R;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if(((*R)->esq == NULL) && ((*R)->dir == NULL)){         // se nao houver filhos...
                free(pAux);
                (*R) = NULL;   
          	}else{     // so tem o filho da dir
             if((*R)->esq == NULL){
                (*R) = (*R)->dir;
                pAux->dir = NULL;
                free(pAux); pAux = NULL;     
            }else{            //so tem filho da esq
                if((*R)->dir == NULL){
                    (*R) = (*R)->esq;
                    pAux->esq = NULL;
                    free(pAux); pAux = NULL;
                }else{       //Escolhi fazer o maior filho direito da subarvore esq.
                   pAux = MaiorDireita(&(*R)->esq); //se vc quiser usar o Menor da esq, so o que mudaria seria isso:
                   pAux->esq = (*R)->esq;          //        pAux = Menoresq(&(*R)->dir);
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
       if((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
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
			//printf("\nArvore Estritamente Binaria: TRUE");
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
    //return hash;
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
//	return hash;
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
	//printf("h = %d", h);
	int cont = h;
	while(cont > 0){
		//printf("cont: %d", cont);
		tamanhoVetor += pow(2,cont);
		cont--;
	}
	printf("Tamanho do vetor: %d", tamanhoVetor);
	
	return (TNodo*) calloc(tamanhoVetor*2, sizeof(TNodo));
	
}

int isEspelho(TNodo *R, int i){

    if (R == NULL && vetor[i].id == 0) 
        return 1; 

    if (R && vetor[i].id > 0 && R->id == vetor[i].id) 
        return isEspelho(R->esq, ((2*i)+2)) && isEspelho(R->dir, ((2*i)+1)); 

    return 0; 
}



