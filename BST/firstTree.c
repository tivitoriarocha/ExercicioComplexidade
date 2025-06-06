#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;


Node* criarNo(int valor){
    Node* novo = malloc(sizeof(Node));
    if(novo){
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
    }
    return novo;
}

int main(){
    Node* raiz = criarNo(20);
    raiz->esquerda = criarNo(10);
    raiz->esquerda->direita = criarNo(15);
    raiz->esquerda->direita->direita = criarNo(18);
}