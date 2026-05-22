#include <stdio.h>
#include <string.h>

#define TAM_NOME 200
#define TAM_ESTADO 26

struct Estado{
    char nome[TAM_NOME];
    int veiculo, acidente;
};

void lerStr(char str[], int tamMax);
void preencherDados(struct Estado *e, int tam);
void encontrarMaiorMenor(struct Estado *e, int tam, int *idMaior, int *idMenor);
double calcularPercentual(struct Estado e);
double mediaAcidentes(struct Estado *e, int tam);
void calcularAcimaDaMedia(struct Estado *e, int tam, double media);
void imprimirPercentual(struct Estado *e, int tam);

int main(){
    struct Estado estado[TAM_ESTADO];
    double media = 0; 
    int idMaior, idMenor;

    //A)
    preencherDados(estado, TAM_ESTADO);

    //B)
    encontrarMaiorMenor(estado, TAM_ESTADO, &idMaior, &idMenor);

    printf("\n--- Estatísticas de Acidentes ---\n");
    printf("Maior número de acidentes: %d no estado %s\n", estado[idMaior].acidente, estado[idMaior].nome);
    printf("Menor número de acidentes: %d no estado %s\n", estado[idMenor].acidente, estado[idMenor].nome);

    //Letra C
    printf("\n--- Percentual de Veículos envolvidos em acidentes ---\n");
    imprimirPercentual(estado, TAM_ESTADO);

    // D)
    media = mediaAcidentes(estado, TAM_ESTADO);
    printf("Média de acidentes no país: %.2f\n", media);

    //E)
    calcularAcimaDaMedia(estado, TAM_ESTADO, media);

    return 0;
}

void lerStr(char str[], int tamMax){
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam-1] == '\n'){
        str[tam-1] = '\0';
        tam--;
    }
    if(tam > 0 && str[tam-1] == '\r'){
        str[tam-1] = '\0';
    }
}

// Letra A
void preencherDados(struct Estado *e, int tam){
    char buf[TAM_NOME];
    printf("Preencha os dados solicitados: \n");
    for(int i = 0; i < tam; i++){
        printf("--------------------------\n");
        printf("Nome do estado %d: ", i + 1);
        lerStr(e[i].nome, TAM_NOME);

        printf("Quantidade de veículos: ");
        fgets(buf, TAM_NOME, stdin);
        sscanf(buf, "%d", &e[i].veiculo);

        printf("Quantidade de acidentes: ");
        fgets(buf, TAM_NOME, stdin);
        sscanf(buf, "%d", &e[i].acidente);
    }
    printf("--------------------------\n");
}

// Letra B
void encontrarMaiorMenor(struct Estado *e, int tam, int *idMaior, int *idMenor){
    *idMaior = 0;
    *idMenor = 0;
    for(int i = 1; i < tam; i++){
        if(e[i].acidente > e[*idMaior].acidente){
            *idMaior = i;
        }
        if(e[i].acidente < e[*idMenor].acidente){
            *idMenor = i;
        }
    }
}

// Letra C
double calcularPercentual(struct Estado e){
    return ((double)e.acidente/e.veiculo) * 100; 
}

void imprimirPercentual(struct Estado *e, int tam){
    for(int i = 0; i < tam; i++){
        double pc = calcularPercentual(e[i]);
        printf("Estado: %s | Percentual: %.2f%%\n", e[i].nome, pc);
    }
}

// Letra D
double mediaAcidentes(struct Estado *e, int tam){
    double sum = 0;
    for(int i = 0; i < tam; i++){
        sum += e[i].acidente;
    }
    return sum / tam;
}

// Letra E
void calcularAcimaDaMedia(struct Estado *e, int tam, double media){
    int cont = 0;
    printf("Estados brasileiros acima da média de acidentes:\n");
    printf("----------------------");
    for(int i = 0; i < tam; i++){
        if(e[i].acidente > media){
            printf("%s -> %d acidentes\n", e[i].nome, e[i].acidente);
            cont++;
        }
    }
    if (cont == 0){printf("Todos os estados estão abaixo da média nacional.\n");}
}