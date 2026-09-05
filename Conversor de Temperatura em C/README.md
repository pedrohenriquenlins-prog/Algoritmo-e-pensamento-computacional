# 🌡️ Conversor de Temperaturas em C

## 📌 Descrição da atividade

Este projeto consiste no desenvolvimento de um **sistema de conversão de temperaturas em linguagem C**.

O programa permite que o usuário escolha, por meio de um menu, entre diferentes tipos de conversão envolvendo as escalas **Celsius, Kelvin e Fahrenheit**.

A atividade tem como objetivo praticar conceitos fundamentais da linguagem C, como:

* Variáveis e tipos de dados;
* Entrada de dados com `scanf()`;
* Saída de dados com `printf()`;
* Estrutura condicional `switch...case`;
* Operadores matemáticos;
* Organização e estruturação de um programa em C.

---

## ⚙️ Funcionamento do programa

Ao iniciar o programa, é apresentado um menu com as opções de conversão disponíveis.

O usuário deve:

1. Escolher uma opção de conversão;
2. Informar o valor da temperatura solicitado;
3. O programa realiza o cálculo correspondente;
4. O resultado da conversão é apresentado na tela.

O programa utiliza a estrutura `switch...case` para identificar a opção escolhida pelo usuário e executar a conversão correspondente.

Caso o usuário informe uma opção que não esteja entre **1 e 6**, o programa apresenta uma mensagem informando que a opção é inválida.

### Exemplo de funcionamento

```text
=== Sistema de conversão de temperaturas ===
Escolha a opção de conversão:
1 - Celsius para Kelvin
2 - Celsius para Fahrenheit
3 - Kelvin para Celsius
4 - Kelvin para Fahrenheit
5 - Fahrenheit para Celsius
6 - Fahrenheit para Kelvin

Digite uma opção: 1

Digite o valor em Celsius: 25

25.00 Celsius equivale a 298.15 Kelvin
```

---

## 🔄 Opções de conversão implementadas

O programa possui **6 opções de conversão**:

| Opção | Conversão            | Fórmula                       |
| ----: | -------------------- | ----------------------------- |
|     1 | Celsius → Kelvin     | `K = C + 273.15`              |
|     2 | Celsius → Fahrenheit | `F = (C × 9/5) + 32`          |
|     3 | Kelvin → Celsius     | `C = K - 273.15`              |
|     4 | Kelvin → Fahrenheit  | `F = (K - 273.15) × 9/5 + 32` |
|     5 | Fahrenheit → Celsius | `C = (F - 32) × 5/9`          |
|     6 | Fahrenheit → Kelvin  | `K = (F - 32) × 5/9 + 273.15` |

---

## 🧮 Estrutura do programa

O programa utiliza:

### `stdio.h`

A biblioteca `stdio.h` é utilizada para realizar a entrada e saída de dados, principalmente através das funções:

```c
printf()
scanf()
```

### `switch...case`

A estrutura `switch...case` é utilizada para determinar qual conversão será executada de acordo com a opção escolhida pelo usuário.

Exemplo:

```c
switch(opcao) {

    case 1:
        // Celsius para Kelvin
        break;

    case 2:
        // Celsius para Fahrenheit
        break;

    // Demais opções...

    default:
        printf("Opção inválida!\n");
}
```

### Variáveis

O programa utiliza as seguintes variáveis principais:

```c
int opcao;
float temperatura, resultado;
```

* `opcao`: armazena a opção escolhida no menu;
* `temperatura`: armazena o valor informado pelo usuário;
* `resultado`: armazena o resultado da conversão.

---

## 💻 Instruções para execução

### 1. Pré-requisitos

Para executar o projeto, é necessário possuir um **compilador de linguagem C**, como o GCC.

Também é possível utilizar ambientes de desenvolvimento como:

* Visual Studio Code;
* Code::Blocks;
* Dev-C++;
* Visual Studio;
* OnlineGDB ou outros compiladores online.

---

### 2. Clonar o repositório

No terminal, utilize:

```bash
git clone URL_DO_REPOSITORIO
```

Depois, entre na pasta do projeto:

```bash
cd nome-do-repositorio
```

---

### 3. Compilar o programa

Caso esteja utilizando o GCC:

```bash
gcc conversor_temperatura.c -o conversor_temperatura
```

---

### 4. Executar

No Windows:

```bash
conversor_temperatura.exe
```

No Linux ou macOS:

```bash
./conversor_temperatura
```

---

## 📁 Estrutura do repositório

```text
conversor-temperatura/
│
├── conversor_temperatura.c
└── README.md
```

---

## 🎓 Objetivo acadêmico

Este projeto foi desenvolvido como uma atividade prática de programação em linguagem C, com o objetivo de aplicar conceitos básicos de programação por meio da criação de um sistema funcional de conversão de temperaturas.

---

## 👨‍💻 Autor

**Pedro Henrique**

Projeto desenvolvido para fins acadêmicos.

