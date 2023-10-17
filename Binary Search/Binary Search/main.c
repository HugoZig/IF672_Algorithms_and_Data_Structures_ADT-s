#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* A, int l, int r, int k);

int main (){
    int choice, number, counter = 0;
    int* array = (int*) malloc(sizeof(int));
    do {
        printf("What would you like to do:\n");
        printf("1....Add number (must be bigger then before)\n");
        printf("2....Binary Search!\n");
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
            printf("Insert the number you want to search: ");
            scanf("%d", &number);
            number  = binarySearch(array, 0, counter-1, number);
            printf("%d\n", number);
        }
        if (choice == 3) {
            choice = -1;
        }
    } while (choice != -1);
    free(array);
}




int binarySearch(int* A, int l, int r, int k){
    if (r >= l) {
        int m = (l+r)/2;
        if (k == A[m]) {
            return m;
        }
        else if (k < A[m]){
            return binarySearch(A, l, m-1, k);
        }
        else
            return binarySearch(A, m+1, r, k);
    }
    else return -1;
}
