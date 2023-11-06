#include <stdio.h>
#include <stdlib.h>

// Exemplo typedf
// typedef int booleano, toda vez que aparecer "booleano" vai valer com int

// Definindo os dados do tipo abstrato de dados fila
typedef struct Item
{              // typedef serve para renomear algo(?)
    int Chave; // poderia ser FILE *chave
    struct Item *Proximo;
} Item;

typedef struct Fila
{ // typedef serve para fazer a referência com o "Fila" Final
    Item *Inicio;
    Item *Final;
} Fila;

// Fila é o tipo de dados, fila é a variável que está sendo manipulada
// Função do tipo ponteiro porque o resultado é o local de memória onde
//  está sendo manipulada

// OBS : Caso os atributos de fila sejam NULL, a fila está vazia
// função criarFila();
Fila *criarFila()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila == NULL)
    {
        perror("Erro ao alocar memória para fila");
        exit(1);
    }
    fila->Inicio = NULL; // Pois a fila é vazia
    fila->Final = NULL;  // Vazia
    return fila;
}

// OBS: Retorna 1 caso f esteja vazia e 0 caso tenha elemento.
// Função: Verificar se está vazia
int estaVazia(Fila *f)
{
    if (f->Inicio == NULL)
        return 1;
    else
        return 0;

    // outra opção que teria o mesmo resultado
    //  return(f->Inicia == NULL);
}

// Função: enfileirar()

void enfileirar(Fila *f, int chave)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    if(novoItem == NULL)
    {
        printf("Erro na alcação de memória par ao item\n");
        exit(1);
    }

    novoItem->Chave = chave;
    novoItem->Proximo = NULL;

    if (estaVazia(f) == 1)
    { // Não precisar do == 1
        f->Inicio = novoItem;
        f->Final = novoItem;
    }
    else
    {
        f->Final->Proximo = novoItem; // O antigo último elemento que está apontando
        f->Final = novoItem;          // A fila tem a identificação de último item
        // ou seja, tem dois ponteiros apontando para o último, o ponteiro do elemento anterior e o elemento final fila
    }
}


//Função desenfileirar()
//OBS poderia ser void para só retirar o último elemento, mas nesse caso vai retornar
//o valor do elemento que foi retirado
int desenfileirar(Fila *f) {
    if(estaVazia(f)){
        printf("Erro: a fila está vazia \n");
        exit(1);
    }

    Item *temp = f->Inicio;
    int chave = temp->Chave;

    f->Inicio = temp->Proximo;
    free(temp);
    if(f->Inicio==NULL) f->Final = NULL; //A lista só tinha um elemento
    return(chave);
}

void imprimirFila(Fila *f) {
    Item* atual = f->Inicio;
    printf("Fila : ");
    while (atual != NULL) {
        printf("%d ", atual->Chave);
        atual = atual->Proximo;
    }
}

int main() {
    Fila *X = criarFila();
    enfileirar(X, 10);
    enfileirar(X, 20);
    enfileirar(X, 30);
    enfileirar(X, 40);
     
     imprimirFila(X);


    return 0;
}