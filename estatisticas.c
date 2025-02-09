#include <math.h>
#include "estatisticas.h"

float calcularAmplitudeSalarial(ListaFuncionarios *lista) {
    float min = lista->funcionarios[0].salario;
    float max = min;

    for (int i = 1; i < lista->quantidade; i++) {
        if (lista->funcionarios[i].salario < min) min = lista->funcionarios[i].salario;
        if (lista->funcionarios[i].salario > max) max = lista->funcionarios[i].salario;
    }
    return max - min;
}

float calcularMediaSalarial(ListaFuncionarios *lista) {
    float soma = 0;
    for (int i = 0; i < lista->quantidade; i++) {
        soma += lista->funcionarios[i].salario;
    }
    return soma / lista->quantidade;
}

float calcularMediaGeometricaSalarial(ListaFuncionarios *lista) {
    float produto = 1.0;
    int n = lista->quantidade;
    
    if (n == 0) return 0;

    for (int i = 0; i < n; i++) {
        produto *= lista->funcionarios[i].salario;
    }
    
    return pow(produto, 1.0 / n);
}