#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#define MAX_ALUNOS 30
#define MAX_NOME 51

struct Aluno {
    int matricula;
    float nota1, nota2, nota3, soma, media;
    char nome[MAX_NOME];
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Aluno alunos[MAX_ALUNOS];

    int n_alunos;
    printf("Quantos alunos deseja cadastrar(Máximo 30)? ");
    scanf("%d", &n_alunos);

    for (int i = 0; i < n_alunos; i++) {
        printf("Digite os dados do aluno %d:\n", i + 1);
        printf("Insira o nome do aluno: ");
        scanf("%s", alunos[i].nome);
        printf("Insira a matricula do aluno: ");
        scanf("%d", &alunos[i].matricula);
        printf("Insira a nota1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Insira a nota2: ");
        scanf("%f", &alunos[i].nota2);
        printf("Insira a nota3: ");
        scanf("%f", &alunos[i].nota3);
        alunos[i].soma = alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3;
        alunos[i].media = alunos[i].soma / 3;
        if (alunos[i].media >= 6) {
    printf("Aluno aprovado\n");
} else {
    printf("Aluno reprovado\n");
}
     printf("*******************\n");
    }
  

    for (int i = 0; i < n_alunos; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Média: %.2f\n\n", alunos[i].media);
        printf("*******************\n");
    }

    float soma_medias = 0.0;
    for (int i = 0; i < n_alunos; i++) {
        soma_medias += alunos[i].media;
    }
    float media_geral = soma_medias / n_alunos;
    printf("Média geral dos alunos: %.2f\n", media_geral);
    
   return 0;
}

