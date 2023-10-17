#include <stdio.h>
#include <stdlib.h>

void Heapify(int* H, int size);

void removeTop(int* heap, int size);

void printHeap(int* heap, int size);

void swap(int* a, int* b);


int main(){
    int size = 1;
    int choice;
    int* heap = (int*) malloc(size * sizeof(int));
    do {
        printf("What would you like to do:\n");
        printf("1.....Insert number\n");
        printf("2.....Max value\n");
        printf("3.....Remove top value\n");
        printf("5.....Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                size++;
                heap = (int*) realloc(heap, size*sizeof(int));
                scanf("%d", &heap[size-1]);
                Heapify(heap, size-1);
                break;
            case 2:
                if (size == 1) {
                    printf("the array is empty\n");
                    break;
                }
                printf("The Max value is: %d\n", heap[1]);
                break;
            case 3:
                if (size == 1) {
                    printf("the array is empty\n");
                    break;
                }
                printf("%d will be removed\n", heap[1]);
                removeTop(heap, size-1);
                size--;
                Heapify(heap, size-1);
                break;
            case 5:
                break;
            default:
            printf("Wrong command, please try again!\n");
                break;
        }
    } while (choice !=5);
    
    
}





void Heapify(int* H, int n){
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


void removeTop(int* heap, int size){
    swap(&heap[1], &heap[size]);
    heap = (int*) realloc(heap, (size)*sizeof(int));
}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
