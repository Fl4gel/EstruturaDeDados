#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct Item {
    int linha;
    int coluna;
    int valor;
    struct Item *proxLinha;
    struct Item *proxColuna;
    struct Item *antLinha;
    struct Item *antColuna;
} Item;

typedef struct Lista {
    Item *cabecaLinha;
    Item *cabecaColuna;
    int Tamanho;
} Lista;

Lista* criarListaVazia();

void InserirElemento(Lista *matriz, int linha, int coluna, int valor);

void LerArquivoEntrada(char* arquivo, Lista *matriz);

void LerValoresUnitarios(double *V);

int SomarValoresDaLinha(Lista *matriz, int linha);

int SomarValoresDaColuna(Lista *matriz, int coluna);

void ImprimirElementosDaLinha(Lista *matriz, int linha);

void JuntarMatriz(Lista *matriz1, Lista *matriz2);

void ImprimirMatriz(Lista *matriz);

const char *NomeProduto(int indice);

int SomarValoresMatriz(Lista *matriz);
void GerarMatrizFinal(Lista *matriz);
void GerarArquivoDeSaida(char *nome_arquivo, Lista *matriz, double *ValoresProdutos);
double MaiorValorDaLinha(Lista *matriz, int nlin);
double MaiorValorDaColuna(Lista *matriz, int ncol);
double MenorValorDaLinha(Lista *matriz, int nlin);
double MenorValorDaColuna(Lista *matriz, int ncol);

#endif

