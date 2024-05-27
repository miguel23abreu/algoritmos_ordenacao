#include <stdio.h>
#include <stdlib.h>

void quicksort(int *lista, int inicio, int fim);
int partition(int *lista, int inicio, int fim);

int main(){
    int lista[5] = {5,2,4,3,1};
    int i;
    printf("lista desordenada: ");
    for(i = 0; i < 5; i++){
        printf("%d ", lista[i]);
    }
    putchar('\n');
    printf("lista ordenada: ");
    quicksort(lista, 0, 5);
    for(i = 0; i < 5; i++){
        printf("%d ", lista[i]);
    }

    return 0;
}

void quicksort(int *lista,int inicio, int fim){
    if(inicio < fim){
        int p = partition(lista, inicio, fim);
        quicksort(lista, inicio, p-1);
        quicksort(lista, p+1, fim);
    }
}

int partition(int *lista, int inicio, int fim){
    //int pivo = lista[fim];
    int e = fim, d = inicio, i, a;
    for(i = inicio+1; i < fim; i++){
        if(lista[i] < lista[inicio]){
            d++;
            a = lista[i];
            lista[i] = lista[d];
            lista[d] = a;
        }
    }
    a = lista[inicio];
    lista[inicio] = lista[d];
    lista[d] = a;
    return a;
}


