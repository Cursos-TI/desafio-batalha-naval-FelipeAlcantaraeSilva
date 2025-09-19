#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define EFEITO 5

// Inicia tabuleiro com AGUA

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {

        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

            tabuleiro[i][j] = AGUA;

        }

    }

}

// Exibe o tabuleiro

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {

    // Exibe o cabeçalho

    printf("\n   ");

    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

        printf("%3c", 'A' + j);

    }

    printf("\n");

    // Exibe as linhas

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {

        printf("%2d ", i);

        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

            // Representação da água
            if (tabuleiro[i][j] == AGUA) {
                
                printf("  0");

            // Representação do navio
            } else if (tabuleiro[i][j] == NAVIO) {

                printf("  3");

            // Representação do efeito/habilidade
            } else if (tabuleiro[i][j] == EFEITO) {

                printf("  5");

            } else {

                printf("%3d", tabuleiro[i][j]);

            }

        }

        printf("\n");

    }

}

// Cria o CONE

void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {

    int centro = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

            habilidade[i][j] = 0;

        }

    }

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (int j = centro - i; j <= centro + i; j++) {

            if (j >= 0 && j < TAMANHO_HABILIDADE) {

                habilidade[i][j] = 1;

            }

        }

    }

}

// Cria a CRUZ

void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {

    int centro = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

            habilidade[i][j] = 0;

        }

    }

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {

        habilidade[centro][i] = 1;

        habilidade[i][centro] = 1;

    }

}

// Cria o OCTAEDRO

void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    
    int centro = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
    
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            if (abs(i - centro) + abs(j - centro) <= centro) {
            
                habilidade[i][j] = 1;
            
            } else {
            
                habilidade[i][j] = 0;
            }
        }
    }
}

// Sobreposição

void sobreporHabilidade(

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],

    int linha_central,

    int coluna_central) {

    int tamanho_metade = TAMANHO_HABILIDADE / 2;

    int linha_inicio = linha_central - tamanho_metade;

    int coluna_inicio = coluna_central - tamanho_metade;

        for (int linha_habilidade = 0; linha_habilidade < TAMANHO_HABILIDADE; linha_habilidade++) {

            for (int coluna_habilidade = 0; coluna_habilidade < TAMANHO_HABILIDADE; coluna_habilidade++) {

                int linha_tabuleiro = linha_inicio + linha_habilidade;

                int coluna_tabuleiro = coluna_inicio + coluna_habilidade;

                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&

                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {

                if (matriz_habilidade[linha_habilidade][coluna_habilidade] == 1) {

                tabuleiro[linha_tabuleiro][coluna_tabuleiro] = EFEITO;

                }

                if (matriz_habilidade[linha_habilidade][coluna_habilidade] == 1) {

                if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] == AGUA) {

                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = EFEITO;
                }
                
                }

            }

        }

    }

}

int main() {

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarHabilidadeCone(habilidade_cone);

    criarHabilidadeCruz(habilidade_cruz);

    criarHabilidadeOctaedro(habilidade_octaedro);

    // Navios e CONE

    inicializarTabuleiro(tabuleiro);

    for (int i = 0; i < 3; i++) { tabuleiro[2][7 + i] = NAVIO; }

    for (int i = 0; i < 3; i++) { tabuleiro[6 + i][1] = NAVIO; }

    printf("\nNavios e habilidade de CONE\n");

    sobreporHabilidade(tabuleiro, habilidade_cone, 3, 4);

    exibirTabuleiro(tabuleiro);

    // Navios e CRUZ

    inicializarTabuleiro(tabuleiro);

    for (int i = 0; i < 3; i++) { tabuleiro[4 - i][5 - i] = NAVIO; }

    printf("\nNavios e habilidade de CRUZ\n");

    sobreporHabilidade(tabuleiro, habilidade_cruz, 7, 7);

    exibirTabuleiro(tabuleiro);

    // Navios e OCTAEDRO

    inicializarTabuleiro(tabuleiro);

    for (int i = 0; i < 3; i++) { tabuleiro[7 + i][9 - i] = NAVIO; }

    printf("\nNavios e habilidade de OCTAEDRO\n");

    sobreporHabilidade(tabuleiro, habilidade_octaedro, 5, 5);

    exibirTabuleiro(tabuleiro);

    return 0;

}
