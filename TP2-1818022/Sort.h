#ifndef __SORT__
#define __SORT
#include "array.h"

void bubbleSort(TArray*,unsigned long long*,unsigned long long*);
void bubbleSortO(TArray*,unsigned long long*,unsigned long long*);

void selectSort(TArray*,unsigned long long*,unsigned long long*);
void selectSortO(TArray*,unsigned long long*,unsigned long long*);

void insertionSort(TArray*,unsigned long long*,unsigned long long*);
void insertionSortO(TArray*,unsigned long long*,unsigned long long*);

void shellSort(TArray*,unsigned long long*,unsigned long long*);
void quickSort(TArray*,unsigned long long*,unsigned long long*);
void heapSort(TArray*,unsigned long long*,unsigned long long*);
void mergeSort(TArray*,unsigned long long*,unsigned long long*);
void radixsort(TArray*,unsigned long long*, unsigned long long*);
void bogosort(TArray*,unsigned long long*, unsigned long long*);
int isSortedBogo(TArray *pA, unsigned long long *comp);

//Quicksort
void ordena(TArray *A, int esq, int dir, unsigned long long *att, unsigned long long *comp);
void particao(TArray *A, int esq, int dir, int *i, int *j, unsigned long long *att, unsigned long long *comp);

//Heapsort
void refaz(TArray* pA, int esq, int dir);
void constroi(TArray *pA);

//Mergesort
void mergeSortIntercala(TItem *v, int esq, int meio, int dir, unsigned long long *att, unsigned long long *comp);

#endif // __SORT__
