#include "tree.h"

void searchTree(NodeT current_node, const char* curr_word) {
    if(!strcmp(current_node->word, curr_word)){
        ++current_node->count;
    } else if (strcmp(curr_word, current_node->word) < 0){
        if (current_node->left_node == NULL) {
            current_node->left_node = addNode(curr_word);
        } else {
            searchTree(current_node->left_node, curr_word);
        }
    } else {
        if (current_node->right_node == NULL ) {
            current_node->right_node = addNode(curr_word);
        } else {
            searchTree(current_node->right_node, curr_word);
        }
    }
}

NodeT addNode(const char* curr_word) {
    NodeT new_node = (NodeT)malloc(sizeof(struct word_node));
    new_node->word = (char *)malloc(sizeof(char)*strlen(curr_word+1));
    strcpy(new_node->word, curr_word);
    new_node->count = 1;
    new_node->left_node, new_node->right_node = NULL;
    return new_node;
}

void printTree(NodeT current_node, FILE* o){
//    if(current_node->left_node != NULL){
//        printTree(current_node->left_node, o);
//    }
    if(current_node == NULL){
        return;
    }
    printTree(current_node->left_node, o);
    // Print word and count
    fprintf(o, "%s", current_node->word);
    fprintf(o, "%c", '\t');
    fprintf(o, "%u", current_node->count);
    fprintf(o, "%c", '\n');
    printTree(current_node->right_node, o);
//    if(current_node->right_node != NULL) {
//        printTree(current_node->right_node, o);
//    }
}

void destroyTree(NodeT current_node){
    if(current_node == NULL) {
        return;
    }
    destroyTree(current_node->left_node);
    destroyTree(current_node->right_node);
    free(current_node->word);
    free(current_node);
}