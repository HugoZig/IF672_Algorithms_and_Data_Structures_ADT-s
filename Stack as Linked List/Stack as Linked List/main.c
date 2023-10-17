#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int element;
    struct Link *next;
} Link;


typedef struct{
    Link* top;
    int size;
} Stack;

Link* createLink (int it, Link *nextVal);

Stack* createStack(void);

void push(Stack* s, int it);

int pop(Stack* s);

void getFree(Stack* s);

void display(Stack* s);

int topValue(Stack* s);


int main (){
    Stack* stack = NULL;
    int choice = 0;
    int number;
    
    do {
        printf("How can I help you?\n\n");
        printf("1....Create Linked Stack\n");
        printf("2....Insert Number\n");
        printf("3....Remove\n");
        printf("4....Top Value\n");
        printf("5....Leave\n");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                stack = createStack();
                break;
            case 2:
                printf("What number would you like to add? ");
                scanf("%d", &number);
                push(stack, number);
                break;
            case 3:
                number = pop(stack);
                printf("%d was removed\n", number);
                break;
            case 4:
                number = topValue(stack);
                printf("The top value is: %d\n", number);
                break;
            case 5:
                printf("Goodbye!!!\n");
                choice = -1;
                break;
            default:
                printf("Wrong command, please try again\n");
                break;
        }
        display(stack);
        printf("\n\n\n");
    } while (choice != -1);
    
    getFree(stack);
    
    return 0;
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

Stack* createStack(void) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s == NULL) {
        printf("problem at createStack function\n");
        exit(1);
    }
    s->top = NULL;
    s->size = 0;
    return s;
}


void push(Stack* s, int it){
    s->top = createLink(it , s->top);
    (s->size)++;
}


int pop(Stack* s){
    int it;
    if (s->top == NULL) {
        printf("error at pop function\n");
        exit(1);
    }
    Link *aux = s->top;
    it = s->top->element;
    s->top = s->top->next;
    free(aux);
    (s->size)--;
    
    return it;
}


void getFree(Stack* s){
    if (s->top == NULL) {
        printf("error at pop function\n");
        exit(1);
    }
    Link *temp = s->top;
    s->top = s->top->next;
    free(temp);
    if (s->top == NULL) {
        return;
    }
}

void display(Stack* s){
    if (s->size == 0) {
        return;
    }
    Link *temp = s->top;
    for (int i = 0; i < s->size; i++) {
        printf("%d ", temp->element);
        temp = temp->next;
    }
}


int topValue(Stack* s){
    return s->top->element;
}
