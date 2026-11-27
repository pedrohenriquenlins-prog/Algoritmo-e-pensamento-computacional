
#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "operacoes.h"

int main(void) {
    int quantidade;
    int opcao;

    printf("\n====================================\n");
    printf(" SISTEMA DE OPERACOES COM MATRIZES\n");
    printf("====================================\n");

    quantidade = lerInteiro(
        "Quantidade de matrizes (2 a 100): ",
        2,
        100
    );

    Matriz *matrizes = calloc(
        quantidade,
        sizeof(Matriz)
    );

    if (matrizes == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Cadastro das matrizes
    for (int i = 0; i < quantidade; i++) {
        matrizes[i] = lerMatriz(i + 1);

        if (matrizes[i].dados == NULL) {
            printf("Erro durante o cadastro!\n");

            for (int j = 0; j < quantidade; j++) {
                liberarMatriz(matrizes[j]);
            }

            free(matrizes);
            return 1;
        }
    }

    // Menu principal
    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Adicao\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao matricial\n");
        printf("0 - Encerrar\n");
        printf("==========================\n");

        opcao = lerInteiro("Escolha uma opcao: ", 0, 4);

        if (opcao != 0) {
            Matriz resultado = executarOperacao(
                matrizes,
                quantidade,
                opcao
            );

            if (resultado.dados != NULL) {
                printf("\nRESULTADO:\n");
                exibirMatriz(resultado);

                liberarMatriz(resultado);
            } else {
                printf("\nNao foi possivel realizar "
                       "a operacao.\n");
            }
        }

    } while (opcao != 0);

    // Liberacao da memoria
    for (int i = 0; i < quantidade; i++) {
        liberarMatriz(matrizes[i]);
    }

    free(matrizes);

    printf("\nPrograma encerrado com sucesso!\n");

    return 0;
}


