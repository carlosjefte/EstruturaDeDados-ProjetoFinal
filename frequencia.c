#include <stdio.h>
#include "frequencia.h"

void calcularDistribuicaoFrequencia(ListaFuncionarios *lista) {
    printf("Cálculo da distribuição de frequência ainda não implementado.\n");
}

float calcularSalarioModal(ListaFuncionarios *lista) { // Corrigido: agora recebe ListaFuncionarios *
    return lista->quantidade > 0 ? lista->funcionarios[0].salario : 0;
}