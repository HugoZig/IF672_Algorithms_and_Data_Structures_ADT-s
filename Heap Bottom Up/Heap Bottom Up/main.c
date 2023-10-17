#include <stdio.h>
#include <stdlib.h>

void HeadBottomUp(int* H, int size);


int main(){
    int size = 10;
    int* heap = (int*) malloc(size * sizeof(int));
    int i;
    
    for (i = 0; i < size; i++) {
        scanf("%d", &heap[i]);
    }
    HeadBottomUp(heap, size);
    
    for (i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
}





void HeadBottomUp(int* H, int n){
    int i;
    for (i = n/2; i > 1; i++) {
        int k = i; int v = H[k];
        _Bool heap = 0;
        while (!heap && 2*k <= n) {
            int j = 2*k;
            if (j<n) {
                if (H[j] < H[j+1]) {
                    j += 1;
                }
            }
            if (v >= H[j]) {
                heap = 1;
            }
            else{
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

