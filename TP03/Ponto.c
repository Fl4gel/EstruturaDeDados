#include <stdio.h>
#include "ponto.h"
#include <math.h>


double calcularArea(Ponto p1, Ponto p2, Ponto p3) {
    double base, altura;

    // Calcula a base como a distância entre os pontos p1 e p2
    base = sqrt(pow(p2.X - p1.X, 2) + pow(p2.Y - p1.Y, 2));

    // Calcula a altura como a distância perpendicular da linha formada pelos pontos p1 e p2 ao ponto p3
    altura = fabs((p2.X - p1.X) * (p3.Y - p1.Y) - (p3.X - p1.X) * (p2.Y - p1.Y)) / base;

    // Calcula e retorna a área (base * altura / 2)
    double areaTriangulo = (base * altura) / 2.0;
    return areaTriangulo;
}

