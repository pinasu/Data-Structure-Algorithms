#ifndef STD_H
#include "std.h"
#endif
#include "ord_arraylist.h"

/*
 * Pointer: Node
 * -------------------------
 * _node structure pointer.
 *
 */
typedef struct _node* Node;

/*
 * Struct: _node
 * -------------------------
 * _node structure definition, an N-ary tree.
 *
 * value: the value of the current node,
 * father: a pointer to the father _node,
 * child: a pointer to the child _node,
 * brother: a pointer to the brother _node,
 *
 */
struct _node{
  void* value;
  Node father;
  Node child;
  Node brother;
};

/*
 * Function: create_tree
 * -------------------------
 * Prototype of create_tree to create a _node pointer.
 *
 * value: the root value,
 * father: a pointer to a _node father,
 * child: a pointer to a _node child,
 * brother: a pointer to a _node brother.
 *
 * returns: a new Node with given value in root.
 *
 */
 Node create_tree(void* value, Node father, Node child, Node brother);

 /*
  * Function: get_father
  * -------------------------
  * Prototype of get_father to get _node father pointer.
  *
  * node: the _node pointer which father will be returned.
  *
  * returns: the father pointer in _node.
  *
  */
Node get_father(Node node);

/*
 * Function: get_child
 * -------------------------
 * Prototype of get_child to get _node child pointer.
 *
 * node: the _node pointer which child will be returned.
 *
 * returns: the child pointer in _node.
 *
 */
Node get_child(Node node);

/*
 * Function: get_brother
 * -------------------------
 * Prototype of get_brother to get _node brother.
 *
 * node: the _node pointer which brother will be returned.
 *
 * returns: the brother pointer in _node.
 *
 */
 Node get_brother(Node node);

 /*
  * Function: max_degree
  * -------------------------
  * Prototype of max_degree to get _node max degree.
  *
  * node: the _node pointer which maximum degree will be calculated.
  *
  * returns: the _node max degree.
  *
  */
int max_degree(Node node);

/*
 * Function: is_binary
 * -------------------------
 * Prototype of is_binary to determine if tree with node as root is binary.
 *
 * node: the _node root pointer.
 *
 * returns: 0 if the tree is binary, -1 otherwise.
 *
 */
int is_binary(Node node);

/*
 * Function: num_nodes
 * -------------------------
 * Prototype of num_nodes to get node number in given tree.
 *
 * node: the _node root pointer.
 *
 * returns: the node number.
 *
 */
int num_nodes(Node node);

/*
 * Function: depth
 * -------------------------
 * Prototype of depth to get tree max depth.
 *
 * node: the _node root pointer.
 *
 * returns: the _node max depth.
 *
 */
int depth(Node node);

/*
 * Function: get_binary
 * -------------------------
 * Prototype of get_binary to transform a given n-ary tree to a binary tree.
 *
 * node: the _node root pointer,
 * c: a compare function pointer.
 *
 * returns: the root pointer of the modified tree.
 *
 */
Node get_binary(Node node, compare c);

/*
 * Function: get_binary_aux
 * -------------------------
 * Prototype of get_binary to transform a given n-ary tree to a binary tree.
 *
 * node: the _node root pointer,
 * c: a compare function pointer.
 *
 * returns: the root pointer of the modified tree.
 *
 */

Node get_binary_aux(Ord_Arraylist arraylist, int start, int end, Node father);

/*
 * Function: get_array_ord
 * -------------------------
 * Prototype of get_array_ord to get an ordered array from a tree pointer.
 *
 * node: the _node root pointer,
 * arraylist: an _arraylist pointer in which tree values will be stored.
 *
 * returns: the arraylist with tree data in it.
 *
 */
void get_array_ord(Node node, Ord_Arraylist arraylist);

/*
 * Function: print_tree
 * -------------------------
 * Prototype of print_tree to print a tree.
 *
 * node: the _node root pointer.
 *
 */
void print_tree(Node root);

/* Function protptype to read file and create n-ary tree */
void read_file(Node* tree, compare c);

/* Function protptype to insert given string to n-ary tree */
void manage_insert(char* string, Node* tree, compare c);

/* Function protptype to insert family to n-ary tree */
void insert_nary(Node* tree, char** family, int count, compare c);

/* Function protptype to return father pointer in given n-ary tree */
Node find_father(Node tree, void* father, compare c);
