#ifndef Pilha_H
#define Pilha_H

typedef struct Item{
    int chave;
    struct Item *Proximo;
} Item;

typedef struct Pilha{
    int Tamanho;
    Item *topo;
} Pilha;

//Assinatura das funções 

Pilha *criarPilha();
int estaVazia(Pilha *p);
Item *criarItem(int x);
void empilhar(Pilha *p, int chave);
int desempilhar(Pilha *p);
int topo(Pilha* p);
void liberarPilha(Pilha *p);
//e recuperar o tamanho da pilha
//Falta  localizar  o i-ésimo elemento

#endif