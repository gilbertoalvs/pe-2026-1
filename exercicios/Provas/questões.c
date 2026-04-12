#include <stdio.h>

#define QTD_LINHAS 5
#define QTD_COLUNAS 5


void preencherMatriz(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas){
    for(int i = 0; i < qtdLinhas; i++){
        for(int j = 0; j < qtdColunas; j++){
            printf("Digite o número correspondente a linha %d e a coluna %d: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}


void extrairVetorMaiorLinha(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas, int v[]){

    int maiorSoma = 0;
    int maiorI = 0;

    for(int i = 0; i < qtdLinhas; i++){
        int soma = 0;
        for(int j = 0; j < qtdColunas; j++){
            soma += m[i][j];
        }
        if(i == 0 || soma > maiorSoma){
            maiorSoma = soma;
            maiorI = i;
        }
    }

    for(int j = 0; j < qtdColunas; j++){
        v[j] = m[maiorI][j];
    }

}

void bubbleSort(int v[], int n){
    int i, troca, fim, pos, chave;
    troca = 1; fim = n - 2; pos = 0;

    while(troca == 1){
        troca = 0;
        for(i = 0; i <= fim; i++){
            if(v[i] > v[i + 1]){
                chave = v[i]; v[i] = v[i + 1]; v[i + 1] = chave;
                troca = 1; pos = i;
            }
        }
        fim = pos - 1;
    }
}

void selectionSort(int v[], int n){
    int i, j, menor, aux;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i+1; j <= n-1; j++){
            if(v[i] < v[menor]){
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
    for(i = 1; i <= n-1; i++){
        chave = v[i];
        j = i - 1;
        while(j<=0 && v[j] > chave){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
}

void receberVetor(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("Digite o numero da posição %d: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void tirarRepetidos(int v[], int n){
    int resultado[n];
    int cont = 0;

    for(int i = 0; i < n; i++){
        int achou = 0;
        for(int j = 0; j < cont; j++){
            if(v[i] == resultado[j]){
                achou = 1;
                break;
            }
        }
        if(achou == 0){
            resultado[cont] = v[i];
            cont++;
        }
    }
    printf("Vetor sem repetidos: ");
    for(int i = 0; i < cont; i++){
        printf("%d", resultado[i]);
    }
}

int ehPrimo(int num){
    if(num < 2){
        return 0;
    }
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

void encontrarPrimos(int v[], int n){
    printf("Numeros primos no vetor: ");
    for(int i = 0; i < n; i++){
        if(ehPrimo(v[i]) == 1){
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

void maiorValorLinhaMatriz(int m[][QTD_COLUNAS], int lin, int col, int resultado[]){
    for(int i = 0; i < lin; i++){
        int maior = m[i][0];
        for(int j = 1; j < col; j++){
            if(m[i][j] > maior){
                maior = m[i][j];
            }
        }
        resultado[i] = maior;
    }
}

void inverterFrase(char str[]){
    int inicio = 0;
    int fim = 0;

    while(str[fim] != '\0'){
        fim++;
    }
    fim--;

    while(inicio < fim){
        char aux = str[inicio];
        str[fim] = aux;

        inicio++;
        fim--;
    }

    print("Frase invertida: %s\n", str);
}

void vetorParesEImpares(int v[], int par[], int impar[], int n){
    int iPar = 0;
    int iImpar = 0;
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0){
            par[iPar] = v[i];
            iPar++;
        } else{
            impar[iImpar] = v[i];
            iImpar++;
        }
    }
}

void somaDiagPrincipal(int m[][QTD_COLUNAS], int lin, int col){
    int soma = 0;
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(i == j){
                soma += m[i][j];
            }
        }
    }
    printf("A soma da diagonal principal eh: %d\n", soma);
}

void somaDiagPrincipalOtimizada(int m[][QTD_COLUNAS], int lin){
    int soma = 0;
    for(int i = 0; i < lin; i++){
        soma += m[i][i];
    }
    printf("A soma da diagonal principal eh: %d\n", soma);
}

int ehPolindrono(char str[]){
    int inicio = 0;
    int fim = 0; 
    while(str[fim] != '\0'){
        fim++;
    }
    fim--;

    while(inicio < fim){
        if(str[inicio] != str[fim]){
            return 0;
        }
        inicio++;
        fim--;
    }
    return 1;
}

void segundoMaiorValorVetor(int v[], int n){
    int maior = v[0];
    int segundoMaior = -1;
    for(int i = 1; i < n; i++){
        if(v[i] > maior){
            segundoMaior = maior;
            maior = v[i];
        } else if(v[i] > segundoMaior && v[i] != maior){
            segundoMaior = v[i];
        }
    }
    printf("O maior valor eh: %d\n", maior);
    printf("O segundo maior valor eh: %d\n", segundoMaior);
}

int meuStrLen(char str[]){
    int tam = 0;
    while(str[tam] != '\0'){
        tam++;
    }
    return tam;
}

int validarCPF(char str[]){
    int tam = meuStrLen(str);

    if(tam != 14){
            return 0;
        }

    for(int i = 0; i < tam; i++){
        if((i==3 || i==7) && str[i] != '.'){
            return 0;
        }
        else if(i == 11 && str[i] != '-'){
            return 0;
        }
        else {
            if(str[i] < '0' || str[i] > '9'){
                return 0;
            }
        }
    }
    return 1;
}

void ordernarString(char str[]){
    int tam = meuStrLen(str);
    int i, troca, pos, fim;
    char chave;
    troca = 1; pos = 0; fim = tam - 2;

    while(troca == 1){
        troca = 0;
        for(i = 0; i <= fim; i++){
            if(str[i] > str[i + 1]){
                chave = str[i]; str[i] = str[i + 1]; str[i + 1] = chave; troca = 1; pos = i;
            }
        }
        fim = pos - 1;
    }
}

void MaisUmSelectionSort(int v[], int n){
    int i, j, menor, aux;
    for(i = 0; i<n-1; i++){
        menor = v[i];
        for(j = i+1; j <= n-1; j++){
            if(v[j] > v[menor]){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void maisUmInsertionSort(int v[], int n){
    int i, j, chave;
    for(i = 1; i<=n-1; i++){
        chave = v[i];
        j = i - 1;
        while(j>=0 && v[j] > v[j+1]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
}