#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM 50
//Struct data
typedef struct data{
    int dia;
    int mes;
    int ano;
}TData;

//Struct endereço
typedef struct endereco{
    char logadouro [TAM];
    char cidade [TAM];
    char bairro[TAM];
    int CEP;
    int numero;
    char complemento[TAM];
}TEndereco;

//Struct do Cliente
typedef struct Clientes{
    int ID;
    int Tipo;
    TEndereco EnderecoCompleto;
    TData DataCompleta;
    char Nome [TAM];
    int Identidade;
}TClientes;

typedef struct moduloCliente{
TClientes vetor [TAM];
int indice;
}TModuloCliente;

void LerCliente(TClientes *cliente);
void ImprimirCliente(TClientes ICliente);

#endif // CLIENTE_H_INCLUDED
