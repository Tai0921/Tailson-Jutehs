#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char nome[20];
    int forca;
    int inteligencia;
    int velocidade;
};

// Função para mostrar uma carta
void mostrarCarta(struct Carta c) {
    printf("\nCarta: %s\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Inteligência: %d\n", c.inteligencia);
    printf("Velocidade: %d\n", c.velocidade);
}

// Função para comparar atributos
void jogar(struct Carta jogador, struct Carta computador, int escolha) {
    int valorJogador, valorComputador;

    if (escolha == 1) {
        valorJogador = jogador.forca;
        valorComputador = computador.forca;
        printf("\nComparando FORÇA...\n");
    } else if (escolha == 2) {
        valorJogador = jogador.inteligencia;
        valorComputador = computador.inteligencia;
        printf("\nComparando INTELIGÊNCIA...\n");
    } else {
        valorJogador = jogador.velocidade;
        valorComputador = computador.velocidade;
        printf("\nComparando VELOCIDADE...\n");
    }

    printf("Sua carta: %d\n", valorJogador);
    printf("Carta do computador: %d\n", valorComputador);

    if (valorJogador > valorComputador) {
        printf("\n🎉 Você venceu!\n");
    } else if (valorJogador < valorComputador) {
        printf("\n😢 Você perdeu!\n");
    } else {
        printf("\n🤝 Empate!\n");
    }
}

int main() {
    srand(time(NULL)); // Semente para aleatoriedade

    // Cartas disponíveis
    struct Carta baralho[3] = {
        {"Goku", 98, 65, 90},
        {"Batman", 60, 99, 70},
        {"Flash", 50, 70, 100}
    };

    // Sorteio das cartas
    int indiceJogador = rand() % 3;
    int indiceComputador;

    do {
        indiceComputador = rand() % 3;
    } while (indiceComputador == indiceJogador);

    struct Carta cartaJogador = baralho[indiceJogador];
    struct Carta cartaComputador = baralho[indiceComputador];

    printf("=== SUPER TRUNFO - VERSÃO C ===\n");

    printf("\nSua carta foi:");
    mostrarCarta(cartaJogador);

    printf("\nEscolha um atributo para jogar:\n");
    printf("1 - Força\n2 - Inteligência\n3 - Velocidade\n");
    int escolha;
    scanf("%d", &escolha);

    printf("\nCarta do computador era:");
    mostrarCarta(cartaComputador);

    jogar(cartaJogador, cartaComputador, escolha);

    return 0;
}
