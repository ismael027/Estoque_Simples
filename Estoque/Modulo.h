#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Produto.h"
#include "Vendas.h"

typedef struct moduloProduto{
TProdutos vetor[TAM];
int indice;
}TModuloProduto;

typedef struct moduloCliente{
TClientes vetor [TAM];
int indice;
}TModuloCliente;

typedef struct moduloVendas{
TVendas vetor [TAM];
int indice;
}TModuloVendas;

#endif // MODULO_H_INCLUDED
