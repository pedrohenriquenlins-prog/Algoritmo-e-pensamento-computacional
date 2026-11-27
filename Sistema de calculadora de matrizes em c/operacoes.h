
#ifndef OPERACOES_H
#define OPERACOES_H

#include "matriz.h"

Matriz somarMatrizes(Matriz a, Matriz b);
Matriz subtrairMatrizes(Matriz a, Matriz b);
Matriz multiplicarMatrizes(Matriz a, Matriz b);
Matriz dividirMatrizes(Matriz a, Matriz b);

int inverterMatriz(Matriz original, Matriz *inversa);

Matriz executarOperacao(
    Matriz matrizes[],
    int quantidade,
    int opcao
);

#endif
