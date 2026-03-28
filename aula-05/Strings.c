#include <stdio.h>
#include <string.h>

#define TAM_MSG 50

void lerStr(char str[], int tam);

int main(){

    char mensagem[TAM_MSG] = "Ola, mundo!";
    printf("Essa é a mensagem: %s\n\n", mensagem);

    printf("Digite uma mensagem (insegura): ");
    scanf("%[^\n]", mensagem); // Digitação não segura.
    printf("Essa é a mensagem digitada: '%s'\n\n\n", mensagem);

    printf("Digite uma mensagem (segura): ");
    lerStr(mensagem, TAM_MSG); //Ler enter anterior.
    lerStr(mensagem, TAM_MSG);
    printf("\nEssa é a mensagem digitada '%s'\n\n", mensagem);

    return 0;
}

void lerStr(char str[], int tam){
    fgets(str, TAM_MSG, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam -1] == '\n'){
        str[tam -1] = '\0';
    }
}