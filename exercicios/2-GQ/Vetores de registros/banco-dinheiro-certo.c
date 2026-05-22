#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_CPF 15
#define TAM_TEL 20
#define TAM_CONTAS 100

struct Conta{
    int numero;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char telefone[TAM_TEL];
    double saldo;
};

struct Cadastro{
    struct Conta contas[TAM_CONTAS];
    int total_contas;
};

int buscarConta(struct Cadastro *cad, int num);
void lerStr(char str[], int tamMax);
void cadastrarConta(struct Cadastro *cad, int num);
void consultarSaldo(struct Cadastro *cad, int num);
void depositar(struct Cadastro *cad, int num);
void sacar(struct Cadastro *cad, int num);
void exibirContas(struct Cadastro *cad);

int main(){

    struct Cadastro corrente = {.total_contas = 0};
    struct Cadastro poupanca = {.total_contas = 0};

    int opcao, tipoConta, numConta;
    struct Cadastro *cad_selecionado;

    do{
        printf("\n=== Banco Dinheiro Certo ===\n");
        printf("1. Cadastrar Conta\n");
        printf("2. Consultar Saldo\n");
        printf("3. Realizar Deposito\n");
        printf("4. Realizar Saque\n");
        printf("5. Exibir Contas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 5) {
            printf("Selecione o Cadastro (1 - Corrente | 2 - Poupanca): ");
            scanf("%d", &tipoConta);
            
            if (tipoConta == 1) {
                cad_selecionado = &corrente;
            } else if (tipoConta == 2) {
                cad_selecionado = &poupanca;
            } else {
                printf("Tipo de conta invalido!\n");
                continue;
            }
            
            if (opcao != 5) {
                printf("Digite o numero da conta: ");
                scanf("%d", &numConta);
            }

            switch(opcao) {
                case 1: cadastrarConta(cad_selecionado, numConta); break;
                case 2: consultarSaldo(cad_selecionado, numConta); break;
                case 3: depositar(cad_selecionado, numConta); break;
                case 4: sacar(cad_selecionado, numConta); break;
                case 5: exibirContas(cad_selecionado); break;
            }
        }

    }while(opcao !=0);

    return 0;
}

// Letra a)
int buscarConta(struct Cadastro *cad, int num){
    if(cad->total_contas == 0){
        return -1; // Cadastro vazio
    }
    for(int i = 0; i < cad->total_contas; i++){
        if(cad->contas[i].numero == num){
            return i; //Posição encontrada com sucesso
        }
    }
    return -2; // Não encontrada
}

// Letra B)

void lerStr(char str[], int tamMax){
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam-1] == '\n'){str[tam-1] = '\0';}
}

void cadastrarConta(struct Cadastro *cad, int num){
    if(cad->total_contas >=TAM_CONTAS){
        printf("Erro: O cadastro atingiu o limite maximo de %d contas.\n", TAM_CONTAS);
        return;
    }

    int pos = buscarConta(cad, num);
    if(pos >=0){
        printf("Aviso. Não é possivel realizar o cadastro. Número de conta repetido.\n");
    } else{
        struct Conta nova;
        nova.numero = num;

        printf("Digite o nome do cliente: ");
        lerStr(nova.nome, TAM_NOME);
        lerStr(nova.nome, TAM_NOME);
        printf("Digite o CPF: ");
        lerStr(nova.cpf, TAM_CPF);
        printf("Digite o telefone de contado: ");
        lerStr(nova.telefone, TAM_TEL);
        printf("Digite o saldo inicial: R$ ");
        scanf("%lf", &nova.saldo);

        cad->contas[cad->total_contas] = nova;
        cad->total_contas++;
        printf("Conta cadastrada com sucesso!\n");
    }
}

// Letra C
void consultarSaldo(struct Cadastro *cad, int num){
    int pos = buscarConta(cad, num);
    if(pos >=0){
        printf("Saldo da conta %d: R$ %.2lf\n", num, cad->contas[pos].saldo);
    } else{
        printf("Aviso: Conta não está cadastrada.\n");
    }
}

// Letra D
void depositar(struct Cadastro *cad, int num){
    int pos = buscarConta(cad, num);
    if(pos >= 0){
        double valor;
        printf("Digite o valor do deposito: R$ ");
        scanf("%lf", &valor);
        if(valor > 0){
            cad->contas[pos].saldo += valor;
            printf("Deposito efetuado com sucesso. Novo saldo: R$ %.2lf\n", cad->contas[pos].saldo);
        } else{
            printf("Erro: Valor de deposito invalido.\n");
        }
    } else {
        printf("Aviso: Conta não está cadastrada.\n");
    }
}

// Letra e
void sacar(struct Cadastro *cad, int num){
    int pos = buscarConta(cad, num);
    if(pos == -1 || pos == -2){
        printf("Aviso: Conta não está cadastrada.\n");
    } else{
        double valor;
        printf("Digite o valor do saque: R$ ");
        scanf("%lf", &valor);

        if(valor > 0 && cad->contas[pos].saldo >=valor){
            cad->contas[pos].saldo -= valor;
            printf("Saque efetuado com sucesso. Novo saldo: R$ %.2lf\n", cad->contas[pos].saldo);
        } else if(valor > cad->contas[pos].saldo){
            printf("Aviso: Nao existe saldo suficiente para este saque.\n");
        } else {
            printf("Erro: Valor de saque invalido.\n");
        }
    }
}

// Letra f)
void exibirContas(struct Cadastro *cad){
    if(cad->total_contas == 0){
        printf("Nenhuma conta cadastrada neste registro.\n");
        return;
    }
    printf("\n--- Lista de Contas ---\n");
    for (int i = 0; i < cad->total_contas; i++) {
        printf("Numero da Conta: %d | Titular: %s | Telefone: %s\n", 
               cad->contas[i].numero, cad->contas[i].nome, cad->contas[i].telefone);
    }
    printf("-----------------------\n");
}