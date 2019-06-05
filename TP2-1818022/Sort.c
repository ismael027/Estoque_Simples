#include "sort.h"
#include <limits.h>

void bubbleSort(TArray* pA, unsigned long long* att, unsigned long long* comp){
	TItem aux;

	for(int i = 0; i < pA->n-1; i++){
		for(int j = 1; j < pA->n-i; j++){
			(*comp)++;
			if(pA->item[j].key < pA->item[j-1].key){
				aux           = pA->item[j];
				pA->item[j]   = pA->item[j-1];
				pA->item[j-1] = aux;
				(*att) += 3;
			}
		}
	}
}

//bubbleSort Otimizado
void bubbleSortO(TArray* pA, unsigned long long* att, unsigned long long* comp){
	TItem aux;
	int troca = 0;
	for(int i = 0; i < pA->n-1; i++){
             troca = 0;
		for(int j = 1; j < pA->n-i; j++){
			(*comp)++;
			if(pA->item[j].key < pA->item[j-1].key){
				aux           = pA->item[j];
				pA->item[j]   = pA->item[j-1];
				pA->item[j-1] = aux;
				troca = 1;
				(*att) += 4;
			}
		}
        if(troca == 0) break;
	}
}

void selectSort(TArray* pA, unsigned long long* att, unsigned long long* comp){
	int min; TItem aux;

    for(int i = 0; i < pA->n - 1; i++){
        min = i;
        for(int j = i + 1; j < pA->n; j++){
            if( pA->item[j].key < pA->item[min].key){
                    min = j;
                    (*att)++;
            } (*comp)++;
        }
                aux = pA->item[min];
                pA->item[min] = pA->item[i];
                pA->item[i] = aux;
                (*att) += 3;
    }
}

void selectSortO(TArray* pA, unsigned long long* att, unsigned long long* comp){
	int min;
    TItem aux;
    for(int i = 0; i < pA->n-1; i++){
        min = i;
        for(int j = i+1; j < pA->n; j++){
            if( pA->item[j].key < pA->item[min].key){
                min = j;
                (*att)++;
            } (*comp)++;
        }

        if(i != min){
            aux = pA->item[min];
            pA->item[min] = pA->item[i];
            pA->item[i] = aux;
            (*att) += 3;
        }
        (*comp)++;
    }
}

void insertionSort(TArray* pA, unsigned long long* att, unsigned long long* comp){
    TItem aux;
    int i, j;
	for (i = 1; i < pA->n; i++) {
		aux = pA->item[i];
		j = i - 1;
		(*att)++;

		while ((j >= 0) && (aux.key < pA->item[j].key)) {
			pA->item[j + 1] = pA->item[j];
			j--;
			(*att)++;
			(*comp)++;
		}
		(*comp)++;

		pA->item[j + 1] = aux;
		(*att)++;
	}
}

void insertionSortO(TArray *pA,unsigned long long* att,unsigned long long* comp){
    int i, j;
    TItem temp, *arraySentinel = malloc((pA->n + 1) * sizeof(TItem));
    for(i = 0; i < pA->n; i++){
        arraySentinel[i+1] = pA->item[i];
        (*att)++;
    }
    arraySentinel[0].key = INT_MIN;
    (*att)++;

    for (i = 1; i < (pA->n + 1); i++) {
            temp = arraySentinel[i];
            j = i;
            (*att) += 2;
            while (arraySentinel[j - 1].key > temp.key) {
                arraySentinel[j] = arraySentinel[j - 1];
                j--;
                (*att)++;
                (*comp)++;
            }
            arraySentinel[j] = temp;
            (*att)++;
    }

    for (int i = 1; i < (pA->n + 1); i++){
        pA->item[i-1] = arraySentinel[i];
        (*att)++;
    }
}

void shellSort(TArray* pA,unsigned long long* att,unsigned long long* comp){
	int i, j, h = 1;
	TItem aux;
	do {
        h = h * 3 + 1;
        (*att)++;
        (*comp)++;
    } while(h < pA->n);
	do{
        h /= 3;
        (*att)++;
        for(i = h; i < pA->n; i++){
            aux = pA->item[i]; j = i;
            (*att) += 2;
            while(pA->item[j - h].key > aux.key){
                pA->item[j] = pA->item[j-h]; j-=h;
                (*att) += 2;
                (*comp)+= 2;
                if(j<h){ break;}
            }
            pA->item[j] = aux;
            (*att)++;
        }
        (*comp)++;
	} while(h != 1);
}

void quickSort(TArray* pA, unsigned long long* att, unsigned long long* comp){
	ordena(pA, 0, (pA->n) - 1, att, comp);
}

