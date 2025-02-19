#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#define MAX_FUNCIONARIOS 100

typedef struct Funcionario {
    int matricula;
    char nome[100];
    int dependentes;
    float salario;
    char cargo[50];
    int anoAdmissao; // Alterado de dataAdmissao (string) para um inteiro
    struct Funcionario *prox; // Adicionando ponteiro para lista encadeada
} Funcionario;

// Estrutura ListaFuncionarios
typedef struct {
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    int quantidade;
} ListaFuncionarios;

// Funções
void inicializarLista(ListaFuncionarios *lista);
void carregarFuncionarios(ListaFuncionarios *lista, const char *arquivo);
void aplicarBonificacao(ListaFuncionarios *lista);
int contarFuncionariosTresAnos(ListaFuncionarios *lista);
void imprimirFuncionarios(ListaFuncionarios *lista);
void imprimirHashTables(ListaFuncionarios *lista); // Adicionado

#endif