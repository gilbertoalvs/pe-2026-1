#include <stdio.h>

#define QTD_MIN 2
#define QTD_MAX 3
#define MIN_IDADE 0
#define MAX_IDADE 130

double calcularMedia(int v[], int n);
void imprimirMaiorIgualMedia(int v[], int n, double media);
void preencherIdadesDigitacao(int v[], int n);
int buscaSequecial(int v[], int n, int x);
void buscarIdades(int v[], int n);
void inserir(int v[], int n, int pos, int x);
int inserirIdades(int v[], int n, int max);
void imprimir(int v[], int n);

int main()
{
    int idades[QTD_MAX];
    int tam;
    double media;

    do
    {
        printf("Digite a quantidade de participantes (%d - %d): ", QTD_MIN, QTD_MAX);
        scanf("%d", &tam);
    } while (tam < QTD_MIN || tam > QTD_MAX);

    preencherIdadesDigitacao(idades, tam);
    media = calcularMedia(idades, tam);
    printf("A média de idade dos participantes é de %.2lf anos\n", media);
    imprimirMaiorIgualMedia(idades, tam, media);
    buscarIdades(idades, tam);
    tam = inserirIdades(idades, tam, QTD_MAX);
    printf("Vetor final: ");
    imprimir(idades, tam);
    return 0;
}

double calcularMedia(int v[], int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += v[i];
    }
    return (double)soma / (double)n;
}

void imprimirMaiorIgualMedia(int v[], int n, double media)
{
    printf("\n\nAs idades maiores ou igual a média são\n");
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= media)
        {
            printf("Idade do %dº participante: %d\n", i + 1, v[i]);
        }
    }
}

void preencherIdadesDigitacao(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Digite a idade do %dº participante (%d - %d): ", i + 1);
            scanf("%d", &v[i]);
        } while (v[i] < MIN_IDADE || v[i] > MAX_IDADE);
    }
}

int buscaSequecial(int v[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void buscarIdades(int v[], int n)
{
    int idade, pos;
    printf("Digite uma idade a ser buscada: ");
    scanf("%d", &idade);
    while (idade >= 0)
    {
        pos = buscaSequecial(v, n, idade);
        if (pos != -1)
        {
            printf("Encontrou a idade %d na posição %d\n", idade, pos + 1);
        }
        else
        {
            printf("A idade %d não se encontra no vetor.\n", idade);
        }
        printf("Digite uma idade para ser buscada (< 0 p/ finalizar): ");
        scanf("%d", &idade);
    }
}

void inserir(int v[], int n, int pos, int x)
{
    for (int i = n - 1; i >= pos; i--)
    {
        v[i + 1] = v[i];
    }
    v[pos] = x;
}

int inserirIdades(int v[], int n, int max)
{
    int idade, pos, tam = n;
    char opcao;
    do
    {
        if (tam >= max)
        {
            printf("\nVetor está cheio!");
            return tam;
        }
        imprimir(v, tam);
        do
        {
            printf("Digite uma idade a ser inserida (%d - %d): ", QTD_MIN, QTD_MAX);
            scanf("%d", &idade);
        } while (idade < MIN_IDADE || idade > MAX_IDADE);
        do
        {
            printf("Digite a posição que esta idade deve ser inserida: ");
            scanf("%d", &pos);
        } while (pos < 1 || pos > tam + 1);
        inserir(v, tam, pos - 1, idade);
        tam += 1;
        imprimir(v, tam);
        printf("Você quer inserir outra idade? (s/n)? ");
        scanf("%c", &opcao);
        scanf("%c", &opcao);
    } while (opcao == 's' || opcao == 'S');
    return tam;
}

void imprimir(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}