#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"

// Inicializa a lista de funcionários
void inicializarLista(ListaFuncionarios *lista) {
    lista->quantidade = 0;
}

// Carrega funcionários a partir de um arquivo
void carregarFuncionarios(ListaFuncionarios *lista, const char *arquivo) {
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        // Ignorar linhas em branco
        if (linha[0] == '\n' || linha[0] == '\r') continue;

        if (lista->quantidade >= MAX_FUNCIONARIOS) {
            printf("Limite máximo de funcionários atingido.\n");
            break;
        }

        Funcionario *novoFunc = &lista->funcionarios[lista->quantidade];

        // Zerar a estrutura antes de preencher
        memset(novoFunc, 0, sizeof(Funcionario));

        // Lendo cada campo corretamente
        if (sscanf(linha, "Matrícula: %d", &novoFunc->matricula) != 1) continue;
        do { fgets(linha, sizeof(linha), file); } while (linha[0] == '\n' || linha[0] == '\r'); // Ignora linhas em branco
        if (sscanf(linha, "Nome: %[^\n]", novoFunc->nome) != 1) continue;
        do { fgets(linha, sizeof(linha), file); } while (linha[0] == '\n' || linha[0] == '\r');
        if (sscanf(linha, "Número de Dependentes: %d", &novoFunc->dependentes) != 1) continue;
        do { fgets(linha, sizeof(linha), file); } while (linha[0] == '\n' || linha[0] == '\r');
        if (sscanf(linha, "Salário: %f", &novoFunc->salario) != 1) continue;
        do { fgets(linha, sizeof(linha), file); } while (linha[0] == '\n' || linha[0] == '\r');
        if (sscanf(linha, "Cargo: %[^\n]", novoFunc->cargo) != 1) continue;
        do { fgets(linha, sizeof(linha), file); } while (linha[0] == '\n' || linha[0] == '\r');
        
        int dia, mes, ano;
        if (sscanf(linha, "Data de Admissão: %d/%d/%d", &dia, &mes, &ano) != 3) continue;
        novoFunc->anoAdmissao = ano;

        lista->quantidade++;
    }

    fclose(file);
}

// Aplica bonificação de 5% para funcionários que atendem aos critérios
void aplicarBonificacao(ListaFuncionarios *lista) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->funcionarios[i].salario <= 2500.00 || lista->funcionarios[i].dependentes >= 2) {
            lista->funcionarios[i].salario *= 1.05;
        }
    }
}

// Conta funcionários com pelo menos 3 anos na empresa
int contarFuncionariosTresAnos(ListaFuncionarios *lista) {
    int contador = 0;
    int anoAtual = 2025; // Atualize conforme necessário

    for (int i = 0; i < lista->quantidade; i++) {
        if ((anoAtual - lista->funcionarios[i].anoAdmissao) >= 3) {
            contador++;
        }
    }

    return contador;
}

// Imprime todos os funcionários da lista
void imprimirFuncionarios(ListaFuncionarios *lista) {
    for (int i = 0; i < lista->quantidade; i++) {
        printf("\nMatrícula: %d\nNome: %s\nDependentes: %d\nSalário: %.2f\nCargo: %s\nAno de Admissão: %d\n",
               lista->funcionarios[i].matricula, lista->funcionarios[i].nome, lista->funcionarios[i].dependentes,
               lista->funcionarios[i].salario, lista->funcionarios[i].cargo, lista->funcionarios[i].anoAdmissao);
    }
}

// Simula a impressão das tabelas hash (ajustado para a estrutura de ListaFuncionarios)
void imprimirHashTables(ListaFuncionarios *lista) {
    printf("\n--- Tabela Hash Simulada ---\n");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("\nMatrícula: %d | Nome: %s | Cargo: %s | Salário: %.2f\n",
               lista->funcionarios[i].matricula, lista->funcionarios[i].nome,
               lista->funcionarios[i].cargo, lista->funcionarios[i].salario);
    }
}