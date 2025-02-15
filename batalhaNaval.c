#include <stdio.h>

#define TAMANHO_TABULEIRO 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha][coluna + i] = 3; // 3 representa a parte do navio
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna] = 3; // 3 representa a parte do navio
    }
}

// Função para aplicar uma habilidade em cone
void habilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (i + j >= -2 && i + j <= 2 && linha + i >= 0 && linha + i < TAMANHO_TABULEIRO && coluna + j >= 0 && coluna + j < TAMANHO_TABULEIRO) {
                tabuleiro[linha + i][coluna + j] = 1; // 1 representa área atingida
            }
        }
    }
}

// Função para aplicar uma habilidade em cruz
void habilidadeCruza(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        tabuleiro[linha][i] = 1; // Horizontal
        tabuleiro[i][coluna] = 1; // Vertical
    }
}

// Função para aplicar uma habilidade em octaedro
void habilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2 && linha + i >= 0 && linha + i < TAMANHO_TABULEIRO && coluna + j >= 0 && coluna + j < TAMANHO_TABULEIRO) {
                tabuleiro[linha + i][coluna + j] = 1; // 1 representa área atingida
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com 0 (vazio)

    // Posicionamento dos navios (Nível Novato)
    posicionarNavioHorizontal(tabuleiro, 2, 3, 4); // Navio horizontal na linha 2, coluna 3
    posicionarNavioVertical(tabuleiro, 5, 6, 3); // Navio vertical na linha 5, coluna 6
    
    // Exibição do tabuleiro após posicionamento dos navios
    printf("Tabuleiro com navios:\n");
    exibirTabuleiro(tabuleiro);
    
    // Nível Aventureiro - Posicionamento de navios na diagonal
    posicionarNavioVertical(tabuleiro, 1, 1, 3); // Navio vertical na diagonal
    posicionarNavioHorizontal(tabuleiro, 4, 4, 4); // Outro navio na diagonal

    // Exibição do tabuleiro após posicionamento na diagonal
    printf("\nTabuleiro com navios na diagonal:\n");
    exibirTabuleiro(tabuleiro);

    // Nível Mestre - Aplicando habilidades especiais

    // Habilidade em cone
    habilidadeCone(tabuleiro, 5, 5);
    printf("\nTabuleiro com habilidade em cone:\n");
    exibirTabuleiro(tabuleiro);

    // Habilidade em cruz
    habilidadeCruza(tabuleiro, 4, 4);
    printf("\nTabuleiro com habilidade em cruz:\n");
    exibirTabuleiro(tabuleiro);

    // Habilidade em octaedro
    habilidadeOctaedro(tabuleiro, 3, 3);
    printf("\nTabuleiro com habilidade em octaedro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
