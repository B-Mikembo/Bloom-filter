#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

typedef struct _node {
    char *word;                 /* donnee stockee : un mot  */
    int height;              /* la hauteur de l'arbre       */
    struct _node *left;      /* pointeur sur le fils gauche */
    struct _node *right;     /* pointeur sur le fils droit  */
} node;

node *create_node(char *word);

void free_tree(node *t);

int is_avl(node *t);

node *find_avl(node *t, char *word);

node *insert_avl(node *t, char *word);

node *remove_avl(node *t, char *word);

void update_height(node *t);

int height(node *t);

int height_node(node *t);

node *rotate_right(node *t);

node *rotate_left(node *t);

node *rotate_left_right(node *t);

node *rotate_right_left(node *t);

int compute_balance(node *t);

node *rebalance(node *t);

int chrono(int n);

#endif /* AVL_H */
