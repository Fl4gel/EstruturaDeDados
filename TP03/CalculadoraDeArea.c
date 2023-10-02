#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

/*funcao para calcuar a areai
double area(double base, double altura) {
    double area = (base * altura) / 2.0;
    return area;
}

double calcularArea(double A1, double B1, double A2, double B2, double A3, double B3) {
    double base, altura;

    // Calcula a base como a distância entre os pontos 1 e 2
    base = sqrt(pow(A2 - A1, 2) + pow(B2 - B1, 2));

    // Calcula a altura como a distância perpendicular da linha formada pelos pontos 1 e 2 ao ponto 3
    altura = fabs((A2 - A1) * (B3 - B1) - (A3 - A1) * (B2 - B1)) / base;

    return area(base, altura); // Retorna a área calculada
}*/

int main() {
    Ponto p1, p2, p3; //utilizando a struc ponto
    int numeroVertices;

    FILE *entrada = fopen("Dados.txt","r");//abrindo o arquivo para leitura
    FILE *saida = fopen("Saida.txt","w");//abrindo ou criando o arquivo com os valores de saida

    if(entrada == NULL || saida == NULL){//para informar se deu alguma erro ao abrir os arquivos
    printf("Erro ao acessar os arquivos");
    return 1;
}

    fscanf(entrada,"%d",&numeroVertices);//Obter o 1 número no arquivo que é o numero de vertices do poligno

    if(numeroVertices>3 || numeroVertices<3){//informar que há um erro e o sistema não funcionará se for > 3
        printf("Deve ser um triângulo para o calculo funcionar");
        return 1;//para encerrar o programa
    }

    fscanf(entrada,"%f %f",&p1.X , &p1.Y);

    fscanf(entrada,"%f %f",&p2.X , &p2.Y);

    fscanf(entrada,"%f %f",&p3.X , &p3.Y);

    //Ler as coordenadas dos vértices do triângulo
    /*
    printf("Digite as coordenadas do vértice 1 (X Y): ");
    scanf("%f %f", &p1.X, &p1.Y);

    printf("Digite as coordenadas do vértice 2 (X Y): ");
    scanf("%f %f", &p2.X, &p2.Y);

    printf("Digite as coordenadas do vértice 3 (X Y): ");
    scanf("%f %f", &p3.X, &p3.Y);*/

    // Calcular a área do triângulo com a função definida em Ponto.c
    double areaTriangulo = calcularArea(p1, p2, p3);

    // Exibir a área
    printf("A área do triângulo é %.2lf\n", areaTriangulo);

    fclose(entrada);
    fclose(saida);

    return 0;
}


