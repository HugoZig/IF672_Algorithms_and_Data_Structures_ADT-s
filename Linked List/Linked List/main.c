#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int element;
    struct Link *next;
} Link;

typedef struct{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;
} List;


Link* createHead (Link *nextVal);

Link* createLink (int it, Link *nextVal);

List* createList (void);

void insert (List* l, int it);

void moveToStart (List* l);

void moveToEnd (List* l);

void prev (List* l);

void next (List* l);

int remoove (List* l);

void getFree(List* l);

void display(List* l);

int main (){
    List* list = NULL;
    int choice = 0;
    int number;
    
    do {
        printf("How can I help you?\n\n");
        printf("1....Create Linked List\n");
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
                list = createList();
                break;
            case 2:
                printf("What number would you like to add? ");
                scanf("%d", &number);
                insert(list, number);
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
                number = remoove(list);
                printf("%d was removed\n", number);
                break;
            case 8:
                printf("Goodbye!!!\n");
                choice = -1;
                break;
            default:
                printf("Wrong command, please try again\n");
                break;
        }
        display(list);
        printf("\n\n\n");
    } while (choice != -1);
    
    getFree(list);
    
    return 0;
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


Link* createLink (int it, Link *nextVal){
    Link* n =(Link*) malloc(sizeof(Link));
    if (n == NULL) {
        printf("problem at createLink function\n");
        exit(1);
    }
    n->element = it;
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
    l->curr->next = createLink(it, l->curr->next);
    if (l->curr == l->tail) {
        l->tail = l->curr->next;
    }
    (l->cnt)++;
}


void moveToStart(List* l){
    l->curr = l->head;
}

void moveToEnd(List* l){
    l->curr = l->tail;
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


void next(List* l){
    if (l->curr == l->tail) {
        return;
    }
    l->curr = l->curr->next;
}


int remoove(List* l){
    Link* holder;
    holder = l->curr->next;
    if (l->curr->next == NULL) {
        return -1;
    }
    int it = holder->element;
    if (l->tail == l->curr->next) {
        l->tail = l->curr;
    }

    l->curr->next = holder->next;
    (l->cnt)--;
    free(holder);
    return it;

}

void getFree(List* l){
    Link *temp = l->head;
    l->head = l->head->next;
    free(temp);
    if (l->head == NULL) {
        return;
    }
}


void display(List* l){
    if (l->cnt == 0) {
        return;
    }
    Link *temp = l->head->next;
    for (int i = 0; i < l->cnt; i++) {
        printf("%d ", temp->element);
        temp = temp->next;
    }
}
