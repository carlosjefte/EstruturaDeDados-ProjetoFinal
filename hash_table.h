#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>  // Para getcwd()
#include "funcionarios.h"

#define TAM_HASH 50  // Tamanho da tabela hash

// Estrutura para uma tabela hash
typedef struct TabelaHash {
    Funcionario *hashTable[TAM_HASH];
    struct TabelaHash *prox;
} TabelaHash;

extern TabelaHash *listaTabelas;  // Lista de tabelas hash

// Funções
int hashFunction(int matricula);
void inserirFuncionario(TabelaHash *tabela, Funcionario *novoFunc);
void carregarFuncionarios(ListaFuncionarios *lista, const char *arquivo);
void imprimirTabelasHash();
int calcularAnosNaEmpresa(int anoAdmissao);
void concederBonificacao(ListaFuncionarios *lista);
int contarFuncionariosAntigos();

#endif