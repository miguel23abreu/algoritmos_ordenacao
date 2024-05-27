#include <stdio.h>
#include <stdlib.h>

void mergesort(int *v, int inicio, int fim);
void sort(int *v, int inicio, int meio, int fim);

int main()
{
    int v[7] = {2,3,1,5,9,8,6};
    int i;
    printf("vetor desordenado: ");
    for(i = 0; i < 7; i++){
        printf("%d", v[i]);
    }
    putchar('\n');
    mergesort(v, 0, 7);
    printf("vetor ordenado: ");
    for(i = 0; i < 7; i++){
        printf("%d", v[i]);
    }
    return 0;
}

int maxVetor(int *v, int n){
    mergesort(v, 0, n);
    return v[n-1];
}

void mergesort(int *v, int inicio, int fim){
    if(inicio >= fim){
        return;
    }
    int meio = (inicio+fim)/2;
    mergesort(v, inicio ,meio);
    mergesort(v, meio+1, fim);
    sort(v, inicio, meio, fim);
}

void sort(int *v, int inicio, int meio, int fim){
    int i = inicio, j = meio+1, a;
    int *c = malloc(sizeof(int) * fim);
    for(a = 0; a <= fim; a++){
        c[a] = v[a];
    }
    a = inicio;
    while(i <= meio && j <= fim){
        if(c[i] <= c[j]){
            v[a++] = c[i++];
        }
        else{
            v[a++] = c[j++];
        }
    }
    while(i <= meio){
        v[a++] = c[i++];
    }
    while(j <= fim){
        v[a++] = c[j++];
    }
    free(c);
}
