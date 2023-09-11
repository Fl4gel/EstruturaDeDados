#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct do aluno que será chamada depois
struct Aluno {
	float N1;
	float N2;
	char Nome[80];
};

int main(){
	FILE *entrada, *saida;
	char ArquivoEntrada[] = "DadosEntrada.csv";
	char ArquivoSaida[] = "SituacaoFinal.csv";
	
    //funcionado
	entrada = fopen(ArquivoEntrada, "r");
	if (entrada == NULL){
		printf("Erro ao abrir o arquivo de leitura,\nVerifique se a referência está correta");
		return 1;
	}
	//funcionado
	saida = fopen(ArquivoSaida, "w");
	if(saida == NULL) {
		printf("Erro ao abrir o arquivo destino,\nVerifique se a referência está correta");
		return 1;
	}
	
	char linha[256];
    while (fgets(linha, sizeof(linha), entrada)) {
        // Declarou as variáveis
        struct Aluno aluno;
        float media;
        char situacao[15];

        //Cria a tokenização pra formartar no arquivo csv

        //essa porra abaixo não está funcionando 
        char *token = strtok(linha, ",");
        strcpy(aluno.Nome, token);
        token = strtok(NULL, ","); //strtof para converter tipo string para calcular a média
        aluno.N1 = strtof(token, NULL);
        token = strtok(NULL, ",");
        aluno.N2 = strtof(token, NULL);

        media = (aluno.N1 + aluno.N2) / 2;

        //condicional está funcionando
        if (media >= 7.0) {
            strcpy(situacao, "APROVADO");
        } else {
            strcpy(situacao, "REPROVADO");
        }

        fprintf(saida, "%s, %.2f, %s\n", aluno.Nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    printf("Processamento concluído. Resultados escritos em %s\n", ArquivoSaida);

    return 0;
	
}
