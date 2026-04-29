#include <stdio.h>

#define TOTAL_ALUNOS 30

struct Aluno{
    double nota1;
    double nota2;
    double media;
};

void lerDados(struct Aluno *a);
void calcularMedia(struct Aluno *a);
double calcularMediaTurma(struct Aluno *a);
void imprimir(struct Aluno *a, double media_turma);

int main(){
    struct Aluno turma[TOTAL_ALUNOS];
    
    lerDados(turma);
    calcularMedia(turma);
    double mediaTurma = calcularMediaTurma(turma);
    imprimir(turma, mediaTurma);

    printf("\n\nEnd.");
    return 0;
}

void lerDados(struct Aluno *a){
    for(int i = 0; i < TOTAL_ALUNOS; i++){
        printf("Digite as notas do aluno %d:\n", i + 1);

        //Validação da nota 1.
        while(1){
            printf("Nota 1 (0 a 10): ");

            if(scanf("%lf", &a[i].nota1) == 1 && a[i].nota1 >= 0 && a[i].nota1 <= 10){
                break;
            } else{
                printf("Erro: Digite um numero valido entre 0 e 10.\n");
                while(getchar() != '\n');
            }
         }

        //Validação da nota 2.
        while(1){
            printf("Nota 2 (0 a 10): ");

            if(scanf("%lf", &a[i].nota2) == 1 && a[i].nota2 >= 0 && a[i].nota2 <= 10){
                break;
            } else{
                printf("Erro: Digite um numero valido entre 0 e 10.\n");
                while(getchar() != '\n');
            }
        }    
    }      
}

void calcularMedia(struct Aluno *a){
    for(int i = 0; i < TOTAL_ALUNOS; i++){
        a[i].media = (a[i].nota1 * 2 + a[i].nota2 * 3) / 5;
    }
}

double calcularMediaTurma(struct Aluno *a){
    double soma = 0;
    for(int i = 0; i < TOTAL_ALUNOS; i++){
        soma += a[i].media;
    }
    return soma / TOTAL_ALUNOS;
}

void imprimir(struct Aluno *a, double media_turma){
    printf("\n============================\n");
    printf("Média da turma: %.2lf", media_turma);
    printf("\n============================\n");

    printf("Alunos acima da media:\n");
    for(int i = 0; i < TOTAL_ALUNOS; i++){
        if(a[i].media > media_turma){
            printf("Aluno %d -> N1: %.1lf | N2: %.1lf | Media: %.2lf\n", i + 1, a[i].nota1, a[i].nota2, a[i].media);
        }
    }
}