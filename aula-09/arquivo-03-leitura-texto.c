#include <stdio.h>
#include <string.h>

#define TAM_FRASE 100


void lerStr(char str[], int tamMAx);
char *fLerStr(char str[], int tamMAx, FILE *arq);

int main(){

    FILE *arq;
    char nomeArq[] = "teste.txt";
    char frase[TAM_FRASE], *status;
    int tamFrase;

    arq = fopen(nomeArq, "rt");
    if(!arq){
        printf("Erro ao tentar abrir o arquivo\n");
        return 1;
    }

    printf("-------------------------------------------\n");
    printf("Conteudo do arquivo:\n");
    fLerStr(frase, TAM_FRASE, arq);
    tamFrase = strlen(frase);
    status = fprintf(arq,"%s\n", frase);
    while(tamFrase > 0 && status == tamFrase + 1){
        lerStr(frase, TAM_FRASE);
        tamFrase = strlen(frase);
        status = fprintf(arq,"%s\n", frase);
    }
    printf("-------------------------------------------\n");
    
    status = fclose(arq);

    if(status != 0){
        printf("Erro ao tentar fechar o arquivo %s\n", nomeArq);
        return 2;
    }

    printf("Arquivo fechado com sucesso\n");
    return 0;
}

char *fLerStr(char str[], int tamMAx, FILE *arq){
    char *res = fgets(str, tamMAx, arq);
    int tam = strlen(str);
    if(tam > 0 && str[tam-1] == '\n'){
        str[tam-1] = '\0';
    }
    return res;
}

void lerStr(char str[], int tamMAx){
    fLerStr(str, tamMAx, stdin);
}

