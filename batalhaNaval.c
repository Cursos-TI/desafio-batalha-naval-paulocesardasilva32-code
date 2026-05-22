#include <stdio.h>

#define LINHAS 5
#define COLUNAS 5

int main() {
    // 1. Inicializa o tabuleiro 5x5 com 0 (representando a água)
    int tabuleiro[LINHAS][COLUNAS] = {0};

    // 2. Posicionamento Manual dos Navios através de variáveis
    // Navio Horizontal (Tamanho 3) -> Linha 1, Colunas 1, 2 e 3
    int navioH_linha = 1;
    int navioH_coluna_inicio = 1;
    
    tabuleiro[navioH_linha][navioH_coluna_inicio] = 3;
    tabuleiro[navioH_linha][navioH_coluna_inicio + 1] = 3;
    tabuleiro[navioH_linha][navioH_coluna_inicio + 2] = 3;

    // Navio Vertical (Tamanho 3) -> Coluna 3, Linhas 2, 3 e 4
    int navioV_coluna = 3;
    int navioV_linha_inicio = 2;

    tabuleiro[navioV_linha_inicio][navioV_coluna] = 3;
    tabuleiro[navioV_linha_inicio + 1][navioV_coluna] = 3;
    tabuleiro[navioV_linha_inicio + 2][navioV_coluna] = 3;

    // 3. Exibição das Coordenadas de cada navio utilizando printf
    printf("=========================================\n");
    printf("      COORDENADAS DOS NAVIOS POSITIONADOS\n");
    printf("=========================================\n\n");

    printf("Navio Horizontal (Tamanho 3):\n");
    printf("Parte 1 -> Linha: %d, Coluna: %d\n", navioH_linha, navioH_coluna_inicio);
    printf("Parte 2 -> Linha: %d, Coluna: %d\n", navioH_linha, navioH_coluna_inicio + 1);
    printf("Parte 3 -> Linha: %d, Coluna: %d\n\n", navioH_linha, navioH_coluna_inicio + 2);

    printf("Navio Vertical (Tamanho 3):\n");
    printf("Parte 1 -> Linha: %d, Coluna: %d\n", navioV_linha_inicio, navioV_coluna);
    printf("Parte 2 -> Linha: %d, Coluna: %d\n", navioV_linha_inicio + 1, navioV_coluna);
    printf("Parte 3 -> Linha: %d, Coluna: %d\n\n", navioV_linha_inicio + 2, navioV_coluna);

    // 4. Exibição Visual do Tabuleiro (Opcional, mas ótimo para validação)
    printf("Visualizacao do Tabuleiro (0 = Agua, 3 = Navio):\n");
    printf("    0  1  2  3  4 (Colunas)\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%d | ", i); // Imprime o índice da linha
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}