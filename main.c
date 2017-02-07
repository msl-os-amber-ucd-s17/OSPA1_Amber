#include "tree.h"
#define MAX_LENGTH 64

int main(int argc, char** argv) {
    char * mode = "r";  // Read Only Mode
    char * inFileName = argv[1];
    NodeT root = NULL;
    char word[MAX_LENGTH];
    char errMsg[36] = "ERROR! Cannot open the input file: ";

    FILE * in_file = fopen(inFileName, mode);
    if(in_file == NULL) {
        printf(strcat(errMsg, inFileName));
        exit(-1);
    }

    while(fscanf(in_file, " %64s", word) == 1){
        if(word == NULL) {
            printf("There was an error reading from the file");
            fclose(in_file);
            exit(-2);
        }
        if(root == NULL){
            root = (NodeT)malloc(sizeof(struct word_node));
            root->word = (char *)malloc(sizeof(char)*strlen(word + 1));
            strcpy(root->word, word);
            root->count = 1;
            root->left_node = NULL;
            root->right_node = NULL;
        } else {
            searchTree(root, word);
        }
    }
    fclose(in_file);

    // PRINT TO THE FILE
    mode = "w";
    FILE* out_file = fopen("output.txt", mode);
    printTree(root, out_file);
    fclose(out_file);

    // DEALLOCATE
    destroyTree(root);


    return 0;
}