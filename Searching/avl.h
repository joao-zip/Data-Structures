#ifndef AVL_H
#define AVL_H

typedef struct node {
    int key;

    struct node *left, *right;
    unsigned height;
} AVL;

// Function Declarations

AVL* avl_create();
AVL* avl_insert(AVL*, const int);
int avl_search(AVL*, const int);
AVL* avl_remove(AVL*, const int);
AVL* avl_delete(AVL*);


// Internal Functions

int avl_balance_factor(AVL*);

AVL* avl_rright(AVL*);
AVL* avl_rleft(AVL*);
AVL* avl_rleftright(AVL*);
AVL* avl_rrightleft(AVL*);

#endif // !AVL_H
