#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* A, int l, int r);

void merge(int* A, int l, int r);


int main (){
    int choice, number, counter = 0;
    int* array = (int*) malloc(sizeof(int));
    do {
        printf("What would you like to do:\n");
        printf("1....Add number\n");
        printf("2....Merge!\n");
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
            mergeSort(array, 0, counter-1);
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



void mergeSort(int* A, int l, int r){
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, r);
    }
}

void merge(int* A, int l, int r){
    int i;
    int m = (l+r)/2;
    int i1 = l;
    int i2 = m+1;
    int curr;
    
    int temp[r+1];
    for (i = l; i <= r; i++) {
        temp[i] = A[i];
    }
    
    for (curr = l; curr <= r; curr++) {
        if (i1 == m+1) {
            A[curr] = temp[i2++];
        }
        else if (i2 > r){
            A[curr] = temp[i1++];
        }
        else if (temp[i1] <= temp[i2]){
            A[curr] = temp[i1++];
        }
        else A[curr] = temp[i2++];
    }
}
