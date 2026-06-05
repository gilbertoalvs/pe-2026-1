#include <stdio.h>
#include <string.h>

struct Produto{
    int id;
    char descricao[20];
    int qtdEstoque;
    double vlrUnit;
};

struct Venda{
    int id;
    int qtdProdutosVendidos;
    int idsProdutos[5];
    int qtsVendidas[5]
};

void lerstr(char str[], int tamMax);
int buscaSequencialDesc(struct Produto v[], int tam, char x[]);
int buscaBinariaId(struct Venda v[], int tam, int x);
int alteraProduto(struct Produto v[], int tam);
void venda(struct Produto vp[], int tamProd, struct Venda vv[], int tamVendas);
void relatorio(struct Produto vp[], int tamProd, struct Venda vv[], int tamvendas);

int main(){

}

void lerstr(char str[], int tamMAx){
    fgets(str, tamMAx, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam-1] == '\n'){
        str[tam-1] = '\0';
    }
}

int buscaSequencialDesc(struct Produto v[], int tam, char x[]){
    for(int i = 0; i < tam; i++){
        if(strcmp(v[i].descricao, x) == 0){
                return i;
        } 
    }
    return -1;
}

int buscaBinariaId(struct Venda v[], int tam, int x){
    int inicio = 0, meio, fim = tam - 1;

    do{
        meio = (inicio + fim) / 2;
        if(v[meio].id > x){
            fim = meio - 1;
        } else if(v[meio].id < x){
            inicio = meio + 1;
        } else{
            break;
        }
    } while(v[meio].id != x && inicio <= fim);

    if(x == v[meio].id){
        return meio;
    } else{
        return -1;
    }
}

int alteraProduto(struct Produto v[], int tam){

    char desc[20];
    char resp;

    printf("Digite a descrição do produto: ");
    lerstr(desc, 20);
    int indice = buscaSequencialDesc(v, tam, desc);

    if(indice < 0){
        printf("Produto não encontrado!\n");
        return 0;
    }

    printf("Você deseja alterar a descrição (s/n)? ");
    scanf(" %c", &resp);
    while(getchar() != '\n');
    if(resp == 's' || resp == 'S'){
        printf("Digite a nova descrição: ");
        lerstr(v[indice].descricao, 20);
    }

    printf("Você deseja alterar a quantidade em estoque (s/n)?");
    scanf(" %c", &resp);
    if(resp == 'S' || resp == 's'){
        printf("Digite a nova quantidade: ");
        scanf("%d", &v[indice].qtdEstoque);
    }

    printf("Deseja alterar o valor unitário (S/N)? ");
    scanf(" %c", &resp);
    if(resp == 'S' || resp == 's'){
        printf("Digite o novo valor unitário: ");
        scanf("%f", &v[indice].vlrUnit);
    }

    return 1;
}

void venda(struct Produto vp[], int tamProd, struct Venda vv[], int tamVendas){
    int idVenda, posVenda;

    do{
        printf("Digite o Id da nova venda: ");
        scanf("%d", &idVenda);
        
        posVenda = buscaBinariaId(vv, tamVendas, idVenda);

        if(posVenda != -1){
            printf("Id Já existe! Tente outro.\n");
        }
    } while(posVenda != -1);

    vv[tamVendas].id = idVenda;

    do{
        printf("Quantos produtos diferentes vai levar (1 a 5)? ");
        scanf("%d", &vv[tamVendas].qtdProdutosVendidos);

        if(vv[tamVendas].qtdProdutosVendidos < 1 || vv[tamVendas].qtdProdutosVendidos > 5){
            printf("Quantidade inválida! Digite um valor entre 1 e 5.\n");
        }
    } while(vv[tamVendas].qtdProdutosVendidos < 1 || vv[tamVendas].qtdProdutosVendidos > 5);

    for(int i = 0; i < vv[tamVendas].qtdProdutosVendidos; i++){
        printf("\n--- Item %d ---\n", i + 1);

        printf("Digite o Id do novo produto: ");
        scanf("%d", vv[tamVendas].idsProdutos[i]);

        printf("Digite a quantidade vendida deste produto: ");
        scanf("%d", &vv[tamVendas].qtsVendidas);
    }

    printf("\nVenda registrada com sucesso!\n");
}

void relatorio(struct Produto vp[], int tamProd, struct Venda vv[], int tamVendas) {

    for(int i = 0; i < tamVendas; i++) {
        
        if(vv[i].qtdProdutosVendidos > 2) {
            
            // Imprime o cabeçalho da venda atual
            printf("\n+---------------------------------------+\n");
            printf("|        V E N D A          N. %03d      |\n", vv[i].id);
            printf("+---------------------------------------+\n");
            printf("|QTD| D E S C R I Ç Ã O |VLR UNIT|VLR TOTAL|\n");
            printf("+---+-------------------+--------+--------+\n");

            double totalGeral = 0.0;

            for(int j = 0; j < vv[i].qtdProdutosVendidos; j++) {
                int idProcurado = vv[i].idsProdutos[j];
                int qtdVendida = vv[i].qtsVendidas[j];

                for(int k = 0; k < tamProd; k++) {
                    if(vp[k].id == idProcurado) {
                        
                        double vlrTotalItem = qtdVendida * vp[k].vlrUnit;
                        totalGeral += vlrTotalItem;

                        printf("| %2d| %-17s | %6.2f | %6.2f |\n", 
                               qtdVendida, 
                               vp[k].descricao, 
                               vp[k].vlrUnit, 
                               vlrTotalItem);
                        
                        break;
                    }
                }
            }
            
            printf("+---+-------------------+--------+--------+\n");
            printf("|      Total Geral      |        | %6.2f |\n", totalGeral);
            printf("+---+-------------------+--------+--------+\n");
        }
    }
}