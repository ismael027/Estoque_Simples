#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"

void IniciarModiloProduto(TModuloProduto *modulo){
modulo->indice = 0;
}

//Fun��o para ler os produtos
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

//Fun��o para imprimir os produtos
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

void InserirProduto(TModuloProduto *modulo, TProdutos produto){
    if( modulo->indice < TAM ){
        modulo->vetor[modulo->indice] = produto;
        modulo->indice++;
        printf("Produto cadastrado com sucesso!!");
    }
    else{
        printf("Nao � possivel cadastrar, memoria cheia!!");
    }
}

int PesquisarProduto(TModuloProduto modulo, TProdutos produto)
{
    int i;
    for(i = 0; i < modulo.indice; i++)
    {
        if(produto.CodigoProduto == modulo.vetor.[ i ].CodigoProduto)
        {
            return i;
        }
    }
    return -1;
}
