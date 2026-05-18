#include <stdio.h>
#include <string.h>

#define TAM_DES 100
#define TAM 40

struct Produto{
    int codigo;
    char descricao[TAM_DES];
    double vlrUnit;
    int qtdUnit; 
};

void lerStr(char str[], int tamMax);
void preencherProduto(struct Produto *p);
void imprimir(struct Produto *p);

int main(){

    struct Produto produto[TAM];
    int opcao;
    
    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Cadastrar dados.\n");
        printf("7. Imprimir\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            preencherProduto(produto);
            break;
        case 7:
            imprimir(produto);
            break;
        case 0:
            printf("Programa encerrado!\n");
            break;
        default:
            printf("Opção invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0; 
}

// Letra A
void preencherProduto(struct Produto *p){
    char str[TAM_DES];
    printf("---------------------------------------------\n");
    printf("Digite o código do produto: ");
    scanf("%d", &p->codigo);
    printf("Digite a descrição do produto: ");
    lerStr(p->descricao, TAM_DES);
    lerStr(p->descricao, TAM_DES);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &p->qtdUnit);
    printf("Digite o valor unitário do produto: ");
    scanf("%lf", &p->vlrUnit);
    printf("---------------------------------------------\n");
}

void lerStr(char str[], int tamMax){
    fgets(str, TAM_DES, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam - 1] == '\n'){
        str[tam - 1] = '\0';
    }
}

// Letra G
void imprimir(struct Produto *p){
    printf("Produto: (%d) -> %s\n", p->codigo, p->descricao);
}