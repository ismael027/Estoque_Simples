#include <stdio.h>
#include <stdlib.h>
#include "Vendas.h"

//Função Ler Vendas
void LerVendas(TVendas *vendas)
{
    printf("\n======CADASTRO DE VENDAS======");
    printf("\nDigite o nome: ");
    fflush(stdin);
    fgets(vendas->Nome, TAM, stdin);

    printf("\nDigite o codigo: ");
    fflush(stdin);
    scanf("%d", &vendas->Codigo);

    printf("\nDia da venda: ");
    fflush(stdin);
    scanf("%d", &vendas->DataDeVenda.dia);

    printf("\nMes da venda: ");
    fflush(stdin);
    scanf("%d", &vendas->DataDeVenda.mes);

    printf("\nAno da venda: ");
    fflush(stdin);
    scanf("%d", &vendas->DataDeVenda.ano);

    printf("\nDia do pagamento: ");
    fflush(stdin);
    scanf("%d", &vendas->DataDoPagamento.dia);

    printf("\nMes do pagamento: ");
    fflush(stdin);
    scanf("%d", &vendas->DataDoPagamento.mes);

    printf("\nAno do pagamento: ");
    fflush(stdin);
    scanf("%d", &vendas->DataDoPagamento.ano);

    printf("\nTipo do pagamento: a vista digite 0, no credito digite 1");
    fflush(stdin);
    scanf("%d",&vendas->tipo);
}


void ImprimirVendas(TVendas IVendas)
{
    printf("\n\n==========VENDAS==========");
    printf("\nNome: %s", IVendas.Nome);
    printf("Codigo: %d", IVendas.Codigo);
    printf("\nData da compra: %d/%d/%d", IVendas.DataDeVenda.dia, IVendas.DataDeVenda.mes, IVendas.DataDeVenda.ano);
    printf("\nData do pagamento: %d/%d/%d", IVendas.DataDoPagamento.dia, IVendas.DataDoPagamento.mes, IVendas.DataDoPagamento.ano);
    if(IVendas.tipo == 0)
    {
        printf("\nTipo do pagamento: A vista");
    }
    else
    {
        printf("\nTipo do pagamento: Credito");
    }
}
