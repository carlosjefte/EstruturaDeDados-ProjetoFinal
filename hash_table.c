#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

TabelaHash *listaTabelas = NULL;  // Inicializa a lista de tabelas hash

// Função de hash (distribui os funcionários pelo número da matrícula)
int hashFunction(int matricula) {
    return matricula % TAM_HASH;
}

// Insere um funcionário na tabela hash
void inserirFuncionario(TabelaHash *tabela, Funcionario *novoFunc) {
    int index = hashFunction(novoFunc->matricula);

    // Certifique-se de que o funcionário pode ser encadeado
    novoFunc->prox = tabela->hashTable[index];
    tabela->hashTable[index] = novoFunc;
}

// Lê os funcionários do arquivo e cria múltiplas tabelas hash
void lerArquivo(const char *arquivo, ListaFuncionarios *lista) {
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    TabelaHash *tabelaAtual = NULL;

    while (fgets(linha, sizeof(linha), file)) {
        // Quando encontra a linha de separação, cria uma nova tabela hash
        if (strstr(linha, "x----------------------------x")) {
            TabelaHash *novaTabela = (TabelaHash *)malloc(sizeof(TabelaHash));
            if (novaTabela == NULL) {
                printf("Erro ao alocar memória para nova tabela hash.\n");
                fclose(file);
                return;
            }
            memset(novaTabela->hashTable, 0, sizeof(novaTabela->hashTable));
            novaTabela->prox = listaTabelas;
            listaTabelas = novaTabela;
            tabelaAtual = novaTabela;
            continue;
        }

        if (tabelaAtual == NULL) continue;  // Ignorar se não há tabela criada

        Funcionario *novoFunc = (Funcionario *)malloc(sizeof(Funcionario));
        if (novoFunc == NULL) {
            printf("Erro ao alocar memória para funcionário.\n");
            fclose(file);
            return;
        }

        // Lê os dados do funcionário formatados
        sscanf(linha, "Matrícula: %d", &novoFunc->matricula);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Nome: %[^\n]", novoFunc->nome);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Número de Dependentes: %d", &novoFunc->dependentes);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Salário: %f", &novoFunc->salario);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Cargo: %[^\n]", novoFunc->cargo);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Data de Admissão: %d", &novoFunc->anoAdmissao);

        novoFunc->prox = NULL;
        inserirFuncionario(tabelaAtual, novoFunc);
    }

    fclose(file);
}

// Exibe os funcionários armazenados em todas as tabelas hash
void imprimirTabelasHash() {
    int contador = 1;
    TabelaHash *tabelaAtual = listaTabelas;

    while (tabelaAtual != NULL) {
        printf("\n--- Tabela Hash %d ---\n", contador);
        for (int i = 0; i < TAM_HASH; i++) {
            Funcionario *atual = tabelaAtual->hashTable[i];
            while (atual) {
                printf("\nMatrícula: %d\nNome: %s\nDependentes: %d\nSalário: %.2f\nCargo: %s\nAno de Admissão: %d\n",
                       atual->matricula, atual->nome, atual->dependentes, atual->salario, atual->cargo, atual->anoAdmissao);
                atual = atual->prox;
            }
        }
        tabelaAtual = tabelaAtual->prox;
        contador++;
    }
}

// Calcula quantos anos o funcionário tem na empresa
int calcularAnosNaEmpresa(int anoAdmissao) {
    time_t t = time(NULL);
    struct tm *hoje = localtime(&t);
    int anoAtual = hoje->tm_year + 1900;

    return anoAtual - anoAdmissao;
}

// Concede bonificação de 5%
void concederBonificacao(ListaFuncionarios *lista) {
    TabelaHash *tabelaAtual = listaTabelas;

    while (tabelaAtual != NULL) {
        for (int i = 0; i < TAM_HASH; i++) {
            Funcionario *atual = tabelaAtual->hashTable[i];
            while (atual) {
                if (atual->salario <= 2500.00 || atual->dependentes >= 2) {
                    atual->salario *= 1.05;
                }
                atual = atual->prox;
            }
        }
        tabelaAtual = tabelaAtual->prox;
    }
}

// Conta funcionários com pelo menos 3 anos na empresa
int contarFuncionariosAntigos() {
    int contador = 0;
    TabelaHash *tabelaAtual = listaTabelas;

    while (tabelaAtual != NULL) {
        for (int i = 0; i < TAM_HASH; i++) {
            Funcionario *atual = tabelaAtual->hashTable[i];
            while (atual) {
                if (calcularAnosNaEmpresa(atual->anoAdmissao) >= 3) {
                    contador++;
                }
                atual = atual->prox;
            }
        }
        tabelaAtual = tabelaAtual->prox;
    }

    return contador;
}