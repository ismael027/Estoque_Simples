#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"


typedef struct prdutos{
    int CodigoProduto;
    char NomeProduto[TAM];
    char DescricaoProduto[TAM];
    TData DataFabricacao;
    int LoteProduto;
    float PrecoUnitario;
    int EstoqueProduto;

}TProdutos;

void LerProduto(TProdutos *produto);

void ImprimirProduto(TProdutos IProduto);

#endif // PRODUTO_H_INCLUDED
