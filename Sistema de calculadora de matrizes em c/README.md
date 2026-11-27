
# Sistema de Operações com Matrizes em C

## Descrição

Este projeto foi desenvolvido em linguagem C para realizar
operações matemáticas com duas ou mais matrizes.

O sistema permite cadastrar matrizes de diferentes dimensões
e executar operações respeitando as regras matemáticas.

## Funcionalidades

- Cadastro de duas ou mais matrizes.
- Definição da quantidade de linhas e colunas.
- Preenchimento individual dos elementos.
- Adição de matrizes.
- Subtração de matrizes.
- Multiplicação de matrizes.
- Divisão matricial utilizando matriz inversa.
- Validação das dimensões.
- Identificação de matrizes singulares.
- Exibição organizada dos resultados.
- Menu interativo para novas operações.

## Tecnologias utilizadas

- Linguagem C.
- Alocação dinâmica de memória.
- Estruturas de dados.
- Funções.
- Método de Gauss-Jordan para inversão de matrizes.

## Como executar

### 1. Compilar

Utilizando o GCC:

```bash
gcc main.c -o matrizes -lm
```

### 2. Executar

No Linux:

```bash
./matrizes
```

No Windows:

```bash
matrizes.exe
```

## Organização do projeto

```text
sistema-matrizes/
│
├── main.c
└── README.md
```

## Autor

Desenvolvido como atividade acadêmica
de programação em linguagem C.
