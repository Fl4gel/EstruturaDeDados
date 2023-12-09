#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#define MAXLINHAS 10
#define MAXCOLUNAS 6

//Prótipo: void InserirElemento(Lista *matriz, int linha, int coluna, int valor)
//Função: Serve para adicionar um elemento na matriz
//Entrada: recebe a matriz, a linha, a coluna e o valor do Item a ser adicionado
//Saída: Nada
void InserirElemento(Lista *matriz, int linha, int coluna, int valor)
{
    Item *novoElemento = (Item *)malloc(sizeof(Item));
    if (novoElemento == NULL)
    {
        exit(EXIT_FAILURE);
    }

    novoElemento->linha = linha;
    novoElemento->coluna = coluna;
    novoElemento->valor = valor;
    novoElemento->proxLinha = NULL;
    novoElemento->antLinha = NULL;
    novoElemento->proxColuna = NULL;
    novoElemento->antColuna = NULL;

    // Inserir na lista de linhas
    if (matriz->cabecaLinha == NULL)
    {
        matriz->cabecaLinha = novoElemento;
    }
    else
    {
        novoElemento->proxLinha = matriz->cabecaLinha;
        matriz->cabecaLinha->antLinha = novoElemento;
        matriz->cabecaLinha = novoElemento;
    }

    // Inserir na lista de colunas
    if (matriz->cabecaColuna == NULL)
    {
        matriz->cabecaColuna = novoElemento;
    }
    else
    {
        novoElemento->proxColuna = matriz->cabecaColuna;
        matriz->cabecaColuna->antColuna = novoElemento;
        matriz->cabecaColuna = novoElemento;
    }

    //Códigos abaixo foram utilizados para apurar se estava sendo executado de forma correta
    // printf("Inserindo elemento: (%d, %d) = %d\n", linha, coluna, valor);
    // printf("(%d, %d): %d\n", novoElemento->linha, novoElemento->coluna, novoElemento->valor);

    matriz->Tamanho++;
}

//Prótipo: void LerArquivoEntrada(char *arquivo, Lista *matriz)
//Função: Ele lê um arquivo .txt no formato 10x6 representando os 10 produtos do semestre e insere esses valores na matriz
//Entrada:Recebe o nome do arquivo e qual matriz deve adicionar os reusltado
//Saída: nada
void LerArquivoEntrada(char *arquivo, Lista *matriz)
{
    FILE *arq = fopen(arquivo, "r");
    int v[6];
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; i++)
    {
        if (fscanf(arq, "%d %d %d %d %d %d", &v[0], &v[1], &v[2], &v[3], &v[4], &v[5]) == 6)
        {
            printf("Chegou No fscanf\n");

            for (int j = 0; j < 6; j++)
            {
                InserirElemento(matriz, i, j, v[j]);
            }
        }
        else
        {
            fprintf(stderr, "Erro ao ler a linha %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }

    fclose(arq); // Adicionei o fclose para fechar o arquivo após a leitura
}

//Prótipo:Lista *criarListaVazia()
//Função: Cria uma lista nova declarando as cabeças como nula e definindo o tamanho como 0
//Entrada: nada
//Saída: Devolve um ponteiro para a matriz gerada
Lista *criarListaVazia()
{
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));
    if (novaLista == NULL)
    {
        printf("Erro ao alocar memória para a lista.\n");
        exit(1);
    }
    novaLista->cabecaColuna = NULL;
    novaLista->cabecaLinha = NULL;
    novaLista->Tamanho = 0;
    return novaLista;
}

//Prótipo: void LerValoresUnitarios(double *V)
//Função: Ela recebe os preços dos produtos do usuário e os armazena em um vetor v
//Entrada:Recebe o endereço para o vetor V
//Saída: Nada
void LerValoresUnitarios(double *V)
{
    char produto[10][50];
    strcpy(produto[0], "Sola inteira: ");
    strcpy(produto[1], "Meia sola: ");
    strcpy(produto[2], "Quarto de sola: ");
    strcpy(produto[3], "Entre sola: ");
    strcpy(produto[4], "Palmilha: ");
    strcpy(produto[5], "Meia palmilha: ");
    strcpy(produto[6], "Salto alto: ");
    strcpy(produto[7], "Salto medio: ");
    strcpy(produto[8], "Salto curto: ");
    strcpy(produto[9], "Salto baixo: ");

    printf("Informe os valores unitários para cada um dos 10 produtos:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Valor do produto %s", produto[i]);
        scanf("%lf", &V[i]); // Agora os valores dos produtos estão salvos como V
    }
}

