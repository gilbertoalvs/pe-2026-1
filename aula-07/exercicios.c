#include <stdio.h>
#include <stdlib.h>

#define LIN 4
#define COL 4

void preencheMatrizAleatorio(int m[][COL], int lin, int col);
void matSoma(int a[][COL], int b[][COL], int soma [][COL]);
void imprimirMatriz(int m[][COL], int lin, int col);
void matTransposta(int m[][COL], int lin, int col);

int main(){

    srand(2);
    int A[LIN][COL];
    int B[LIN][COL];
    int soma[LIN][COL];

    preencheMatrizAleatorio(A, LIN, COL);
    preencheMatrizAleatorio(B, LIN, COL);

    matSoma(A, B, soma);
    printf("Matriz A:\n");
    imprimirMatriz(A, LIN, COL);
    printf("Matriz B:\n");
    imprimirMatriz(B, LIN, COL);
    printf("Matriz soma:\n");
    imprimirMatriz(soma, LIN, COL);
    printf("Matriz transposta de soma:\n");
    matTransposta(soma, LIN, COL);
    imprimirMatriz(soma, LIN, COL);
    return 0;
}


//1) Crie uma função que recebe 3 matrizes como parâmetro: Mat A, Mat B, Mat soma,
// onde cada elemento da mat soma é a soma dos elementos correspondentes das 
// matrizes matA e MatB.

void preencheMatrizAleatorio(int m[][COL], int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void matSoma(int a[][COL], int b[][COL], int soma [][COL]){
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            soma[i][j] = a[i][j] + b[i][j];
        }
    }
}

void imprimirMatriz(int m[][COL], int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < COL; j++){
            printf("%3d\t", m[i][j]);
        }
        printf("\n");
    }
}

// 2) Crie uma função que receba como parâmetro uma matriz quadrada
// e modifique a própria matriz para que ela seja a matriz transposta.

void matTransposta(int m[][COL],int lin, int col){
    int aux;
    for(int i = 0; i < lin; i++){
        for(int j = i + 1; j < col; j++){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }

}

// 3) Crie uma função que receba 3 matrizes como parâmetro matA, matB
// e matMulti que realize a multiplicação das matrizes matA e matB, e
// salve o resultado em matMult. Verifique inicialmente se as 3 matrizes
// são compatíveis.