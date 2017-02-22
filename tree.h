#ifndef OSPA1_TREE_H
#define OSPA1_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct word_node* word_nodePTR;

struct word_node {
    char* word;
    unsigned int count;
    word_nodePTR left_node, right_node;
};

word_nodePTR addRoot(const char*);
void searchTree(word_nodePTR, const char*);
word_nodePTR addNode(const char*);
void printTree(word_nodePTR, FILE*);
void destroyTree(word_nodePTR);

#endif