#include <stdio.h>
#include "ordenacao.h"

void trocar(Funcionario *a, Funcionario *b) {
    Funcionario temp = *a;
    *a = *b;
    *b = temp;
}

// Ordena os funcionários por tempo de empresa (mais antigo primeiro)
void ordenarPorTempoNaEmpresa(ListaFuncionarios *lista) {
    for (int i = 0; i < lista->quantidade - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < lista->quantidade; j++) {
            if (lista->funcionarios[j].anoAdmissao < lista->funcionarios[menor].anoAdmissao) {
                menor = j;
            }
        }
        if (menor != i) {
            trocar(&lista->funcionarios[i], &lista->funcionarios[menor]);
        }
    }
}

// Ordena os funcionários por número de dependentes (menor número primeiro)
void ordenarPorDependentes(ListaFuncionarios *lista) {
    for (int i = 0; i < lista->quantidade - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < lista->quantidade; j++) {
            if (lista->funcionarios[j].dependentes < lista->funcionarios[menor].dependentes) {
                menor = j;
            }
        }
        if (menor != i) {
            trocar(&lista->funcionarios[i], &lista->funcionarios[menor]);
        }
    }
}

// Ordena os funcionários por salário (do menor para o maior)
void ordenarPorSalario(ListaFuncionarios *lista) {
    for (int i = 0; i < lista->quantidade - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < lista->quantidade; j++) {
            if (lista->funcionarios[j].salario < lista->funcionarios[menor].salario) {
                menor = j;
            }
        }
        if (menor != i) {
            trocar(&lista->funcionarios[i], &lista->funcionarios[menor]);
        }
    }
}