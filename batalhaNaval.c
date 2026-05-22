#include <stdio.h>

#define TAMANHO 10

int main() {
    // 1. Inicializa o tabuleiro 10x10 completamente com 0 (água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // --- POSICIONAMENTO DOS NAVIOS ---

    // Navio 1: Horizontal (Tamanho 3) -> Linha 2, Colunas 1, 2, 3
    int h_linha = 2, h_col = 1;
    tabuleiro[h_linha][h_col] = 3;
    tabuleiro[h_linha][h_col + 1] = 3;
    tabuleiro[h_linha][h_col + 2] = 3;

    // Navio 2: Vertical (Tamanho 3) -> Coluna 7, Linhas 4, 5, 6
    int v_linha = 4, v_col = 7;
    tabuleiro[v_linha][v_col] = 3;
    tabuleiro[v_linha + 1][v_col] = 3;
    tabuleiro[v_linha + 2][v_col] = 3;

    // Navio 3: Diagonal Descendo/Direita (Tamanho 3) -> Linha+1 e Coluna+1
    // Posições: (0,0), (1,1), (2,2)
    int d1_linha = 0, d1_col = 0;
    tabuleiro[d1_linha][d1_col] = 3;
    tabuleiro[d1_linha + 1][d1_col + 1] = 3;
    tabuleiro[d1_linha + 2][d1_col + 2] = 3;

    // Navio 4: Diagonal Descendo/Esquerda (Tamanho 3) -> Linha+1 e Coluna-1
    // Posições: (7,5), (8,4), (9,3)
    int d2_linha = 7, d2_col = 5;
    tabuleiro[d2_linha][d2_col] = 3;
    tabuleiro[d2_linha + 1][d2_col - 1] = 3;
    tabuleiro[d2_linha + 2][d2_col - 2] = 3;


    // --- EXIBIÇÃO DAS COORDENADAS ---
    printf("==================================================\n");
    printf("         RELATORIO DE COORDENADAS (3 = NAVIO)     \n");
    printf("==================================================\n");
    printf("Navio Horizontal: (%d,%d), (%d,%d), (%d,%d)\n", h_linha, h_col, h_linha, h_col+1, h_linha, h_col+2);
    printf("Navio Vertical:   (%d,%d), (%d,%d), (%d,%d)\n", v_linha, v_col, v_linha+1, v_col, v_linha+2, v_col);
    printf("Navio Diagonal 1: (%d,%d), (%d,%d), (%d,%d)\n", d1_linha, d1_col, d1_linha+1, d1_col+1, d1_linha+2, d1_col+2);
    printf("Navio Diagonal 2: (%d,%d), (%d,%d), (%d,%d)\n\n", d2_linha, d2_col, d2_linha+1, d2_col-1, d2_linha+2, d2_col-2);


    // --- EXIBIÇÃO COMPLETA DO TABULEIRO ---
    printf("TABULEIRO COMPLETO 10x10:\n\n");
    
    // Imprime o cabeçalho das colunas (com espaçamento ajustado para alinhar)
    printf("    ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n   ---------------------\n");

    // Varre a matriz para desenhar as linhas
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d | ", i); // Imprime o índice da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}