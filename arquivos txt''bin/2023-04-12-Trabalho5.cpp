#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50], bairro[20], regiao[15];
    char data[10], dataRelativa[55];
    char inicio[7], local[91];
    int publico, anoPrimeiro;
} Bloco;

int pesquisaBinaria(Bloco *blocos, int inicio, int fim, char *nomeBloco) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (strcmp(blocos[meio].nome, nomeBloco) == 0) {
            return meio;
        } else if (strcmp(blocos[meio].nome, nomeBloco) < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo = fopen("BlocosdeRua_2016_ordenado.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    rewind(arquivo);
    int numRegistros = tamanhoArquivo / sizeof(Bloco);

    Bloco *blocos = (Bloco *) malloc(numRegistros * sizeof(Bloco));
    if (blocos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    fread(blocos, sizeof(Bloco), numRegistros, arquivo);

    fclose(arquivo);
    
    char nomeBloco[50];
    printf("Digite o nome do bloco: ");
    fgets(nomeBloco, 50, stdin);
    nomeBloco[strcspn(nomeBloco, "\n")] = 0;

    int posicaoBloco = pesquisaBinaria(blocos, 0, numRegistros - 1, nomeBloco);
    if (posicaoBloco == -1) {
        printf("O bloco %s não foi encontrado.\n", nomeBloco);
    } else {
        printf("O bloco %s foi encontrado nas seguintes ocorrências:\n", nomeBloco);
        for (int i = posicaoBloco; i < numRegistros && strcmp(blocos[i].nome, nomeBloco) == 0; i++) {
            printf("%s %s %s\n", blocos[i].nome, blocos[i].data, blocos[i].inicio);
        }
    }
    free(blocos);

    return 0;
}


