#include "avl.h"

// Internal Functions

int avl_balance_factor(AVL *root) {
    if(root && root->left && root->right)
        return root->right->height - root->left->height;
    else if(root && root->left)
        return - root->left->height;
    else if(root && root->right)
        return root->right->height;
    return 0;
}

AVL* avl_rright(AVL* root) {
    AVL* new_root = root->left;
}
