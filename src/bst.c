#include <stdlib.h>
#include <stdbool.h>

#include "bst.h"

struct BSTNode
{
        int num;
        BST right_child;
        BST left_child;
};

/**
 * Creates an empty Binary Search Tree.
 *
 * @param bst a uninitiallized bst.
 */
void bst_create(BST *bst)
{
        *bst = NULL;
}

/**
 * Returns the root element of the BST.
 *
 * @param  bst the BST.
 * @return the root element of `bst`.
 */
int bst_root(BST bst)
{
        return bst->num;
}

/**
 * Returns true if the BST is empty.
 * False otherwise.
 *
 * @param  bst the BST.
 * @return boolean indicating if the BST `bst` is empty.
 */
bool bst_is_empty(BST bst)
{
        return bst == NULL;
}

/**
 * Returns the BST's right child.
 * Shares memory with `bst`.
 *
 * @param  bst the BST.
 * @return the right child of `bst`.
 */
BST bst_right_child(BST bst)
{
        return bst->right_child;
}

/**
 * Returns the BST's left child.
 * Shares memory with `bst`.
 *
 * @param  bst the BST.
 * @return the left child of `bst`.
 */
BST bst_left_child(BST bst)
{
        return bst->left_child;
}

/**
 * Returns true if the BST has a right child.
 * False otherwise.
 *
 * @param  bst the BST.
 * @return boolean indicating if the BST `bst` has a right child.
 */
bool bst_has_right_child(BST bst)
{
        return bst_is_empty(bst_right_child(bst));
}

/**
 * Returns true if the BST has a left child.
 *
 * @param  bst the BST.
 * @return boolean indicating if the BST `bst` has a left child.
 */
bool bst_has_left_child(BST bst)
{
        return bst_is_empty(bst_left_child(bst));
}

/**
 * Returns true if the BST is a leaf.
 *
 * @param  bst the BST.
 * @return boolean indicating if the BST `bst` is a leaf.
 */
bool bst_is_leaf(BST bst)
{
        bool has_right_child = bst_has_right_child(bst);
        bool has_left_child = bst_has_left_child(bst);

        bool is_leaf = !(has_right_child || has_left_child);
        return is_leaf;
}

/**
 * Adds element to the BST.
 * If the element is already in the BST it does nothing.
 *
 * @param bst the BST.
 * @param num the element to be added.
 */
void bst_add(BST *bst, int num)
{
        if (bst_is_empty(*bst))
        {
                (*bst) = malloc(sizeof(struct BSTNode));
                (*bst)->num = num;
                (*bst)->right_child = NULL;
                (*bst)->left_child = NULL;
        }
        else if (bst_root(*bst) < num)
        {
                BST right_child = bst_right_child(*bst);
                bst_add(&right_child, num);
        }
        else if (bst_root(*bst) > num)
        {
                BST left_child = bst_left_child(*bst);
                bst_add(&left_child, num);
        }
}

/**
 * Returns true if BST contains given element.
 *
 * @param  bst the BST.
 * @param  num the number to check look for.
 * @return boolean indicating if BST `bst` contains element `num`.
 */
bool bst_contains(BST bst, int num)
{
        if (bst_is_empty(bst))
        {
                return false;
        }
        else if (bst_root(bst) < num)
        {
                return bst_contains(bst_right_child(bst), num);
        }
        else if (bst_root(bst) > num)
        {
                return bst_contains(bst_left_child(bst), num);
        }
        else
        {
                return true;
        }
}

/**
 * Returns sub BST where the given num is root.
 * If the element is not found in the BST returns NULL.
 * Shares memory with `bst`.
 *
 * @param  bst the BST.
 * @param  num the element to search.
 * @return sub BST of BST `bst` where element `num` is root.
 */
BST bst_search(BST bst, int num)
{
        if (bst_is_empty(bst))
        {
                return NULL;
        }
        else if (bst_root(bst) < num)
        {
                return bst_search(bst_right_child(bst), num);
        }
        else if (bst_root(bst) > num)
        {
                return bst_search(bst_left_child(bst), num);
        }
        else
        {
                return bst;
        }
}

/**
 * Returns the smallest element of the BST.
 *
 * @param  bst the BST.
 * @return the smallest element of BST `bst`.
 */
int bst_min(BST bst)
{
        if (bst_has_right_child(bst))
        {
                return bst_min(bst_left_child(bst));
        }
        else
        {
                return bst_root(bst);
        }
}

/**
 * Returns the biggest element of the BST.
 *
 * @param  bst the BST.
 * @return the biggest element of the BST `bst`.
 */
int bst_max(BST bst)
{
        if (bst_has_right_child(bst))
        {
                return bst_max(bst_right_child(bst));
        }
        else
        {
                return bst_root(bst);
        }
}

/**
 * Removes element from BST.
 * If the element isn't in the BST it does nothing.
 *
 * @param bst the BST.
 * @param num the element to be removed.
 */
void bst_remove(BST *bst, int num)
{
        if (!bst_is_empty(*bst))
        {
                if (bst_root(*bst) < num)
                {
                        BST right_child = bst_right_child(*bst);
                        bst_remove(&right_child, num);
                }
                else if (bst_root(*bst) > num)
                {
                        BST left_child = bst_left_child(*bst);
                        bst_remove(&left_child, num);
                }
                else if (bst_is_leave(*bst))
                {
                        free(*bst);
                }
                else if (!bst_has_left_child(*bst))
                {
                        BST temp_bst = *bst;
                        *bst = bst_right_child(*bst);
                        free(temp_bst);
                }
                else if (!bst_has_right_child(*bst))
                {
                        BST temp_bst = *bst;
                        *bst = bst_left_child(*bst);
                        free(temp_bst);
                }
                else
                {
                        int max_from_left_child = bst_max(bst_left_child(*bst));
                        (*(*bst)).num = max_from_left_child;

                        BST left_child = bst_left_child(*bst);
                        bst_remove(&left_child, max_from_left_child);
                }
        }
}

/**
 * Returns the quantity of nodes the BST has.
 *
 * @param  bst the BST.
 * @return the quantity of nodes of BST `bst`.
 */
int bst_quantity(BST bst)
{
        if (bst_is_empty(bst))
        {
                return 0;
        }
        else
        {
                BST left_child = bst_left_child(bst);
                BST right_child = bst_right_child(bst);

                return 1 + bst_quantity(left_child) + bst_quantity(right_child);
        }
}

int int_max(int a, int b)
{
        return a > b ? a : b;
}

/**
 * Returns the height of the BST.
 * If BST is empty, the height is 0.
 *
 * @param  bst the BST.
 * @return the height of BST `bst`.
 */
int bst_height(BST bst)
{
        if (bst_is_empty(bst))
        {
                return 0;
        }
        else
        {
                BST left_child = bst_left_child(bst);
                BST right_child = bst_left_child(bst);

                return 1 + int_max(bst_height(left_child), bst_height(right_child));
        }
}

/**
 * Destroys the BST and frees all memory associated with it.
 *
 * @param bst the BST to be destroyed.
 */
void bst_destroy(BST *bst)
{
        if (!bst_is_empty(*bst))
        {
                BST left_child = bst_left_child(*bst);
                bst_destroy(&left_child);

                BST right_child = bst_right_child(*bst);
                bst_destroy(&right_child);

                free(*bst);
        }
}
