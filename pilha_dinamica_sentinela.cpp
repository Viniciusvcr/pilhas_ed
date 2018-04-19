#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

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

void mostra_bin(pilha* p){ //Função usada para mostrar uma pilha sem espaços entre os elementos
	celula *aux = p->topo->prox;

	while(aux != NULL){
		cout << aux->item.chave;
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
	celula *aux;
	celula *del;

	if(!vazia(p)){
		aux = p->topo->prox;
		del = aux;
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

void dec_to_bin(int decimal, pilha* binario){ //exercício 3
	item resto;

	while(decimal != 0){
		resto.chave = decimal%2;
		empilha(binario, resto);
		decimal /= 2;
	}
}

int copia_pilha(pilha* A, pilha* B){ //exercício 2
	pilha C;
	item topo;
	int flag = 0;

	inicializa(&C);
	while(desempilha(B, &topo)){
		empilha(&C, topo);
		flag = 1; //Caso B não esteja vazia, esta Flag marcará o retorno como 1, indicando a realização da cópia
	}
	while(desempilha(&C, &topo)){
		empilha(A, topo);
		empilha(B, topo);
	}
	return flag;
}

void clear_screen(){
	system("cls");
}

void pause_screen(){
	system("pause");
	cout << endl;
}

int main(){
	pilha A, B, binario;
	int opt, decimal;
	item insere;
	item retornos;
	char expressao[100], lista_escolhida;

	do{
		fflush(stdin);
		clear_screen();
		cout << "[01] Inicializar pilhas A, B e Binario" << endl;
		cout << "[02] Pilha vazia?" << endl;
		cout << "[03] Mostrar pilha" << endl;
		cout << "[04] Inserir elemento" << endl;
		cout << "[05] Tirar primeiro" << endl;
		cout << "[06] Mostrar item do topo" << endl;
		cout << "[07] Expressao regular" << endl;
		cout << "[08] Esvaziar pilha" << endl;
		cout << "[09] Decimal para Binario" << endl;
		cout << "[10] Copia B para A" << endl;
		cin >> opt;
		switch(opt){
			case 1:
				inicializa(&A);
				inicializa(&binario);
				inicializa(&B);
				cout << "PILHAS INICIALIZADAS" << endl;
				pause_screen();
			break;

			case 2:
				if(vazia(&A)) cout << "PILHA 'A' VAZIA" << endl;
				else cout << "PILHA 'A' NAO VAZIA" << endl;
				if(vazia(&B)) cout << "PILHA 'B' VAZIA" << endl;
				else cout << "PILHA 'B' NAO VAZIA" << endl;
				pause_screen();
			break;

			case 3:
				clear_screen();
				cout << "PILHA A COMPLETA: ";
				mostra_pilha(&A);
				cout << "PILHA B COMPLETA: ";
				mostra_pilha(&B);
				pause_screen();
			break;

			case 4:
				clear_screen();
				cout << "Insira o elemento que deseja inserir: ";
				cin >> insere.chave;
				cout << "Em qual lista inserir? ";
				cin >> lista_escolhida;
				if(lista_escolhida == 'A' || lista_escolhida == 'a')
					empilha(&A, insere);
				else if(lista_escolhida == 'B' || lista_escolhida == 'b')
					empilha(&B, insere);
				cout << "ELEMENTO INSERIDO" << endl;
				pause_screen();
			break;

			case 5:
				clear_screen();
				cout << "De qual lista tirar? ";
				cin >> lista_escolhida;
				if(lista_escolhida == 'A' || lista_escolhida == 'a'){
					if(desempilha(&A, &retornos))
						cout << retornos.chave << " RETIRADO COM SUCESSO" << endl;
					else cout << "ERRO NA REMOCAO" << endl;
				}
				else if(lista_escolhida == 'B' || lista_escolhida == 'b'){
					if(desempilha(&B, &retornos))
						cout << retornos.chave << " RETIRADO COM SUCESSO" << endl;
					else cout << "ERRO NA REMOCAO" << endl;
				}
				pause_screen();
			break;

			case 6:
				if(topo(&A, &retornos))
					cout << "ITEM DO TOPO DE 'A': " << retornos.chave << endl;
				else cout << "LISTA 'A' VAZIA!" << endl;
				if(topo(&B, &retornos))
					cout << "ITEM DO TOPO DE 'B': " << retornos.chave << endl;
				else cout << "LISTA 'B' VAZIA!" << endl;
				pause_screen();
			break;

			case 7:
				clear_screen();
				cout << "Escreva a expressao: ";
				cin >> expressao;
				if(exp_regular(expressao, strlen(expressao)))
					cout << "EXPRESSAO CORRETA!" << endl;
				else cout << "EXPRESSAO INCORRETA" << endl;
				pause_screen();
			break;

			case 8:
				cout << "Qual lista esvaziar? ";
				cin >> lista_escolhida;
				if(lista_escolhida == 'A' || lista_escolhida == 'a'){
					if(esvazia_pilha(&A))
						cout << "PILHA ESVAZIADA COM SUCESSO!" << endl;
					else cout << "ERRO NA OPERACAO" << endl;
				}
				else if(lista_escolhida == 'B' || lista_escolhida == 'b'){
					if(esvazia_pilha(&B))
						cout << "PILHA ESVAZIADA COM SUCESSO!" << endl;
					else cout << "ERRO NA OPERACAO" << endl;	
				}
				pause_screen();
			break;

			case 9:
				esvazia_pilha(&binario);
				clear_screen();
				cout << "Digite o numero decimal: ";
				cin >> decimal;
				dec_to_bin(decimal, &binario);
				cout << decimal << " em binario: ";
				mostra_bin(&binario);
				pause_screen();
			break;

			case 10:
				if(copia_pilha(&A, &B))
					cout << "COPIA EFETUADA" << endl;
				else cout << "PILHA B VAZIA!" << endl;
				pause_screen();
			break;
		}
	}while(opt != 0);
}