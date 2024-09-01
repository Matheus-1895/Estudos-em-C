#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[51];
    char bairro[21];
    char regiao[16];
    char data_2016[11];
    char data_carnaval[56];
    char hora[8];
    char local[92];
    int quant_pessoas;
    int ano;
} BlocoRua;

int main() {

    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo_binario;
    BlocoRua bloco;
    int num_registros = 0;

    arquivo_binario = fopen("BlocosdeRua_2016.bin", "rb");
    if (arquivo_binario == NULL) {
        printf("Erro ao abrir o arquivo binário.\n");
        return 1;
    }

    while (fread(&bloco, sizeof(BlocoRua), 1, arquivo_binario) == 1) {
        num_registros++;
        printf("Registro: %d\n", num_registros);
        printf("Nome: %s\n", bloco.nome);
        printf("Bairro: %s\n", bloco.bairro);
        printf("Regiao: %s\n", bloco.regiao);
        printf("Data: %s\n", bloco.data_2016);
        printf("Data relativa: %s\n", bloco.data_carnaval);
        printf("Inicio: %s\n", bloco.hora);
        printf("Local: %s\n", bloco.local);
        printf("Publico: %d\n", bloco.quant_pessoas);
        printf("Primeiro desfile: %d\n", bloco.ano);
        printf("\n");
    }

    fclose(arquivo_binario);
    
    printf("\nForam lidos %d registros do arquivo binário.\n", num_registros);
    
    return 0;
}

