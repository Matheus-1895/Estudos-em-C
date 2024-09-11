#include <stdio.h>
#include <string.h>
#include<math.h>
#include<locale.h>
#define MAX_PECAS 10
#define MAX_NOME 11

struct peca {
    int codigo, quantidade;
    char nome[MAX_NOME];
    float preco;
};

int main() {
    struct peca estoque[MAX_PECAS];
    int i, codigo_maior_valor;
    float valor_total = 0.0, maior_valor = 0.0;

    setlocale(LC_ALL, "Portuguese");
    
    for (i = 0; i < MAX_PECAS; i++) {
        printf("Digite os dados do produto %d:\n", i + 1);
        printf("Insira o Código do um Produto: ");
        scanf("%d", &estoque[i].codigo);
        printf("Insira o Nome do um Produto(no máximo 10 caracteres): ");
        scanf("%s", estoque[i].nome);
        printf("Quantidade do Produto no Estoque: ");
        scanf("%d", &estoque[i].quantidade);
        printf("Insira o Preço do Produto: ");
        scanf("%f", &estoque[i].preco);
        printf("\n");
    
        valor_total += estoque[i].quantidade * estoque[i].preco;


        if (estoque[i].quantidade * estoque[i].preco > maior_valor) {
            maior_valor = estoque[i].quantidade * estoque[i].preco;
            codigo_maior_valor = estoque[i].codigo;
        }
    }
    
    printf("Informações do estoque: \n");
    printf("Valor total: R$%.2f\n", valor_total);
    printf("Peca com maior valor: codigo %d, nome %s\n", codigo_maior_valor, estoque[codigo_maior_valor - 1].nome);

    return 0;
}  
