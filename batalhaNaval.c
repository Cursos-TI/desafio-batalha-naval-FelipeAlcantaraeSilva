#include <stdio.h>

// Iniciar o tabuleiro;

void inicializarTabuleiro(int tabuleiro[10][10]) {

    int i, j;

    for (i = 0; i < 10; i++) {

        for (j = 0; j < 10; j++) {

            tabuleiro[i][j] = 0;

        }

    }

}

// Exibir o tabuleiro;

void exibirTabuleiro(int tabuleiro[10][10]) {

    int i, j;

    // Espaço na primeira linha para alinhar o cabeçalho;

    printf("\n   ");

    for (j = 0; j < 10; j++) {

        printf("%3c", 'A' + j);

    }

    printf("\n");

    // Exibe as linhas;

    for (i = 0; i < 10; i++) {

        printf("%2d ", i);

        for (j = 0; j < 10; j++) {

            printf("%3d", tabuleiro[i][j]);

        }

        printf("\n");

    }

}

int main() {

    int tabuleiro[10][10];

    inicializarTabuleiro(tabuleiro);

    printf("TABULEIRO EM BRANCO \n");

    exibirTabuleiro(tabuleiro);

// Exibir navio horizontal;

int linha_h = 3;
int coluna_h_inicio = 6;
for (int i = 0; i < 3; i++) {
    
    tabuleiro[linha_h][coluna_h_inicio + i] = 3;
}

// Exibir navio vertical;

int linha_v_inicio = 7;
int coluna_v = 2;
for (int i = 0; i < 3; i++) {

    tabuleiro[linha_v_inicio + i][coluna_v] = 3;
}

// Exibir navio na diagonal 1;

int diagonal_1_inicio = 0;
int coluna_1 = 5;
for (int i = 0; i < 3; i++) {
    
    tabuleiro[diagonal_1_inicio + i][coluna_1 - i] = 3;

}

// Exibir navio na diagonal 2;

int diagonal_2_inicio = 6;
int coluna_2 = 5;
for (int i = 0; i < 3; i++) {
    
    tabuleiro[diagonal_2_inicio - i][coluna_2 - i] = 3;

}

    printf("\nTABULEIRO COM JOGADAS\n");

    exibirTabuleiro(tabuleiro);

    return 0;

}
