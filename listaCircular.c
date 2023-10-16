























/*#include <stdio.h>
#include <stdlib.h>


//as structs a seguir deveriam ser incluidas no arquivo de cabeçalho (.h)
typedef struct Item {
    int chave;
    struct Item *proximo;
} Item;

typedef struct listaCircular {
    Item *cabeca;
    int tamanho;
} listaCircular ;


//implementando a função exibir lista
void exibirListaCircular(listaCircular *lista ){ //vai acessar a lista pelo ponteiro na cabeça(?)

  printf("Lista : ");
  Item *atual = lista->cabeca;// de inicia atual é o primeiro elemento da lista
  while (atual->proximo != lista->cabeca) { // Erro arrumado , não é mais NULL é até chegar na cabeça já que na lista ciruclar não tem o último apontaodo para NULL
    printf("%d", atual->chave);
    atual = atual->proximo; // atualização do ponteiro atual
  }
  printf("%d", atual->chave);
  printf("\n")
}

void exibirListaCircularV_02(listaCircular *lista ){ //vai acessar a lista pelo ponteiro na cabeça(?)

  printf("Lista : ");
  Item *atual = lista->cabeca;// de inicia atual é o primeiro elemento da lista
  while (atual->proximo != lista->cabeca) { // Erro arrumado , não é mais NULL é até chegar na cabeça já que na lista ciruclar não tem o último apontaodo para NULL
    printf("%d", atual->chave);
    atual = atual->proximo; // atualização do ponteiro atual
  }
  printf("%d", atual->chave);
  printf("\n")
}


//Implementação da função criarListaCircularVazia()
listaCircular *criarListaCircularVazia() { // vai devolver um ponteiro apontando pra essa lista criada
    listaCircular *novaLista = (listaCircular *) malloc(sizeof(listaCircular))//calcula o tamanho com base na listaCircular
    if(novaLista == NULL){
        printf("Erro ao alocar memória \n");
        exit(1); // ou return; -> return volta pra função que chamou essa exit mata o processamento
    }
    novaLista->cabeca = NULL;
    novaLista->tamanho = 0;
}

//Implementação da função para adicionar elemento no final da lista
void adicionarElemento(listaCircular *lista, Item *novoItem){
  if(novoItem == NULL){
    printf("O item passado é inválido.\n");
    return;
  }
  if(lista->cabeca == NULL){
    novoItem->proximo = novoItem; // formando um ciclo pois a lista esta vazia 
    lista->cabeca = novoItem;
  } else {
    novoItem->proximo = lista->cabeca; // agora o novoItem aponta para o primeiro que é o lista->cabeca
    Item *atual = lista->cabeca;
    while(atual->proximo != lista->cabeca){
        atual = atual->proximo;
    }
    atual->proximo = novoItem;

  }
  lista->tamanho++;

}

//função principal 
int main() {
    listaCircular *X = criarListaCircularVazia();
    Item *I1 = (Item *)malloc(sizeof(Item));
    Item *I2 = (Item *)malloc(sizeof(Item));
    Item *I3 = (Item *)malloc(sizeof(Item));
    Item *I4 = (Item *)malloc(sizeof(Item));

    I1->chave = 10;
    I2->chave = 20;
    I3->chave = 30;
    I4->chave = 40;
    
    adicionarElemento(X, I1);
    adicionarElemento(X, I2);
    adicionarElemento(X, I3);
    adicionarElemento(X, I4);

    printf("Tamanho : %d", X->tamanho);
}*/