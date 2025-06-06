#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno *esquerdo;
    struct Aluno *direito;
} Aluno;

Aluno* criarAluno(const char *nome, int matricula, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if(novo) {
        strncpy(novo->nome, nome, 49);
        novo->nome[49] = '\0';
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
return novo;
}

Aluno* inserirAluno(Aluno* raiz, const char *nome, int matricula, float nota) {
    if(raiz == NULL) {
        return criarAluno(nome, matricula, nota);
    }
    if(matricula < raiz->matricula) {
        raiz->esquerdo = inserirAluno(raiz->esquerdo, nome, matricula, nota);
    } else {
        raiz->direito = inserirAluno(raiz->direito, nome, matricula, nota);
    }
    return raiz;
}

Aluno* buscarPorNome(Aluno* raiz, const char *nome) {
    if(raiz == NULL) {
        return NULL;
    }
    if(strcmp(raiz->nome, nome) == 0) {
        return raiz;
    }
    Aluno* encontrado = buscarPorNome(raiz->esquerdo, nome);
    if(encontrado != NULL) {
        return encontrado;
    }
    return buscarPorNome(raiz->direito, nome);
}

void calcularMedia(Aluno* raiz, float *soma, int *contador) {
    if(raiz != NULL) {
        *soma += raiz->nota;
        (*contador)++;
        calcularMedia(raiz->esquerdo, soma, contador);
        calcularMedia(raiz->direito, soma, contador);
    }
}

void imprimirAluno(Aluno* aluno) {
    if(aluno != NULL) {
        printf("Nome: %s\n", aluno->nome);
        printf("Matricula: %d\n", aluno->matricula);
        printf("Nota: %.2f\n\n", aluno->nota);
    }
}

void percorrerEmOrdem(Aluno* raiz) {
    if(raiz != NULL) {
        percorrerEmOrdem(raiz->esquerdo);
        imprimirAluno(raiz);
        percorrerEmOrdem(raiz->direito);
    }
}

void liberarArvore(Aluno* raiz) {
    if(raiz != NULL) {
        liberarArvore(raiz->esquerdo);
        liberarArvore(raiz->direito);
        free(raiz);
    }
}

int main() {

    Aluno* raiz = NULL;
    
    raiz = inserirAluno(raiz, "Joao Silva", 12345, 8.5);
    raiz = inserirAluno(raiz, "Maria Santos", 12344, 9.0);
    raiz = inserirAluno(raiz, "Pedro Oliveira", 12347, 7.5);
    raiz = inserirAluno(raiz, "Ana Costa", 12346, 8.0);
    printf("Alunos cadastrados (em ordem de matricula):\n");
    percorrerEmOrdem(raiz);
    const char* nomeBusca = "Maria Santos";
    Aluno* alunoEncontrado = buscarPorNome(raiz, nomeBusca);
    printf("\nResultado da busca por '%s':\n", nomeBusca);
    if(alunoEncontrado != NULL) {
        imprimirAluno(alunoEncontrado);
    } else {
        printf("Aluno nao encontrado.\n");
    }
    float somaNotas = 0;
    int totalAlunos = 0;
    calcularMedia(raiz, &somaNotas, &totalAlunos);
    if(totalAlunos > 0) {
        printf("\nMedia das notas: %.2f\n", somaNotas / totalAlunos);
    } else {
        printf("\nNao ha alunos cadastrados para calcular a media.\n");
    }
    liberarArvore(raiz);
    
return 0;
}