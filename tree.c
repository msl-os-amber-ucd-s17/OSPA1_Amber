#include "tree.h"

const nodePTR addRoot(const char* curr_word){ return addNode(curr_word); }

void searchTree(const nodePTR current_node, const char* curr_word) {
    // If the word(argument) is the same as the word(node) increment the occurrence count
    //  of this word.
    if(!strcmp(current_node->word, curr_word)){
        ++current_node->count;
    } else if (strcmp(curr_word, current_node->word) < 0){
        // If left child is NULL add the word to a new node as the left child otherwise
        //  recurse left.
        if (current_node->left_node == NULL) {
            current_node->left_node = addNode(curr_word);
        } else {
            searchTree(current_node->left_node, curr_word);
        }
    } else {
        // If right child is NULL add the word to a new node as the right child otherwise
        //  recurse right
        if (current_node->right_node == NULL ) {
            current_node->right_node = addNode(curr_word);
        } else {
            searchTree(current_node->right_node, curr_word);
        }
    }
}

const nodePTR addNode(const char* curr_word) {
    // Allocate memory for a new node
    nodePTR new_node = (nodePTR)malloc(sizeof(struct word_node));

    // Allocate enough memory to hold the word(argument)
    new_node->word = (char *)malloc(sizeof(char)*strlen(curr_word+1));

    // Copy the word(argument) into the memory allocated for the word(node)
    strcpy(new_node->word, curr_word);

    // Initialize the count and child pointers.
    new_node->count = 1;
    new_node->left_node, new_node->right_node = NULL;

    // Return the node.
    return new_node;
}

void printTree(const nodePTR current_node, FILE* o){
    // If the tree is not empty print it to the file.
    if(current_node != NULL){
        // Recurse left
        printTree(current_node->left_node, o);

        // Print word and count
        fprintf(o, "%s", current_node->word);
        fprintf(o, "%c", ':');
        fprintf(o, "%c", ' ');
        fprintf(o, "%u", current_node->count);
        fprintf(o, "%c", '\n');

        // Recurse right
        printTree(current_node->right_node, o);
    }

}

void destroyTree(nodePTR current_node){
    if(current_node != NULL) {
        // Recurse Left
        destroyTree(current_node->left_node);

        // Recurse Right
        destroyTree(current_node->right_node);

        // Deallocate the current node's allocated memory
        free(current_node->word);
        free(current_node);
    }

}