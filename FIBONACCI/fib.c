#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int fibonacci1(int n){
    if (n<=1){
        return n;
    }
    return fibonacci1(n-1)+ fibonacci1(n-2);
}

int main(int argc, char* argv[]){

    int n = atoi(argv[1]);
    int n_max = atoi(argv[2]);
    clock_t start, end;
    double tempo = 0.0;
    int resultado;

    for (size_t i = 0; i < n_max; i++){
        start = clock();
        resultado = fibonacci1(n);
        end = clock();
        tempo += ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Progresso: %.2f%% concluído\n", ((i+1)/(double)n_max)*100);
    }

    printf("Fibonacci1 na posição %d é %d\n", n, resultado);
    printf("Tempo médio: %f us\n", (tempo/n_max)*1e6);

return 0;    
}