//Prótipo: void JuntarMatriz(Lista *matriz1, Lista *matriz2)
//Função: Deveria juntar as duas matriz para vacilitar o calculo do total ----> Não funciona
//Entrada:Endereço da matriz1 e da matriz2
//Saída: Nada
void JuntarMatriz(Lista *matriz1, Lista *matriz2)
{
    // Encontrar o último nó da última coluna da primeira matriz
    Item *ultimoNo = matriz1->cabecaColuna;
    while (ultimoNo->proxColuna != NULL)
    {
        ultimoNo = ultimoNo->proxColuna;
    }

    // Adicionar os valores da segunda matriz na continuação da primeira
    Item *noMatriz2 = matriz2->cabecaColuna;

    while (noMatriz2 != NULL)
    {
        // Adiciona o valor na continuação da última coluna da primeira matriz
        InserirElemento(matriz1, noMatriz2->linha, noMatriz2->coluna + matriz1->Tamanho, noMatriz2->valor);

        // Move para o próximo nó da segunda matriz
        noMatriz2 = noMatriz2->proxColuna;
    }
}

//Prótipo:void ImprimirMatriz(Lista *matriz)
//Função: Imprime os valores da matriz
//Entrada:Recebe um ponteiro para a matriz
//Saída: nada (mas imprime os valores por um printf dentro da função, então não "devolve" nada)
void ImprimirMatriz(Lista *matriz)
{
    for (int i = 0; i < matriz->Tamanho; i++)
    {
        Item *noAtual = matriz->cabecaLinha;

        while (noAtual != NULL && noAtual->linha != i)
        {
            noAtual = noAtual->proxLinha;
        }

        if (noAtual != NULL)
        {
            while (noAtual != NULL && noAtual->linha == i)
            {
                if (noAtual->valor != 0)
                {
                    printf("(%d, %d): %d ", noAtual->linha, noAtual->coluna, noAtual->valor);
                }
                noAtual = noAtual->proxColuna;
            }
            printf("\n");
        }
        else
        {
            // Se a linha não está presente, imprima a linha vazia para apurara para erros
            for (int j = 0; j < 6; j++)
            {
                printf("(%d, %d): 0 ", i, j);
            }
            printf("\n");
        }
    }
}





//Prótipo:void GerarArquivoDeSaida(char *nome_arquivo, Lista *matriz, double *ValoresProdutos)
//Função: Deveria gerar um arquivo txt de acordo com as intruções do professor ----> não funciona
//Entrada:Recebe o nome do arquivo a ser gerado(ou criado), a matriz a ser utilizada e os Valores dos Produtos
//Saída: 
void GerarArquivoDeSaida(char *nome_arquivo, Lista *matriz, double *ValoresProdutos)
{
    FILE *arq_saida = fopen(nome_arquivo, "w");

    if (arq_saida == NULL)
    {
        perror("Erro ao abrir o arquivo de saída");
        exit(EXIT_FAILURE);
    }

    // Escrever cabeçalho
    fprintf(arq_saida, "--------------------------------------------------------------------------\n");
    fprintf(arq_saida, " Produção anual total em unidades por produto\n");
    fprintf(arq_saida, "---------------------------------------------------------------------------\n");

    // Escrever informações por linha
    for (int i = 0; i < matriz->Tamanho; i++)
    {
        int totalLinha = SomarValoresDaLinha(matriz, i);

        // Escrever nome do produto e total
        fprintf(arq_saida, "%-15s %4d\n", NomeProduto(i), totalLinha);
    }

    // Escrever linha com o total geral
    fprintf(arq_saida, "Total: %14d\n", SomarValoresMatriz(matriz));

    fclose(arq_saida);
}

// Função auxiliar para obter o nome do produto com base no índice da linha
const char *NomeProduto(int indice)
{
    const char *nomes[10] = {
        "Sola inteira",
        "Meia sola",
        "Quarto de sola",
        "Entre sola",
        "Palmilha",
        "Meia palmilha",
        "Salto alto",
        "Salto medio",
        "Salto curto",
        "Salto baixo"};

    return nomes[indice];
}

//Prótipo:int SomarValoresMatriz(Lista *matriz)
//Função: Soma os valores da matriz
//Entrada: Recebe o endereço da matriz
//Saída:  Devolve a soma total dos valores( valores não preços, mas sim valores dos Itens)
int SomarValoresMatriz(Lista *matriz) {
    int soma = 0;

    // Percorre todos os elementos da matriz
    Item *noAtual = matriz->cabecaLinha;

    while (noAtual != NULL) {
        soma += noAtual->valor;
        noAtual = noAtual->proxColuna;
    }

    return soma;
}



