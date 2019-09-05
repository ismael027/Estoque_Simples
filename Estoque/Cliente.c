#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

void IniciarModuloCliente(TModuloCliente *modulo){
    modulo->indice = 0;
}

//Função para ler os clientes
void LerCliente(TClientes *cliente)
{
    printf("\n=================CADASTRO DE CLIENTE=================");
    printf("\nTipo (digite 0 para pessoa fisica ou 1 para juridica): ");
    fflush(stdin);
    scanf("%d", &cliente->Tipo);

    if(cliente->Tipo == 0)
    {
        printf("\nDigite o CPF: ");
        fflush(stdin);
        scanf("%d", &cliente->ID);
    }
    else
    {
        printf("\nDigite o CNPJ: ");
        fflush(stdin);
        scanf("%d", &cliente->ID);
    }

    printf("\nNome: ");
    fflush(stdin);
    fgets(cliente->Nome, TAM, stdin);

    printf("\nIdentidade:");
    fflush(stdin);
    scanf("%d", &cliente->Identidade);

    printf("\nDia de nascimento: ");
    fflush(stdin);
    scanf("%d", &cliente->DataCompleta.dia);

    printf("\nMes de nascimento: ");
    fflush(stdin);
    scanf("%d", &cliente->DataCompleta.mes);

    printf("\nAno de nascimento: ");
    fflush(stdin);
    scanf("%d", &cliente->DataCompleta.ano);

    printf("\nDigite o nome da rua: ");
    fflush(stdin);
    fgets(cliente->EnderecoCompleto.logadouro, TAM, stdin);

    printf("\nDigite o numero: ");
    fflush(stdin);
    scanf("%d", &cliente->EnderecoCompleto.numero);

    printf("\nDigite o bairro: ");
    fflush(stdin);
    fgets(cliente->EnderecoCompleto.bairro, TAM, stdin);

    printf("\nDigite a cidade: ");
    fflush(stdin);
    fgets(cliente->EnderecoCompleto.cidade, TAM, stdin);

    printf("\nDigite o CEP: ");
    fflush(stdin);
    scanf("%d", &cliente->EnderecoCompleto.CEP);

    printf("\nDigite o complemento: ");
    fflush(stdin);
    fgets(cliente->EnderecoCompleto.complemento, TAM, stdin);
}

//Função para imprimir cliente
void ImprimirCliente(TClientes ICliente)
{
    printf("\n==========CLIENTE==========");
    printf("\nNome: %s", ICliente.Nome);

    if(ICliente.Tipo == 0)
    {
        printf("Tipo: Fisico");
        printf("\nCPF: %d", ICliente.ID);
    }
    else
    {
        printf("Tipo: Juridico");
        printf("\nCNPJ: %d",ICliente.ID);
    }

    printf("\nIdentidade: %d",ICliente.Identidade);
    printf("\nData de nascimento: %d/%d/%d", ICliente.DataCompleta.dia,ICliente.DataCompleta.mes,ICliente.DataCompleta.ano);
    printf("\nEndereco: %s", ICliente.EnderecoCompleto.logadouro);
    printf("Numero: %d", ICliente.EnderecoCompleto.numero);
    printf("\nBairro: %s", ICliente.EnderecoCompleto.bairro);
    printf("Cidade: %s", ICliente.EnderecoCompleto.cidade);
    printf("CEP: %d", ICliente.EnderecoCompleto.CEP);
    printf("\nComplemento: %s", ICliente.EnderecoCompleto.complemento);


}
