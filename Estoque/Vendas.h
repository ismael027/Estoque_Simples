#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

typedef struct vendas{
    char Nome [TAM];
    int Codigo;
    TData DataDeVenda;
    TData DataDoPagamento;
    int tipo;
}TVendas;

void LerVendas(TVendas *vendas);
void ImprimirVendas(TVendas IVendas);

#endif // VENDAS_H_INCLUDED