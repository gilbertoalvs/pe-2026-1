#include <stdio.h>
#include <string.h>

#define TAM_NOME 30
#define QTD_PESSOAS 3

typedef int tIdade; // Usar o typedef é tipo um apelido.

struct Pessoa{
    char nome [TAM_NOME];
    int idade;
    double peso, altura;
};

void lerStr(char str[], int tamMax);
void imprimirPessoa(struct Pessoa p);
void imprimirPessoas(struct Pessoa vp[], int tam);
void preencherPessoa(struct Pessoa *p);
void preencherPessoas(struct Pessoa vp[], int tam);
double calcularIMC(struct Pessoa p);
double calcularMediaAltura(struct Pessoa vp[], int tam);
int buscaSequencialPorNome(struct Pessoa vp[], int tam, char x[]);
void buscarNomes(struct Pessoa vp[], int tam);
void bubbleSortPorNome(struct Pessoa vp[], int tam);

int main(){

    struct Pessoa pessoas[QTD_PESSOAS];

    preencherPessoas(pessoas, QTD_PESSOAS);
    printf("-------------------\n");
    imprimirPessoas(pessoas, QTD_PESSOAS);
    double mediaAlt = calcularMediaAltura(pessoas, QTD_PESSOAS);
    printf("A media de altura das pessoas eh: %.2lf metros.\n", mediaAlt);
    buscarNomes(pessoas, QTD_PESSOAS);

    return 0;
}

void lerStr(char str[], int tamMax){
    fgets(str, TAM_NOME, stdin); // Ler String de forma segura. 
    // stdin - Definir que a informação vem do teclado.
    int tam = strlen(str);
    if(tam > 0 && str[tam -1] == '\n'){
        str[tam -1] = '\0';
    }
}

void imprimirPessoa(struct Pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Peso: %.2lf\n", p.peso);
    printf("Altura: %.2lf\n", p.altura);
    printf("IMC: %.2lf\n", calcularIMC(p));
}

void preencherPessoa(struct Pessoa *p){
    char temStr[TAM_NOME];
    printf("Digite o nome:\n");
    lerStr(p->nome, TAM_NOME);
    printf("Digite a idade:\n");
    scanf("%d", &p->idade);
    printf("Digite o peso:\n");
    scanf("%lf", &p->peso);
    printf("Digite a altura:\n");
    scanf("%lf", &p->altura);
    lerStr(temStr, TAM_NOME);
}


double calcularIMC(struct Pessoa p){
    return p.peso / (p.altura * p.altura);
}

void preencherPessoas(struct Pessoa vp[], int tam){
    for(int i = 0; i < tam; i++){
        printf("--------- Digitação pessoa %d ----------\n", i + 1);
        preencherPessoa(&vp[i]);
    }
}

void imprimirPessoas(struct Pessoa vp[], int tam){
    for(int i = 0; i < tam; i++){
        printf("--- Pessoa %d ---\n", i + 1);
        imprimirPessoa(vp[i]);
    }
}

double calcularMediaAltura(struct Pessoa vp[], int tam){
    double soma = 0.0;
    for(int i = 0; i < tam; i++){
        soma += vp[i].altura;
    }
    return soma / tam;
}

int buscaSequencialPorNome(struct Pessoa vp[], int tam, char x[]){
    for(int i = 0; i < tam; i++){
        if(strcmp(vp[i].nome, x) == 0){
            return i;
        } 
    }
    return -1;
}

void buscarNomes(struct Pessoa vp[], int tam){
    char nome[TAM_NOME], opcao;
    char tempStr[TAM_NOME];
    printf("--------- Buscar por nome ----------\n");
    do{
        printf("Digite o nome a ser digitado: ");
        lerStr(nome, TAM_NOME);
        int pos = buscaSequencialPorNome(vp, tam, nome);
        if (pos != -1) {
        printf("A pessoa %d tem o nome buscado!\n", pos + 1);
        } else{
            printf("Nenhuma pessoa tem o nome procurado.\n");
        }
        printf("Você deseja realizar outra busca (s/n): ");
        scanf("%c", &opcao);
        lerStr(tempStr, TAM_NOME);
    } while(opcao == 'S' || opcao == 's');
}

void bubbleSortPorNome(struct Pessoa v[], int tam){
    int i, fim, pos, troca;
    struct Pessoa chave;
    troca = 1; pos = 0; fim = tam - 2;
    while(troca == 1){
        troca = 0;
        for(i = 0; i < fim; i++){
            if(strcmp(v[i].nome, v[i+1].nome) > 0){
                chave = v[i]; v[i] = v[i+1]; v[i+1] = chave;
                pos = i; troca = 1;
            }
        }
        fim = pos - 1;
    } 
}