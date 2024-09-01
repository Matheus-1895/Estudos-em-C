#include <stdio.h>
#include <locale.h>
#include <math.h>

int ficha_5, ficha_10, ficha_20, ficha_50, ficha_100;

double dinheiro;
int VAL_int;

 int ValorFicha5(int n5);
 int ValorFicha10(int n10);
 int ValorFicha20(int n20);
 int ValorFicha50(int n50);
 int ValorFicha100(int n100);
double Frac(double decimal);

int main(){
setlocale(LC_ALL, "portuguese");

  printf(" COMPRE SUAS FICHAS \n");
  printf("\n---VALORES TABELADOS DAS FICHAS--- \n");
  printf("\n VALOR DE 5,00 R$ ---- 1 FICHA");
  printf("\n VALOR DE 10,00 R$ ---- 2 FICHAS");
  printf("\n VALOR DE 20,00 R$ ---- 4 FICHAS");
  printf("\n VALOR DE 50,00 R$---- 10 FICHAS");
  printf("\n VALOR DE 100,00 R$---- 20 FICHAS \n");
  printf("---------------------------------------------");
  printf("\nINSIRA O VALOR INTEIRO: ");
	scanf("%lf", &dinheiro);  

  VAL_int = (int)dinheiro;

  while (VAL_int >= 5){
    if (VAL_int >= 100){
    ficha_100 = ValorFicha100(VAL_int);
    VAL_int %= 5;
    }
    else if (50 <= VAL_int && VAL_int < 100){
    ficha_50 = ValorFicha50(VAL_int);
    VAL_int %= 5;
    }
    else if (20 <= VAL_int && VAL_int < 50){
    ficha_20 = ValorFicha20(VAL_int);
    VAL_int %= 5;
    }
    else if (10 <= VAL_int && VAL_int < 20){
    ficha_10 = ValorFicha10(VAL_int);
    VAL_int %= 5;
    }
    else if (5 <= VAL_int && VAL_int < 10){
    ficha_5 = ValorFicha5(VAL_int);
    VAL_int %= 5;
    }
  }
  printf("=========================================================");
  printf("\n QUANTIDADE DE FICHAS COMPRADAS \n");

   printf("\nQUANTIDADE DE FICHAS NO TOTAL: %d \n", (ficha_5 + ficha_10 + ficha_20 + ficha_50 + ficha_100));

  printf("\nTROCO: %.2lf", (Frac(dinheiro) + VAL_int));

  return 0;
}

int ValorFicha5(int n5){
  return n5/5;
}
int ValorFicha10(int n10){
  return n10/5;
}
int ValorFicha20(int n20){
  return n20/5;
}
int ValorFicha50(int n50){
  return n50/5;
}
int ValorFicha100(int n100){
  return n100/5;
}
double Frac(double decimal){
  double frac = modf(decimal, &decimal);
  return frac;
}
