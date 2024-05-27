#include <stdio.h>
#include <stdlib.h>

void heapsort(int *v, int n);
void criaheap(int *v, int inicio, int fim);

int main()
{
    int v[5] = {10,2,4,12,0};
    for(int i = 0; i < 5; i++){
        printf("%d ", v[i]);
    }
    heapsort(v, 5);
    putchar('\n');
    for(int i = 0; i < 5; i++){
        printf("%d ", v[i]);
    }
    return 0;
}

void heapsort(int *v, int n){
    int i, a;
    for(i = (n - 1)/2; i >= 0; i--){
        criaheap(v, i, n-1);
    }
    for(i = n-1; i >= 1; i--){
        a = v[0];
        v[0] = v[i];
        v[i] = a;
        criaheap(v, 0, i-1);
    }
}

void criaheap(int *v, int i, int fim){
    int a = v[i], f = i * 2 + 1;
    while(f <= fim){
        if(f < fim){
            if(v[f] < v[f+1]){
                f++;
            }
        }
        if(a < v[f]){
            v[i] = v[f];
            i = f;
            f = i * 2 + 1;
        }
        else{
            f = fim + 1;
        }
    }
    v[i] = a;
}



