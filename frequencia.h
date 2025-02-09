#ifndef FREQUENCIA_H
#define FREQUENCIA_H

#include "funcionarios.h"

// Estrutura para distribuição de frequência
typedef struct {
    float min;
    float max;
    int frequencia;
} IntervaloClasse;

// Funções
void calcularDistribuicaoFrequencia(ListaFuncionarios *lista);
float calcularSalarioModal(ListaFuncionarios *lista); // Corrigido: agora recebe ListaFuncionarios *

#endif