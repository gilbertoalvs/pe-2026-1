#include <stdio.h>

double calcularIMC(double peso, double altura);

int main(){

    double peso, altura, imc;

    printf("Digite o seu peso: ");
    scanf("%lf", &peso);
    printf("Digite a sua a altura: ");
    scanf("%lf", &altura);
    imc = calcularIMC(peso, altura);
    printf("A sua altura eh %.2lf\n", imc);
    return 0;
}

double calcularIMC(double peso, double altura){
    return peso / (altura * altura);
}

