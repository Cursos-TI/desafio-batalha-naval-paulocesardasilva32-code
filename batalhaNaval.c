#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

// Protótipos das funções para manter o código limpo e organizado
void limparTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], const char* nomeHabilidade);

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Coordenadas centrais para os disparos das habilidades (inseridas via variáveis)
    int centro_linha = 4;
    int centro_coluna = 4;

    printf("==================================================\n");
    printf("         BATALHA NAVAL - Nivel Mestre            \n");
    printf("==================================================\n\n");
    printf("Ponto de Origem dos Disparos: Linha %d, Coluna %d\n\n", centro_linha, centro_coluna);

    // ==========================================
    // 1. HABILIDADE EM CONE
    // ==========================================
    limparTabuleiro(tabuleiro);
    
    // O cone se expande para baixo a partir do topo (centro)
    // Linha 0 do cone: 1 bloco | Linha 1 do cone: 3 blocos | Linha 2 do cone: 5 blocos
    for (int i = 0; i < 3; i++) { // 3 linhas de altura para o cone
        int linha_atual = centro_linha + i;
        
        // Garante que não vamos tentar acessar uma linha fora do tabuleiro
        if (linha_atual < TAMANHO) {
            // A largura do cone aumenta a cada linha para a esquerda e para a direita
            for (int j = -i; j <= i; j++) {
                int coluna_atual = centro_coluna + j;
                
                // Garante que não vamos tentar acessar uma coluna fora do tabuleiro
                if (coluna_atual >= 0 && coluna_atual < TAMANHO) {
                    tabuleiro[linha_atual][coluna_atual] = 1;
                }
            }
        }
    }
    exibirTabuleiro(tabuleiro, "HABILIDADE: CONE");


    // ==========================================
    // 2. HABILIDADE EM CRUZ
    // ==========================================
    limparTabuleiro(tabuleiro);
    
    // A cruz afeta a linha inteira e a coluna inteira do centro, limitado a um alcance (ex: 2 blocos)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            // Se estiver na mesma linha do centro OU na mesma coluna do centro...
            // E limitando o alcance a no máximo 2 blocos de distância para ficar igual ao exemplo
            if (i == centro_linha && abs(j - centro_coluna) <= 2) {
                tabuleiro[i][j] = 1;
            }
            if (j == centro_coluna && abs(i - centro_linha) <= 2) {
                tabuleiro[i][j] = 1;
            }
        }
    }
    exibirTabuleiro(tabuleiro, "HABILIDADE: CRUZ");


    // ==========================================
    // 3. HABILIDADE EM OCTAEDRO (Losango)
    // ==========================================
    limparTabuleiro(tabuleiro);
    
    // Um octaedro 2D (losango) afeta posições onde a distância da linha + distância da coluna
    // em relação ao centro é menor ou igual ao raio do efeito (neste caso, raio = 1)
    int raio_octaedro = 1;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            // abs() calcula o valor absoluto (distância positiva)
            int distancia_linha = abs(i - centro_linha);
            int distancia_coluna = abs(j - centro_coluna);
            
            if (distancia_linha + distancia_coluna <= raio_octaedro) {
                tabuleiro[i][j] = 1;
            }
        }
    }
    exibirTabuleiro(tabuleiro, "HABILIDADE: OCTAEDRO");

    return 0;
}

// Função auxiliar para zerar o tabuleiro (água/área não afetada)
void limparTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função auxiliar para exibir a matriz de forma limpa e organizada
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], const char* nomeHabilidade) {
    printf("%s\n", nomeHabilidade);
    printf("    0 1 2 3 4 5 6 7 8 9 (Colunas)\n");
    printf("   ---------------------\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d | ", i); // Índice da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); // Requisito do printf("%d ", ...)
        }
        printf("\n");
    }
    printf("\n--------------------------------------------------\n\n");
}