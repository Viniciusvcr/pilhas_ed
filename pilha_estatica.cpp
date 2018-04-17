#include <iostream>
#include <stdio.h>
#define TAM 100

typedef struct tipo_item{
	int chave;
}item;

typedef struct tipo_pilha{
	int topo;
	struct tipo_item dados[TAM];
}pilha;

void inicializa(pilha* p){
	p->topo = 0;
}

int cheia(pilha* p){
	return p->topo == TAM;
}

int vazia(pilha* p){
	return p->topo == 0;
}

void mostra_pilha(pilha* p){
	for(int i=0; i<p->topo; i++){
		cout << p->dados[i].chave << " ";
	}
	cout << endl;
}

int empilha(pilha* p, item x){
	if(!cheia(p)){
		p->dados[p->topo] = x;
		p->topo++;
		return 1;
	}
	return 0;
}

int desempilha(pilha* p, item* retorno){
	if(!vazia(p)){
		p->topo--;
		*retorno = p->dados[p->topo];
		return 1;
	}
	return 0;
}

int main(){
	pilha A;
	item insere;
	int opt;

	do{
		fflush(stdin);
		clear_screen();
		cout << "[1] Inicia pilha" << endl;
		cout << "[2] Pilha cheia?" << endl;
		cout << "[3] Pilha vazia?" << endl;
		cout << "[4] Mostra pilha" << endl;
		cout << "[5] Insere elemento" << endl;
		cout << "[6] Tira elemento" << endl;
		switch(opt){
			case 1:
				inicializa(&A);
			break;

			case 2:
				if(cheia(&A)) cout << "PILHA CHEIA" << endl;
				else cout << "PILHA NAO ESTA CHEIA" << endl;
				pause_screen();
			break;

			case 3:
				if(vazia(&A)) cout << "PILHA VAZIA" << endl;
				else cout << "PILHA NAO ESTA VAZIA" << endl;
				pause_screen();
			break;

			case 4:
				clear_screen();
				mostra_pilha(&A);
				pause_screen();
			break;

			case 5:
				
		}
	}while(opt!=0);
}