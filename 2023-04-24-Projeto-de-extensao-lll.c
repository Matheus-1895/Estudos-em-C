#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// Vari�veis globais
int i,j,k;
const float precoQuentinha = 20.50;
enum meses { Janeiro = 1, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto, Setembro, Outubro, Novembro, Dezembro };
enum meses mes;
const char *meses_str[] = {
    "Janeiro", "Fevereiro", "Mar�o", "Abril", "Maio", "Junho", "Julho","Agosto", "Setembro", "Outubro", "Novembro", "Dezembro", NULL
};

// Fun��o para retornar o nome do m�s em uma string
const char *nomeMes(enum meses m) {
    if(m < Janeiro || m > Dezembro)
        return "M�s inv�lido.";
    return meses_str[m-1];
}

// Definindo a estrutura de dados para armazenar as informa��es de cada item vendido
struct vendas{
	float precoQuilo;
	float precoBebida;
	int vetorMes;
	int quantidadeBebida;
	int peso;
	float total;
};
struct vendas venda[101][32][13];
void swap(float* a, float* b) {
    float t = *a;
    *a = *b;
    *b = t;
}
int divisao(float arr[], int menor, int maior) {
    float pivo = arr[maior];
    int i = (menor - 1);
	int j;
    for (j = menor; j <= maior - 1; j++) {
        if (arr[j] >= pivo) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[maior]);
    return (i + 1);
}
void quickSort(float arr[], int menor, int maior) {
    if (menor < maior) {
        int pi = divisao(arr, menor, maior);
        quickSort(arr, menor, pi - 1);
        quickSort(arr, pi + 1, maior);
    }
}

// Fun��o para capturar o valor e a quantidade de bebidas do cliente
void bebidas(float *base1, int *base2){
	printf("Tudo certo, qual o valor da bebida?\nR$");
    scanf("%f", base1);
    printf("Qual ser� a quantidade de bebidas?\n");
    scanf("%d", base2);
}

// Fun��o para definir o pre�o e a quantidade de bebidas na estrutura de dados
void definirBebidas(float base1, int base2){
	venda[i][j][k].precoBebida=base1;
	venda[i][j][k].quantidadeBebida=base2;
}

