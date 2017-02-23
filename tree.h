#ifndef OSPA1_TREE_H
#define OSPA1_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Defines an alias to a pointer to a word_node called nodePTR
typedef struct word_node* nodePTR;

// Struct that defines a node
//  contains a char* to store the word, an unsigned int to store
//  the occurrence count and two nodePTRs for each child.
struct word_node {
    char* word;
    unsigned int count;
    nodePTR left_node, right_node;
};

// addRoot(const char*) takes a word as an argument, and calls
//  the general purpose function addNode(). This function is
//  used to initialize the tree (instead of searchTree(), because
//  it returns the nodePTR (so the main has access to the root)
const nodePTR addRoot(const char*);

// searchTree(const NodePTR, const char*) takes a nodePTR, and a
//  word as arguments, it then recursively searches the tree for
//  any occurrences of the word. If the word is found its
//  count is incremented. If not addNode() is called to add the
//  word to the tree.
void searchTree(const nodePTR, const char*);

// addNode(const char*) takes a word in as an argument, builds a
//  new node, initializes the node, and returns a pointer to the
//  node.
const nodePTR addNode(const char*);

// printTree(const nodePTR, FILE*) takes in a node pointer, and
//  a file. It then traverses the tree in a depth first fashion
//  printing each word and its associated count to the file.
void printTree(const nodePTR, FILE*);

// destroyTree(nodePTR) takes in the root node of the tree.
//  This function traverses the tree in a breadth first fashion,
//  de-allocating first the node's word, then the node itself
//  before popping up.
void destroyTree(nodePTR);

#endif