#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10;

typedef struct{
    char string[15];
} Element;

typedef struct{
    Element* element;
    _Bool deleted;
    _Bool empty;
    char Key[];
} Pair;

typedef struct{
    int m;
    int cnt;
    Pair* H;
    int (*h)(char K[]);
}Dictionary;


Dictionary* create_dict(int size, int (*h)(char K[]));

void insertD(Dictionary* d, char k[], char e[]);

int find(Dictionary* d, char Key[]);

void displayD(Dictionary* d, int size);

void sizeD(Dictionary* d);

void removeD(Dictionary* d, char Key[]);

void insert(Dictionary* d, int pos, char Key[]);

int hash(char K[]);

int main(){

    Dictionary* dictionary = NULL;
    int choice = 0;
    char number[15];
    int size = M;
do {
    printf("How can I help you?\n\n");
    printf("1....Create Hash Table\n");
    printf("2....Insert Value\n");
    printf("3....Print Table\n");
    printf("4....Table Size\n");
    printf("5....Remove value\n");
    printf("6....Leave\n");
    scanf(" %d", &choice);
    switch (choice) {
        case 1:
            dictionary = create_dict(size, hash);
            break;
        case 2:
            printf("What word would you like to add? ");
            scanf("%s", number);
            insertD(dictionary, number, number);
            break;
        case 3:
            displayD(dictionary, size);
            break;
        case 4:
            sizeD(dictionary);
            break;
        case 5:
            printf("What number would you like to remove? ");
            scanf("%s", number);
            removeD(dictionary, number);
            break;
        case 6:
            printf("Goodbye!!!\n");
            choice = -1;
            break;
        default:
            printf("Wrong command, please try again\n");
            break;
    }
    displayD(dictionary, size);
    printf("\n");
} while (choice != -1);

    
return 0;
}

int hash(char K[]){
    int s = strlen(K);
    int i, sum = 0;
    for (i = 0; sum < s;) {
        sum += sum + K[i];
    }
    return abs(sum)%M;
}


Dictionary* create_dict(int size, int (*h)(char K[])){
    Dictionary* d = (Dictionary*) malloc(sizeof(Dictionary));
    if (d == NULL) {
        printf("problem at create_dict function\n");
        exit(1);
    }
    d->m = size; d->cnt = 0; d->H = (Pair*) calloc(size, sizeof(Pair)); d->h = hash;
    int i;
    for (i = 0; i < d->m; i++) {
        d->H[i].empty = 1;
        d->H[i].deleted = 0;
        d->H[i].element = (Element*) malloc(sizeof(Element));
    }
    return d;
}

void insertD(Dictionary* d, char k[], char e[]){
    if (d->cnt < d->m && -1 == find(d, k)) {
        int pos = d->h(k);
        int i = 0;
        if (d->H[pos].empty == 0) {
            do {
                i+=1;
                pos = (pos+i)%d->m;
            } while (d->H[pos].empty == 0);
        }
        insert(d, pos, k);
        d->cnt++; d->H[pos].empty = 0;
    }
}


int find(Dictionary* d, char Key[]){
    int i = 0;
    int h = hash(Key);
    while (strcmp(d->H[h].Key, Key) != 0 && i < d->m) {
        i++;
        h = (h+1)%d->m;
    }
    if (i == d->m) {
        return -1;
    }
    else return h;
}

void displayD(Dictionary* d, int size){
    int i;
    for (i = 0; i < d->m; i++) {
        printf("%s\n", d->H[i].element->string);
    }
    printf("\n");
    
}

void sizeD(Dictionary* d){
    printf("The Hash tables has %d Lists and %d numbers\n", d->m, d->cnt);
}

void removeD(Dictionary* d, char Key[]){
    int found = find(d, Key);
    if (found != -1) {
        strcpy(d->H[found].element->string, "               ");
        d->H[found].deleted = 1;
    }
}

void insert(Dictionary* d, int pos, char Key[]){
    strcpy(d->H[pos].element->string, Key);
    strcpy(d->H[pos].Key, Key);
}