// Fun��o principal
  int main(){
  	// Definindo a localidade para Portugu�s
	setlocale(LC_ALL, "Portuguese");
	
	// Inicializando vari�veis
	i=0;j=0;k=0;
	float base1,soma,somaMes[13];
	int verificardata=1,base2,escolha,opcao,tipo,perguntapedido,l[32][13],j1=0,k1=0;
	memset(somaMes, 0, sizeof(somaMes));// atribui toda a matriz com o valor zero
	memset(l, 0, sizeof(l));// atribui toda a matriz com o valor zero
	while(escolha!=5){
	verificardata=1;
	
	// Loop para capturar a data correta
	while(verificardata==1){
		printf("Digite o dia e o m�s que deseja acessar (insira no formato 'dia m�s'):\n");
    	scanf("%d %d",&j,&mes);
    	
    	// Verificando se a data � v�lida
    	if(mes < Janeiro || mes > Dezembro || j<0 || j>31){
    		printf("Data inv�lida\n");
		}else{
			verificardata=0;
			}
	}
    system("cls");
    k=mes-1;
    i=l[j][k];
    escolha=0;
    while (escolha!=4){
    printf("Dia %d de %s\n",j,nomeMes(mes));// Imprime a data atual
	printf("*---Restaurante Flor de Sal---*\n\n1 - Registrar pedido\n2 - Relat�rio di�rio\n3 - Relat�rio Mensal\n4 - Alterar data\n5 - Relat�rio anual\n6 - Sair\n");
	scanf("%d",&escolha);// L� a escolha do usu�rio
	switch (escolha){
		case 1:// Registro de pedido
			perguntapedido=0;tipo=0;
			while(perguntapedido!=2 && tipo!=3){
			printf("O pedido � uma quentinha ou prato a quilo?\n1 - Quentinha (pre�o fixo de R$20,50)\n2 - Quilo\n3 - Retornar\n");
			scanf("%d",&tipo);
			switch (tipo){
				case 1:// Quentinha
					venda[i][j][k].total+=precoQuentinha;// Adiciona o pre�o da quentinha ao total
					printf("Deseja bebidas com o pedido?\n(1 - Sim 2 - N�o)\n");
					scanf("%d",&tipo);// L� a escolha do usu�rio
					if (tipo==1){
						bebidas(&base1,&base2);// Chama a fun��o para selecionar as bebidas
						definirBebidas(base1,base2);// Define as bebidas escolhidas
						venda[i][j][k].total+=venda[i][j][k].quantidadeBebida*venda[i][j][k].precoBebida;// Adiciona o pre�o das bebidas ao total
					}
					break;
				case 2:// Quilo
					printf("Qual o valor do quilo da comida?\nR$");
					scanf("%f",&venda[i][j][k].precoQuilo);//L� o pre�o do quilo
					printf("Quantos gramas de comida foram colocados no prato?\n");
					scanf("%d",&venda[i][j][k].peso);// L� o peso do prato
					venda[i][j][k].total+=venda[i][j][k].peso*venda[i][j][k].precoQuilo/1000;// Calcula o pre�o do prato e adiciona ao total
					printf("Deseja bebidas com o pedido?\n(1 - Sim 2 - N�o)\n");
					scanf("%d",&tipo);// L� a escolha do usu�rio
					if (tipo==1){
						bebidas(&base1,&base2);// Chama a fun��o para selecionar as bebidas
						definirBebidas(base1,base2);// Define as bebidas escolhidas
						venda[i][j][k].total+=venda[i][j][k].quantidadeBebida*venda[i][j][k].precoBebida;// Adiciona o pre�o das bebidas ao total
					}
					break;	
			}
			if (tipo==1 || tipo ==2){ // Verifica se o tipo de venda escolhido � 1 (quentinha) ou 2 (prato)
			printf("O total da venda %d � R$%.2f\n",i+1,venda[i][j][k].total);// Imprime o n�mero e o valor total da venda
			printf("Deseja adicionar mais um pedido?\n(1 - Sim 2 - N�o)\n");// Pergunta ao usu�rio se deseja fazer outro pedido
			scanf("%d",&perguntapedido);// L� a escolha do usu�rio
			i++;// Incrementa o contador de vendas
			l[j][k]=i;// Atualiza o n�mero de vendas do dia
			}
			}
			break;
		
		case 2:// Se a escolha for 2, exibe informa��es sobre as vendas do dia
		soma=0; // Inicializa a vari�vel soma com zero
        i=0; // Inicializa o contador de vendas com zero
		for (i=0;i<l[j][k];i++){// Percorre todas as vendas do dia
		soma+=venda[i][j][k].total;// Soma o valor total da venda na vari�vel soma
		}
		if(soma==0){// Se n�o houver vendas no dia
			printf("N�o foram feitas vendas nesse dia.\n");// Exibe uma mensagem informando que n�o houve vendas
		}else{// Se houver vendas no dia
		printf("Foram feitas %d compras no valor total de R$%.2f\nO ticket m�dio por cliente � de R$%.2f\n",l[j][k],soma,soma/l[j][k]);// Exibe o n�mero de vendas, o valor total das vendas e o ticket m�dio por cliente
		printf("Deseja mais detalhes sobre as compras feitas nesse dia?\n(1 - Sim 2 - N�o)\n");// Pergunta ao usu�rio se deseja ver mais detalhes sobre as vendas do dia
		scanf("%d",&escolha);// L� a escolha do usu�rio
		if (escolha==1){// Se o usu�rio escolher ver mais detalhes
			i=0;// Reinicializa o contador de vendas com zero
			for (i=0;i<l[j][k];i++){// Percorre todas as vendas do dia
			if (venda[i][j][k].peso==0){// Se a venda for uma quentinha
				printf("\nVenda %d:\nQuentinha no valor de R$%.2f com %d unidades de bebida por R$%.2f por unidade.\nO valor total da compra foi R$%.2f\n",i+1,precoQuentinha,venda[i][j][k].quantidadeBebida,venda[i][j][k].precoBebida,venda[i][j][k].total);
			}else{// Se a venda for um prato
				printf("\nVenda %d:\nPrato com %d gramas de comida no valor de R$%.2f o quilo com %d unidades de bebida por R$%.2f por unidade.\nO valor total da compra foi R$%.2f\n",i+1,venda[i][j][k].peso,
				venda[i][j][k].precoQuilo,venda[i][j][k].quantidadeBebida,venda[i][j][k].precoBebida,venda[i][j][k].total);
			}
		}
		}
		}
		system("pause");
		break;
		
		case 3:
		soma=0;
		i=0;
		for(j1=0;j1<31;j1++){
			for (i=0;i<l[j1][k];i++){
			soma+=venda[i][j1][k].total;
			}
		}
		printf("Nesse m�s o faturamento foi de R$%.2f.\n",soma);
		system("pause");
		break;
		
		case 4:
			break;
		case 5://Calculo da venda mensal e anual 
			soma=0;
			i=0;
			for(k1=0;k1<12;k1++){
			for(j1=0;j1<31;j1++){
				for (i=0;i<l[j1][k1];i++){
				soma+=venda[i][j1][k1].total;
				}
			}
			somaMes[k1]+=soma;
			soma=0;
			}
			quickSort(somaMes, 0, 12);
			soma=0;
			printf("Faturamento mensal em ordem decrescente:\n");
			k1=0;
			   for (i = 0; i < 12; i++) {
        printf("\nR$%.2f", somaMes[i]);
        soma+=somaMes[i];
    	}
			printf("\nForam vendidos R$%.2f no ano.",soma);
			system("pause");
			break;
		case 6:
			exit(0);
			break;
}
system("cls");
}
}
	return 0;
}
