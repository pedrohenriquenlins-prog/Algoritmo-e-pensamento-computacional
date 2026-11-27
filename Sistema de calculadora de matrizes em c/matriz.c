
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "matriz.h"

// Leitura de numeros inteiros
int lerInteiro(char mensagem[], int min, int max) {
    char entrada[100];
    char *fim;
    long valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return min;
        }

        valor = strtol(entrada, &fim, 10);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim == entrada || *fim != '\0') {
            printf("Entrada invalida!\n");
            continue;
        }

        if (valor < min || valor > max) {
            printf("Digite um valor entre %d e %d!\n", min, max);
            continue;
        }

        return (int)valor;
    }
}

// Leitura de numeros reais
double lerReal(char mensagem[]) {
    char entrada[100];
    char *fim;
    double valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return 0.0;
        }

        valor = strtod(entrada, &fim);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim == entrada || *fim != '\0' ||
            !isfinite(valor)) {
            printf("Numero invalido!\n");
            continue;
        }

        return valor;
    }
}

// Matriz invalida
Matriz matrizInvalida(void) {
    Matriz m;

    m.linhas = 0;
    m.colunas = 0;
    m.dados = NULL;

    return m;
}

// Criacao dinamica
Matriz criarMatriz(int linhas, int colunas) {
    Matriz m;

    m.linhas = linhas;
    m.colunas = colunas;

    m.dados = calloc(linhas, sizeof(double *));

    if (m.dados == NULL) {
        return matrizInvalida();
    }

    for (int i = 0; i < linhas; i++) {
        m.dados[i] = calloc(colunas, sizeof(double));

        if (m.dados[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(m.dados[j]);
            }

            free(m.dados);
            return matrizInvalida();
        }
    }

    return m;
}

// Copia de matriz
Matriz copiarMatriz(Matriz original) {
    if (original.dados == NULL) {
        return matrizInvalida();
    }

    Matriz copia = criarMatriz(
        original.linhas,
        original.colunas
    );

    if (copia.dados == NULL) {
        return matrizInvalida();
    }

    for (int i = 0; i < original.linhas; i++) {
        for (int j = 0; j < original.colunas; j++) {
            copia.dados[i][j] =
                original.dados[i][j];
        }
    }

    return copia;
}

// Liberacao de memoria
void liberarMatriz(Matriz m) {
    if (m.dados == NULL) {
        return;
    }

    for (int i = 0; i < m.linhas; i++) {
        free(m.dados[i]);
    }

    free(m.dados);
}

// Cadastro
Matriz lerMatriz(int numero) {
    char mensagem[100];

    printf("\nCADASTRO DA MATRIZ %d\n", numero);

    int linhas = lerInteiro(
        "Quantidade de linhas (1 a 100): ", 1, 100
    );

    int colunas = lerInteiro(
        "Quantidade de colunas (1 a 100): ", 1, 100
    );

    Matriz m = criarMatriz(linhas, colunas);

    if (m.dados == NULL) {
        return matrizInvalida();
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            snprintf(
                mensagem,
                sizeof(mensagem),
                "Elemento [%d][%d]: ",
                i + 1,
                j + 1
            );

            m.dados[i][j] = lerReal(mensagem);
        }
    }

    return m;
}

// Exibicao
void exibirMatriz(Matriz m) {
    if (m.dados == NULL) {
        printf("Matriz invalida!\n");
        return;
    }

    for (int i = 0; i < m.linhas; i++) {
        printf("| ");

        for (int j = 0; j < m.colunas; j++) {
            printf("%10.2lf ", m.dados[i][j]);
        }

        printf("|\n");
    }
}
