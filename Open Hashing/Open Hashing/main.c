#include <stdio.h>
#include <stdlib.h>
#define M 10;

typedef struct{
    int value;
} Element;

typedef struct{
    int key;
    Element* data;
} Pair;

typedef struct{
    Pair element;
    struct Link *next;
} Link;

typedef struct{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;
} List;

typedef struct{
    int m;
    int cnt;
    List** H;
    int (*h)(int K);
}Dictionary;

int hash(int K);

Dictionary* create_dict(int size, int (*h)(int K));

Link* createHead (Link *nextVal);

Link* createLink (int it, Link *nextVal);

List* createList (void);

void insertD(Dictionary* d, int k, int e);

int find(Dictionary* d, int Key);

void insert(List* l, int it);

void displayD(Dictionary* d, int size);

void sizeD(Dictionary* d);

void display(List* l);

void next(List* l);

void remoove(List* l);

void removeD(Dictionary* d, int Key);

void prev(List* l);

int main(){

    Dictionary* dictionary = NULL;
    int choice = 0;
    int number;
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
            printf("What number would you like to add? ");
            scanf("%d", &number);
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
            scanf("%d", &number);
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

int hash(int K){
    return abs(K)%M;
}


Dictionary* create_dict(int size, int (*h)(int K)){
    int i;
    Dictionary* d = (Dictionary*) malloc(sizeof(Dictionary));
    if (d == NULL) {
        printf("problem at create_dict function\n");
        exit(1);
    }
    d->m = size; d->cnt = 0; d->H = (List**) malloc(size* sizeof(List*));
    if (d->H == NULL) {
        printf("problem at create_dict2 function\n");
        exit(1);
    }
    for (i = 0; i < size; i++) {
        d->H[i] = createList();
    }
    d->h = &hash;
    return d;
}

void insertD(Dictionary* d, int k, int e){
    if (!find(d,k)) {
        int pos = d->h(k);
        List* temp = d->H[pos];
        insert(temp, e);
        d->cnt++;
    }
}


int find(Dictionary* d, int Key){
    int i = 0;
    int h = hash(Key);
    Link* holder = d->H[h]->head;
    while (holder->element.key != Key && holder == NULL) {
        holder = holder->next;
    }
    if (holder->element.key == Key) {
        return 1;
    }
    else return 0;
}

void displayD(Dictionary* d, int size){
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", i);
        display(d->H[i]);
        printf("\n");
    }
}

void sizeD(Dictionary* d){
    printf("The Hash tables has %d Lists and %d numbers\n", d->m, d->cnt);
}

void removeD(Dictionary* d, int Key){
    int temp = hash(Key);
    Link* holder = d->H[temp]->head;
    while (holder->element.key != Key) {
        holder = holder->next;
    }
    d->H[temp]->curr = holder;
    prev(d->H[temp]);
    remoove(d->H[temp]);
}


void display(List* l){
    int i;
    if (l->cnt == 0) {
        return;
    }
    Link *temp = l->head->next;
    for (i = 0; i < l->cnt; i++) {
        printf("%d ", temp->element.key);
        temp = temp->next;
    }
}

Link* createLink (int it, Link *nextVal){
    Link* n =(Link*) malloc(sizeof(Link));
    if (n == NULL) {
        printf("problem at createLink function\n");
        exit(1);
    }
    n->element.data = (Element*) malloc(sizeof(Element));
    n->element.data->value = it;
    n->element.key = it;
    n->next = nextVal;
    return n;
}


List* createList (void){
    List* l = (List*) malloc(sizeof(List));
    if (l == NULL) {
        printf("problem at createList function\n");
        exit(1);
    }
    l->curr = l->tail = l->head = createHead(NULL);
    l->cnt = 0;
    return l;
}

void insert(List* l, int it){
    next(l);
    l->curr->next = createLink(it, l->curr->next);
    if (l->curr == l->tail) {
        l->tail = l->curr->next;
    }
    (l->cnt)++;
}

Link* createHead (Link *nextVal){
    Link* n = (Link*) malloc(sizeof(Link));
    if (n == NULL) {
        printf("problem at createHead function\n");
        exit(1);
    }
    n->next = nextVal;
    return n;
}

void next(List* l){
    if (l->curr == l->tail) {
        return;
    }
    l->curr = l->curr->next;
}

void remoove(List* l){
    Link* holder;
    holder = l->curr->next;
    if (l->curr->next == NULL) {
        return;
    }
    if (l->tail == l->curr->next) {
        l->tail = l->curr;
    }

    l->curr->next = holder->next;
    (l->cnt)--;
    free(holder);
}

void prev(List* l){
    if (l->curr == l->head) {
        return;
    }
    Link *temp = l->head;
    while (temp->next != l->curr) {
        temp = temp->next;
    }
    l->curr = temp;
}
