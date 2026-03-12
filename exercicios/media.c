#include <stdio.h>
#define TOTAL_ALUNOS 30

int main(){

    double nota1 [TOTAL_ALUNOS];
    double nota2 [TOTAL_ALUNOS];
    double media [TOTAL_ALUNOS];
    double soma = 0, media_turma;

    for(int i =0; i < TOTAL_ALUNOS; i++){
        printf("Digite as notas do aluno %d:\n", i + 1);
        printf("Nota 1: ");
        scanf("%lf", &nota1[i]);
        printf("Nota 2: ");
        scanf("%lf", &nota2[i]);

        media[i] = (nota1[i] * 2 + nota2[i] * 3) / 5;

        soma += media[i];
    }

    media_turma = soma / TOTAL_ALUNOS;

    printf("--- RESULTADOS ---\n");
    printf("Media da turma: %.2f\n", media_turma);
    printf("------------------\n");

    printf("Alunos com media superior a media da turma:\n");

    for(int i = 0; i < TOTAL_ALUNOS; i++){
        if (media[i] > media_turma){
            printf("Aluno %d = Nota 1: %.1f | Nota 2: %.1f | Media: %.2f\n", i + 1, nota1[i], nota2[i], media[i]);
        }
    }

    return 0;

}
