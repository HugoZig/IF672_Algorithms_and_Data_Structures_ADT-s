#include <stdio.h>
#include <stdlib.h>


void HeadBottomUp(int* H, int size);

void swap(int* a, int* b);

int* heapSort(int* heap, int size);


int main(){
    int size;
    scanf("%d", &size);
    size += 1;
    int* heap = (int*) malloc(size * sizeof(int));
    int i;
    
    for (i = 1; i < size; i++) {
        scanf("%d", &heap[i]);
    }
    
    heap = heapSort(heap, size-1);
    
    for (i = size-2; i >= 0; i--) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}





void HeadBottomUp(int* H, int n){
    int i;
    for (i = n/2; i >= 1; i--) {
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


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int* heapSort(int* heap, int size){
    int* sorted = (int*) malloc(size* sizeof(int));
    int i = 0;
    HeadBottomUp(heap, size);
    do {
        sorted[i] = heap[1];
        swap(&heap[1], &heap[size]);
        size--; i++;
        HeadBottomUp(heap, size);
    } while (size >= 1);
    
    return sorted;
}
