#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define TAM 100

using namespace std;

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
	for(int i=p->topo-1; i>=0; i--){
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

int topo(pilha* p, item* top){
	if(!vazia(p)){
		*top = p->dados[(p->topo)-1];
		return 1;
	}
	return 0;
}

int esvazia(pilha* p){ //exercício 4a
	if(!vazia(p)){
		p->topo = 0;
		return 1;
	}
	return 0;
}

int copia_pilha(pilha* A, pilha* B){
	pilha C;
	item insere;

	inicializa(&C);
	if(B->topo + A->topo <= TAM){
		for(int i=0; i<B->topo; i++){
			insere = B->dados[i];
			empilha(A, insere);
		}
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
	pilha A, B;
	item insere, retorno;
	int opt;
	char lista_escolhida;

	do{
		fflush(stdin);
		clear_screen();
		cout << "[1] Inicia pilha" << endl;
		cout << "[2] Pilha cheia?" << endl;
		cout << "[3] Pilha vazia?" << endl;
		cout << "[4] Mostra pilha" << endl;
		cout << "[5] Insere elemento" << endl;
		cout << "[6] Tira elemento" << endl;
		cout << "[7] Mostrar item do topo" << endl;
		cout << "[8] Esvaziar pilha" << endl; 
		cout << "[9] "
		cin >> opt;
		switch(opt){
			case 1:
				inicializa(&A);
				inicializa(&B);
				cout << "PILHAS INICIALIZADAS" << endl;
				pause_screen();
			break;

			case 2:
				if(cheia(&A)) cout << "PILHA 'A' CHEIA" << endl;
				else cout << "PILHA 'A' NAO ESTA CHEIA" << endl;
				if(cheia(&B)) cout << "PILHA 'B' CHEIA" << endl;
				else cout << "PILHA 'B' NAO ESTA CHEIA" << endl;
				pause_screen();
			break;

			case 3:
				if(vazia(&A)) cout << "PILHA 'A' VAZIA" << endl;
				else cout << "PILHA 'A' NAO ESTA VAZIA" << endl;
				if(vazia(&B)) cout << "PILHA 'B' VAZIA" << endl;
				else cout << "PILHA 'B' NAO ESTA VAZIA" << endl;
				pause_screen();
			break;

			case 4:
				clear_screen();
				cout << "PILHA 'A' COMPLETA: ";
				mostra_pilha(&A);
				cout << "PILHA 'B' COMPLETA: ";
				mostra_pilha(&B);
				pause_screen();
			break;

			case 5:
				clear_screen();
				cout << "Digite o elemento que deseja inserir: ";
				cin >> insere.chave;
				cout << "Em qual lista inserir? ";
				cin >> lista_escolhida;
				if(lista_escolhida == 'A' || lista_escolhida == 'a'){
					if(empilha(&A, insere))
						cout << "ELEMENTO INSERIDO COM SUCESSO" << endl;
					else cout << "ERRO NA OPERACAO" << endl;
				}
				else if(lista_escolhida == 'B' || lista_escolhida == 'b'){
					if(empilha(&B, insere))
						cout << "ELEMENTO INSERIDO COM SUCESSO" << endl;
					else cout << "ERRO NA OPERACAO" << endl;
				}
				pause_screen();
			break;

			case 6:
				cout << "De qual pilha tirar? ";
				cin >> lista_escolhida;
				if(lista_escolhida == 'A' || lista_escolhida == 'a'){
					if(desempilha(&A, &retorno))
						cout << retorno.chave << " RETIRADO COM SUCESSO" << endl;
					else cout << "ERRO NA OPERACAO" << endl;
				}
				else if(lista_escolhida == 'B' || lista_escolhida == 'b'){
					if(desempilha(&B, &retorno))
						cout << retorno.chave << " RETIRADO COM SUCESSO" << endl;
					else cout << "ERRO NA OPERACAO" << endl;
				}
				pause_screen();
			break;
				
			case 7:
				if(topo(&A, &retorno))
					cout << "ITEM DO TOPO DE 'A': " << retorno.chave << endl;
				else cout << "ERRO NA OPERACAO" << endl;
				if(topo(&B, &retorno))
					cout << "ITEM DO TOPO DE 'B': " << retorno.chave << endl;
				else cout << "ERRO NA OPERACAO" << endl;
				pause_screen();
			break;

			case 8:
				cout << "Qual lista esvaziar? ";
				cin >> lista_escolhida;
				if(lista_escolhida == 'A' || lista_escolhida == 'a'){
					if(esvazia(&A))
						cout << "PILHA ESVAZIADA" << endl;
					else cout << "PILHA JA VAZIA" << endl;
				}
				else if(lista_escolhida == 'B' || lista_escolhida == 'b'){
					if(esvazia(&B))
						cout << "PILHA ESVAZIADA" << endl;
					else cout << "PILHA JA VAZIA" << endl;
				}
				
				pause_screen();
			break;

			case 9:
				if(copia_pilha(&A, &B))
					cout << "COPIA EFETUADA" << endl;
				else cout << "ERRO NA OPERACAO" << endl;
				pause_screen();
			break;
		}
	}while(opt!=0);
}