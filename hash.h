#include "arvore.h"

TNodo *HASH;
int tam;

TNodo* aloca(int valor);
void insereHash(int id, char nome[50], float saldo);
int funcaohash(int chave);
void inicializarHash(int tamanho);
int percorrerArvoreInserirHash(TNodo *R);
void imprimirHash();
TNodo* buscaHash(int chave);
