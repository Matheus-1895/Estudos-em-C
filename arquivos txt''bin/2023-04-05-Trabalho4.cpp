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

void selection_sort(Bloco* blocos, int length) {
    int i, j, min_idx;
    Bloco temp;

    for (i = 0; i < length - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < length; j++) {
            if (strcmp(blocos[j].nome, blocos[min_idx].nome) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = blocos[i];
            blocos[i] = blocos[min_idx];
            blocos[min_idx] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    FILE* arquivoBinario;
    FILE* arquivoTexto;
    Bloco* blocos;
    long tamanhoArquivo;
    int numRegistros;
    int i;

    arquivoBinario = fopen("BlocosdeRua_2016.bin", "rb");
    if (arquivoBinario == NULL) {
        printf("Erro ao abrir o arquivo binário.\n");
        exit(1);
    }

    fseek(arquivoBinario, 0, SEEK_END);
    tamanhoArquivo = ftell(arquivoBinario);
    numRegistros = tamanhoArquivo / sizeof(Bloco);
    fseek(arquivoBinario, 0, SEEK_SET);

    blocos = (Bloco*) malloc(numRegistros * sizeof(Bloco));
    if (blocos == NULL) {
        printf("Erro ao alocar memória para o vetor de blocos.\n");
        exit(1);
    }

    fread(blocos, sizeof(Bloco), numRegistros, arquivoBinario);

    selection_sort(blocos, numRegistros);

    arquivoTexto = fopen("desfile.txt", "w");
    if (arquivoTexto == NULL) {
        printf("Erro ao abrir o arquivo texto.\n");
        exit(1);
    }

    for (i = 0; i < numRegistros; i++) {
        fprintf(arquivoTexto, "%s - %s - %s\n", blocos[i].nome, blocos[i].data, blocos[i].inicio);
    }

    fclose(arquivoBinario);
    fclose(arquivoTexto);
    free(blocos);

    printf("Foram processados %d registros.\n", numRegistros);

    return 0;
}


