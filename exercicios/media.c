#include <stdio.h>
#define TOTAL_ALUNOS 30

int main(){

    double nota1 [TOTAL_ALUNOS];
    double nota2 [TOTAL_ALUNOS];
    double media [TOTAL_ALUNOS];
    double soma = 0, media_turma;

    for(int i =0; i < TOTAL_ALUNOS; i++){
        printf("Digite as notas do aluno %d:\n", i + 1);
        
        while (1) {
            printf("Nota 1 (0 a 10): ");
        
            if (scanf("%lf", &nota1[i]) == 1 && nota1[i] >= 0 && nota1[i] <= 10) {
                break; // Entrada válida, sai do loop
            } else {
                printf("Erro: Digite um numero valido entre 0 e 10.\n");
                while (getchar() != '\n'); 
            }
        }

        while (1) {
            printf("Nota 2 (0 a 10): ");
            if (scanf("%lf", &nota2[i]) == 1 && nota2[i] >= 0 && nota2[i] <= 10) {
                break; 
            } else {
                printf("Erro: Digite um numero valido entre 0 e 10.\n");
                while (getchar() != '\n'); 
            }
        }

        media[i] = (nota1[i] * 2 + nota2[i] * 3) / 5;

        soma += media[i];
    }

    media_turma = soma / TOTAL_ALUNOS;

    printf("\n============================\n");
    printf("Media da Turma: %.2f\n", media_turma);
    printf("============================\n");

    printf("Alunos acima da media:\n");
    for (int i = 0; i < TOTAL_ALUNOS; i++) {
        if (media[i] > media_turma) {
            printf("Aluno %d -> N1: %.1f | N2: %.1f | Media: %.2f\n", 
                    i + 1, nota1[i], nota2[i], media[i]);
        }
    }

    return 0;

}
