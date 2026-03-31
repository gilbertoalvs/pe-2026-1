#include <stdio.h>
#include <string.h>

#define TAM_MSG 50

void lerStr(char str[], int tam);
int meuStrLen(char str[]);
void meuStrCpy(char strDest[], char strOrigem[]);
int ehMinuscula(char caractere);
void transformarPrimeirasLetrasMaiscula(char str[]);

int main(){

    char mensagem[TAM_MSG] = "Ola, mundo!";
    printf("Essa é a mensagem: %s\n\n", mensagem);

    printf("Digite uma mensagem (insegura): ");
    scanf("%[^\n]", mensagem); // Digitação não segura.
    printf("\nEssa é a mensagem digitadai: '%s'\n\n\n", mensagem);

    printf("Digite uma mensagem (segura): ");
    lerStr(mensagem, TAM_MSG); //Ler enter anterior.
    lerStr(mensagem, TAM_MSG);
    printf("\nEssa é a mensagem digitada '%s'\n\n", mensagem);
    transformarPrimeirasLetrasMaiscula(mensagem);
    printf("\nEssa é a mensagem modificada '%s'\n\n", mensagem);

    return 0;
}

void lerStr(char str[], int tamMax){
    fgets(str, TAM_MSG, stdin);
    int tam = meuStrLen(str);
    if(tam > 0 && str[tam -1] == '\n'){
        str[tam -1] = '\0';
    }
}

int meuStrLen(char str[]){
    int tam = 0;
    
    while(str[tam] != '\0'){
        tam +=1;
    }
    return tam;
}

void meuStrCpy(char strDest[], char strOrigem[]){
    int tam = meuStrLen(strOrigem);
    for(int i = 0; i < tam; i++){
        strDest[i] = strOrigem[i];
    }
    strDest[tam] = '\0';
}

// Tabela ASCII
// Ex: 'a' = 97 e 'A' = 65
// Ou seja se subtrair 97 por 32 
// achamos o A maisculo e o inverso tb funciona.
char maiscusla(char caractere){
    return caractere - 32;
}

int ehMinuscula(char caractere){
    return caractere >= 'a' && caractere <= 'z';
}

void transformarPrimeirasLetrasMaiscula(char str[]){
    int tam = meuStrLen(str);
    for(int i = 0; i < tam; i++){
        if(ehMinuscula && (i == 0 || str[i - 1] == ' ')){
            str[i] = maiscusla(str[i]);
        }
    }
}