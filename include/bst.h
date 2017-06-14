#ifndef BST_H
#define BST_H

#include <stdbool.h>

struct BSTNode;
typedef struct BSTNode *BST;

void bst_create (BST *bst);

int bst_root (BST bst);

bool bst_is_empty (BST bst);

BST bst_right_child (BST bst);

BST bst_left_child (BST bst);

bool bst_has_right_child (BST bst);

bool bst_has_left_child (BST bst);

bool bst_is_leave (BST bst);

void bst_add (BST *bst, int num);

bool bst_contains (BST bst, int num);

BST bst_search (BST bst, int num);

int bst_min (BST bst);

int bst_max (BST bst);

void bst_remove (BST *bst, int num);

int bst_quantity (BST bst);

int bst_height (BST bst);

void bst_destroy (BST *bst);

#endif /* BST_H */
