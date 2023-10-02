#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int chave;
     //Outros campos...
} Item;

typedef struct {
	Item *array;
	int Tamanho; //Número de Itens na lista
	int Capacidade; // Número máximo de itens que a lista suporta
}Lista;


Lista* criarLista(int Capacidade) {
	Lista *X = (Lista*) malloc(sizeof(Lista));  //sizeof indica em bites             Reservando memória para a lista(total)
 	if (X == NULL){
		perror("Erro ao alocar memória para a lista.");
		exit(1);
	}
	
	X->array = (Item *)malloc(Capacidade * sizeof(Item));                        //reservando memória para cada Item
	if(X->array == NULL){
		perror("Erro ao alocar memória para os Itens.");
		exit(1);
	}
	
	X->Capacidade = Capacidade;
	X->Tamanho = 0;
	
	return X;

}


void inserirElemento(Lista *X, Item Elemento){

    if(X->Tamanho >= X->Capacidade) {
        printf("Não é possível adicionar mais um elemento pois a lista está cheia");
        return;
    }

    X->array[X->Tamanho] = Elemento;
    X->Tamanho++;

}

Item* localizarElemento(Lista *X, int indice){

    if(indice>X->Tamanho){
        printf("A posição não existe dentro da lista ");
        return;
    }

     printf("%d\n", X->array[indice]);
     return &(X->array[indice]);

};


Lista* combinarLista(Lista *A, Lista *B){
    int Capacidade = A->Capacidade + B->Capacidade;
    Lista* novaLista = criarLista(Capacidade);

    for(int i = 0; i < A->Tamanho;i++){
        inserirElemento (novaLista, A->array[i]); //pra cada elemento da lista A você coloca na nova lista
    }
    for(int i = 0; i < B->Tamanho;i++){
        inserirElemento (novaLista, B->array[i]); //pra cada elemento da lista B você coloca na nova lista
    }
}


int main() {
     int i =0;
     int Indice;
    setlocale(LC_ALL,"");
	
	int capacidade = 20;
	Lista* A = criarLista(capacidade); // retorna um ponteiro pra lista
	printf("\n Tamanho %d\n", A->Tamanho);
	// printf("Memória alocada: %d", sizeof(lista));

    Item elemento1 = {1};
    Item elemento2 = {2};
    Item elemento3 = {3};
    Item elemento4 = {4};
    Item elemento5 = {5};
    inserirElemento(A, elemento1);
    inserirElemento(A, elemento2);
    inserirElemento(A, elemento3);
    inserirElemento(A, elemento4);
    inserirElemento(A, elemento5);

    Lista* B = criarLista(capacidade); // retorna um ponteiro pra lista
    printf("\n Tamanho %d\n", B->Tamanho);
    
    inserirElemento(B, (Item){1});
    inserirElemento(B, (Item){7});
    inserirElemento(B, (Item){13});
    inserirElemento(B, (Item){-1});
    inserirElemento(B, (Item){10});

    
    
    Lista* C = combinarLista(A,B);
    printf("\n Tamanho %d\n", C->Tamanho);
    
    
    
    
    
    
    
    
    
     //printf("Insira o indice");
    // scanf("%d",&Indice);

     //int numero = localizarElemento(lista,Indice);
     //printf("%d", numero);


     /*printf("\nTamanho: %d\n", lista->Tamanho);

     for(i=0;i<lista->Tamanho;i++){
        printf("%d\n", lista->array[i]);
     }*/
	
	free(A->array);
	free(A);
    free(B->array);
	free(B);
	
	
	
	return(0);
}