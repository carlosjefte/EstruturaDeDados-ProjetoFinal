# Gerenciamento de Funcionários

Este é um sistema em C para gerenciamento de funcionários, permitindo operações como exibição, ordenação, bonificação e cálculo de estatísticas salariais.

## Funcionalidades

- Carregamento de funcionários a partir de um arquivo de texto
- Exibição de dados em formato de tabela hash simulada
- Concessão de bonificação para funcionários elegíveis
- Cálculo de estatísticas salariais (média, moda, amplitude salarial, etc.)
- Ordenação de funcionários por salário, dependentes ou tempo na empresa

## Estrutura do Projeto

```
ProjetoFinal/
│── main.c                # Arquivo principal
│── funcionarios.c        # Gerenciamento de dados dos funcionários
│── funcionarios.h        # Definição das estruturas e funções
│── estatisticas.c        # Cálculo de estatísticas salariais
│── estatisticas.h        # Cabeçalho das estatísticas
│── ordenacao.c           # Funções de ordenação
│── ordenacao.h           # Cabeçalho da ordenação
│── frequencia.c          # Distribuição de frequência salarial
│── frequencia.h          # Cabeçalho da distribuição de frequência
│── hash_table.c          # Simulação de tabela hash
│── hash_table.h          # Cabeçalho da tabela hash
│── func.txt              # Arquivo com dados dos funcionários
│── Makefile              # Arquivo para compilação automática
```

## Compilação e Execução

Para compilar o programa, utilize o GCC:

```sh
gcc main.c funcionarios.c estatisticas.c ordenacao.c frequencia.c hash_table.c -o programa -lm
```

Para executar o programa:

```sh
./programa
```

## Formato do Arquivo `func.txt`

O arquivo de entrada `func.txt` deve seguir o seguinte formato:

```
Matrícula: 12345
Nome: João Silva
Número de Dependentes: 2
Salário: 3000.00
Cargo: Analista de Sistemas
Data de Admissão: 12/05/2018
x----------------------------x

Matrícula: 67890
Nome: Maria Souza
Número de Dependentes: 1
Salário: 4500.00
Cargo: Gerente de Projetos
Data de Admissão: 07/09/2015
x----------------------------x
```

## Exemplo de Uso

1. Ao iniciar, o programa carrega os dados do arquivo `func.txt`.
2. O usuário pode interagir com o menu e escolher opções como visualizar, ordenar e calcular estatísticas.
3. As opções de ordenação permitem organizar os dados por diferentes critérios.

## Possíveis Melhorias

- Melhor tratamento de erros na leitura de arquivos.
- Implementação de uma estrutura real de hash table.
- Opção para salvar os funcionários ordenados em um novo arquivo.

## Autor

Este projeto foi desenvolvido como parte de um estudo prático em linguagem C para manipulação de dados estruturados.

