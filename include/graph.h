#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef char *NodeId;

struct Node;
typedef struct Node *GraphNode;

struct NodeList;
typedef struct NodeList *Graph;

/**
 * Creates an empty graph.
 */
void graph_create(Graph *graph);

/**
 * Returns true if the BST is empty.
 * False otherwise.
 */
bool graph_is_empty(Graph graph);

/**
 * Adds a node to the graph.
 */
void graph_add_node(Graph *graph, GraphNode *node);

/**
 * Returns true if BST contains given element.
 */
bool graph_contains(Graph graph, NodeId node_id);

/**
 * Returns the smallest element of the BST.
 */
int graph_min(Graph graph);

/**
 * Returns the biggest element of the graph.
 */
int graph_max(Graph graph);

/**
 * Removes element from graph.
 * If the element isn't in the graph it does nothing.
 */
void graph_remove(Graph *graph, NodeId node_id);

/**
 * Returns the quantity of nodes the graph has.
 */
int bst_quantity(Graph graph);

/**
 * Destroys the BST and frees all memory associated with it.
 *
 * @param bst the BST to be destroyed.
 */
void graph_destroy(BST *bst);

#endif /* GRAPH_H */
