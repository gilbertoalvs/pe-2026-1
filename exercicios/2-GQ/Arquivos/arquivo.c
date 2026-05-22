#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_NOME 50

struct Produto{
    int id;
    char nome[TAM_NOME];
    double preco;
    int estoque;
};

// Prótotipos:
void lerStr(char str[], int tamMax);
int buscarProdutoPorId(int id, struct Produto * p);
void cadastrarProduto();
void listarProdutos();
void buscarProduto();
void atualizarProduto();
void removerProduto();

int main(){

    int op;
    do {
        printf("\n------------------------------\n");
        printf("   SISTEMA DE VENDAS E ESTOQUE\n");
        printf("------------------------------\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("4 - Atualizar produto\n");
        printf("5 - Remover produto\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &op);

        switch(op){
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos();   break;
            case 3: buscarProduto();    break;
            case 4: atualizarProduto(); break;
            case 5: removerProduto();   break;
            case 0: printf("\nEncerrando...\n"); break;
            default: printf("\nOpcao invalida.\n");
        }

    } while(op != 0);

    return 0;

}

// Auxiliares
void lerStr(char str[], int tamMax){
    while(getchar() != '\n'); // Limpar buffer.
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam-1] == '\n'){str[tam-1] = '\0';}
}

int buscarProdutoPorId(int id, struct Produto * p){
    FILE *arq = fopen("produtos.dat", "rb");

    if(arq == NULL){
        return 0;
    }

    while (fread(p, sizeof(struct Produto), 1, arq)) {
        if (p->id == id) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

// Produtos
void cadastrarProduto(){

    FILE *arq;
    struct Produto p;
    struct Produto temp;
    int idDuplicado;

    printf("\n---- Cadastro de Produto ----\n");

    // Validação do ID
    do{
        printf("ID: ");
        scanf("%d", &p.id);

        if(p.id <= 0){
            printf("ID Invalido. Digite um número  positivo.\n");
            continue;
        }

        arq = fopen("produtos.dat", "rb");
        idDuplicado = 0;

        if(arq != NULL){
            while(fread(&temp, sizeof(struct Produto), 1, arq)){
                if(temp.id == p.id){
                    idDuplicado = 1;
                    break;
                }
            }
            fclose(arq);
        }

        if(idDuplicado){
            printf("ID já cadastrado. Tente outro.\n");
        }
    }while(p.id <= 0 || idDuplicado);

    printf("Nome: ");
    lerStr(p.nome, TAM_NOME);

    do{
        printf("Preço: ");
        scanf("%lf", &p.preco);
        if(p.preco < 0){
            printf("Preço invalido.\n");
        }
    }while(p.preco < 0);

    do {
        printf("Estoque: ");
        scanf("%d", &p.estoque);
        if (p.estoque < 0){
            printf("Estoque invalido.\n");
        }
    } while (p.estoque < 0);

    arq = fopen("produtos.dat", "ab");
    if(arq == NULL){
        printf("\nErro ao abrir arquivo. Produto nao cadastrado.\n");
        return;
    }
    fwrite(&p, sizeof(struct Produto), 1, arq);
    fclose(arq);

    printf("\nProduto cadastrado com sucesso!\n");
}

void listarProdutos(){
    
    FILE *arq;
    struct Produto p;

    arq = fopen("produtos.dat", "rb");

    if(arq == NULL){
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n---- Lista de Produtos ----\n");

    while (fread(&p, sizeof(struct Produto), 1, arq)) {
        printf("\nID: %d\n", p.id);
        printf("Nome: %s\n", p.nome);
        printf("Preco: %.2lf\n", p.preco);
        printf("Estoque: %d\n", p.estoque);
        printf("-----------------------------\n");
    }

    fclose(arq);

}

void buscarProduto(){

    struct Produto p;
    int id;

    printf("\nDigite o ID do produto: ");
    scanf("%d", &id);

    if(buscarProdutoPorId(id, &p)){
        printf("\n---- PRODUTO ENCONTRADO ----\n");
        printf("ID: %d\n", p.id);
        printf("Nome: %s\n", p.nome);
        printf("Preco: %.2lf\n", p.preco);
        printf("Estoque: %d\n", p.estoque);
    } else {
        printf("\nProduto não encontrado.\n");
    }
}

void atualizarProduto(){

    FILE *arq;
    struct Produto p;
    int id;
    int encontrou = 0;

    printf("\n---- Atualizar Produto ----\n");

    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    arq = fopen("produtos.dat", "rb+");

    if(arq == NULL){
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    while(fread(&p, sizeof(struct Produto), 1, arq)){
        if(p.id == id){
            encontrou = 1;

            printf("\nNovo nome: ");
            lerStr(p.nome, TAM_NOME);

            do {
                printf("Novo preco: ");
                scanf("%lf", &p.preco);
                if (p.preco < 0) printf("Preco invalido.\n");
            } while (p.preco < 0);

            do {
                printf("Novo estoque: ");
                scanf("%d", &p.estoque);
                if (p.estoque < 0) printf("Estoque invalido.\n");
            } while (p.estoque < 0);

            fseek(arq, -(long)sizeof(struct Produto), SEEK_CUR);
            fwrite(&p, sizeof(struct Produto), 1, arq);

            printf("\nProduto atualizado com sucesso!\n");
            break;
        }
    }

    if(!encontrou){
        printf("\nProduto nao encontrado.\n");
    }
    fclose(arq);
}

void removerProduto(){

    FILE *original;
    FILE *temp;
    struct Produto p;
    int id, encontrou = 0;

    printf("\n---- Remover Produto ----\n");

    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    original = fopen("produtos.dat", "rb");

     if (original == NULL) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    temp = fopen("temp.dat", "wb");
    if(temp == NULL){
        printf("\nErro ao criar arquivo temporario.\n");
        fclose(original);
        return;
    }
    
    while (fread(&p, sizeof(struct Produto), 1, original)) {
        if (p.id != id) {
            fwrite(&p, sizeof(struct Produto), 1, temp);
        } else {
            encontrou = 1;
        }
    }

    fclose(original);
    fclose(temp);

    if (encontrou) {
        remove("produtos.dat");
        rename("temp.dat", "produtos.dat");
        printf("\nProduto removido com sucesso!\n");
    } else {
        remove("temp.dat");
        printf("\nProduto nao encontrado.\n");
    }
}