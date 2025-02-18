#include <stdio.h>
#include "frequencia.h"

void calcularDistribuicaoFrequencia(ListaFuncionarios *lista) {
    float soma = 0.0, mult = 0.0;
    float limite_inferior[] = {0.0, 1518.0, 3036.0, 7590.0, 9108.0};
    float pontosMedios[] = {759, 2277, 5313, 8349, 9867};
    float limite_superior[] = {1518, 3036, 7590, 9108, 10626};
    
    int frequencia [] = {0,0,0,0,0};
    
    // Calcula a frequência de cada intervalo
    for(int i = 0; i < lista->quantidade; i++){ 
        for(int j = 0; j < 5; j++){
            if(lista->funcionarios[i].salario > limite_inferior[j] && lista->funcionarios[i].salario <= limite_superior[j]){
                frequencia[j]++;
                break; // Para evitar contagem em múltiplos intervalos
            }
        }
    }

    // Imprime a distribuição de frequência
    printf("------------------------------------- \n");
    printf("I.C*                               fi*\n");
    printf("------------------------------------- \n");
    for (int k = 0; k < 5; k++) {
        printf("Faixa %.2f - %.2f: %d funcionários\n", 
                limite_inferior[k], 
                limite_superior[k], 
                frequencia[k]);
    }
    
    // Calcula a média intervalar
    for(int i = 0 ; i < 5 ; i++){
        soma += frequencia[i];
        mult += frequencia[i] * pontosMedios[i];
    }
    
    float media = mult / soma;
    printf("A média intervalar é: %.2f \n", media);
}


float calcularSalarioModal(ListaFuncionarios *lista) { // Corrigido: agora recebe ListaFuncionarios *
    return printf("ok");
    // return lista->quantidade > 0 ? lista->funcionarios[0].salario : 0;
}