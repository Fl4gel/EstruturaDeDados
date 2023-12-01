#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define sim 1
#define nao 0

typedef struct Item
{ // trocar para No e dados
    double chave;
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

Item *criarItem(double x)
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

void empilhar(Pilha *p, double chave)
{ // funcao que vai empilhar o elemento, void porque não tem retorno
    Item *novoItem = criarItem(chave);
    novoItem->Proximo = p->topo;
    p->topo = novoItem;
    p->Tamanho = p->Tamanho + 1;
}

double desempilhar(Pilha *p) {
    if (estaVazia(p) == sim) {
        printf("Erro: a pilha está vazia");
        return -1.0; // Retorna um valor padrão em caso de erro
    }
    Item *temp = p->topo;
    double chave = temp->chave;
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

void removerEspacos(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

double calculo(Pilha *p, char *x) {
    double resultado;
    char conta;
    double temp;

    
    if (*x == '+' || *x == '-' || *x == '*' || *x == '/' || *x == '^') {

        if (p->Tamanho < 2) {
            printf("Erro no cáculo, a pilha não tem valores suficientes para uma operação binária");
            return 1;
        }
        double op2 = desempilhar(p);
        double op1 = desempilhar(p);

        switch (*x) {

            case '+':
                resultado = op1 + op2;
                printf("%.2f + %.2f ", op1,op2);
                return resultado;
                break;

            case '-':
                resultado = op1 - op2;
                printf("%.2f - %.2f ", op1,op2);
                return resultado;
                break;

            case '*':
                resultado = op1 * op2;
                printf("%.2f * %.2f ", op1,op2);
                return resultado;
                break;

            case '/':
                resultado = op1 / op2;
                printf("%.2f / %.2f ", op1,op2);
                return resultado;
                break;

            case '^':
                resultado = pow(op2, op1);
                printf("%.2f ^ %.2f ", op1,op2);
                return resultado;
                break;

            default:
                printf("Erro");
                break;
        }
    } else if (*x == 'l' || *x == 'c' || *x == 't' || *x == 's') {

        if (estaVazia(p)) {
            printf("Erro, a pilha está vazia");
            return 0.0;
        }
                double valor = desempilhar(p);
        switch (*x) {



            case 'l':
                resultado = log10(valor);
                printf("log(%.3lf)",valor);
                return resultado;
                break;

            case 's':
                resultado = sin(valor);
                printf("sen(%.3lf)",valor);
                return resultado;
                break;

            case 'c':
                resultado = cos(valor);
                printf("cos(%.3lf)",valor);
                return resultado;
                break;
            case 't':
                resultado = tan(valor);
                printf("tg(%.3lf)",valor);
                return resultado;
                break;

            default:
                break; // até aqui tudo funciona
        }
    } else {
        printf("Erro: operador %c não aceito", *x);
        exit(1);
    }
}




// Operadores chatos


// Definições de pilha e funções que você já implementou...
int main()
{

    Pilha *p = criarPilha();
    char expressao[100];
    double temp;

    // Era bom transformar em uma expressão em vez de deixar na main
    printf("Utilize 'l' para logaritmo\n'c' para cosseno\n's' para seno\n't' para tangente\n'^' para potenciação e os quatro operadores básicos\n");
    printf("Insira a expressao pos-fixa (separe com espacos): ");
    
    fgets(expressao, sizeof(expressao), stdin); // recebe a expressão

    char *token = strtok(expressao, " "); // pega as informações separadas pelo espaço

    while (token != NULL)
    {
        if (isdigit(token[0]))
        { // Se for um dígito, é um operando

                //Tudo aqui dentro está funcionando
            temp = strtod(token, NULL); // string to double strod, o NULL é porcausa dos argumentos que a função strtod pede
            empilhar(p, temp); // coloca no topo da pilha
        }
        else
        { // Se não for dígito, é um operador

            double resultado = calculo(p, token);

            empilhar(p, resultado);
        }

        token = strtok(NULL, " ");
    }

    printf("\nO resultado final da expressao pos-fixa: %.3f\n", topo(p));

    // liberarPilha(p);

    return 0;
}
