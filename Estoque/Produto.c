#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"

//Função para ler os produtos
void LerProduto(TProdutos *produto)
{
    printf("\n=======CADASTRO DE PRODUTO=======");
    printf("\nDigite o codigo: ");
    fflush(stdin);
    scanf("%d", &produto->CodigoProduto);

    printf("\n Nome: ");
    fflush(stdin);
    fgets(produto->NomeProduto, TAM, stdin);

    printf("\nDescricao: ");
    fflush(stdin);
    fgets(produto->DescricaoProduto, TAM, stdin);

    printf("\nDia de farbicacao: ");
    fflush(stdin);
    scanf("%d", &produto->DataFabricacao.dia);

    printf("\nMes de farbicacao: ");
    fflush(stdin);
    scanf("%d", &produto->DataFabricacao.mes);

    printf("\nAno de farbicacao: ");
    fflush(stdin);
    scanf("%d", &produto->DataFabricacao.ano);

    printf("\nLote: ");
    fflush(stdin);
    scanf("%d", &produto->LoteProduto);

    printf("\nPreco unitario: ");
    fflush(stdin);
    scanf("%f", &produto->PrecoUnitario);

    printf("\nEstoque: ");
    fflush(stdin);
    scanf("%d", &produto->EstoqueProduto);
}

//Função para imprimir os produtos
void ImprimirProduto(TProdutos IProduto)
{
    printf("\n==========PRODUTO==========");
    printf("\nNome: %s", IProduto.NomeProduto);
    printf("Codigo: %d", IProduto.CodigoProduto);
    printf("\nDescricao: %s", IProduto.DescricaoProduto);
    printf("Data de fabricacao: %d/%d/%d", IProduto.DataFabricacao.dia, IProduto.DataFabricacao.mes, IProduto.DataFabricacao.ano);
    printf("\nLote: %d", IProduto.LoteProduto);
    printf("\nPreco unitario: R$%.2f", IProduto.PrecoUnitario);
    printf("\nEstoque: %d", IProduto.EstoqueProduto);
}
