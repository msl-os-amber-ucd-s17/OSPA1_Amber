#ifndef OSPA1_TREE_H
#define OSPA1_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct word_node* NodeT;

struct word_node {
    char* word;
    unsigned int count;
    NodeT left_node, right_node;
};

void searchTree(NodeT, const char*);
NodeT addNode(const char*);
void printTree(NodeT, FILE*);
void destroyTree(NodeT);

#endif