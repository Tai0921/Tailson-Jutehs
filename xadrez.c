#include <stdio.h>

void inicializarTabuleiro(char tabuleiro[8][8]) {
    // Peças pretas
    char linha1[] = {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'};
    char linha2[] = {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
    char linha7[] = {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'};
    char linha8[] = {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'};

    for (int i = 0; i < 8; i++) {
        tabuleiro[0][i] = linha1[i]; // linha 1: peças pretas
        tabuleiro[1][i] = linha2[i]; // linha 2: peões pretos
        tabuleiro[6][i] = linha7[i]; // linha 7: peões brancos
        tabuleiro[7][i] = linha8[i]; // linha 8: peças brancas
    }

    // Espaços vazios
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = '.';
        }
    }
}

void exibirTabuleiro(char tabuleiro[8][8]) {
    printf("\n A B C D E F G H\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[8][8];
    inicializarTabuleiro(tabuleiro);
    
    printf("=== TABELA DE XADREZ ===\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
