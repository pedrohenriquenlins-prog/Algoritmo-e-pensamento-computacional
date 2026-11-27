
#include <stdio.h>
#include <math.h>
#include "matriz.h"

#define EPSILON 1e-10

// ADICAO
Matriz somarMatrizes(Matriz a, Matriz b) {
    if (a.dados == NULL || b.dados == NULL ||
        a.linhas != b.linhas ||
        a.colunas != b.colunas) {

        printf("Erro: dimensoes incompatíveis para adicao!\n");
        return matrizInvalida();
    }

    Matriz r = criarMatriz(a.linhas, a.colunas);

    if (r.dados == NULL) return matrizInvalida();

    for (int i = 0; i < a.linhas; i++) {
        for (int j = 0; j < a.colunas; j++) {
            r.dados[i][j] =
                a.dados[i][j] + b.dados[i][j];
        }
    }

    return r;
}

// SUBTRACAO
Matriz subtrairMatrizes(Matriz a, Matriz b) {
    if (a.dados == NULL || b.dados == NULL ||
        a.linhas != b.linhas ||
        a.colunas != b.colunas) {

        printf("Erro: dimensoes incompatíveis para subtracao!\n");
        return matrizInvalida();
    }

    Matriz r = criarMatriz(a.linhas, a.colunas);

    if (r.dados == NULL) return matrizInvalida();

    for (int i = 0; i < a.linhas; i++) {
        for (int j = 0; j < a.colunas; j++) {
            r.dados[i][j] =
                a.dados[i][j] - b.dados[i][j];
        }
    }

    return r;
}

// MULTIPLICACAO
Matriz multiplicarMatrizes(Matriz a, Matriz b) {
    if (a.dados == NULL || b.dados == NULL ||
        a.colunas != b.linhas) {

        printf("Erro: dimensoes incompatíveis para multiplicacao!\n");
        return matrizInvalida();
    }

    Matriz r = criarMatriz(a.linhas, b.colunas);

    if (r.dados == NULL) return matrizInvalida();

    for (int i = 0; i < a.linhas; i++) {
        for (int j = 0; j < b.colunas; j++) {
            for (int k = 0; k < a.colunas; k++) {
                r.dados[i][j] +=
                    a.dados[i][k] * b.dados[k][j];
            }
        }
    }

    return r;
}

// INVERSAO - GAUSS-JORDAN
int inverterMatriz(Matriz original, Matriz *inversa) {
    if (original.dados == NULL ||
        original.linhas != original.colunas) {
        return 0;
    }

    int n = original.linhas;

    Matriz a = copiarMatriz(original);

    if (a.dados == NULL) return 0;

    Matriz inv = criarMatriz(n, n);

    if (inv.dados == NULL) {
        liberarMatriz(a);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        inv.dados[i][i] = 1.0;
    }

    for (int i = 0; i < n; i++) {
        int pivo = i;

        for (int k = i + 1; k < n; k++) {
            if (fabs(a.dados[k][i]) >
                fabs(a.dados[pivo][i])) {
                pivo = k;
            }
        }

        if (fabs(a.dados[pivo][i]) < EPSILON) {
            liberarMatriz(a);
            liberarMatriz(inv);
            return 0;
        }

        if (pivo != i) {
            for (int j = 0; j < n; j++) {
                double temp = a.dados[i][j];
                a.dados[i][j] = a.dados[pivo][j];
                a.dados[pivo][j] = temp;

                temp = inv.dados[i][j];
                inv.dados[i][j] = inv.dados[pivo][j];
                inv.dados[pivo][j] = temp;
            }
        }

        double divisor = a.dados[i][i];

        for (int j = 0; j < n; j++) {
            a.dados[i][j] /= divisor;
            inv.dados[i][j] /= divisor;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double fator = a.dados[k][i];

                for (int j = 0; j < n; j++) {
                    a.dados[k][j] -=
                        fator * a.dados[i][j];

                    inv.dados[k][j] -=
                        fator * inv.dados[i][j];
                }
            }
        }
    }

    liberarMatriz(a);

    *inversa = inv;

    return 1;
}

// DIVISAO MATRICIAL
// A / B = A * INVERSA(B)

Matriz dividirMatrizes(Matriz a, Matriz b) {
    if (b.dados == NULL || b.linhas != b.colunas) {
        printf("Erro: matriz divisora deve ser quadrada!\n");
        return matrizInvalida();
    }

    if (a.dados == NULL || a.colunas != b.linhas) {
        printf("Erro: dimensoes incompatíveis para divisao!\n");
        return matrizInvalida();
    }

    Matriz inversa;

    if (!inverterMatriz(b, &inversa)) {
        printf("Erro: matriz divisora singular!\n");
        return matrizInvalida();
    }

    Matriz resultado = multiplicarMatrizes(a, inversa);

    liberarMatriz(inversa);

    return resultado;
}

// EXECUCAO SEQUENCIAL
Matriz executarOperacao(
    Matriz matrizes[],
    int quantidade,
    int opcao
) {
    Matriz resultado = copiarMatriz(matrizes[0]);

    if (resultado.dados == NULL) {
        return matrizInvalida();
    }

    for (int i = 1; i < quantidade; i++) {
        Matriz novo = matrizInvalida();

        switch (opcao) {
            case 1:
                novo = somarMatrizes(resultado, matrizes[i]);
                break;

            case 2:
                novo = subtrairMatrizes(resultado, matrizes[i]);
                break;

            case 3:
                novo = multiplicarMatrizes(resultado, matrizes[i]);
                break;

            case 4:
                novo = dividirMatrizes(resultado, matrizes[i]);
                break;

            default:
                liberarMatriz(resultado);
                return matrizInvalida();
        }

        if (novo.dados == NULL) {
            liberarMatriz(resultado);
            return matrizInvalida();
        }

        liberarMatriz(resultado);
        resultado = novo;
    }

    return resultado;
}
