#define  _CRT_SECURE_NO_WARNINGS


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_carro
{
    char placa[10];
    char modelo[20];
    char marca[20];
    char cor[20];
    char ano[5];
};
typedef struct st_carro Carro;

struct cad_cliente
{
    char nome[30];
    int  idade;
    char CPF_CNPJ[20];
    char CNH[20];
    char Endereco[50];
};
typedef struct cad_cliente Cliente;

int le_um_carro(Carro*);
int le_um_cliente(Cliente*);
int mostra_um_carro(Carro* c);
int mostra_um_cliente(Cliente* c);

int main(void)
{
    Carro info;
    Cliente cliente;

    int opcao = 2;
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
    default:
        printf("Opcao inesperada: %d\n", opcao);
        break;
    };  // switch()
};  // main()

int le_um_carro(Carro* C)
{
    char aux[200];
    Carro info;
        printf("Informe o numero da placa [7 digitos]: ");
    placa:
        fflush(stdin);
        fgets(aux, 300, stdin);
        if (strlen(aux) < 7) {
            printf("erro quantidade de digitos menor do que o correto\n");
            printf("Digite novamente: ");
            goto placa;
        }
        else if (strlen(aux) > 7) {
            printf("erro quantidade de digitos maior do que o correto\n");
            printf("Digite novamente: ");
            goto placa;
        }
        else {
            strcpy(info.placa, aux);
        }
        printf("Informe a marca do veiculo: ");
        gets(info.marca);
        printf("Informe o modelo do veiculo: ");
        gets(info.modelo);
        printf("Informe a cor do veiculo: ");
        gets(info.cor);
        printf("Informe o ano do veiculo: ");
        gets(info.ano);
        *C = info;
        return 0;
};  // le_um_carro()

int le_um_cliente(Cliente* c)
{
    return 0;
};

int mostra_um_carro(Carro* c)
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

int mostra_um_cliente(Cliente* c)
{
    return 0;
};
