#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long fib[2000] = {0}; 

long long fibonacci2(int n) {
    if (n <= 1) {
        return n;
    }
    if (fib[n] != 0) { 
        return fib[n];
    }
    fib[n] = fibonacci2(n - 1) + fibonacci2(n - 2);
    return fib[n];
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Uso: %s <posição> <n_max>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int n_max = atoi(argv[2]);
    clock_t start, end;
    double tempo = 0.0;
    long long resultado;
    for (int i = 0; i < n_max; i++) {
        start = clock();
        resultado = fibonacci2(n);
        end = clock();
        tempo += ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Progresso: %.2f%% concluído\n", ((i + 1) / (double)n_max) * 100);
    }
    printf("Fibonacci na posição %d é %lld\n", n, resultado);
    printf("Tempo médio: %f us\n", (tempo / n_max) * 1e6);

return 0;
}