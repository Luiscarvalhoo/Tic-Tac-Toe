#include <stdio.h>



void inicializarTabuleiro(char tabuleiro[3][3]) {
    /**/
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

int verificarVitoria(char tabuleiro[3][3], char jogador) {
    for (int i = 0; i < 3; i++) {
        // Verifica linhas e colunas
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return 1;
        }
    }
    // Verifica diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1;
    }
    return 0;
}

int main() {
    char tabuleiro[3][3];
    char jogadorAtual = 'X';
    int linha, coluna;
    int jogadas = 0;
    int ganhou = 0;

    inicializarTabuleiro(tabuleiro);

    while (jogadas < 9 && !ganhou) {
        imprimirTabuleiro(tabuleiro);
        printf("Jogador %c, digite linha (0 a 2): ", jogadorAtual);
        scanf("%d", &linha);
        printf("Jogador %c, digite coluna (0 a 2): ", jogadorAtual);
        scanf("%d", &coluna);

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogadorAtual;
            jogadas++;

            if (verificarVitoria(tabuleiro, jogadorAtual)) {
                imprimirTabuleiro(tabuleiro);
                printf("Jogador %c venceu!\n", jogadorAtual);
                ganhou = 1;
            } else {
                jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Posição inválida, tente novamente.\n");
        }
    }

    if (!ganhou) {
        imprimirTabuleiro(tabuleiro);
        printf("Empate!\n");
    }

    return 0;
}
