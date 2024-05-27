#include <stdio.h>
#include <stdlib.h>

void countingsort(int *v, int n);
int max(int *v, int n);

int main()
{
    int v[7] = {2,5,1,9,7,6,3};
    printf("vetor desordenada: ");
    for(int i = 0; i <= 6; i++){
        printf("%d ", v[i]);
    }
    countingsort(v, 7);
    printf("\nvetor ordenada: ");
    for(int i = 0; i <= 6; i++){
        printf("%d ", v[i]);
    }
    return 0;
}

void countingsort(int *v, int n){
    int maxi, i;
    maxi = max(v, n);
    int a[maxi], b[n];
    maxi++;
    for(i = 0; i < maxi; i++){
        a[i] = 0;
    }
    for(i = 0; i != n; i++){
        a[v[i]]++;
    }
    for(i = 1; i < maxi; i++){
        a[i+1] = a[i] + a[i+1];
    }
    for(i = 0; i < n; i++){
        b[a[v[i]]] = v[i];
        a[v[i]] -= 1;
    }
    for(i = 0; i < n; i++){
        v[i] = b[i+1];
    }
}

int max(int *v, int n){
    int i, maxi;
    for(i = 0; i < n; i++){
        if(i == 0){
            maxi = v[i];
        }
        else{
            if(maxi <= v[i]){
                maxi = v[i];
            }
        }
    }
    return maxi;
}
