#ifndef BST_H
#define BST_H

#include <stdbool.h>

struct BSTNode;
typedef struct BSTNode *BST;

/**
 * Creates an empty Binary Search Tree.
 *
 * @param bst a uninitiallized bst.
 */
void bst_create (BST *bst);

/**
 * Returns the root element of the BST.
 *
 * @param  bst the BST.
 * @return the root element of `bst`.
 */
int bst_root (BST bst);

/**
 * Returns true if the BST is empty.
 * False otherwise.
 *
 * @param  bst the BST.
 * @return boolean indicating if the BST `bst` is empty.
 */
bool bst_is_empty (BST bst);

/**
 * Returns the BST's right child.
 * Shares memory with `bst`.
 *
 * @param  bst the BST.
 * @return the right child of `bst`.
 */
BST bst_right_child (BST bst);

/**
 * Returns the BST's left child.
 * Shares memory with `bst`.
 *
 * @param  bst the BST.
 * @return the left child of `bst`.
 */
BST bst_left_child (BST bst);

/**
 * Returns true if the BST has a right child.
 * False otherwise.
 *
 * @param  bst the BST.
 * @return boolean indicating if the BST `bst` has a right child.
 */
bool bst_has_right_child (BST bst);

/**
 * Returns true if the BST has a left child.
 *
 * @param  bst the BST.
 * @return boolean indicating if the BST `bst` has a left child.
 */
bool bst_has_left_child (BST bst);

/**
 * Returns true if the BST is a leave.
 *
 * @param  bst the BST.
 * @return boolean indicating if the BST `bst` is a leave.
 */
bool bst_is_leave (BST bst);

/**
 * Adds element to the BST.
 * If the element is already in the BST it does nothing.
 *
 * @param bst the BST.
 * @param num the element to be added.
 */
void bst_add (BST *bst, int num);

/**
 * Returns true if BST contains given element.
 *
 * @param  bst the BST.
 * @param  num the number to check look for.
 * @return boolean indicating if BST `bst` contains element `num`.
 */
bool bst_contains (BST bst, int num);

/**
 * Returns sub BST where the given num is root.
 * If the element is not found in the BST returns NULL.
 * Shares memory with `bst`.
 *
 * @param  bst the BST.
 * @param  num the element to search.
 * @return sub BST of BST `bst` where element `num` is root.
 */
BST bst_search (BST bst, int num);

/**
 * Returns the smallest element of the BST.
 *
 * @param  bst the BST.
 * @return the smallest element of BST `bst`.
 */
int bst_min (BST bst);

/**
 * Returns the biggest element of the BST.
 *
 * @param  bst the BST.
 * @return the biggest element of the BST `bst`.
 */
int bst_max (BST bst);

/**
 * Removes element from BST.
 * If the element isn't in the BST it does nothing.
 *
 * @param bst the BST.
 * @param num the element to be removed.
 */
void bst_remove (BST *bst, int num);

/**
 * Returns the quantity of nodes the BST has.
 *
 * @param  bst the BST.
 * @return the quantity of nodes of BST `bst`.
 */
int bst_quantity (BST bst);

/**
 * Returns the height of the BST.
 * If BST is empty, the height is 0.
 *
 * @param  bst the BST.
 * @return the height of BST `bst`.
 */
int bst_height (BST bst);

/**
 * Destroys the BST and frees all memory associated with it.
 *
 * @param bst the BST to be destroyed.
 */
void bst_destroy (BST *bst);

#endif /* BST_H */
