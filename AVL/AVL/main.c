#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int key;
    int element;
    int height;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct{
    BSTNode* root;
    int nodecount;
} BST;

BSTNode* create_bstnode(int k, int e);

BST* create_bst(void);

int find(BST* bst, int k);

int findhelp(BSTNode* rt, int k);

void insert(BST* bst, int k, int e);

int remove_bstnode(BST* bst, int k);

BSTNode* removehelp(BSTNode* rt, int k);

BSTNode* inserthelp(BSTNode* rt, int k, int e);

BSTNode* getmin(BSTNode* rt);

BSTNode* deletemin(BSTNode* rt);

void pre_order(BSTNode* rt);

void in_order(BSTNode* rt);

void pos_order(BSTNode* rt);

int getBalance(BSTNode* rt);

int h(BSTNode* rt);

int max(int a, int b);

BSTNode* leftRotate(BSTNode* rt);

BSTNode* rightRotate(BSTNode* rt);

int main(){
    int option, key, element;
    BST* bst = create_bst();
    do {
        printf("What would you like to do:\n");
        printf(".....1 Insert value\n");
        printf(".....2 Remove value\n");
        printf(".....3 Preorder!\n");
        printf(".....4 Inorder!\n");
        printf(".....5 Posorder!\n");
        printf(".....6 BST size\n");
        printf(".....7 Quit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("What is the key of the element:");
                scanf("%d", &key);
                printf("What is the element:");
                scanf("%d", &element);
                insert(bst, key, element);
                break;
            case 2:
                printf("What is the key of the element you want to remove:");
                scanf("%d", &key);
                remove_bstnode(bst, key);
                break;
            case 3:
                pre_order(bst->root);
                break;
            case 4:
                in_order(bst->root);
                break;
            case 5:
                pos_order(bst->root);
                break;
            case 6:
                printf("%d\n", bst->nodecount);
            case 7:
                break;
            default:
                printf("wrong command, try again\n");
                break;
        }
    } while (option != 7);
}
 
BSTNode* create_bstnode(int key, int element){
    BSTNode* n = (BSTNode*) malloc(sizeof(BSTNode));
    if (n == NULL) {printf("error at create_bstnode function\n"); exit(1);}
    n->key = element; n->height = -1; n->element = element; n->left = n->right = NULL;
    return n;
}


BST* create_bst(void){
    BST* bst = (BST*) malloc(sizeof(BST));
    if (bst == NULL) {printf("error at create_bst function\n"); exit(1);}
    bst->nodecount = 0; bst->root = NULL;
    return bst;
}


int find(BST* bst, int k){
    return findhelp(bst->root, k);
}

int findhelp(BSTNode* rt, int k){
    if (rt == NULL) {
        return -1;
    }
    if (rt->key > k) {
        return findhelp(rt->left, k);
    }
    if (rt->key == k) {
        return rt->element;
    }
    else return findhelp(rt->right, k);
}

void insert(BST* bst, int k, int e){
    bst->root = inserthelp(bst->root, k, e);
    (bst->nodecount)++;
}

BSTNode* inserthelp(BSTNode* rt, int k, int e){
    if (rt == NULL) {
        return create_bstnode(k, e);
    }
    if (rt->key > k) {
        rt->left = inserthelp(rt->left, k, e);
    }
    else rt->right = inserthelp(rt->right, k, e);
    
    rt->height = 1+max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);
    BSTNode* holder = rt->right;
    if (balance < -1 && k >= holder->key) {return leftRotate(rt);}
    if (balance > 1 && k < holder->key) {return rightRotate(rt);}
    if (balance > 1 && k >= holder->key) {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if (balance < -1 && k < holder->key) {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

int remove_bstnode(BST* bst, int k){
    int temp = findhelp(bst->root, k);
    if (temp != NULL) {
        bst->root = removehelp(bst->root, k);
        (bst->nodecount)--;
    }
    return temp;
}

BSTNode* removehelp(BSTNode* rt, int k){
    if (rt == NULL) {
        return NULL;
    }
    if (rt->key > k) {
        removehelp(rt->left, k);
    }
    else if (rt->key < k){
        removehelp(rt->right, k);
    }
    else {
        if (rt->left == NULL) {
            return rt->right;
        }
        else if (rt->right = NULL){
            return rt->left;
        }
        else{
            BSTNode* temp = getmin(rt->right);
            rt->element = temp->element;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}

BSTNode* getmin(BSTNode* rt){
    if (rt->left == NULL) {
        return rt;
    }
    return getmin(rt->left);
}

BSTNode* deletemin(BSTNode* rt){
    if (rt->left == NULL) {
        return rt->right;
    }
    rt->left = deletemin(rt->left);
    return rt;
}

void pre_order(BSTNode* rt){
    if (rt != NULL) {
        printf("%d ", rt->element);
        pre_order(rt->left);
        pre_order(rt->right);
    }
}


void in_order(BSTNode* rt){
    if (rt != NULL) {
        in_order(rt->left);
        printf("%d ", rt->element);
        in_order(rt->right);
    }
}


void pos_order(BSTNode* rt){
    if (rt != NULL) {
        pos_order(rt->left);
        pos_order(rt->right);
        printf("%d ", rt->element);
    }
}

int getBalance(BSTNode* rt){
    if (rt == NULL) {
        return 0;
    }
    return (h(rt->left) - h(rt->right));
}

int h(BSTNode* rt){
    if (rt == NULL) {
        return -1;
    }
    return rt->height;
}

int max(int a, int b){
    return (a>b)? a : b;
}

BSTNode* rightRotate(BSTNode* rt){
    BSTNode* l = rt->left;
    BSTNode* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = 1 + max(h(rt->left), h(rt->right));
    l->height = 1 + max(h(l->left), h(l->right));
    
    return l;
}

BSTNode* leftRotate(BSTNode* rt){
    BSTNode* r = rt->right;
    BSTNode* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = 1 + max(h(rt->left), h(rt->right));
    r->height = 1 + max(h(r->left), h(r->right));
    
    return r;
}
