#include <stdio.h>
#include <string.h>

#define TAM_NOME 30

typedef int tIdade; // Usar o typedef é tipo um apelido.

struct Pessoa{
    char nome [TAM_NOME];
    int idade;
    double peso, altura;
};

void lerStr(char str[], int tamMax);
void imprimirPessoa(struct Pessoa p);
void preencherPessoa(struct Pessoa *p);
void preencherPessoa2(struct Pessoa *p);
double calcularIMC(struct Pessoa p);

int main(){

    struct Pessoa pessoa;

    printf("-------------------\n");
    preencherPessoa(&pessoa);
    printf("-------------------\n");
    imprimirPessoa(pessoa);

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
    printf("Digite o nome:\n");
    lerStr(p->nome, TAM_NOME);
    printf("Digite a idade:\n");
    scanf("%d", &p->idade);
    printf("Digite o peso:\n");
    scanf("%lf", &p->peso);
    printf("Digite a altura:\n");
    scanf("%lf", &p->altura);
}

// Notação menos utilizada.
void preencherPessoa2(struct Pessoa *p){
    printf("Digite o nome:\n");
    lerStr((*p).nome, TAM_NOME);
    printf("Digite a idade:\n");
    scanf("%d", &(*p).idade);
    printf("Digite o peso:\n");
    scanf("%lf", &(*p).peso);
    printf("Digite a altura:\n");
    scanf("%lf", &(*p).altura);
}

double calcularIMC(struct Pessoa p){
    return p.peso / (p.altura * p.altura);
}