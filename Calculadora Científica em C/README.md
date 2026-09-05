🧮 Calculadora Completa em C

Projeto acadêmico de uma calculadora completa desenvolvida em linguagem C, utilizando conceitos fundamentais de programação, como variáveis, entrada e saída de dados, estruturas condicionais, estruturas de repetição, funções, modularização e a biblioteca math.h.

🎯 Objetivo

Desenvolver uma calculadora capaz de realizar diferentes operações matemáticas por meio de um menu interativo, aplicando os conceitos estudados em programação em C.

🚀 Funcionalidades

O programa possui 23 operações/funções, superando o mínimo de 20 solicitado:

Nº

Operação

1

Soma

2

Subtração

3

Multiplicação

4

Divisão

5

Potenciação

6

Raiz quadrada

7

Raiz cúbica

8

Seno

9

Cosseno

10

Tangente

11

Logaritmo natural

12

Logaritmo base 10

13

Valor absoluto

14

Porcentagem

15

Média aritmética

16

Conversão de graus para radianos

17

Conversão de radianos para graus

18

Área do círculo

19

Área do retângulo

20

Hipotenusa

21

Módulo

22

Fatorial

23

IMC

🛠️ Conceitos utilizados

Variáveis e tipos de dados

printf() para saída de dados

scanf() para entrada de dados

switch...case para seleção de operações

do...while para repetição do menu

if...else para validações e classificações

Funções para modularização

Biblioteca stdio.h

Biblioteca math.h

pow(), sqrt(), cbrt(), sin(), cos(), tan()

log(), log10(), fabs(), fmod() e hypot()

Estrutura for para o cálculo do fatorial

Tratamento básico de erros

⚠️ Tratamento de erros

O programa possui verificações para situações como:

divisão por zero;

módulo por zero;

raiz quadrada de número negativo;

logaritmo de número menor ou igual a zero;

raio, base, altura, peso ou altura negativos/inválidos;

fatorial de número negativo;

opções inexistentes no menu;

entrada inválida para a opção principal.

📁 Estrutura do projeto

calculadora-c/
│
├── calculadora.c
└── README.md

💻 Como executar

1. Clone o repositório

git clone URL_DO_SEU_REPOSITORIO

2. Entre na pasta

cd calculadora-c

3. Compile

Com GCC:

gcc calculadora.c -o calculadora -lm

O parâmetro -lm é utilizado para vincular a biblioteca matemática math.h.

4. Execute

No Linux/macOS:

./calculadora

No Windows:

calculadora.exe

📋 Exemplo de uso

============================================
          CALCULADORA COMPLETA EM C
============================================
 1  - Soma
 2  - Subtracao
 3  - Multiplicacao
 ...
23  - IMC
 0  - Sair
============================================
Escolha uma opcao: 1

Digite dois valores: 10 5
Resultado: 15.00

Exemplo de IMC

Escolha uma opcao: 23

Digite o peso em kg: 70
Digite a altura em metros: 1.75
IMC: 22.86
Classificacao: peso normal.

👨‍💻 Autor

Pedro Henrique

Projeto desenvolvido para fins acadêmicos como prática dos fundamentos de programação em C.
