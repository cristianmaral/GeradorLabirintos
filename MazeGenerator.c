#include "MazeGenerator.h"
#include <stdlib.h>

/* Função para alocar o labirinto dinamicamente de acordo com a quantidade de linhas e colunas */
int** alocaLabirinto (int linhas, int colunas) {
    int **labirinto;
    int i;

    labirinto = (int **)malloc(linhas * sizeof(int *));
    for (i=0; i<linhas; i++) {
        labirinto[i] = (int *)malloc(colunas * sizeof(int));
    }
    return labirinto;
}

/* Função responsável por gerar randomicamente o labirinto de acordo com a dificuldade */
void geraLabirinto (int **labirinto, int linhas, int colunas, int dificuldade) {
    int i, j, linhaAux, colunaAux, qtdParedes = 0;

    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            labirinto[i][j] = 1;
        }
    }
    if (dificuldade == 1)
        qtdParedes = (linhas - 1) * colunas * 0.1;
    else if (dificuldade == 2)
        qtdParedes = (linhas - 1) * colunas * 0.2;
    else
        qtdParedes = (linhas - 1) * colunas * 0.4;

    labirinto[linhas - 1][rand() % colunas] = 2; //Posição inicial aleatória para o cachorro
    for (i=0; i<qtdParedes; i++) {
        do {
            linhaAux = rand() % (linhas - 1);
            colunaAux = rand() % colunas;
        } while (labirinto[linhaAux][colunaAux] != 1);
        labirinto[linhaAux][colunaAux] = 3;
    }
}

/* Função responsável por escrever no arquivo de saída o labirinto gerado de acordo com o padrão */
void escreveLabirintoArquivo (FILE *arquivoLabirinto, int **labirinto, int linhas, int colunas) {
    int i, j;

    fprintf(arquivoLabirinto, "%d %d\n", linhas, colunas);
    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            fprintf(arquivoLabirinto, "%d", labirinto[i][j]);
        }
        fprintf(arquivoLabirinto, "\n");
    }
}
