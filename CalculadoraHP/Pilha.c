#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define sim 1
#define nao 0

typedef struct Item
{ // trocar para No e dados
    int chave;
    struct Item *Proximo;
} Item;

typedef struct Pilha
{
    int Tamanho;
    Item *topo;
} Pilha;

Pilha *criarPilha()
{

    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL)
    {

        printf("Erro ao alocar memória");
        return NULL;
    }
    p->Tamanho = 0;
    p->topo = NULL;
    return p;
}

int estaVazia(Pilha *p)
{ // foi usado int pelos define's lá em cima
    if (p->topo == NULL)
        return sim;
    else
        return nao;
}

Item *criarItem(int x)
{ // funcao para ser chamada na funcao empilhar
    Item *novoItem = (Item *)malloc(sizeof(Item));
    if (novoItem == NULL)
    {
        printf("Erro ao alocar memória");
        return NULL;
    }
    novoItem->chave = x;
    novoItem->Proximo = NULL;
    return novoItem;
}

void empilhar(Pilha *p, float chave)
{ // funcao que vai empilhar o elemento, void porque não tem retorno
    Item *novoItem = criarItem(chave);
    novoItem->Proximo = p->topo;
    p->topo = novoItem;
    p->Tamanho = p->Tamanho + 1;
}

int desempilhar(Pilha *p)
{ // int porque retorna o chave
    if (estaVazia(p) == sim)
    {
        printf("Erro: a pilha ja está vazia");
        return -1;
    }
    Item *temp = p->topo;
    int chave = temp->chave;
    p->topo = temp->Proximo;
    free(temp);
    p->Tamanho = p->Tamanho - 1;
    return chave;
}

float topo(Pilha *p)
{ // Retorna o valor do elemento que está no topo
    if (estaVazia(p))
    {
        printf("Erro, a pilha está vazia");
        return 0.0;
    }
    return p->topo->chave;
}

void liberarPilha(Pilha *p)
{ // usa a funcao desempilhar para ir descartando essas porras
    while (!estaVazia(p))
    {
        desempilhar(p);
    }
    free(p);
}

float calculo(Pilha *p,char *x){
    double resultado;
    if(*x == '+' || *x == '-' || *x == '*' || *x == '/' || *x == '^'){

            double op2 = desempilhar(p);
            double op1 = desempilhar(p);

        switch (*x) {



            //Não pode fazer direto porque a ordem fica torta, tem que usar op's
        case '+': 
         resultado = op1 + op2;
         return resultado;
            break;

        case '-': 

         resultado = op1 - op2;
         return resultado;
            break;

        case '*': 

         resultado = op1 * op2;
         return resultado;
            break;

        case '/': 

         resultado = op1 / op2;
         return resultado;
            break;

            case '^': 

         resultado = pow(op1,op2);
         return resultado;
            break;
        
        default:
            break; // até aqui tudo funciona
        }
    
    } else if(strcmp(x, "log") == 0){
        double valor = desempilhar(p);
       resultado = log10(valor);
       return resultado;

    } else if(strcmp(x, "sen") == 0){
        resultado = sin(desempilhar(p));
        return resultado;

    } else if(strcmp(x, "cos") == 0){
        resultado = cos(desempilhar(p));
        return resultado;

    } else if(strcmp(x, "tg") == 0){
        resultado = tan(desempilhar(p));
        return resultado;
    }
}



// Operadores chatos


// Definições de pilha e funções que você já implementou...
int main()
{

    Pilha *p = criarPilha();
    char expressao[100];
    float temp;

    // Era bom transformar em uma expressão em vez de deixar na main
    printf("Insira a expressao pos-fixa (separe com espacos): ");
    fgets(expressao, sizeof(expressao), stdin); // recebe a expressão

    char *token = strtok(expressao, " "); // pega as informações separadas pelo espaço

    while (token != NULL)
    {
        if (isdigit(token[0]))
        { // Se for um dígito, é um operando

            temp = strtod(token, NULL); // string to double strod, o NULL é porcausa dos argumentos que a função strtod pede

            empilhar(p, temp); // coloca no topo da pilha
        }
        else
        { // Se não for dígito, é um operador

            double resultado = calculo(p, &token[0]);
            empilhar(p, resultado);
        }

        token = strtok(NULL, " ");
    }

    printf("O resultado final da expressao pos-fixa: %.f\n", topo(p));

    // liberarPilha(p);

    return 0;
}

/*
empilhar(p, 10);
printf("Elemento topo : %d\n", topo(p));
empilhar(p, 38);
printf("Elemento topo : %d\n", topo(p));
empilhar(p, 10);
printf("Elemento topo : %d\n", topo(p));
empilhar(p, 50);
printf("Elemento topo : %d\n", topo(p));
empilhar(p, 30);
printf("Elemento topo : %d\n", topo(p));

printf("Desempilhando...\n");
while (!estaVazia(p))
{
    printf("Chave : %d\n", desempilhar(p));
}
liberarPilha(p);*/