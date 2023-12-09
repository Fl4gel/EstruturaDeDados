#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

// prod-2011-2010.txt
// o ano do mês quando foi gerado e depois o ano aos quais os semestres pertencem
int main()
{
    double ValoresProdutos[10]; // O usuário que vai definir os valores dos produtos

    Lista *MatrizSemestre1 = criarListaVazia(); // inicializar uma nova matriz
    Lista *MatrizSemestre2 = criarListaVazia(); // inicializar a matriz do segundo semesestre

    LerArquivoEntrada("prod-2022-1.txt", MatrizSemestre1); // pega os dados do arquivo .txt
    LerArquivoEntrada("prod-2022-2.txt", MatrizSemestre2);
    printf("\n\n");
    // ImprimirMatriz(MatrizSemestre1);
    //// printf("\n---------------------------------------------------\n");
    // ImprimirMatriz(MatrizSemestre2);




    // A função SomarValoresDaColuna não funciona
    printf("\n-------------------------------------------------\n");
    int SomaColuna1_1 = SomarValoresDaColuna(MatrizSemestre1, 0);
    printf("Soma da coluna %d", SomaColuna1_1);

    // ImprimirMatriz(MatrizSemestre1);
    LerValoresUnitarios(ValoresProdutos);

    printf("\n\n\n\n\n\n\n\n\n\n");
    //Gera o arquivo mas o arquivo vem vazio 
   GerarArquivoDeSaida("prod-2022-2023.txt", MatrizSemestre1, ValoresProdutos);
   


    return 0;
}


// Parte usada para teste, e todos tiveram sucesso
/*
    int soma1_0 = SomarValoresDaLinha(MatrizSemestre1, 0);
    ImprimirElementosDaLinha(MatrizSemestre1, 0);
    printf("Soma das linhas %d", soma1_0);
    printf("\n---------------------------------------------------\n");
    int soma1_1 = SomarValoresDaLinha(MatrizSemestre1, 1);
    ImprimirElementosDaLinha(MatrizSemestre1, 1);
    printf("Soma das linhas %d", soma1_1);
    printf("\n---------------------------------------------------\n");
    int soma1_2 = SomarValoresDaLinha(MatrizSemestre1, 2);
    ImprimirElementosDaLinha(MatrizSemestre1, 2);
    printf("Soma das linhas %d", soma1_2);
    printf("\n---------------------------------------------------\n");
    int soma1_3 = SomarValoresDaLinha(MatrizSemestre1, 3);
    ImprimirElementosDaLinha(MatrizSemestre1, 3);
    printf("Soma das linhas %d", soma1_3);
    printf("\n---------------------------------------------------\n");
    int soma1_4 = SomarValoresDaLinha(MatrizSemestre1, 4);
    ImprimirElementosDaLinha(MatrizSemestre1, 4);
    printf("Soma das linhas %d", soma1_4);
    printf("\n---------------------------------------------------\n");
    int soma1_5 = SomarValoresDaLinha(MatrizSemestre1, 5);
    ImprimirElementosDaLinha(MatrizSemestre1, 5);
    printf("Soma das linhas %d", soma1_5);
    printf("\n---------------------------------------------------\n");
    int soma1_6 = SomarValoresDaLinha(MatrizSemestre1, 6);
    ImprimirElementosDaLinha(MatrizSemestre1, 6);
    printf("Soma das linhas %d", soma1_6);
    printf("\n---------------------------------------------------\n");
    int soma1_7 = SomarValoresDaLinha(MatrizSemestre1, 7);
    ImprimirElementosDaLinha(MatrizSemestre1, 7);
    printf("Soma das linhas %d", soma1_7);
    printf("\n---------------------------------------------------\n");
    int soma1_8 = SomarValoresDaLinha(MatrizSemestre1, 8);
    ImprimirElementosDaLinha(MatrizSemestre1, 8);
    printf("Soma das linhas %d", soma1_8);
    printf("\n---------------------------------------------------\n");
    int soma1_9 = SomarValoresDaLinha(MatrizSemestre1, 9);
    ImprimirElementosDaLinha(MatrizSemestre1, 9);
    printf("Soma das linhas %d", soma1_9);
    printf("\n---------------------------------------------------\n");

    // Segunda matriz
    int soma2_0 = SomarValoresDaLinha(MatrizSemestre2, 0);
    ImprimirElementosDaLinha(MatrizSemestre2, 0);
    printf("Soma das linhas %d", soma2_0);
    printf("\n---------------------------------------------------\n");
    int soma2_1 = SomarValoresDaLinha(MatrizSemestre2, 1);
    ImprimirElementosDaLinha(MatrizSemestre2, 1);
    printf("Soma das linhas %d", soma2_1);
    printf("\n---------------------------------------------------\n");
    int soma2_2 = SomarValoresDaLinha(MatrizSemestre2, 2);
    ImprimirElementosDaLinha(MatrizSemestre2, 2);
    printf("Soma das linhas %d", soma2_2);
    printf("\n---------------------------------------------------\n");
    int soma2_3 = SomarValoresDaLinha(MatrizSemestre2, 3);
    ImprimirElementosDaLinha(MatrizSemestre2, 3);
    printf("Soma das linhas %d", soma2_3);
    printf("\n---------------------------------------------------\n");
    int soma2_4 = SomarValoresDaLinha(MatrizSemestre2, 4);
    ImprimirElementosDaLinha(MatrizSemestre2, 4);
    printf("Soma das linhas %d", soma2_4);
    printf("\n---------------------------------------------------\n");
    int soma2_5 = SomarValoresDaLinha(MatrizSemestre2, 5);
    ImprimirElementosDaLinha(MatrizSemestre2, 5);
    printf("Soma das linhas %d", soma2_5);
    printf("\n---------------------------------------------------\n");
    int soma2_6 = SomarValoresDaLinha(MatrizSemestre2, 6);
    ImprimirElementosDaLinha(MatrizSemestre2, 6);
    printf("Soma das linhas %d", soma2_6);
    printf("\n---------------------------------------------------\n");
    int soma2_7 = SomarValoresDaLinha(MatrizSemestre2, 7);
    ImprimirElementosDaLinha(MatrizSemestre2, 7);
    printf("Soma das linhas %d", soma2_7);
    printf("\n---------------------------------------------------\n");
    int soma2_8 = SomarValoresDaLinha(MatrizSemestre2, 8);
    ImprimirElementosDaLinha(MatrizSemestre2, 8);
    printf("Soma das linhas %d", soma2_8);
    printf("\n---------------------------------------------------\n");
    int soma2_9 = SomarValoresDaLinha(MatrizSemestre2, 9);
    ImprimirElementosDaLinha(MatrizSemestre2, 9);
    printf("Soma das linhas %d", soma2_9);
    printf("\n---------------------------------------------------\n");
    
    
    
      //  Essa parte é para calcular a soma total da linha, ou seja de um produto do mes 1 no caso janeiro até o mês 12, dezembro funciona
    int SomaF1 = soma1_0 + soma2_0;
    int SomaF2 = soma1_1 + soma2_1;
    int SomaF3 = soma1_2 + soma2_2;
    int SomaF4 = soma1_3 + soma2_3;
    int SomaF5 = soma1_4 + soma2_4;
    int SomaF6 = soma1_5 + soma2_5;
    int SomaF7 = soma1_6 + soma2_6;
    int SomaF8 = soma1_7 + soma2_7;
    int SomaF9 = soma1_8 + soma2_8;
    int SomaF10 = soma1_9 + soma2_9;
    */
