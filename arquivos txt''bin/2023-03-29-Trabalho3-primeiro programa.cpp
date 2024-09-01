#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    char bairro[20];
    char regiao[15];
    char data_desfile[10];
    char data_carnaval[55];
    char hora_desfile[7];
    char local_desfile[91];
    int qtd_pessoas;
    int ano_primeiro_desfile;
} BlocoRua;

int main() {
	
	setlocale(LC_ALL, "Portuguese");
    FILE *arq_texto;
    FILE *arq_binario;
    BlocoRua bloco;
    int num_blocos = 0;

    arq_texto = fopen("BlocosdeRua_2016.txt", "r");
    if (arq_texto == NULL) {
        printf("Erro ao abrir arquivo de entrada\n");
        return 1;
    }

    arq_binario = fopen("BlocosdeRua_2016.bin", "wb");
    if (arq_binario == NULL) {
        printf("Erro ao abrir arquivo de saída\n");
        return 1;
    }

    while (fscanf(arq_texto, "%49[^\n]\n%19[^\n]\n%14[^\n]\n%9[^\n]\n%54[^\n]\n%6[^\n]\n%90[^\n]\n%d\n%d\n",
                  bloco.nome, bloco.bairro, bloco.regiao, bloco.data_desfile, bloco.data_carnaval,
                  bloco.hora_desfile, bloco.local_desfile, &bloco.qtd_pessoas, &bloco.ano_primeiro_desfile) == 9) {
        fwrite(&bloco, sizeof(BlocoRua), 1, arq_binario);
        num_blocos++;
    }

    fclose(arq_texto);
    fclose(arq_binario);

    printf("Foram criados %d registros no arquivo binário\n", num_blocos);

    return 0;
}

