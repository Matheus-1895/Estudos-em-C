#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct Fila {
    No* inicio;
} Fila;

void inicializar(Fila* fila) {
    fila->inicio = NULL;
}

int vazia(Fila* fila) {
    return fila->inicio == NULL;
}

void enfileira(Fila* fila, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if (vazia(fila)) {
        novoNo->proximo = novoNo;
        novoNo->anterior = novoNo;
        fila->inicio = novoNo;
    } else {
        novoNo->proximo = fila->inicio;
        novoNo->anterior = fila->inicio->anterior;
        fila->inicio->anterior->proximo = novoNo;
        fila->inicio->anterior = novoNo;
    }
}

int desenfileira(Fila* fila, int index) {
    if (vazia(fila)) {
        printf("Erro: fila vazia\n");
        exit(1);
    }

    No* atual = fila->inicio;
    for (int i = 0; i < index - 1; i++) {
        atual = atual->proximo;
    }

    int valor = atual->valor;

    if (atual == fila->inicio) {
        if (fila->inicio->proximo == fila->inicio) {
            fila->inicio = NULL;
        } else {
            fila->inicio = fila->inicio->proximo;
            fila->inicio->anterior = atual->anterior;
            atual->anterior->proximo = fila->inicio;
        }
    } else {
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
    return valor;
}

void mostra(Fila* fila) {
    if (vazia(fila)) {
        printf("Fila vazia\n");
        return;
    }

    No* atual = fila->inicio;
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != fila->inicio);

    printf("\n");
}

void mostraInverso(Fila* fila) {
    if (vazia(fila)) {
        printf("Fila vazia\n");
        return;
    }

    No* atual = fila->inicio->anterior;
    do {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    } while (atual != fila->inicio->anterior);

    printf("\n");
}


int main() {
    Fila fila;
    inicializar(&fila);

    printf("Fila vazia? \n%d\n", vazia(&fila));

    int elementos;
    printf("Quantos elementos deseja enfileirar? ");
    scanf("%d", &elementos);

    for (int i = 0; i < elementos; i++) {
        int valor;
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &valor);
        enfileira(&fila, valor);
    }

    printf("Elementos da fila: \n");
    mostra(&fila);

    int index;
    printf("Digite o elemento a ser removido: ");
    scanf("%d", &index);

    int elemento = desenfileira(&fila, index);
    printf("Elemento removido:\n %d\n", elemento);

    printf("Elementos restantes: \n");
    mostra(&fila);

    printf("Fila em ordem inversa:\n ");
    mostraInverso(&fila);

    
    return 0;
}
