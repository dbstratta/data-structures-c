#include <stdlib.h>
#include <stdbool.h>

#include "bst.h"

struct BSTNode
{
        int num;
        BST right_child;
        BST left_child;
};

void bst_create (BST *bst)
{
        *bst = NULL;
}

int bst_root (BST bst)
{
        return bst->num;
}

bool bst_is_empty (BST bst)
{
        return bst == NULL;
}

BST bst_right_child (BST bst)
{
        return bst->right_child;
}

BST bst_left_child (BST bst)
{
        return bst->left_child;
}

bool bst_has_right_child (BST bst)
{
        return bst_is_empty(bst_right_child(bst));
}

bool bst_has_left_child (BST bst)
{
        return bst_is_empty(bst_left_child(bst));
}

bool bst_is_leave (BST bst)
{
        bool has_right_child = bst_has_right_child(bst);
        bool has_left_child = bst_has_left_child(bst);

        bool is_leave = !(has_right_child || has_left_child);
        return is_leave;
}

void bst_add (BST *bst, int num)
{
        if (bst_is_empty(*bst)) {
                (*bst) = malloc(sizeof(struct BSTNode));
                (*bst)->num = num;
                (*bst)->right_child = NULL;
                (*bst)->left_child = NULL;
        } else if (bst_root(*bst) < num) {
                BST right_child = bst_right_child(*bst);
                bst_add(&right_child, num);
        } else if (bst_root(*bst) > num) {
                BST left_child = bst_left_child(*bst);
                bst_add(&left_child, num);
        }
}

bool bst_contains (BST bst, int num)
{
        if (bst_is_empty(bst)) {
                return false;
        } else if (bst_root(bst) < num) {
                return bst_contains(bst_right_child(bst), num);
        } else if (bst_root(bst) > num) {
                return bst_contains(bst_left_child(bst), num);
        } else {
                return true;
        }
}

BST bst_search (BST bst, int num)
{
        if (bst_is_empty(bst)) {
                return NULL;
        } else if (bst_root(bst) < num) {
                return bst_search(bst_right_child(bst), num);
        } else if (bst_root(bst) > num) {
                return bst_search(bst_left_child(bst), num);
        } else {
                return bst;
        }
}

int bst_min (BST bst)
{
        if (bst_has_right_child(bst)) {
                return bst_min(bst_left_child(bst));
        } else {
                return bst_root(bst);
        }
}

int bst_max (BST bst)
{
        if (bst_has_right_child(bst)) {
                return bst_max(bst_right_child(bst));
        } else {
                return bst_root(bst);
        }
}

void bst_remove(BST *bst, int num)
{
        if (!bst_is_empty(*bst)) {
                if (bst_root(*bst) < num) {
                        BST right_child = bst_right_child(*bst);
                        bst_remove(&right_child, num);
                } else if (bst_root(*bst) > num) {
                        BST left_child = bst_left_child(*bst);
                        bst_remove(&left_child, num);
                } else if (bst_is_leave(*bst)) {
                        free(*bst);
                } else if (!bst_has_left_child(*bst)) {
                        BST temp_bst = *bst;
                        *bst = bst_right_child(*bst);
                        free(temp_bst);
                } else if (!bst_has_right_child(*bst)) {
                        BST temp_bst = *bst;
                        *bst = bst_left_child(*bst);
                        free(temp_bst);
                } else {
                        int max_from_left_child = bst_max(bst_left_child(*bst));
                        (*(*bst)).num = max_from_left_child;

                        BST left_child = bst_left_child(*bst);
                        bst_remove(&left_child, max_from_left_child);
                }
        }
}

int bst_quantity (BST bst)
{
        if (bst_is_empty(bst)) {
                return 0;
        } else {
                BST left_child = bst_left_child(bst);
                BST right_child = bst_right_child(bst);

                return 1 + bst_quantity(left_child) + bst_quantity(right_child);
        }
}

int int_max (int a, int b) {
        return a > b ? a : b;
}

int bst_height (BST bst)
{
        if (bst_is_empty(bst)) {
                return 0;
        } else {
                BST left_child = bst_left_child(bst);
                BST right_child = bst_left_child(bst);

                return 1 + int_max(bst_height(left_child), bst_height(right_child));
        }
}

void bst_destroy (BST *bst)
{
        if (!bst_is_empty(*bst)) {
                BST left_child = bst_left_child(*bst);
                bst_destroy(&left_child);

                BST right_child = bst_right_child(*bst);
                bst_destroy(&right_child);

                free(*bst);
        }
}
