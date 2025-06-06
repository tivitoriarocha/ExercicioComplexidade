#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Versão usando fórmula fechada (Binet) - aproximação para n < 70
double fibonacci_binet(int n) {
    double sqrt5 = sqrt(5);
    double phi = (1 + sqrt5) / 2;
    return round(pow(phi, n) / sqrt5);
}

// Versão iterativa para n >= 70 (mais precisa)
long long fibonacci_iterativo(int n) {
    if (n <= 1) return n;
    
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
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
        if (n < 70) {
            resultado = (long long)fibonacci_binet(n);
        } else {
            resultado = fibonacci_iterativo(n);
        }
        end = clock();
        tempo += ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Progresso: %.2f%% concluído\n", ((i + 1) / (double)n_max) * 100);
    }

    printf("Fibonacci na posição %d é %lld\n", n, resultado);
    printf("Tempo médio: %f us\n", (tempo / n_max) * 1e6);

    return 0;
}