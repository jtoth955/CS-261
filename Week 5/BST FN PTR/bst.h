#ifndef __BST_H
#define __BST_H

#ifndef TYPE
#define TYPE void*
#endif



/* function used to compare two TYPE values to each other, define this in your compare.c file */
//int compare(TYPE left, TYPE right);
typedef int (*comparator)(void *left, void*right);
/* function used to print TYPE values, define this in your compare.c file */
//void print_type(TYPE curval);
typedef void (*printer)(void *node);

/*
  File: bst.h
  Interface definition of the binary search tree data structure.
*/
struct BSTree;
/* Declared in the c source file to hide the structure members from the user. */

/* Initialize binary search tree structure. */
void initBSTree(struct BSTree *tree);

/* Alocate and initialize search tree structure. */
struct BSTree *newBSTree();

/* Deallocate nodes in BST. */
void clearBSTree(struct BSTree *tree);

/* Deallocate nodes in BST and BST structure. */
void deleteBSTree(struct BSTree *tree);

/*-- BST Bag interface --*/
int  isEmptyBSTree(struct BSTree *tree);
int     sizeBSTree(struct BSTree *tree);

void     addBSTree(struct BSTree *tree, TYPE val, comparator compare);
int containsBSTree(struct BSTree *tree, TYPE val, comparator compare);
void  removeBSTree(struct BSTree *tree, TYPE val, comparator compare);
void printTree(struct BSTree *tree, printer print_type);
# endif
