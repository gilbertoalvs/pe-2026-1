#include <stdio.h>

#define TAM_MAX 5
#define LIN 4
#define COL 4

void preencherVetor(int v[], int n);
void imprimirVetor(int v[], int n);
void ordenar(int v[], int n);
void imprimirMaiorImpar(int v[], int n);
void criarParesImpares(int v[], int n, int pares[], int impares[]);
void preencheMatriz(int m[][COL], int qntLinhas, int qtdColunas);
void preencherVetorMedia(int m[][COL], int qtdLinhas, int qtdColunas, int v[]);

int main(){
    int teste[TAM_MAX];

    preencherVetor(teste, TAM_MAX);
    imprimirVetor(teste, TAM_MAX);
    ordenar(teste, TAM_MAX);
    imprimirVetor(teste, TAM_MAX);
    imprimirMaiorImpar(teste, TAM_MAX);
}

//Questão 1. A)função deverá preencher o vetor recebido como parâmetro solicitando que o usuário digite n valores inteiros 

void preencherVetor(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("Digite o número da posição %d: ", i + 1);
        scanf("%d", &v[i]);
    }
}


// Questão 1. B) esta função deverá imprimir os n valores armazenados neste vetorseparados por vírgula e dentro de chaves. Exemplo: { 2, 4, 1, 7, 9 }

void imprimirVetor(int v[], int n){
    printf("{ ");
    for(int i = 0; i < n; i++){
        printf("%d", v[i]);
        if(i < n-1){
            printf(", ");
        }
    }
    printf(" }\n");
}

//Questão 1. C) deverá ordenar este vetor utilizando o algoritmo bubble sort. 
void ordenar(int v[], int n){
    int i, fim, pos, troca, chave;
    troca = 1; fim = n - 2; pos = 0;
    while(troca == 1){
        troca = 0;
        for(i = 0; i <= fim; i++){
            if(v[i] > v[i+1]){
                chave = v[i]; v[i] = v[i+1]; v[i+1] = chave; pos = i; troca = 1;
            }
        }
        fim = pos-1;
    }
}

// Questão 1. D) Esta função deverá imprimir o maior valor ímpar do vetor, ou a mensagem “Não há números ímpares no vetor”

void imprimirMaiorImpar(int v[], int n){
    int maior = 0, achou = 0;
    for(int i = 0; i < n; i++){
        if(v[i] % 2 != 0){
            if(achou == 0 || v[i] > maior){
                maior = v[i];
                achou = 1;
            }
        }
    }
    if(achou == 1){
        printf("O maior ímpar do vetor é %d\n", maior);
    } else{
        printf("Não há números ímpares no vetor\n"); 
    }
}

// Questão 1. E) Recebe um vetor v preenchido, e preenche os vetores pares e ímpares, contendo, respectivamente, todos os números pares e números ímpares do vetor original. OBS: todas as posições dos vetores pares e impares que não foram preenchidas, deve ser preenchida com o valor -1 

void criarParesImpares(int v[], int n, int pares[], int impares[]){
    int iP = 0, iI = 0;

    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0){
            pares[iP] = v[i];
            iP++;
        } else{
            impares[iI] = v[i];
            iI++;
        }
    }

    for(int i = iP; i < n; i++){
        pares[i] = -1;
    }

    for(int i = iI; i < n; i++){
        impares[i] = -1;
    }
}

//Questão 2. 
//A) Preenche a matriz inteira com valores digitados pelo usuário.

void preencheMatriz(int m[][COL], int qntLinhas, int qtdColunas){
    for(int i = 0; i < qntLinhas; i++){
        for(int j = 0; j < qtdColunas; j++){
            printf("Digite o número da linha %d e da coluna %d: ", i + 1, j +1);
            scanf("%d", &m[i][j]);
        }
    }
}

//B) Preencha um vetor v recebido como parâmetro, onde cada posição tem a média de todos os valores de respectiva coluna na matriz.

void preencherVetorMedia(int m[][COL], int qtdLinhas, int qtdColunas, int v[]){
    for(int j = 0; j < qtdColunas; j++){
        int soma = 0;
        for(int i = 0; i < qtdLinhas; i++){
            soma += m[i][j];
        }
        v[j] = soma / qtdLinhas;
    }
}