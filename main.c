#include "MazeGenerator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *arquivoLabirinto = NULL;
    int **labirinto = NULL;
    int linhas, colunas, dificuldade, opcao;
    char nomeArquivo[1000];

    srand((unsigned)time(NULL)); /* Fazendo com que labirintos diferentes sejam gerados
                                    a cada execução do programa */

    while (1) {
        printf("+----------------------------------+\n");
        printf("|  Programa Gerador de Labirintos  |\n");
        printf("+----------------------------------+\n");
        printf("|               MENU               |\n");
        printf("+----------------------------------+\n");
        printf("| 1 -> Escolher arquivo de saída   |\n");
        printf("| 2 -> Gerar labirinto no arquivo  |\n");
        printf("| 3 -> Sair do programa            |\n");
        printf("+----------------------------------+\n\n");

        printf("Entre com a opcao desejada: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                getchar();
                printf("Entre com o nome do arquivo de entrada: ");
                scanf("%[^\n]s", nomeArquivo);
                arquivoLabirinto = fopen(nomeArquivo, "w");
                printf("Arquivo de saida %s carregado com sucesso!\n\n", nomeArquivo);
                break;
            case 2:
                if (arquivoLabirinto == NULL)
                    printf("\nPor favor, escolha primeiro o arquivo de saida!\n\n");
                else {
                    /* Lendo a quantidade de linhas */
                    do {
                        printf("Entre com a quantidade de linhas: ");
                        scanf("%d", &linhas);
                        if (linhas < 1)
                            printf("Quantidade de linhas invalida!\n");
                    } while (linhas < 1);
                    /* Lendo a quantidade de colunas */
                    do {
                        printf("Entre com a quantidade de colunas: ");
                        scanf("%d", &colunas);
                        if (colunas < 1)
                            printf("Quantidade de colunas invalida!\n");
                    } while (colunas < 1);
                    labirinto = alocaLabirinto(linhas, colunas); //Alocando o labirinto
                    /* Lendo a dificuldade */
                    do {
                        printf("Entre com o nivel de dificuldade (1, 2 ou 3): ");
                        scanf("%d", &dificuldade);
                        if (dificuldade < 0 && dificuldade > 3)
                            printf("Dificuldade invalida!\n");
                    } while (dificuldade < 0 && dificuldade > 3);
                    /* Gerando o labirinto e o escrevendo no arquivo de saída */
                    geraLabirinto(labirinto, linhas, colunas, dificuldade);
                    escreveLabirintoArquivo(arquivoLabirinto, labirinto, linhas, colunas);
                    printf("\nLabirinto impresso no arquivo de saída com sucesso!\n\n");
                    fclose(arquivoLabirinto); //Fechando o arquivo de saída
                }
                break;
            case 3:
                printf("\nFim do programa gerador de labirintos!\n");
                return 0;
            default:
                printf("\nOpcao invalida!\n\n");
        }
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        system("clear");
    }
}