void heapSort(TArray *pA, unsigned long long* att,unsigned long long* comp){
   int i = pA->n / 2, pai, filho;
   int n = pA->n;
   TItem t;
   while(1 < 2) {
      if (i > 0) {
          i--;
          t = pA->item[i];
      } else {
          (pA->n)--;
          if (pA->n == 0){
            pA->n = n;
            return;
          }
          t = pA->item[pA->n];
          pA->item[pA->n] = pA->item[0];
          (*att) += 3;
          (*comp)++;
      }
      (*comp)++;

      pai = i;
      filho = i * 2 + 1;
      (*att)+=2;
      while (filho < pA->n) {
          if ((filho + 1 < pA->n) && (pA->item[filho + 1].key > pA->item[filho].key)){
              filho++;
              (*att)++;
          }
          if (pA->item[filho].key > t.key) {
             pA->item[pai] = pA->item[filho];
             pai = filho;
             filho = pai * 2 + 1;
             (*att) += 3;
          } else {
             break;
          }
          (*comp) += 2;
      }
      pA->item[pai] = t;
      (*att)++;
   }
}

void mergeSort(TArray *A,unsigned long long *att,unsigned long long *comp){
    int esq, dir;
    int b = 1;
    int n = A->n;
    (*att) += 2;

    while(b < n){
        esq = 0;
        while(esq + b < n){
            dir = esq + 2 * b;
            if(dir>n){
                dir = n;
                (*att)++;
            }
            (*att)++;
            (*comp)++;
            mergeSortIntercala(A->item, esq, esq+b-1, dir-1, att, comp);
            esq = esq + 2 * b;
        }
        b *= 2;
        (*att)++;
        (*comp)++;
    }
}

void mergeSortIntercala(TItem *v, int esq, int meio, int dir, unsigned long long *att, unsigned long long *comp){
    int i, j, k;
    int a_tam = meio-esq+1;
    int b_tam = dir-meio;

    TItem *a = (TItem *) malloc(sizeof(TItem) * a_tam);
    TItem *b = (TItem *) malloc(sizeof(TItem) * b_tam);

    (*att) += 4;

    for (i = 0; i < a_tam; i++){ a[i] = v[i+esq]; (*att)++; (*comp)++;}
    for (i = 0; i < b_tam; i++){ b[i] = v[i+meio+1]; (*att)++; (*comp)++;}

    for (i = 0, j = 0, k = esq; k <= dir; k++){
        if (i == a_tam){
            v[k] = b[j++]; (*att)++; (*comp)++;
        }
        else if (j == b_tam) {
            v[k] = a[i++]; (*att)++; (*comp)+=2;
        }
        else if (a[i].key < b[j].key) {
            v[k] = a[i++]; (*att)++; (*comp)+=3;
        }
        else {
            v[k] = b[j++]; (*att)++; (*comp)+=4;
        }
    }
    free(a);
    free(b);
}

void particao(TArray *A, int esq, int dir, int *i, int *j, unsigned long long *att, unsigned long long *comp){
     TItem x, aux;
     *i = esq; *j = dir;
     x = A->item[(*i + *j)/2];

     do{
        while(x.key > A->item[*i].key){
                (*i)++;
                (*comp)++;
        }
        while(x.key < A->item[*j].key){
                (*j)--;
                (*comp)++;
        }
         (*comp)++;
         if(*i <= *j){
            aux = A->item[*i];
            A->item[*i] = A->item[*j];
            A->item[*j] = aux;

            (*i)++;
            (*j)--;

            (*att) += 3;
         }
         (*comp)++;
     }while(*i <= *j);
}

void ordena(TArray *A, int esq, int dir, unsigned long long *att, unsigned long long *comp){
    int i, j;
    particao(A, esq, dir, &i, &j, att, comp);
    if(esq < j ) ordena(A, esq, j , att, comp);
    if(i < dir) ordena(A, i, dir, att, comp);
}

void radixsort(TArray *pA, unsigned long long *att, unsigned long long *comp) {
    int i;
    TItem *b;
    TItem maior = pA->item[0];
    int exp = 1;

    b = (TItem *)calloc(pA->n, sizeof(TItem));

    for (i = 0; i < pA->n; i++){
            (*comp)++;
        if (pA->item[i].key > maior.key){
    	    maior = pA->item[i];
            (*att)++;
        }
    }

    while (maior.key/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < pA->n; i++){
    	    bucket[(pA->item[i].key / exp) % 10]++;
    	    (*comp)++;
    	    (*att)++;
    	}
    	for (i = 1; i < 10; i++){
    	    bucket[i] += bucket[i - 1];
    	    (*att)++;
    	}
    	for (i = pA->n - 1; i >= 0; i--){
    	    b[--bucket[(pA->item[i].key / exp) % 10]] = pA->item[i];
            (*comp)++;
    	    (*att)++;
    	}
    	for (i = 0; i < pA->n; i++){
    	    pA->item[i] = b[i];
            (*comp)++;
    	    (*att)++;
    	}
    	exp *= 10;
    	(*att)++;
    	(*comp)++;
    }

    free(b);
}



