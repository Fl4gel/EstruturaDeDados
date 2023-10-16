#include <stdio.h>
#include <stdlib.h>

int numeroDeOcorrencias(listaCircular *X, Item *Temp) {
    if (X->cabeca == NULL || Temp == NULL) {
        exit(1); // Verifica se a lista ou o elemento Temp são inválidos
    }
    int ocorrencias = 0;
    Item *atual = X->cabeca;

    while (atual != X->cabeca){
        if (atual->chave == Temp->chave) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }

    return ocorrencias;
}
