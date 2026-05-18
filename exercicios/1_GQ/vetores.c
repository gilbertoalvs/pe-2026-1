#include <stdio.h>

#define MIN 3
#define MAX 50

int inserirOrdenado(int v[], int tamanho, int capacidade, int valor);
void imprimirVetor(int v[], int tamanho);
int buscaBinaria(int v[], int tamanho, int valor);
int removerElemento(int v[], int tamanho, int valor);

int main()
{
    int vetor[MAX];
    int capacidade, inicio, valor, opcao, pos;
    int tamanho_atual = 0;

    // Solicitação da capacidade do vetor.
    do
    {
        printf("Digite a capacidade desejada do vetor (entre 3 e 50): ");
        scanf("%d", &capacidade);
    } while (capacidade < MIN || capacidade > MAX);

    // Solicitação da quantidade de elementos
    do
    {
        printf("Quantos valores você quer inserir agora? (Maximo %d) ", capacidade);
        scanf("%d", &inicio);
    } while (inicio < 0 || inicio > capacidade);

    // Preencher o vetor inicial.
    for (int i = 0; i < inicio; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        tamanho_atual = inserirOrdenado(vetor, tamanho_atual, capacidade, valor);
    }

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Imprimir todo o vetor\n");
        printf("2. Consultar posicao de um elemento\n");
        printf("3. Remover um elemento\n");
        printf("4. Inserir um novo valor\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            imprimirVetor(vetor, tamanho_atual);
            break;
        case 2:
            printf("Digite o valor que deseja buscar: ");
            scanf("%d", &valor);
            pos = buscaBinaria(vetor, tamanho_atual, valor);
            if (pos != -1)
            {
                printf("Valor %d encontrado no indice [%d].\n", valor, pos);
            }
            else
            {
                printf("Valor não encontrado. \n");
            }
            break;
        case 3:
            printf("Digite o valor que deseja remover: ");
            scanf("%d", &valor);
            tamanho_atual = removerElemento(vetor, tamanho_atual, valor);
            break;
        case 4:
            printf("Digite o valor que deseja inserir: ");
            scanf("%d", &valor);
            tamanho_atual = inserirOrdenado(vetor, tamanho_atual, capacidade, valor);
            break;
        case 0:
            printf("Programa encerrado!\n");
            break;
        default:
            printf("Opção invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

int inserirOrdenado(int v[], int tamanho, int capacidade, int valor)
{

    if (tamanho >= capacidade)
    {
        printf("Erro: o vetor ja atingiu capacidade maxima.\n");
        return tamanho;
    }

    int i = tamanho - 1;

    while (i >= 0 && v[i] > valor)
    {
        v[i + 1] = v[i];
        i--;
    }

    v[i + 1] = valor;
    printf(">>> Valor inserido com sucesso!\n");

    return tamanho + 1; // Tamanho incrementado
}

void imprimirVetor(int v[], int tamanho)
{
    if (tamanho == 0)
    {
        printf(">>> O vetor está vazio no momento.\n");
        return;
    }

    printf(">>> Vetor atual (Tamanho %d): [", tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

int buscaBinaria(int v[], int tamanho, int valor)

{
    int meio, inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        meio = inicio + (fim - inicio) / 2;

        if (v[meio] == valor)
        {
            return meio;
        }
        else if (v[meio] > valor)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }

    return -1;
}

int removerElemento(int v[], int tamanho, int valor)
{
    int pos = buscaBinaria(v, tamanho, valor);

    if (pos == -1)
    {
        printf(">>> O valor %d não está no vetor. Nada foi removido.\n", valor);
        return tamanho;
    }

    for (int i = pos; i < tamanho - 1; i++)
    {
        v[i] = v[i + 1];
    }

    printf(">>> Valor removido com sucesso!\n");
    return tamanho - 1;
}