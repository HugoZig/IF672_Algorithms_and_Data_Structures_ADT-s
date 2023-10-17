#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int maxSize;
    int listSize;
    int curr;
    int *listArray;
} Alist;

Alist* createList (int size);

void insert (Alist* l, int it);

void moveToStart (Alist* l);

void moveToEnd (Alist* l);

void prev (Alist* l);

void next (Alist* l);

int remoove (Alist*);


int main (){
    Alist* list = NULL;
    int choice = 0;
    int size;
    
    do {
        printf("How can I help you?\n\n");
        printf("1....Create Array\n");
        printf("2....Insert Number\n");
        printf("3....Move to Start\n");
        printf("4....Move to End\n");
        printf("5....Previous\n");
        printf("6....Next\n");
        printf("7....Remove\n");
        printf("8....Leave\n");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                printf("What will be the size of the list?\n");
                scanf("%d", &size);
                list = createList(size);
                break;
            case 2:
                printf("What number would you like to add? ");
                scanf("%d", &size);
                insert(list, size);
                break;
            case 3:
                moveToStart(list);
                break;
            case 4:
                moveToEnd(list);
                break;
            case 5:
                prev(list);
                break;
            case 6:
                next(list);
                break;
            case 7:
                size = remoove(list);
                printf("%d was removed\n", size);
                break;
            case 8:
                printf("Goodbye!!!\n");
                choice = -1;
                break;
            default:
                printf("Wrong command, please try again\n");
                break;
        }
        for (int i = 0; i < list->listSize; i++) {
            printf("%d ", list->listArray[i]);
        }
        printf("\n\n\n");
    } while (choice != -1);
    
    free(list);
    
    return 0;
}



Alist* createList (int size){
    Alist* l= (Alist*) malloc(sizeof(Alist));
    l->maxSize = size;
    l->curr = l->listSize = 0;
    l->listArray = (int*)malloc(sizeof(int));
    if (l->listArray == NULL) {
        printf("erro at create list\n");
        exit(1);
    }
    
    return l;
}


void insert(Alist* l, int it){
    if (l->maxSize <= l->listSize) {
        printf("array overloaded\n");
        exit(1);
    }
    
    for (int i = l->listSize; i > l->curr; i--) {
        l->listArray[i] = l->listArray[i-1];
    }
    l->listArray[l->curr] = it;
    l->listSize++;
}

void moveToStart(Alist* l){
    l->curr = 0;
}


void moveToEnd(Alist* l){
    l->curr = (l->listSize -1);
}


void prev(Alist* l){
    if (l->curr != 0) {
        (l->curr)--;
    }
}


void next(Alist* l){
    if ((l->curr)+1 < l->listSize) {
        (l->curr)++;
    }
}

int remoove (Alist* l){
    int it;
    if (l->curr < 0 || l->curr >= l->listSize) {
        printf("error at remove\n");
        exit(1);
    }
    it = l->listArray[l->curr];
    for (int i = l->curr; i < l->listSize-1; i++) {
        l->listArray[i] = l->listArray[i+1];
    }
    (l->listSize)--;
    return it;
}
