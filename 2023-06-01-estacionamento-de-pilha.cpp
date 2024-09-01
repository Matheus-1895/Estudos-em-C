#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_GARAGEM 5
#define TAMANHO_PLACA 8

typedef struct {
    char placas[TAMANHO_GARAGEM][TAMANHO_PLACA];
    int manobras[TAMANHO_GARAGEM];
    int topo;
} Pilha;

void empilhar(Pilha* pilha, const char* placa);
void desempilhar(Pilha* pilha, const char* placa);
void mostrarPilha(Pilha* pilha);
void processarEntrada(Pilha* pilha, const char* entrada);

int main() {
    Pilha pilha;
    pilha.topo = 0;

    empilhar(&pilha, "FLA1981");
    empilhar(&pilha, "BRA2023");
    empilhar(&pilha, "NBA1946");
    empilhar(&pilha, "MTS2004");
    empilhar(&pilha, "ANA2018");

    printf("Digite 'S'+'Placa' para retirar ou 'E'+'Placa' para estacionar um carro na garagem.\n");

    char entrada[10];
    while (fgets(entrada, sizeof(entrada), stdin) != NULL) {
        processarEntrada(&pilha, entrada);
         printf("Digite 'S'+'Placa' para retirar ou 'E'+'Placa' para estacionar um carro na garagem.\n");
    }

    return 0;
}

void empilhar(Pilha* pilha, const char* placa) {
    if (pilha->topo < TAMANHO_GARAGEM) {
        strcpy(pilha->placas[pilha->topo], placa);
        pilha->manobras[pilha->topo] = 0;
        pilha->topo++;
        printf("Carro %s estacionou.\n", placa);
    }
}

void desempilhar(Pilha* pilha, const char* placa) {
    int movimentos = 0;
    int i, j;

    for (i = pilha->topo - 1; i >= 0; i--) {
        if (strcmp(pilha->placas[i], placa) == 0) {
            movimentos += pilha->topo - i - 1;

            for (j = i + 1; j < pilha->topo; j++) {
                pilha->manobras[j]++;
            }

            break;
        }
    }

    if (i >= 0) {
        for (j = i; j < pilha->topo - 1; j++) {
            strcpy(pilha->placas[j], pilha->placas[j + 1]);
            pilha->manobras[j] = pilha->manobras[j + 1];
        }
        pilha->topo--;
        printf("Carro %s saiu depois de %d movimentos.\n", placa, movimentos);
        printf("Manobras feitas para saída: %d\n", pilha->manobras[i]);
    }
}

void mostrarPilha(Pilha* pilha) {
    printf("Garagem atualmente:\n");
    for (int i = 0; i < pilha->topo; i++) {
        printf("%s (Manobras: %d)\n", pilha->placas[i], pilha->manobras[i]);
    }
    printf("\n");
}

void processarEntrada(Pilha* pilha, const char* entrada) {
    char acao = entrada[0];
    char placa[TAMANHO_PLACA];
    strncpy(placa, entrada + 2, TAMANHO_PLACA - 1);
    placa[TAMANHO_PLACA - 1] = '\0';

    if (acao == 'E') {
        if (pilha->topo < TAMANHO_GARAGEM) {
            empilhar(pilha, placa);
        } else {
            printf("Não há vaga disponível para o carro %s.\n", placa);
        }
    } else if (acao == 'S') {
        desempilhar(pilha, placa);
    }

    mostrarPilha(pilha);
} 
