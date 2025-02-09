#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include "funcionarios.h"

// Funções para cálculos estatísticos
float calcularAmplitudeSalarial(ListaFuncionarios *lista);
float calcularMediaSalarial(ListaFuncionarios *lista);
float calcularMediaGeometricaSalarial(ListaFuncionarios *lista); // Corrigido

#endif