//Prótipo: int SomarValoresDaLinha(Lista *matriz, int linha)
//Função:Soma os valores de uma linha, percorrendo as colunas uma a uma
//Entrada:Recebe a matriz e qual a linha deve ser percorrida 
//Saída: devolve a soma total da linha
int SomarValoresDaLinha(Lista *matriz, int linha)
{
    int soma = 0;

    // Encontrar o primeiro nó da linha
    Item *noAtual = matriz->cabecaLinha;

    // Percorrer os elementos da linha e somar os valores
    while (noAtual != NULL && noAtual->linha != linha)
    {
        noAtual = noAtual->proxLinha;
    }

    // Verificar se a linha foi encontrada
    if (noAtual != NULL && noAtual->linha == linha)
    {
        // Somar os valores da linha
        while (noAtual != NULL && noAtual->linha == linha)
        {
            soma += noAtual->valor;
            noAtual = noAtual->proxColuna;
        }
    }

    return soma;
}

//Prótipo:int SomarValoresDaColuna(Lista *matriz, int coluna)
//Função: Deveria somar os valores de uma coluna, percorrendo-a, mas mesmo tendo uma aplicação praticamente idêntica a anterior por alguma motivo ela não funciona corretamente.
//Entrada: Recebe o Endereço da matriz e qual coluna deve ser percorrida 
//Saída: Devol a soma total dos valores na coluna 
int SomarValoresDaColuna(Lista *matriz, int coluna) {
    int soma = 0;

    // Percorre os elementos da coluna e soma os valores
    Item *noAtual = matriz->cabecaColuna;

    while (noAtual != NULL) {
        if (noAtual->coluna == coluna) {
            soma += noAtual->valor;
        }
        noAtual = noAtual->proxColuna;
    }

    return soma;
}

//Prótipo:void ImprimirElementosDaLinha(Lista *matriz, int linha)
//Função: Ela imprime todos os elementos de uma linha juntos com suas coordenadas, foi desenvolvida pois a função SomarValoresLinhas estava falhando 
//Entrada:Recebe o endereo da matriz e qual linha deve ser impressa 
//Saída: nada (Imprime os valores juntois com suas coordenadas)
void ImprimirElementosDaLinha(Lista *matriz, int linha)
{
    Item *noAtual = matriz->cabecaLinha;

    while (noAtual != NULL && noAtual->linha != linha)
    {
        noAtual = noAtual->proxLinha;
    }

    while (noAtual != NULL && noAtual->linha == linha)
    {
        printf("(%d, %d): %d\n", noAtual->linha, noAtual->coluna, noAtual->valor);
        noAtual = noAtual->proxColuna;
    }
}

//Prótipo:void GerarMatrizFinal(Lista *matriz)
//Função:  Deveria gerar a matriz final, mas como grande parte das funções ficaram incompletas ou com muitas erros sua implementação não foi possível
//Entrada: Endereço Matriz
//Saída: Nada
void GerarMatrizFinal(Lista *matriz)
{
    
}


//Prótipo:double MaiorValorDaLinha(Lista *matriz, int nlin)
//Função: Deveria devolver qual o maior elemento da linha
//Entrada: Endereço da matriz e número da linha
//Saída: Devolve qual o maior 
double MaiorValorDaLinha(Lista *matriz, int nlin)
{
    
}

//Prótipo: double MaiorValorDaColuna(Lista *matriz, int ncol)
//Função: Deveria devolver qual o maior elemento da coluna
//Entrada:Recebe o endereço da matriz e qual coluna deve ser percorrida 
//Saída: Devolve qual o maior
double MaiorValorDaColuna(Lista *matriz, int ncol)
{
  
}

//Prótipo:double MenorValorDaLinha(Lista *matriz, int nlin)
//Função: Deveria devolver qual o menor elemento da linha
//Entrada:Recebe o endereço da matriz e qual linha deve ser percorrida 
//Saída:   Devolve qual o menor
double MenorValorDaLinha(Lista *matriz, int nlin)
{
}

//Prótipo:double MenorValorDaColuna(Lista *matriz, int ncol)
//Função:Deveria devolver qual o menor elemento da coluna 
//Entrada: Recebe o endereço da matriz e qual coluna deve ser percorrida 
//Saída: Devolve qual o menor
double MenorValorDaColuna(Lista *matriz, int ncol)
{
    // Implemente a busca do menor valor em uma coluna da matriz.
}
