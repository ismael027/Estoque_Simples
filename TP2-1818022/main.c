#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#include "sort.h"
#include "array.h"

int main(int argc, char* argv[])
{

    char SIT[5];
    char ALG[5];
    int NUM;
    unsigned long long *att, *comp;
    int PRINT = 0;
    unsigned long long *tempo;

    att = (unsigned long long*) calloc(1,sizeof(unsigned long long));
    comp = (unsigned long long*) calloc(1,sizeof(unsigned long long));
    tempo = (unsigned long long*) calloc(1,sizeof(unsigned long long));

    NUM = atoi(argv[2]);
    strcpy(ALG, argv[1]);
    strcpy(SIT, argv[3]);

    if(argc == 5){
        printf("%s\n", argv[4]);
            if(strcmp(argv[4], "-p") == 0)
                PRINT = 1;
    }

    if(NUM <= 0)
    {
        printf("ERRO: NUM DE ELEMENTOS DESCONHECIDO\n");
        return 0;
    }

    TArray A;
    allocateArray(&A, NUM);

    printf("Gerando o vetor...\n");
    if(strcmp(SIT, "ordc") == 0)
        generateSorted(&A, A.n);
    else if(strcmp(SIT, "ordi") == 0)
        generateInvert(&A, A.n);
    else if(strcmp(SIT, "ale") == 0)
        generateRandomNoRep(&A, A.n);
    else if(strcmp(SIT, "qord") == 0)
        generateAlmostSortedNoRep(&A, A.n);
    else
    {
        printf("ERRO: SITUACAO DO VETOR DESCONHECIDA\n");
        freeArray(&A);
        return 1;
    }

    if(PRINT)
        printArray(&A);

    clock_t time[2];

    //ordenando o vetor
    printf("Ordenando o vetor...\n");
    if(strcmp(ALG, "bub") == 0)
    {
        time[0] = clock();
        bubbleSort(&A, att, comp);
        time[1] = clock();
    }
    else if(strcmp(ALG, "bubo") == 0)
    {
        time[0] = clock();
        bubbleSortO(&A, att, comp);
        time[1] = clock();
    }
    else if(strcmp(ALG, "sel") == 0)
    {
        time[0] = clock();
        selectSort(&A, att, comp);
        time[1] = clock();
    }
    else if(strcmp(ALG, "selo") == 0)
    {
        time[0] = clock();
        selectSortO(&A, att, comp);
        time[1] = clock();
    }
    else if(strcmp(ALG, "ins") == 0)
    {
        time[0] = clock();
        insertionSort(&A, att, comp);
        time[1] = clock();
    }
    else if(strcmp(ALG, "inso") == 0)
    {
        time[0] = clock();
        insertionSortO(&A, att, comp);
        time[1] = clock();
    }
    else if(strcmp(ALG, "shell") == 0)
    {
        time[0] = clock();
        shellSort(&A, att, comp);
        time[1] = clock();
    }
    else if(strcmp(ALG, "qui") == 0)
    {
        time[0] = clock();
        quickSort(&A, att, comp);
        time[1] = clock();
    }
    else if(strcmp(ALG, "heap") == 0)
    {
        time[0] = clock();
        heapSort(&A, att, comp);
        time[1] = clock();
    }
    else if(strcmp(ALG, "merge") == 0)
    {
        time[0] = clock();
        mergeSort(&A, att, comp);
        time[1] = clock();
    }
    else
    {
        printf("ERRO: ALGORITMO DE ORDENACAO DESCONHECIDO\n");
        freeArray(&A);
        return 2;
    }

    // imprimindo resultados de execucao
    if(!isSorted(&A))
    {
        printf("ERRO: VETOR NAO FOI COMPLETAMENTE ORDENADO!\n");
        return 3;
    }
    if(PRINT)
        printArray(&A);
    printf("%*s: %s\n",   5, "ALG", ALG);
    printf("%*s: %d\n",   5, "NUM", NUM);
    printf("%*s: %ld\n",  5, "att", *att);
    printf("%*s: %ld\n",  5, "comp", *comp);

    *tempo = (time[1] - time[0]);
    printf("Tempo gasto: %g s.", (time[1] - time[0]) / 1000.0);

    freeArray(&A);

    return 4;
}
