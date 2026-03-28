#include <stdio.h>
#include <stdlib.h>

#define MAX 6

void preencherAleatorio(int v[], int n);
void preencherMatriz(int v[], int n);
void imprimir(int v[], int n);
void selectionSort(int v[], int n);
void insertionSort(int v[], int n);
void bubbleSort(int v[], int n);
int buscaBinaria(int v[], int n, int chave);

int main(){

    int A[MAX], chave, posicao;
    srand(2);
    preencherAleatorio(A, MAX);
    bubbleSort(A, MAX);
    imprimir(A, MAX);
    printf("Que numero voce deseja buscar? ");
    scanf("%d", &chave);
    
    posicao = buscaBinaria(A, MAX, chave);
    if(posicao != -1){
        printf("Numero encontrado na posicao: %d\n", posicao + 1);
    } else{
        printf("Numero nao encontrado!\n");
    }

}

void preencherAleatorio(int v[], int n) {
    for (int i = 0; i < n; i += 1) {
        v[i] = rand() % 10 +  1; // (rand() % 1000) / 100.0;
    }
}

void preencherMatriz(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("Digite o numero na posicao %d: \n", i + 1);
        scanf("%d", &v[i]);
    }
}

void imprimir(int v[], int n){
    for(int i=0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}


void selectionSort(int v[], int n){
    int i, j, menor, aux;
    
    for (i = 0; i < n; i++){
        menor = i;
        for (j = i + 1; j <= n - 1; j++){
            if (v[j] < v[menor]){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void insertionSort(int v[], int n){
    int i, j, chave;

    for(i = 1; i <= n -1; i++){
        chave = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j -= 1;
        }
        v[j+1] = chave;
    }
}

void bubbleSort(int v[], int n){
    int i, fim, pos, troca, chave;
    troca = 1; fim = n -2; pos = 0;
    while(troca == 1){
        troca = 0;
        for(i=0; i<=fim; i++){
            if(v[i] > v[i+1]){
                chave = v[i]; v[i] = v[i+1]; v[i+1] = chave; pos = i; troca = 1;
            }
        }
        fim = pos-1;
    }
}

// A busca binária só é possivel se o vetor ja estiver ordenado.

int buscaBinaria(int v[], int n, int chave){
    int inicio = 0, meio, fim = n -1;

    do{
        meio = (inicio + fim) / 2;
        if(v[meio] > chave){
            fim = meio - 1;
        } else{
            inicio = meio + 1;
        }
    } while (chave != v[meio] && inicio <= fim);

    if(chave == v[meio]){
        return meio; // Retorna a posição.
    } else {
        return -1; //Não achou.
    }

}