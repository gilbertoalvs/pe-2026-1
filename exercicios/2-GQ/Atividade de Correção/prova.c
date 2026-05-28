#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria{
    int codigo;
    char nome[50];
};

struct Produto{
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria; // código da categoria que está no vetor categorias
    int preco; // representa um valor numérico com 2 casas decimais
};

void lerStr(char str[], int tamMax);
void cadastrarCategoria(struct Categoria v[], int *qtd);
void imprimirCategorias(struct Categoria v[], int qnt);
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias);
void selectionSortPorDescricao(struct Produto v[], int qtd);
void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x);

int main() {
    struct Categoria categorias[TAM];
    int qtdCategorias = 0;

    struct Produto produtos[TAM];
    int qtdProdutos = 0; 

    int opcao;
    char descricaoBusca[256];

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Cadastrar categoria\n");
        printf("2. Imprimir categorias\n");
        printf("3. Imprimir produtos\n");
        printf("4. Ordenar produtos por descricao\n");
        printf("5. Busca binaria por descricao\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                cadastrarCategoria(categorias, &qtdCategorias);
                break;
            case 2:
                imprimirCategorias(categorias, qtdCategorias);
                break;
            case 3:
                imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);
                break;
            case 4:
                selectionSortPorDescricao(produtos, qtdProdutos);
                printf("Vetor de produtos ordenado com sucesso!\n");
                break;
            case 5:
                printf("\nDigite a descricao que deseja buscar: ");
                lerStr(descricaoBusca, 256);
                buscaBinariaPorDescricao(produtos, qtdProdutos, descricaoBusca);
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void lerStr(char str[], int tamMax){
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam-1] == '\n'){
        str[tam-1] = '\0';
    }
}

// Questão 1.

void cadastrarCategoria(struct Categoria v[], int *qtd){
    if(*qtd >= TAM){
        printf("Capacidade do vetor já foi atingida!\n");
        return;
    }

    int novoCodigo;
    printf("Digite o código da categoria: ");
    scanf("%d", &novoCodigo);
    getchar();

    for(int i = 0; i < *qtd; i++){
        if(v[i].codigo == novoCodigo){
            printf("Erro! Código já existente.\n");
            return;
        }
    }

    v[*qtd].codigo = novoCodigo;
    printf("Qual o nome da categoria: ");
    lerStr(v[*qtd].nome, 50);

    (*qtd)++;
}

// Questão 2.

void imprimirCategorias(struct Categoria v[], int qtd){
    printf("Categorias cadastradas:\n");
    for(int i = 0; i < qtd; i++){
        printf("Codigo : %d | Nome: %s\n", v[i].codigo, v[i].nome);
    }
}

// Questão 3.

void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias){
    printf("Lista de produtos:\n");
    for(int i = 0; i < qtdProdutos; i++){
        char nomeCategoria[50];
        for(int j = 0; j < qtdCategorias; j++){
            if(vc[j].codigo == vp[i].categoria){
                strcpy(nomeCategoria, vc[j].nome);
                break;
            }
        }
        double precoReal = vp[i].preco / 100.0;

        printf("Codigo: %d\n", vp[i].codigo);
        printf("Titulo: %s\n", vp[i].titulo);
        printf("Descricao: %s\n", vp[i].descricao);
        printf("Categoria: %s\n", nomeCategoria);
        printf("Preço: R$ %.2f\n\n", precoReal);
    }
}

// Questão 4.

void selectionSortPorDescricao(struct Produto v[], int qtd){
    int i, j, menor;
    struct Produto aux;
    for(i = 0; i < qtd; i++){
        menor = i;
        for(j = i + 1; j <= qtd-1; j++){
            if(strcmp(v[j].descricao, v[menor].descricao) < 0){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

// Questão 5.

void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x){
    int inicio = 0, meio, fim = qtd - 1, cmp;

    do{
        meio = (inicio + fim) / 2;
        cmp = strcmp(v[meio].descricao, x);

        if(cmp > 0){
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    } while(cmp != 0 && inicio <= fim);

    if (cmp == 0) {
        printf("Produto encontrado!\n");
        printf("Codigo: %d | Titulo: %s\n", v[meio].codigo, v[meio].titulo);
    } else {
        printf("Produto nao encontrado.\n");
    }
}
