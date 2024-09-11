#include<stdio.h>
#include<math.h>
#include<locale.h>

int main(){
	
//Vari�veis 
 float COD_P[5] ={}, TOTAL_P[5] = {};
 
 int COD, CLIENTE, PROD, QUANT;
 int ip, ia, a;
 
  setlocale(LC_ALL, "Portuguese");

    printf("************* Sistema Omega *************\n");
    printf("Inicializando Cadastro de Produtos\n");
    printf("**********************************\n");

 // cadrastos dos produtos 
   for(a = 0; a <=4; a++){
        printf("Insira o C�digo de um Produto: ");
        scanf("%f", &COD_P[a]);
        printf("Quantidade do Produto no Estoque [%.0f]: ",COD_P[a]);
        scanf("%f", &TOTAL_P[a]);
        printf("Produto [%.0f] registrado no sistema com [%.0f] unidades em estoque.\n",COD_P[a],TOTAL_P[a]);
    }

   for(ia = 0; ia <=10; ia++){

  // Tabela de produtos em estoque 
     printf("*****************\n");
     printf("Sistema �mega\n");
     printf("*****************\n");
     printf("****** Produtos no Estoque ******\n");
    for(a = 0; a <=4; a++){
     printf("Produto [%.0f] = [%.0f] unidades em estoque.\n",COD_P[a],TOTAL_P[a]);
	}

	 printf("******************************************************\n");
	 printf("Pedido do Cliente || Para Encerrar digite 0\n");
	 printf("******************************************************\n");	
	
	 printf("C�digo do Cliente: ");
	  scanf("%d",&CLIENTE);
	  
	// comando para encerrar o programa
    if (CLIENTE == 0 ){
     printf("Programa encerrado....");
 
    break;	
} 
	printf("*****************\n");
	printf("C�digo do Produto: ");
	scanf("%d",&PROD);
	printf("*****************\n");
	printf("Quantidade do Produto [%d]: ",PROD);
	 scanf("%d",&QUANT);
	
	
     for(a = 0; a <=4; a++){
	 	if ( COD_P[a] == PROD){
		ip = a;
		
		break;	
	}
}

 		if (PROD != COD_P[a]){
         printf("\n -- Produto n�o encontrado [%d]. -- ",PROD);
		break;
         }
		 		
	if (TOTAL_P[ip] >= QUANT ){
		printf("\nPedido atendido, obrigado!");
		TOTAL_P[ip] = TOTAL_P[ip] - QUANT;
    	printf("\nEstoque atual [%.0f]\n",TOTAL_P[ip]);
	
	}
	else  { 
	printf("\nEstoque insuficiente do produto[%.0f]\n",COD_P[ip]);
	}	
}	
    return 0;

}
