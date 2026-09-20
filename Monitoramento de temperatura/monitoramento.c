#include <stdio.h>

#define TEMP_MIN -50.0f
#define TEMP_MAX 150.0f

int main(void) {
    float limite;
    float temperatura;
    float soma = 0.0f;
    float maior = 0.0f;
    float menor = 0.0f;
    float media;
    int quantidade = 0;
    int acimaLimite = 0;
    int consecutivas = 0;
    int primeiraLeitura = 1;

    printf("==============================================\n");
    printf("   SISTEMA DE MONITORAMENTO INDUSTRIAL\n");
    printf("==============================================\n");
    printf("Faixa valida do sensor: %.1f C a %.1f C\n\n", TEMP_MIN, TEMP_MAX);

    /* do...while garante que o limite seja solicitado pelo menos uma vez
       e continua pedindo enquanto o valor informado for invalido. */
    do {
        printf("Informe o limite de temperatura (C): ");
        if (scanf("%f", &limite) != 1) {
            printf("Valor invalido. Digite um numero.\n\n");
            while (getchar() != '\n') {
                /* Limpa caracteres invalidos do teclado. */
            }
            limite = TEMP_MIN - 1.0f;
        } else if (limite < TEMP_MIN || limite > TEMP_MAX) {
            printf("Limite invalido. Use um valor entre %.1f e %.1f C.\n\n",
                   TEMP_MIN, TEMP_MAX);
        }
    } while (limite < TEMP_MIN || limite > TEMP_MAX);

    printf("\nMonitoramento iniciado!\n");
    printf("Digite as temperaturas do sensor.\n");
    printf("O sistema encerra automaticamente apos 3 leituras consecutivas acima do limite.\n\n");

    /* O while mantem o monitoramento ativo ate ocorrerem 3 alertas seguidos. */
    while (consecutivas < 3) {
        printf("Temperatura %d: ", quantidade + 1);

        if (scanf("%f", &temperatura) != 1) {
            printf("Entrada invalida. Informe uma temperatura numerica.\n\n");
            while (getchar() != '\n') {
                /* Limpa a entrada para permitir uma nova leitura. */
            }
            continue;
        }

        /* Valida a leitura antes de utiliza-la nos calculos. */
        if (temperatura < TEMP_MIN || temperatura > TEMP_MAX) {
            printf("Temperatura invalida. O sensor aceita valores entre %.1f e %.1f C.\n\n",
                   TEMP_MIN, TEMP_MAX);
            continue;
        }

        quantidade++;
        soma += temperatura;

        if (primeiraLeitura) {
            maior = temperatura;
            menor = temperatura;
            primeiraLeitura = 0;
        } else {
            if (temperatura > maior) {
                maior = temperatura;
            }
            if (temperatura < menor) {
                menor = temperatura;
            }
        }

        if (temperatura > limite) {
            acimaLimite++;
            consecutivas++;
            printf("ALERTA: temperatura acima do limite!\n");
            printf("Leituras consecutivas acima do limite: %d/3\n", consecutivas);
        } else {
            consecutivas = 0;
            printf("Temperatura dentro do limite.\n");
        }

        printf("\n");
    }

    media = soma / quantidade;

    printf("==============================================\n");
    printf("              RELATORIO FINAL\n");
    printf("==============================================\n");
    printf("Limite configurado: %.2f C\n", limite);
    printf("Quantidade de leituras validas: %d\n", quantidade);
    printf("Media das temperaturas: %.2f C\n", media);
    printf("Maior temperatura: %.2f C\n", maior);
    printf("Menor temperatura: %.2f C\n", menor);
    printf("Temperaturas acima do limite: %d\n", acimaLimite);
    printf("Motivo do encerramento: 3 temperaturas consecutivas acima do limite.\n");
    printf("==============================================\n");

    return 0;
}
