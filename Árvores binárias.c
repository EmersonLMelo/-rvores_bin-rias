//Aluno: Emerson Lidio Melo
//RA:21020130-5

//Bibliotecas.
#include <stdio.h>
#include <stdlib.h>

//Estuturas.
typedef struct no{
	int dado;
	struct no *esquerdo, *direita;
}No;

//Estrututa Raiz.
typedef struct{
	No *raiz;
}ArvIni;

//Fun��es.
int inserirD(No *no, int valor);
int inserirE(No *no, int valor);
int inserir(ArvIni *arv, int valor);
int imprimir(No *raiz);

//Inserir valor a esquerda, alocando uma memoria.
int inserirE(No *no, int valor){
	if(no->esquerdo == NULL){
		No *novo =  (No*)malloc(sizeof(No));
		novo->dado = valor;
		novo->esquerdo = NULL;
		novo->direita = NULL;
		no->esquerdo = novo;
	}
	else{
		if(valor < no->esquerdo->dado)
			inserirE(no->esquerdo, valor);//Inserir a esquerda, caso a memoria esteja ocupada.
		else
			inserirD(no->esquerdo, valor);//Inserir a direita, caso a memoria esteja ocupada.
		
	}
}
//Inserir valor a direita, alocando uma memoria.
int inserirD(No *no, int valor){
	if(no->direita == NULL){
		No *novo =  (No*)malloc(sizeof(No));
		novo->dado = valor;
		novo->esquerdo = NULL;
		novo->direita = NULL;
		no->direita = novo;
	}
	else{
		if(valor >= no->direita->dado)
			inserirD(no->direita, valor);//Inserir a direita, caso a memoria esteja ocupada.
		else
			inserirE(no->direita, valor);//Inserir a esquerda, caso a memoria esteja ocupada.
	}
}
//Inserir o valor Raiz, alocando uma memoria.
int inserir(ArvIni *arv, int valor){
	if(arv->raiz == NULL){
		No *novo =  (No*)malloc(sizeof(No));
		novo->dado = valor;
		novo->esquerdo = NULL;
		novo->direita = NULL;
		arv->raiz = novo;
	}
	else{
		if(valor < arv->raiz->dado)
			inserirE(arv->raiz, valor);//Inserir a esquerda, caso a memoria esteja ocupada.
		else
			inserirD(arv->raiz, valor);//Inserir a direita, caso a memoria esteja ocupada.
	}
}
//Imprimir valores da Arvore em Pre-Ordem
int imprimir(No *raiz){
	if(raiz != NULL){
		printf("-%d", raiz->dado);
		imprimir(raiz->esquerdo);
		imprimir(raiz->direita);
	}
}

int main() {
	ArvIni arv;
	arv.raiz = NULL;
	inserir(&arv, 2);
	inserir(&arv, 1);
	inserir(&arv, 0);
	inserir(&arv, 2);//Inserindo o RA:21020130
	inserir(&arv, 0);
	inserir(&arv, 1);
	inserir(&arv, 3);
	inserir(&arv, 0);
	printf("Pre-Ordem: ");
	imprimir(arv.raiz);
}
