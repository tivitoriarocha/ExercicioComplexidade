//invertexto.com/rzak36
#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore binária
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

Node* inserir(Node* raiz, int valor){
    if(raiz == NULL){
        return criarNo(valor);
    }
    if(valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }else{
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}


int main(){
    Node* raiz = NULL;
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 31);
}