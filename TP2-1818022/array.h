#ifndef __ARRAY__
#define __ARRAY__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int key;
}TItem;

typedef struct{
	TItem* item;
	int n;
}TArray;

int isSorted(TArray*);
void allocateArray(TArray*, int);
void generateSorted(TArray*, int);
void generateInvert(TArray*,int);
void generateRandom(TArray*, int);
void generateRandomNoRep(TArray*, int);
void generateAlmostSorted(TArray*,int);
void generateAlmostSortedNoRep(TArray*,int);
void printArray(TArray*);
void freeArray(TArray*);
void printHelp();


#endif // __ARRAY__
