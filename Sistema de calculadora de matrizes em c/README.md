
# Sistema de Operações com Matrizes em C

## Descrição

Este projeto consiste no desenvolvimento de um sistema
computacional em linguagem C para realizar operações
matemáticas com duas ou mais matrizes.

O sistema permite cadastrar matrizes de diferentes dimensões
e executar operações matemáticas de forma sequencial,
respeitando as condições e propriedades matemáticas.

O desenvolvimento foi realizado utilizando modularização,
estruturas de dados, funções e alocação dinâmica de memória.

## Funcionalidades

- Cadastro de duas ou mais matrizes.
- Definição da quantidade de linhas e colunas.
- Preenchimento individual dos elementos.
- Armazenamento das matrizes cadastradas.
- Adição de matrizes.
- Subtração de matrizes.
- Multiplicação de matrizes.
- Divisão matricial por meio da matriz inversa.
- Cálculo da inversa pelo método de Gauss-Jordan.
- Identificação de matrizes singulares.
- Validação das dimensões das matrizes.
- Exibição organizada dos resultados.
- Menu interativo para realizar novas operações.
- Liberação de memória ao encerrar o programa.

## Tecnologias utilizadas

- Linguagem C.
- Padrão C11.
- Biblioteca stdio.h.
- Biblioteca stdlib.h.
- Biblioteca math.h.
- Biblioteca ctype.h.
- Alocação dinâmica de memória.
- Modularização por arquivos e funções.

## Organização dos arquivos

```text
sistema-operacoes-matrizes/
│
├── main.c
├── matriz.h
├── matriz.c
├── operacoes.h
├── operacoes.c
├── README.md
└── .gitignore
```

## Organização dos módulos

### main.c
Responsável pelo fluxo principal do programa,
cadastro das matrizes, menu e execução das operações.

### matriz.h
Contém a estrutura da matriz e os protótipos
das funções de gerenciamento.

### matriz.c
Implementa as funções de leitura, criação,
cópia, exibição e liberação das matrizes.

### operacoes.h
Contém os protótipos das operações matemáticas.

### operacoes.c
Implementa adição, subtração, multiplicação,
divisão matricial e inversão de matrizes.

## Regras matemáticas

### Adição
As matrizes devem possuir as mesmas dimensões.

### Subtração
As matrizes devem possuir as mesmas dimensões.

### Multiplicação
O número de colunas da primeira matriz deve
ser igual ao número de linhas da segunda.

### Divisão matricial
A divisão é definida como:

A / B = A × B⁻¹

A matriz divisora deve ser quadrada, inversível
e possuir dimensões compatíveis.

Para três ou mais matrizes, as operações são
realizadas sequencialmente, da esquerda para a direita.

## Como executar no OneCompiler

1. Acesse https://onecompiler.com/c
2. Selecione a linguagem C.
3. Crie os arquivos do projeto no editor, caso
   a interface permita múltiplos arquivos.
4. Adicione o conteúdo de cada arquivo.
5. Execute o programa utilizando a opção Run.

Caso utilize apenas um arquivo, reúna os módulos
em um único arquivo main.c, mantendo a separação
das funções por responsabilidade.

## Como compilar localmente

Utilizando GCC:

```bash
gcc -Wall -Wextra -std=c11 main.c matriz.c operacoes.c -o matrizes -lm
```

Para executar no Linux:

```bash
./matrizes
```

No Windows:

```bash
matrizes.exe
```

## Exemplo de utilização

O usuário cadastra duas matrizes:

Matriz A:

1 2
3 4

Matriz B:

5 6
7 8

Selecionando a opção de adição, o resultado será:

6 8
10 12

## Tratamento de erros

O sistema verifica:

- Quantidade inválida de matrizes.
- Entradas numéricas inválidas.
- Dimensões incompatíveis.
- Matrizes divisoras não quadradas.
- Matrizes singulares, sem inversa.
- Falhas de alocação de memória.

## Objetivo acadêmico

O projeto tem como objetivo aplicar conceitos
fundamentais de programação em linguagem C,
incluindo modularização, estruturas, ponteiros,
alocação dinâmica, funções e operações matriciais.

## Autor

Desenvolvido como atividade acadêmica
de programação em linguagem C.
