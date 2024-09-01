#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int soma(int n1, int n2) {
      int res;
      res = n1 + n2;
      return res;
}
int sub(int n1, int n2) {
      int res;
      res = n1 - n2;
      return res;
}
int multi(int n1, int n2) {
      int res;
      res = n1 * n2;
      return res;
}
int divi(int n1, int n2) {
      int res;
      res = n1 / n2;
      return res;
}
int quad(int n1) {
      int res;
      res = pow(n1, 2);
      return res;
}
int raiz(int n1) {
      int res;
      res = sqrt(n1);
      return res;
}
void close() {
      exit(EXIT_SUCCESS);
}
//Segunda parte--------------------------Tela de selecao das funcionalidades da calculadora
int main() {
      int valor;
      int v1, v2, resultado;
      do {
            printf("\n\t###Calculadora###");
            printf("\n1- Soma");
            printf("\n2- Subtracao");
            printf("\n3- Multiplicacao");
            printf("\n4- Divisao");
            printf("\n5- Numero ao quadrado");
            printf("\n6- Sair");
            printf("\n\n");
            scanf("%d", &valor);
//Terceira parte---------------------------------------------Estrutura pra fazer os calculos especificos usando as funcoes feitas antes
            switch(valor)
            {
                  case 1:
                        printf("\nDigite o primeiro numero: ");
                        scanf("%d", &v1);
                        printf("\nDigite o segundo numero: ");
                        scanf("%d", &v2);
                        resultado = soma(v1, v2);
                        printf("O valor da soma eh: %d", resultado);
                        v1 = 0;
                        v2 = 0;
                        resultado = 0;
                        break;
                  
                  case 2:
                        printf("\nDigite o primeiro numero: ");
                        scanf("%d", &v1);
                        printf("\nDigite o segundo numero: ");
                        scanf("%d", &v2);
                        resultado = sub(v1, v2);
                        printf("O valor da subtracao eh: %d", resultado);
                        v1 = 0;
                        v2 = 0;
                        resultado = 0;
                        break;
                  
                  case 3:
                        printf("\nDigite o primeiro numero: ");
                        scanf("%d", &v1);
                        printf("\nDigite o segundo numero: ");
                        scanf("%d", &v2);
                        resultado = multi(v1, v2);
                        printf("O valor da multiplicacao eh: %d", resultado);
                        v1 = 0;
                        v2 = 0;
                        resultado = 0;
                        break;
                  
                  case 4:
                        printf("\nDigite o primeiro numero: ");
                        scanf("%d", &v1);
                        printf("\nDigite o segundo numero: ");
                        scanf("%d", &v2);
                        if(v2 == 0) {
                              printf("\nDigite um segundo numero diferente de 0");
                              printf("\nDigite o segundo numero: ");
                              scanf("%d", &v2);
                        }
                        resultado = divi(v1, v2);
                        printf("O valor da divisao eh: %d", resultado);
                        v1 = 0;
                        v2 = 0;
                        resultado = 0;
                        break;
                  
                  case 5:
                        printf("\nDigite o numero: ");
                        scanf("%d", &v1);
                        resultado = quad(v1);
                        printf("O valor do numero ao quadrado eh: %d", resultado);
                        v1 = 0;
                        v2 = 0;
                        resultado = 0;
                        break;
                  case 6:
                        close();
                        break;
                  
                  default:
                        printf("\nerro: Digite um numero entre 1 e 8");
            }
      } while(valor != 7);
      return 0;
}	
