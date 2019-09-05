#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Produto.h"

typedef struct vendas{
    char Nome [TAM];
    int Codigo;
    TData DataDeVenda;
    TData DataDoPagamento;
    int tipo;
}TVendas;

typedef struct moduloVendas{
TVendas vetor [TAM];
int indice;
}TModuloVendas;

void LerVendas(TVendas *Venda);
void ImprimirVendas(TVendas IVendas);
void IniciarModuloVendas(TModuloVendas *modulo);

#endif // VENDAS_H_INCLUDED
