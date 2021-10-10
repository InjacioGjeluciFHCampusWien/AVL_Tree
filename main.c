//
//  main.c
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//

#include <stdio.h>
#include "bintree.h"

void preOrder(struct node_ *root)
{
    if(root != NULL)
    {
        printf("%d %d \n", root->key, root->balance);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    // test your implementation here
    // no test cases will be provided this time!

    binTree *tree = t_init();

    char *data = "test";
//    insert(tree, 10, data);
//    insert(tree, 20, data);
//    insert(tree, 30, data);
//    insert(tree, 40, data);
//    insert(tree, 50, data);
//    insert(tree, 25, data);

//Test 2
    insert(tree, 50, data);
    insert(tree, 20, data);
    insert(tree, 60, data);
    insert(tree, 10, data);
    insert(tree, 8, data);
    insert(tree, 15, data);
    insert(tree, 32, data);
    insert(tree, 46, data);
    insert(tree, 11, data);
    insert(tree, 48, data);




//    /* Constructing tree given in the above figure */

    /* The constructed AVL Tree would be
              30
             /  \
           20   40
          /  \     \
         10  25    50
    */

    printf("Preorder traversal of the constructed AVL"
           " tree is \n");
    preOrder(tree->root);




    return 0;
}


