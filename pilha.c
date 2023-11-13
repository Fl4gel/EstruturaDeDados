#include <stdio.h>
#include <stdlib.h>

#define erro -1
#define sim 1
#define nao 0

typedef struct Item{
    int chave;
    struct Item *Proximo;
} Item;

typedef struct Pilha{
    int Tamanho;
    Item *topo;
} Pilha;



Pilha *criarPilha(){

    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if(p == NULL){
        printf("Erro ao alocar memória");
        return erro;
    }
    p->Tamanho = 0;
    p->topo = NULL;
    return p;
}


int estaVazia (Pilha *p){ // foi usado int pelos define's lá em cima
    if(p->topo == NULL) return sim;
    else return nao;
}


Item *criarItem(int x) { // funcao para ser chamada na funcao empilhar
  Item *novoItem = (Item *) malloc(sizeof(Item));
  if(novoItem == NULL){
        printf("Erro ao alocar memória");
        return erro;
}
novoItem->chave = x;
novoItem->Proximo = NULL;
return novoItem;
}


void empilhar(Pilha *p, int chave) {// funcao que vai empilhar o elemento, void porque não tem retorno
    Item *novoItem = criarItem(chave);
    novoItem->Proximo = p->topo;
    p->topo = novoItem;
    p->Tamanho= p->Tamanho + 1;
}

int desempilhar(Pilha *p){// int porque retorna o chave
    if(estaVazia(p) == sim){
        printf("Erro: a pilha ja está vazia");
        return erro;
    }
    Item *temp = p->topo;
    int chave = temp->chave;
    p->topo = temp->Proximo;
    free(temp);
    p->Tamanho = p->Tamanho - 1;
    return chave;
}

void liberarPilha(Pilha *p){//usa a funcao desempilhar para ir descartando essas porras
    while(!estaVazia(p)){
        desempilhar(p);
    }
    free(p);
}


int main() {
    Pilha *p = criarPilha();
    empilhar(p, 10);
    empilhar(p, 38);
    empilhar(p, 10);
    empilhar(p, 50);
    empilhar(p, 30);
    printf("Desempilhando...\n");
    while(!estaVazia(p)) {
        printf("Chave : %d\n", desempilhar(p));
    }
    liberarPilha(p);
    return 0;
}
