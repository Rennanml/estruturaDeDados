#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct Arvore {
    No* raiz;
} Arvore;

Arvore* criarArvore() {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novoNo = (No*)malloc(sizeof(No));
        novoNo->valor = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }

    if (valor < raiz->valor)
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserirNo(raiz->direita, valor);

    return raiz;
}

void inserir(Arvore* arvore, int valor) {
    arvore->raiz = inserirNo(arvore->raiz, valor);
}

void percoPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        percoPreOrdem(raiz->esquerda);
        percoPreOrdem(raiz->direita);
    }
}

void percoEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percoEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        percoEmOrdem(raiz->direita);
    }
}

void percoPosOrdem(No* raiz) {
    if (raiz != NULL) {
        percoPosOrdem(raiz->esquerda);
        percoPosOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

int main() {
    Arvore* arvore = criarArvore();

    inserir(arvore, 10);
    inserir(arvore, 5);
    inserir(arvore, 15);
    inserir(arvore, 3);
    inserir(arvore, 7);

    printf("Pre-Ordem: ");
    percoPreOrdem(arvore->raiz);
    printf("\n");

    printf("Em-Ordem: ");
    percoEmOrdem(arvore->raiz);
    printf("\n");

    printf("Pos-Ordem: ");
    percoPosOrdem(arvore->raiz);
    printf("\n");

    return 0;
}
