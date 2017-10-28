#ifndef MAZEGENERATOR_H_INCLUDED
#define MAZEGENERATOR_H_INCLUDED

#include <stdio.h>

/* Declarações das funções contidas no arquivo MazeGenerator.c */
int** alocaLabirinto (int linhas, int colunas);
void geraLabirinto (int **labirinto, int linhas, int colunas, int dificuldade);
void escreveLabirintoArquivo (FILE *arquivoLabirinto, int **labirinto, int linhas, int colunas);

#endif // MAZEGENERATOR_H_INCLUDED
