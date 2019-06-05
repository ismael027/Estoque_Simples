#include "array.h"
#include <limits.h>


int isSorted(TArray *pA){
	int i;
	for(i=0;i<pA->n-1;i++)
		if (pA->item[i].key > pA->item[i+1].key)
			return i;
	return -1;
}

void allocateArray(TArray *pA, int size){
	pA->n = size;
	pA->item = (TItem*)calloc(size, sizeof(TItem));

	if(!pA->item){
		printf("ERRO: NAO FOI POSSIVEL ALOCAR MEMORIA PARA VETOR\n");
		exit(1);
	}
}


void generateSorted(TArray *pA, int max){
	int i;
	for(i=0; i < pA->n; i++)
		pA->item[i].key = (int) (((double)i/pA->n)*max);
}

void generateInvert(TArray *pA,int max){
	int i;
	for(i=0; i < pA->n; i++)
		pA->item[i].key = (int) ( ( max - ( (double)i/pA->n ) * max ) -1 );
}

void generateRandom(TArray *pA, int max){
	int i;
	srand(time(NULL));
	for(i=0; i<pA->n; i++)
		pA->item[i].key = rand()%max;
}

void generateRandomNoRep(TArray *pA, int max){
	int i,aux;
	int pos1, pos2;
	generateSorted(pA, max);

	srand(time(NULL));
	for(i=0; i < pA->n; i++){
		pos1 = (rand() * rand())%pA->n;
		pos2 = (rand() * rand())%pA->n;
		aux                = pA->item[pos2].key;
		pA->item[pos2].key = pA->item[pos1].key;
		pA->item[pos1].key = aux;
	}
}

void generateAlmostSorted(TArray *pA,int max){
	int i;
	for(i=0; i < (99*pA->n/100); i++)
		pA->item[i].key = (int) (((double)i/pA->n)*max);

	srand(time(NULL));
	for(; i < pA->n; i++)
		pA->item[i].key = rand()%max;
}

void generateAlmostSortedNoRep(TArray *pA,int max){
	int i,aux;
	int pos1,pos2;
	generateSorted(pA, max);

	srand(time(NULL));
	for(i=0; i < pA->n/10; i++){
		pos1 = rand()%pA->n;
		pos2 = rand()%pA->n;
		aux                = pA->item[pos2].key;
		pA->item[pos2].key = pA->item[pos1].key;
		pA->item[pos1].key = aux;
	}
}

void printArray(TArray *pA){
	int i;
	printf("Array:\n");
	for(i=0;i<pA->n;i++)
		printf("%d ",pA->item[i].key);
	printf("\n");
}

void freeArray(TArray *pA){
	if (pA->item != NULL)
		free(pA->item);

	pA->item = NULL;
	pA->n    = 0;
}

void printHelp(){
    printf("\n\n\tOrdenador de vetores\n");
    printf("Modo de usar: ./Sort1.exe <algoritmo> <tamanho do vetor> <situacao do vetor> [-p] [-h]\n\n");

    printf("\tAlgoritmos:\n");
    printf("BubbleSort \t\t- \tbub\n");
    printf("BubbleSort Otimizado \t- \tbubo\n");
    printf("SelectSort \t\t- \tsel\n");
    printf("SelectSort Otimizado \t- \tselo\n");
    printf("InsertSort \t\t- \tins\n");
    printf("InsertSort Otimizado \t- \tinso\n");
    printf("ShellSort \t\t- \tshell\n");
    printf("QuickSort \t\t- \tqui\n");
    printf("HeapSort \t\t- \theap\n");
    printf("MergeSort \t\t- \tmerge\n\n");

    printf("\tTamanho do vetor:\n");
    printf("0 - %d\n\n", INT_MAX);

    printf("\tSituacao do vetor:\n");
    printf("Ordenado \t- \tordc\n");
    printf("Invertido \t- \tordi\n");
    printf("Aleatorio \t- \tale\n");
    printf("Quase ordenado \t- \tqord\n\n");

    printf("Verboso \t- \t-p\n\n");

}
