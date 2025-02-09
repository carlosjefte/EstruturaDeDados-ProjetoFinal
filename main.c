#include <stdio.h>
#include <stdlib.h>
#include "funcionarios.h"
#include "estatisticas.h"
#include "ordenacao.h"
#include "frequencia.h"

void menu(ListaFuncionarios *lista) {
    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Exibir funcionários\n");
        printf("2. Conceder bonificação\n");
        printf("3. Contar funcionários com 3+ anos na empresa\n");
        printf("4. Calcular estatísticas salariais\n");
        printf("5. Exibir distribuição de frequência salarial\n");
        printf("6. Ordenar funcionários\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa buffer de entrada
            continue;
        }

        switch (opcao) {
            case 1:
                imprimirHashTables(lista);
                break;
            case 2:
                concederBonificacao(lista);
                printf("Bonificação aplicada com sucesso!\n");
                break;
            case 3:
                printf("Funcionários com 3+ anos na empresa: %d\n", contarFuncionariosTresAnos(lista));
                break;
            case 4:
                printf("Amplitude Salarial: %.2f\n", calcularAmplitudeSalarial(lista));
                printf("Média Salarial: %.2f\n", calcularMediaSalarial(lista));
                printf("Média Geométrica Salarial: %.2f\n", calcularMediaGeometricaSalarial(lista));
                break;
            case 5:
                calcularDistribuicaoFrequencia(lista);
                printf("Salário Modal: %.2f\n", calcularSalarioModal(lista));
                break;
            case 6: {
                printf("Ordenar por:\n1. Salário\n2. Dependentes\n3. Tempo de empresa\n");
                int crit;
                if (scanf("%d", &crit) != 1) {
                    printf("Entrada inválida. Voltando ao menu.\n");
                    while (getchar() != '\n');
                    continue;
                }

                switch (crit) {
                    case 1: 
                        ordenarPorSalario(lista);
                        printf("Funcionários ordenados por salário.\n");
                        break;
                    case 2: 
                        ordenarPorDependentes(lista);
                        printf("Funcionários ordenados por número de dependentes.\n");
                        break;
                    case 3: 
                        ordenarPorTempoNaEmpresa(lista);
                        printf("Funcionários ordenados por tempo de empresa.\n");
                        break;
                    default: 
                        printf("Opção inválida.\n");
                        continue;
                }

                imprimirFuncionarios(lista); // Agora imprime os funcionários após ordenar
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

int main() {
    ListaFuncionarios lista;
    inicializarLista(&lista);

    printf("Carregando funcionários...\n");
    carregarFuncionarios(&lista, "func.txt");

    if (lista.quantidade == 0) {
        printf("Nenhum funcionário carregado. Verifique o arquivo 'func.txt'.\n");
        return 1;
    }

    menu(&lista);
    return 0;
}