//
//  bintree.c
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//

#include "bintree.h"

binTree *t_init(){
    binTree *tmp = (binTree *)malloc(sizeof(binTree));
    tmp->root = NULL;
    tmp->size = 0;
    return tmp;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->balance = getBalance(x);
    y->balance = getBalance(y);

    // Return new root
    return y;
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->balance = getBalance(y);
    x->balance = getBalance(x);

    // Return new root
    return x;
}

// TODO: double pointer einführen oder über return Werte lösen
node *insertNode(node *start, int key, const char *data){
    node *newNode;
    if (start == NULL) {
        newNode = (node *) malloc(sizeof(node));
        if (newNode != NULL) {
            newNode->data = (char*) malloc(strlen(data)+1);
            strcpy(newNode->data, data);
            newNode->key = key;
            newNode->right = newNode->left = NULL;
        }
        return newNode;
    }
    if (key < start->key) {
        newNode = insertNode(start->left, key, data);
        start->left = newNode;
    } else {
        newNode = insertNode(start->right, key, data);

        start->right = newNode;
    }
    
    // TODO: Schritte 1-3
    // 1. Balancefaktor für den "start" Knoten mit Hilfe von treeDepth berechnen
    getBalance(start);
    // 2. Überprüfung der Lastigkeit
    // 3. Ausführung der einzelnen Rotationen
    // Left Left Case
    if (start->balance > 1 && key < start->left->key)
        return rightRotate(start);

    // Right Right Case
    if (start->balance < -1 && key > start->right->key)
        return leftRotate(start);

    // Left Right Case
    if (start->balance > 1 && key > start->left->key)
    {
        start->left = leftRotate(start->left);
        return rightRotate(start);
    }

//    // Right Left Case
    if (start->balance < -1 && key < start->right->key)
    {
        start->right = rightRotate(start->right);
        return leftRotate(start);
    }
    
    return start;
}

node *insert(binTree *t, int key, const char *data){
    node *newNode;
    newNode = insertNode(t->root, key, data);
    t->root = newNode;
    t->size++;
    return newNode;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int treeDepth(node *start){
    if (start == NULL) {
        return 0;
    }
    else {
        return 1 +  max(treeDepth(start->left),
                        treeDepth(start->right));
    }
}


int getBalance(node *start){
    if (start == NULL) {
        return 0;
    }
    else {
        if(start->right != NULL){
            getBalance(start->right);
        }
        if(start->left != NULL){
            getBalance(start->left);
        }
        if(start->left == NULL && start->right == NULL){
            start->balance = 0;
        }
        int leftDepth = treeDepth(start->left);
        int rightDepth = treeDepth(start->right);
        start->balance = leftDepth-rightDepth;
        return leftDepth-rightDepth;
    }
}


// TODO: Implementierung Rotationen

// rotateLL
// rotateRL
// rotateRR
// rotateLR
