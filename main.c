#include "tree.h"
#define MAX_LENGTH 64

void fileerror(char*);
void readererror(FILE*);
void closefile(FILE*);

char* setread();
char* setwrite();
char* outfilename(char*);
FILE* openfile(char*, char*);
word_nodePTR buildtree(word_nodePTR, FILE *);

int main(int argc, char** argv) {

    // FIRST OPEN INPUT FILE
    FILE * in_file = openfile(argv[1], setread());

    // THEN GET WORDS AND BUILD TREE
    word_nodePTR root = buildtree(NULL, in_file);

    // NEXT CLOSE INPUT FILE
    closefile(in_file);

    // NEXT MAKE OUTPUT
    FILE * out_file = openfile(outfilename(argv[1]), setwrite());
    printTree(root, out_file);
    closefile(out_file);

    // FINALLY DELETE TREE
    destroyTree(root);

    exit(0);
}

char* setread(){
    return "r";
}

char* setwrite() {
    return "w";
}

char* outfilename(char* ifname){
    char * ofname = (char*)malloc(sizeof(char)*strlen(ifname+4));
    char * sptr;
    sptr = strstr(ifname, "put");
    strcpy(ofname, "myout");
    strcat(ofname, sptr);
    return ofname;
}

FILE * openfile(char* fName, char* m){
    FILE * file = fopen(fName, m);
    if(file == NULL) {
        fileerror(fName);
    }
    return file;
}

void closefile(FILE *f){
    fclose(f);
}

void fileerror(char *fName){
    char errMsg[36] = "ERROR! Cannot open the file: ";
    printf(strcat(errMsg, fName));
    exit(-1);
}

void readererror(FILE * f){
    printf("There was an error reading from the file");
    fclose(f);
    exit(-2);
}

word_nodePTR buildtree(word_nodePTR n, FILE * f){
    char word[MAX_LENGTH];
    while(fscanf(f, " %64s", word) == 1){
        if(word == NULL) {
            readererror(f);
        }
        if(n == NULL){
            n = addRoot(word);
        } else {
            searchTree(n, word);
        }
    }
    return n;
}