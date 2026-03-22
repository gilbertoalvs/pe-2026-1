#include <stdio.h>

#define QTD_MAX 5
#define MIN_PESSOAS 0
#define MAX_PESSOAS 130

int main()
{

    int idades[QTD_MAX];
    int soma = 0;
    double media;

    for (int i = 0; i < QTD_MAX; i++)
    {
        do
        {
            printf("Digite a idade do participante %d: ", i + 1);
            scanf("%d", &idades[i]);
        } while (idades[i] < MIN_PESSOAS || idades[i] > MAX_PESSOAS);

        soma += idades[i];
    }

    if (QTD_MAX != 0)
    {
        media = soma / (double)QTD_MAX;
        printf("A média de idades dos participantes é: %.2lf anos\n", media);

        printf("As idades maiores ou iguais da média são:\n");

        for (int i = 0; i < QTD_MAX; i++)
        {
            if (idades[i] >= media)
            {
                printf("idade do %dº participiante: %d\n", i + 1, idades[i]);
            }
        }
    }
    else
    {
        printf("Nenhuma idade válida digitada!\n");
    }
    return 0;
}