#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

node *create_node(int elt) {
    node *n = (node *)malloc(sizeof(node));
    assert(n != NULL);
    n->elt = elt;
    n->height = 0;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void free_tree(node *t) {
    if (t != NULL) {
        free_tree(t->left);
        free_tree(t->right);
        free(t);
    }
}

/* SEARCH */

node *find_avl(node *t, int elt) {
    node *ptr = t;
    while (ptr != NULL && ptr->elt != elt) {
        if (ptr->elt > elt)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}

int max(int x, int y){
    if(x> y){
        return x;
    }
    return y;
}

void update_height(node *t){
    if (t == NULL){
        return;
    }
    t->height = 1 + max(height_node(t->left), height_node(t->right));

}

/*int height(node *t){
    if(t == NULL){
        return -1;
    }
    else{
        if (t->left == NULL && t->right == NULL){
            return 0;
        }
        else if(t->left->height > t->right->height || t->right == NULL){
            return t->left->height+1;
        }
        else{
            return t->right->height-1;
        }
    }
}*/

int height_node(node *t){
    if(t == NULL){
        return -1;
    }
    return t->height;
}

/*node *rotate_right(node *t){
    node *x = t->left;
    t->left = x->right;
    x->right = t;
    update_height(x);
    update_height(t);
    return x;
}*/

node *rotate_right(node *t){
    node *x = t->left;
    node *w = x->right;
    x->right = t;
    t->left = w;
    update_height(t);
    update_height(x);
    return x;
}

/*node *rotate_left(node *t){
    node *x = t->right;
    t->right = x->left;
    x->left = t;
    update_height(x);
    update_height(t);
    return x;
}*/

node *rotate_left(node *t){
    node *x = t->right;
    node *w = x->left;
    x->left = t;
    t->right = w;
    update_height(t);
    update_height(x);
    return x;
}

node *rotate_left_right(node *t){
    t->left = rotate_left(t->left);
    return rotate_right(t);
}

node *rotate_right_left(node *t){
    t->right = rotate_right(t->right);
    return rotate_left(t);
}

int compute_balance(node *t){
    if(t == NULL){
        return 0;
    }
    else{
        if(t->left == NULL && t->right == NULL){
            return 0;
        }
        else if(t->right == NULL){
            return t->left->height;
        }
        else if(t->left == NULL){
            return -1-t->right->height;
        }
        else{
            return t->left->height - t->right->height;
        }
    }
}

node *rebalance(node *t){
    if(t == NULL){
        return NULL;
    }
    else{
        if(compute_balance(t) >= 2){
            if(compute_balance(t->left) == -1){
                t = rotate_left_right(t);
            }
            else{
                t = rotate_right(t);
            }
        }
        if(compute_balance(t) <= -2){
            if(compute_balance(t->right) == 1){
                t = rotate_right_left(t);
            }
            else{
                t = rotate_left(t);
            }
        }
    }
    return t;
}

node *insert_avl(node *t, int elt){
    if(t == NULL){
        return create_node(elt);
    }
    else if(t->elt > elt){
        t->left = insert_avl(t->left, elt);
    }
    else if(t->elt < elt){
        t->right = insert_avl(t->right, elt);
    }
    update_height(t);
    t = rebalance(t);
    return t;
}

int is_avl(node *t){
    if(t == NULL){
        return 1;
    }
    if(abs(compute_balance(t)) < 2 && is_avl(t->left) && is_avl(t->right)){
        return 1;
    }
    return 0;
}

int chrono(int n){
    clock_t start, end;
    int i;
    node *t = NULL;
    start = clock();
    for (i = 0; i < 2*n; i++) {
        t = insert_avl(t, i);
    }
    end = clock();
    return (end-start)*1000/CLOCKS_PER_SEC;
    
}
