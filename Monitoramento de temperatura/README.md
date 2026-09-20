# Desafio Guiado - Sistema Inteligente de Monitoramento Industrial

## 1. Identificação

- **Aluno:** Pedro Henrique do Nascimento Lins
- **Disciplina:** Algoritmos e Pensamento Computacional
- **Professora:** Profa. Karla Sartin
- **Título do projeto:** Sistema Inteligente de Monitoramento Industrial

## 2. Objetivo

O projeto tem como objetivo desenvolver, em linguagem C, um sistema capaz de monitorar temperaturas de uma máquina industrial. O programa recebe um limite de temperatura, realiza várias leituras de um sensor, valida os valores informados, calcula estatísticas e apresenta um relatório final.

O monitoramento é encerrado automaticamente quando o sistema identifica **3 temperaturas consecutivas acima do limite configurado**, representando uma condição de segurança.

## 3. Funcionamento do programa

### Definição do limite

Primeiro, o usuário informa o limite de temperatura que será utilizado durante o monitoramento. O programa aceita limites entre **-50 °C e 150 °C**, que também correspondem à faixa considerada válida para o sensor neste projeto.

Caso o limite seja inválido ou não seja informado como número, o programa solicita uma nova entrada.

### Realização das leituras

Depois de definir o limite, o programa utiliza um laço `while` para receber diversas temperaturas do sensor. Cada leitura válida é armazenada apenas nas variáveis necessárias para os cálculos, como soma, maior valor e menor valor.

### Tratamento de valores inválidos

As temperaturas devem estar entre **-50 °C e 150 °C**. Valores fora dessa faixa são rejeitados e não participam dos cálculos. Entradas que não sejam numéricas também são tratadas como inválidas, e o programa limpa a entrada antes de solicitar uma nova leitura.

### Temperaturas acima do limite

Quando uma temperatura válida é maior que o limite configurado, o sistema apresenta um alerta e aumenta o contador de temperaturas acima do limite.

Quando a temperatura está dentro do limite, o contador de ocorrências consecutivas acima do limite é zerado.

### Contagem de temperaturas consecutivas

A variável `consecutivas` registra quantas temperaturas acima do limite foram recebidas em sequência. A cada temperatura acima do limite, esse contador aumenta em 1. Se uma temperatura estiver dentro do limite, ele volta para 0.

Assim, o sistema identifica uma sequência de 3 temperaturas consecutivas acima do limite.

### Condição de encerramento

O monitoramento termina automaticamente quando `consecutivas` chega a 3. Ao final, o programa apresenta:

- limite configurado;
- quantidade de leituras válidas;
- média das temperaturas;
- maior temperatura;
- menor temperatura;
- quantidade de temperaturas acima do limite;
- motivo do encerramento.

## 4. Estruturas de repetição utilizadas

### `do...while`

O `do...while` é utilizado para validar o limite de temperatura. Ele é adequado porque o programa precisa solicitar o limite pelo menos uma vez e continuar solicitando enquanto o valor for inválido.

### `while`

O `while` é utilizado para realizar o monitoramento. O laço continua recebendo temperaturas enquanto ainda não ocorrerem 3 leituras consecutivas acima do limite.

Também é utilizado um `while` auxiliar para limpar caracteres inválidos da entrada quando o usuário digita algo que não pode ser convertido para número.

## 5. Como executar

### Linux, macOS ou Git Bash

Abra o terminal na pasta do projeto e execute:

```bash
gcc monitoramento.c -o monitoramento
./monitoramento
```

### Windows com GCC/MinGW

No terminal do VS Code ou no Git Bash, execute:

```bash
gcc monitoramento.c -o monitoramento.exe
./monitoramento.exe
```

## 6. Exemplos de testes realizados

### Teste 01 - Funcionamento normal e encerramento por segurança

- Limite: `50`
- Temperaturas: `40`, `55`, `45`, `60`, `70`, `80`
- Resultado esperado: o programa identifica as três últimas temperaturas como consecutivas acima do limite e encerra o monitoramento.

### Teste 02 - Tratamento de temperatura inválida

- Limite: `50`
- Temperaturas: `40`, `200`, `45`, `60`, `70`, `80`
- Resultado esperado: `200 °C` é rejeitada por estar fora da faixa válida do sensor e não entra nos cálculos.

### Teste 03 - Tratamento de entrada não numérica

- Limite: `50`
- Entrada: `abc`
- Resultado esperado: o programa informa que a entrada é inválida, limpa o teclado e solicita novamente a temperatura.

As evidências dos testes estão na pasta `evidencias/`.

## 7. Organização do projeto

```text
desafio-monitoramento/
│
├── monitoramento.c
├── README.md
│
└── evidencias/
    ├── teste01.png
    ├── teste02.png
    └── teste03.png
```

## 8. Tecnologias utilizadas

- Linguagem C
- GCC
- VS Code / terminal
- Git e GitHub

Foi escolhida uma combinação de while e do...while, pois cada estrutura atende melhor a uma parte diferente do algoritmo.

O do...while foi utilizado para definir e validar o limite de temperatura, garantindo que o usuário informe um valor válido antes de continuar o programa. Nesse caso, o teste da condição acontece depois da execução, o que permite solicitar o valor pelo menos uma vez e repetir a pergunta caso ele seja inválido.

Já o while foi utilizado no monitoramento das temperaturas. A condição é verificada antes de cada nova leitura, permitindo que o programa continue recebendo temperaturas enquanto o monitoramento estiver ativo. O while também facilita o encerramento quando são identificadas 3 temperaturas consecutivas acima do limite.
