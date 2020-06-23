#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cad_cliente
{
    char nome[10];
    int idade;
    char CPF_CNPJ[20];
    char CNH[30];
    char Endereco[50];
};
typedef struct cad_cliente Cliente;

typedef struct
{
    char placa[10];
    char modelo[20];
    char marca[20];
    char cor[20];
    char ano[5];
}   Carro;

int     le_um_carro(Carro*);
int     le_um_cliente(Cliente*);
int     menu();
int     mostra_um_carro(Carro*);
int     mostra_um_cliente(Cliente*);

int origem();

int     main(void)
{
    int opcao = 5;
    Carro   info;
    Cliente cliente;

    origem();
    while (opcao != 5) // sair = 5
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            le_um_cliente(&cliente);
            mostra_um_cliente(&cliente);
            break;
        case 2:
            le_um_carro(&info);
            mostra_um_carro(&info);
            break;
        case 5:
            break;
        default:
            printf("Opcao inesperada: %d\n", opcao);
            break;
        };  // switch()
    };   // while();
};  // main()

int     le_um_carro(Carro * C)
{
    char aux[200];
    Carro info;
    printf("Informe o numero da placa [7 digitos]: ");
    placa:
    fflush(stdin);
    fgets(aux, 10, stdin);
    if (strlen(aux) < 8) {
        printf("erro quantidade de digitos menor do que o correto\n");
        printf("Digite novamente: ");
        goto placa;
    }
    else if (strlen(aux) > 8) {
        printf("erro quantidade de digitos maior do que o correto\n");
        printf("Digite novamente: ");
        goto placa;
    }
    else {
        strcpy(info.placa, aux);
    }
    printf("Informe a marca do veiculo: ");
    fgets(info.marca,20,stdin);
    printf("Informe o modelo do veiculo: ");
    fgets(info.modelo,30,stdin);
    printf("Informe a cor do veiculo: ");
    fgets(info.cor,20,stdin);
    printf("Informe o ano do veiculo: ");
    fgets(info.ano,5,stdin);
    *C = info;
    return 0;
};  // le_um_carro()

int     le_um_cliente(Cliente* C)
{
    Cliente info;
    char aux[200];
    system("cls");
    printf("Informe o nome do cliente: ");
    fflush(stdin);
    fgets(info.nome,30,stdin);
    printf("Informe a idade do cliente: ");
    scanf("%d", &info.idade);

    printf("Informe o CPF/CNPJ do cliente: ");
cpf:
    fflush(stdin);
    fgets(aux,20,stdin);
    if (strlen(aux) < 11) {
        printf("erro quantidade de digitos menor do que o correto\n");
        printf("Digite novamente: \n");
        goto cpf;

    }
    else if (strlen(aux) > 11) {
        printf("erro quantidade de digitos maior do que o correto\n");
        printf("Digite novamente: \n");
        goto cpf;

    }
    else {
        strcpy(info.CPF_CNPJ, aux);
    }
    printf("Informe o número do CNH do cliente: ");
cnh:
    fflush(stdin);
    fgets(aux,10,stdin);
    if (strlen(aux) < 11) {
        printf("erro quantidade de digitos menor do que o correto\n");
        printf("digite novamente: \n");
        goto cnh;

    }
    else if (strlen(aux) > 11) {
        printf("erro quantidade de digitos maior do que o correto\n");
        printf("digite novamente: \n");
        goto cnh;

    }
    else {
        strcpy(info.CNH, aux);
    }

    printf("Informe o endereco do cliente: ");
    fgets(info.Endereco,30,stdin);
    *C = info;
    return 0;
};

int     menu()
{
    int opcao = 0;
    system("cls");
    printf("-----------------------------------------\n");
    printf("\tCONTROLE DE ESTACIONAMENTO\n");
    printf("-----------------------------------------\n\n");
    printf("1- Cadastrar Cliente\n");
    printf("\n2- Cadastrar Veiculo\n");
    printf("\n3- Listar veiculos cadastrados\n");
    printf("\n4- Creditos\n");
    printf("\n5- Sair\n");
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    return opcao;
};

int     mostra_um_carro(Carro * c)
{
    printf("Marca/Modelo: %s %s Cor: %s Placa: %s Entrada: %s \n",
        c->marca,
        c->modelo,
        c->cor,
        c->placa,
        c->ano
    );
    return 0;
};

int     mostra_um_cliente(Cliente* C)
{
    return 0;
};

