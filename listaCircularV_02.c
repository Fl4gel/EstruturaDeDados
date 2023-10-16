#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int chave;
    struct Item *proximo;
} Item;

typedef struct listaCircular {
    Item *cabeca;
    int tamanho;
} listaCircular;

void exibirListaCircular(listaCircular *lista) {
    if (lista->cabeca == NULL) {
        printf("Lista vazia\n");
        return;
    }

    printf("Lista: ");
    Item *atual = lista->cabeca;
    do {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    } while (atual != lista->cabeca);
    printf("\n");
}

listaCircular *criarListaCircularVazia() {
    listaCircular *novaLista = (listaCircular *)malloc(sizeof(listaCircular));
    if (novaLista == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    novaLista->cabeca = NULL;
    novaLista->tamanho = 0;
    return novaLista;
}

void adicionarElemento(listaCircular *lista, Item *novoItem) {
    if (novoItem == NULL) {
        printf("O item passado é inválido.\n");
        return;
    }

    if (lista->cabeca == NULL) {
        lista->cabeca = novoItem;
        novoItem->proximo = novoItem; // Forma um ciclo pois a lista está vazia
    } else {
        novoItem->proximo = lista->cabeca;
        Item *atual = lista->cabeca;
        while (atual->proximo != lista->cabeca) {
            atual = atual->proximo;
        }
        atual->proximo = novoItem;
        lista->cabeca = novoItem; // Atualiza a cabeça da lista
    }

    lista->tamanho++;
}

int numeroDeOcorrencias(listaCircular *X, Item *Temp) {
    if (X->cabeca == NULL || Temp == NULL) {
        exit(1);
    }

    int ocorrencias = 0;
    Item *atual = X->cabeca;

    do {
        if (atual->chave == Temp->chave) {
            ocorrencias++;
        }
        atual = atual->proximo;
    } while (atual != X->cabeca);

    return ocorrencias;
}

int main() {
    listaCircular *X = criarListaCircularVazia();
    Item *I1 = (Item *)malloc(sizeof(Item));
    Item *I2 = (Item *)malloc(sizeof(Item));
    Item *I3 = (Item *)malloc(sizeof(Item));
    Item *I4 = (Item *)malloc(sizeof(Item));
    Item *I5 = (Item *)malloc(sizeof(Item));
    Item *I6 = (Item *)malloc(sizeof(Item));
    Item *I7 = (Item *)malloc(sizeof(Item));
    Item *I8 = (Item *)malloc(sizeof(Item));

    I1->chave = 56;
    I2->chave = 70;
    I3->chave = 15;
    I4->chave = 23;
    I5->chave = 15;
    I6->chave = 32;
    I7->chave = 45;
    I8->chave = 15;

    adicionarElemento(X, I1);
    adicionarElemento(X, I2);
    adicionarElemento(X, I3);
    adicionarElemento(X, I4);
    adicionarElemento(X, I5);
    adicionarElemento(X, I6);
    adicionarElemento(X, I7);
    adicionarElemento(X, I8);

    exibirListaCircular(X);

    Item Temp;
    Temp.chave = 15;

    int ocorrencias = numeroDeOcorrencias(X, Temp);
    printf("Ocorrências de %d em X: %d\n", Temp.chave, ocorrencias);

    printf("Tamanho: %d\n", X->tamanho);

    return 0;
}

