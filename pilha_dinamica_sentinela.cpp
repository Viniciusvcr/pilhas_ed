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

int exp_regular(char* expressao, int tam){ //exercício 1
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

int esvazia_pilha(pilha* p){ //exercício 4b
	celula *aux = p->topo->prox;
	celula *del = aux;

	if(!vazia(p)){
		while(aux != NULL){
			aux = aux->prox;
			free(del);
			del = aux;
		}
		p->topo->prox = NULL;
		return 1;
	}
	return 0;
}

void clear_screen(){
	system("cls");
}

void pause_screen(){
	system("pause");
	cout << endl;
}

int main(){
	pilha A;
	int opt;
	celula insere;
	item retornos;
	char expressao[100];

	do{
		fflush(stdin);
		clear_screen();
		cout << "[1] Inicia pilha" << endl;
		cout << "[2] Pilha vazia?" << endl;
		cout << "[3] Mostrar pilha" << endl;
		cout << "[4] Inserir elemento" << endl;
		cout << "[5] Tirar primeiro" << endl;
		cout << "[6] Mostrar item do topo" << endl;
		cout << "[7] Expressao regular" << endl;
		cout << "[8] Esvaziar pilha" << endl;
		cin >> opt;
		switch(opt){
			case 1;
				inicializa(&A);
				cout << "PILHA INICIALIZADA" << endl;
				pause_screen();
			break;

			case 2:
				if(vazia(&A)) cout << "PILHA VAZIA" << endl;
				else cout << "PILHA NAO VAZIA" << endl;
				pause_screen();
			break;

			case 3:
				clear_screen();
				cout << "PILHA COMPLETA: ";
				mostra_pilha(&A);
				pause_screen();
			break;

			case 4:
				clear_screen();
				cout << "Insira o elemento que deseja inserir: ";
				cin >> insere.chave;
				empilha(&A, insere);
				cout << "ELEMENTO INSERIDO" << endl;
				pause_screen();
			break;

			case 5:
				if(desempilha(&A, &retornos))
					cout << retornos.chave << " RETIRADO COM SUCESSO" << endl;
				else cout << "ERRO NA REMOCAO" << endl;
				pause_screen();
			break;

			case 6:
				if(topo(&A, &retornos))
					cout << "ITEM DO TOPO: " << retornos.chave << endl;
				else cout << "LISTA VAZIA!" << endl;
				pause_screen();
			break;

			case 7:
				clear_screen();
				cout << "Escreva a expressao: ";
				cin >> expressao;
				if(exp_regular(expressao, strlen(expressao)))
					cout << "EXPRESSAO CORRETA!" << endl;
				else cout << "EXPRESSAO INCORRETA" << endl;
			break;

			case 8:
				if(esvazia_pilha(&A))
					cout << "PILHA ESVAZIADA COM SUCESSO!" << endl;
				else cout << "ERRO NA OPERACAO" << endl;
				pause_screen();
			break;
		}
	}while(opt != 0);
}