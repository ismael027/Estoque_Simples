#include <stdio.h>
#include <stdlib.h>
#include "Vendas.h"

//Função Ler Venda
void LerVendas(TVendas *Venda)
{
    printf("\n======CADASTRO DE VENDA======");
    printf("\nDigite o nome: ");
    fflush(stdin);
    fgets(Venda->Nome, TAM, stdin);

    printf("\nDigite o codigo: ");
    fflush(stdin);
    scanf("%d", &Venda->Codigo);

    printf("\nDia da venda: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDeVenda.dia);

    printf("\nMes da venda: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDeVenda.mes);

    printf("\nAno da venda: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDeVenda.ano);

    printf("\nDia do pagamento: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDoPagamento.dia);

    printf("\nMes do pagamento: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDoPagamento.mes);

    printf("\nAno do pagamento: ");
    fflush(stdin);
    scanf("%d", &Venda->DataDoPagamento.ano);

    printf("\nTipo do pagamento: a vista digite 0, no credito digite 1");
    fflush(stdin);
    scanf("%d",&Venda->tipo);
}


void ImprimirVendas(TVendas IVenda)
{
    printf("\n\n==========VENDAS==========");
    printf("\nNome: %s", IVenda.Nome);
    printf("Codigo: %d", IVenda.Codigo);
    printf("\nData da compra: %d/%d/%d", IVenda.DataDeVenda.dia, IVenda.DataDeVenda.mes, IVenda.DataDeVenda.ano);
    printf("\nData do pagamento: %d/%d/%d", IVenda.DataDoPagamento.dia, IVenda.DataDoPagamento.mes, IVenda.DataDoPagamento.ano);
    if(IVenda.tipo == 0)
    {
        printf("\nTipo do pagamento: A vista");
    }
    else
    {
        printf("\nTipo do pagamento: Credito");
    }
}
