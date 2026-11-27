
#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int linhas;
    int colunas;
    double **dados;
} Matriz;

// Leitura e validacao
int lerInteiro(char mensagem[], int min, int max);
double lerReal(char mensagem[]);

// Gerenciamento de memoria
Matriz criarMatriz(int linhas, int colunas);
Matriz matrizInvalida(void);
Matriz copiarMatriz(Matriz original);
void liberarMatriz(Matriz m);

// Cadastro e exibicao
Matriz lerMatriz(int numero);
void exibirMatriz(Matriz m);

#endif

