#include <stdio.h>

#define TAM_MAX 5

void preencherVetor(int v[], int n);
void imprimirVetor(int v[], int n);
void ordenar(int v[], int n);

int main(){
    int teste[TAM_MAX];

    preencherVetor(teste, TAM_MAX);
    imprimirVetor(teste, TAM_MAX);
    ordenar(teste, TAM_MAX);
    imprimirVetor(teste, TAM_MAX);
}

void preencherVetor(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("Digite o número da %d posição: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void imprimirVetor(int v[], int n){
    printf("{ ");
    for(int i = 0; i < n; i++){
        printf("%d", v[i]);

        if(i < n -1){
            printf(", "); // Se não for o final então entra a virgula.
        }
    }
    printf(" }\n");
}

void ordenar(int v[], int n){
    int i, fim, pos, troca, aux;
    troca = 1; fim = n-2; pos = 0;
    while(troca == 1){
        troca = 0;
        for(i=0; i<=fim; i++){
            if(v[i] > v[i+1]){
                aux = v[i]; v[i] = v[i+1];
                v[i+1] = aux; pos = i; troca = 1;
            }
        }
        fim = pos - 1;
    } 
}