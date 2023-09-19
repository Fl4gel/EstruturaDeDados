#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para trocar duas palavras em um vetor(?)
void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Função Quicksort para ordenar o vetor de palavras
void quicksort(char *arr, int inicio, int fim, int *comparacoes, int *trocas) {
    if (inicio < fim) {
        int pivo = particionar(arr, inicio, fim, comparacoes, trocas);

        quicksort(arr, inicio, pivo, comparacoes, trocas);
        quicksort(arr, pivo + 1, fim, comparacoes, trocas);
    }
}

// Função para encontrar o pivô e particionar o vetor
//particionar para comparar em conjuntos de numeros menores e ordena-lo de forma geral
int particionar(char **arr, int inicio, int fim, int *comparacoes, int *trocas) {
    // Escolher o elemento central como pivô
    int meio = (inicio + fim) / 2;
    char *pivo = arr[meio];

    int i = inicio;
    int j = fim;

    while (1) {
        while (strcmp(arr[i], pivo) < 0) {
            (*comparacoes)++;
            i++;
        }
        while (strcmp(arr[j], pivo) > 0) {
            (*comparacoes)++;
            j--;
        }
        if (i >= j) {
            break;
        }

        (*trocas)++;
        trocar(&arr[i], &arr[j]);
        i++;
        j--;
    }

    return j;
}

int main(void) {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", 
        "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia",
         "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comparacoes = 0; // Contador de comparações
    int trocas = 0; // Contador de trocas

    // Ordenar o vetor de palavras usando o Quicksort
    quicksort(arr, 0, 19, &comparacoes, &trocas);

    // Exibir o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < 20; i++) {
        printf("%s\n", arr[i]);
    }

    // Gerar um arquivo de saída
    FILE *arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        fprintf(arquivo_saida, "%s\n", arr[i]);
    }
    fclose(arquivo_saida);

    // Calcular a mediana
    int indice_mediana = 20 / 2;
    char *mediana = arr[indice_mediana];

    printf("Mediana: %s\n", mediana);
    printf("Número de comparações: %d\n", comparacoes);
    printf("Número de trocas: %d\n", trocas);

    return 0;
}
