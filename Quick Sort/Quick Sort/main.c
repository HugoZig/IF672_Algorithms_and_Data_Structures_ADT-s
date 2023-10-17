#include <stdio.h>
#include <stdlib.h>

void quickSort(int* A, int l, int r);

int hoarePartition(int* A, int l, int r);

void swap(int* a, int* b);


int main (){
    int choice, number, counter = 0;
    int* array = (int*) malloc(sizeof(int));
    do {
        printf("What would you like to do:\n");
        printf("1....Add number\n");
        printf("2....QuickSort!\n");
        printf("3....Leave\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Insert the number: ");
            scanf("%d", &number);
            if (counter == 0) {
                array[counter] = number;
            }
            else{
                array = realloc(array, (sizeof(int)*(counter + 1)));
                array[counter] = number;
            }
            counter++;
        }
        if (choice == 2) {
            quickSort(array, 0, counter-1);
            for (int i = 0; i < counter; i++) {
                printf("%d\n", array[i]);
            }
        }
        if (choice == 3) {
            choice = -1;
        }
    } while (choice != -1);
    free(array);
}



void quickSort(int* A, int l, int r){
    if (l < r) {
        int s = hoarePartition(A, l, r);
        quickSort(A, l, s-1);
        quickSort(A, s+1, r);
    }
}

int hoarePartition(int* A, int l, int r){
    int p = A[l];
    int i = l;
    int j = r+1;
    
    do {
        do {
            i += 1;
        } while (A[i] < p && i < r);
        do {
            j -= 1;
        } while (A[j] > p);
        swap(&A[i], &A[j]);
    } while (i < j);
    
    swap(&A[i], &A[j]);
    swap(&A[l], &A[j]);
    return j;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
