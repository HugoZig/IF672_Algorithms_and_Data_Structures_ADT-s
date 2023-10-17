#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int element;
    struct Link *next;
} Link;

typedef struct{
    Link* front;
    Link* rear;
    int size;
} Queue;


Queue* createQueue(void);

void enqueue(Queue* q, int it);

int dequeue(Queue* q);

void getFree(Queue* l);

void display(Queue* l);

Link* createLink (int it, Link *nextVal);

Link* createHead (Link *nextVal);

int frontValue(Queue* q);

int main (){
    Queue* queue = NULL;
    int choice = 0;
    int number;
    
    do {
        printf("How can I help you?\n\n");
        printf("1....Create Linked Stack\n");
        printf("2....Insert Number\n");
        printf("3....Remove\n");
        printf("4....Front Value\n");
        printf("5....Leave\n");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                queue = createQueue();
                break;
            case 2:
                printf("What number would you like to add? ");
                scanf("%d", &number);
                enqueue(queue, number);
                break;
            case 3:
                number = dequeue(queue);
                printf("%d was removed\n", number);
                break;
            case 4:
                number = frontValue(queue);
                printf("The front value is %d\n", number);
                break;
            case 5:
                printf("Goodbye!!!\n");
                choice = -1;
                break;
            default:
                printf("Wrong command, please try again\n");
                break;
        }
        display(queue);
        printf("\n\n\n");
    } while (choice != -1);
    
    getFree(queue);
    
    return 0;
}









Queue* createQueue(void){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("problem ate createQueue function\n");
        exit(1);
    }
    q->front = q->rear = createHead(NULL);
    q->size = 0;
    return q;
}


void enqueue(Queue* q, int it){
    q->rear->next = createLink(it, NULL);
    q->rear = q->rear->next;
    (q->size)++;
}


int dequeue(Queue* q){
    if (q->size == 0) {
        printf("error at dequeue function\n");
        exit(1);
    }
    Link* holder = q->front->next;
    int it = holder->element;
    q->front->next = holder->next;
    if (q->front->next == NULL) {
        q->rear = q->front;
    }
    free(holder);
    (q->size)--;
    return it;
}

void getFree(Queue* q){
    Link *temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        return;
    }
}


void display(Queue* q){
    if (q->size == 0) {
        return;
    }
    Link *temp = q->front->next;
    for (int i = 0; i < q->size; i++) {
        printf("%d ", temp->element);
        temp = temp->next;
    }
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

Link* createHead (Link *nextVal){
    Link* n = (Link*) malloc(sizeof(Link));
    if (n == NULL) {
        printf("problem at createHead function\n");
        exit(1);
    }
    n->next = nextVal;
    return n;
}

int frontValue(Queue* q){
    Link* temp = q->front->next;
    return temp->element;
}
