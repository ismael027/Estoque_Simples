#include <stdio.h>
#include <stdlib.h>
#include "Vendas.h"



int main()
{
    TModuloProduto modulo1;
    IniciarModiloProduto(&modulo1);
    TModuloCliente modulo2;
    IniciarModuloCliente(&modulo2);
    TModuloVendas modulo3;
    IniciarModuloVendas(&modulo3);


    TClientes cliente1;
    LerCliente( &cliente1);
    system("cls");

    TProdutos produto1;
    LerProduto(&produto1);
    system("cls");

    TVendas venda1;
    LerVendas( &venda1 );
    system("cls");

    ImprimirCliente(cliente1);
    ImprimirProduto(produto1);
    ImprimirVendas(venda1);

    return 0;
}
