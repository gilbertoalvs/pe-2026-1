#include <stdio.h>
#include <stdlib.h>

void display(int var, int *ptr);
void update(int *p);
void troca(int *a, int *b);

int main(){

    int var = 15;
    int *ptr;

    ptr = &var;

    display(var, ptr);
    update(&var);
    display(var, ptr);

    int m = 5; int n = 4;
    troca(&m, &n);
    printf("M = %d N = %d\n", m, n);

    printf("\n\nEnd.");
    return 0;
}

void display(int var, int *ptr){
    printf("---------------------------\n");
    printf("Conteudo de var: %d\n", var);
    printf("Endereço de var: %p\n", &var);
    printf("Conteudo apontado por ptr: %d\n", *ptr);
    printf("Endereço apontado por ptr: %p\n", ptr);
    printf("Endereço do ptr: %p\n", &ptr);
}

void update(int *p){
    *p+=1;
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Ponteiros: 
// *ptr: O sinal "*" aponta para o conteudo do endereço apontado pelo ponteiro.
// ptr: Endereço da variável.
// &ptr: Endereço do ponteiro.