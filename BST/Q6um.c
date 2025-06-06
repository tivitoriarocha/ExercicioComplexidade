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

Node* buscar(Node* raiz, int valor) {
    if(raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if(valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

Node* encontrarMinimo(Node* no) {
    Node* atual = no;
    while(atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

Node* remover(Node* raiz, int valor) {
    if(raiz == NULL) return raiz;
    
    // Busca pelo nó a ser removido
    if(valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if(valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Nó com apenas um filho ou nenhum filho
        if(raiz->esquerda == NULL) {
            Node* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if(raiz->direita == NULL) {
            Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        
        // Nó com dois filhos: obtém o sucessor in-order (menor na subárvore direita)
        Node* temp = encontrarMinimo(raiz->direita);
        
        // Copia o valor do sucessor in-order para este nó
        raiz->valor = temp->valor;
        
        // Remove o sucessor in-order
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

int maior(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int h(Node* no){
    if(no == NULL){
        return -1;
    }
    return maior(h(no->esquerda), h(no->direita)) + 1;
}

int profundidade(Node* raiz) {
    if(raiz == NULL) {
        return 0;
    } else {
        int profundidadeEsq = profundidade(raiz->esquerda);
        int profundidadeDir = profundidade(raiz->direita);
        
        if(profundidadeEsq > profundidadeDir) {
            return profundidadeEsq + 1;
        } else {
            return profundidadeDir + 1;
        }
    }
}

int somaValores(Node* raiz) {
    if(raiz == NULL) {
        return 0;
    }
    return raiz->valor + somaValores(raiz->esquerda) + somaValores(raiz->direita);
}

int nivelNo(Node* raiz, int valor, int nivelAtual) {
    if(raiz == NULL) {
        return -1; 
    }
    if(raiz->valor == valor) {
        return nivelAtual;
    }
    
    int nivel = nivelNo(raiz->esquerda, valor, nivelAtual + 1);
    if(nivel != -1) {
        return nivel;
    }
    
    return nivelNo(raiz->direita, valor, nivelAtual + 1);
}

int contarNos(Node* raiz) {
    if(raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int contarFolhas(Node* raiz) {
    if(raiz == NULL) {
        return 0;
    }
    if(raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    }
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

void preOrdem(Node* raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(Node* raiz){
    if(raiz != NULL){
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void ordem(Node* raiz){
    if(raiz != NULL){
        preOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        preOrdem(raiz->direita);
    }
}

int main(){
    Node* raiz = NULL;
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 18);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 31);
    //preOrdem(raiz);
    //posOrdem(raiz);
    //ordem(raiz);
}