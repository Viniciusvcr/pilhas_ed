#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_item{
	int chave;
}item;

typedef struct tipo_celula{
	struct tipo_item item;
	struct tipo_celula *prox;
}celula;

typedef struct tipo_pilha{
	struct tipo_celula *topo;
}pilha;

void inicializa(pilha* p){
	p->topo = (celula*)malloc(sizeof(celula));
	p->topo->prox = NULL;
}

int vazia(pilha* p){
	return p->topo->prox == NULL;
}

void mostra_pilha(pilha* p){
	celula *aux = p->topo->prox;

	while(aux != NULL){
		cout << aux->item.chave << " ";
		aux = aux->prox;
	}
	cout << endl;
}

void empilha(pilha* p, item x){
	celula *novo = (celula*)malloc(sizeof(celula));

	novo->item = x;
	novo->prox = p->topo->prox;
	p->topo->prox = novo;
}

int desempilha(pilha* p, item* retorno){
	celula *del = p->topo->prox;
	if(!vazia(p)){
		p->topo->prox = del->prox;
		*retorno = del->item;
		free(del);
		return 1;
	}
	return 0;
}

int topo(pilha* p, item* top){
	if(!vazia(p)){
		*top = p->topo->prox->item;
		return 1;
	}
	return 0;
}

int conta_parenteses(char* expressao, int tam){ //exercício 1
	pilha A;
	item X;
	inicializa(&A);
	X.chave = 0;
	for(int i=0; i<tam; i++){
		if(expressao[i] == '(')
			empilha(&A, X);
		if(expressao[i] == ')'){
			if(!desempilha(&A, &X))
				return 0;
		}
	}
	return vazia(&A);
}

void esvazia_pilha(pilha* p){ //exercício 4b
	celula *aux = p->topo->prox;
	celula *del = aux;

	while(aux != NULL){
		aux = aux->prox;
		free(del);
		del = aux;
	}
	p->topo->prox = NULL;
}