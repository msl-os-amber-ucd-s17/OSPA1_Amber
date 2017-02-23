#include "tree.h"
#define MAX_LENGTH 64

// fileerror(char*) is a helper function for openfile() displays error message
//  and terminates the program (exit code -1)
void fileerror(const char*);

// readererror(FILE*) is called if a read from a file obtains a NULL string
//  displays an error message and terminates the program (exit code -2)
void readererror(FILE*);

// Used to close files (in this case the input and output files.
void closefile(FILE*);

// setread() and setwrite() return the file mode for calls to openfile()
char* setread() {return "r";}
char* setwrite() {return "w";}

// outfilename(char*) returns the correct output file name, based on the input
//  file name. (Expected input file names should be (input#.txt) where # can be
//  any positive number, not limited to single digit numbers.
const char* outfilename(const char*);

// openfile(const char*, const char*) opens a file in the specified mode. The
//  first argument is the name of the file in which to open, and the second
//  is the mode in which the file should be opened. This mode corresponds directly
//  to the modes used by the fopen() function in the c library.
FILE* openfile(const char*, const char*);

// buildtree(const nodePTR, FILE *) returns a constant node pointer. This function
//  is passed NULL in its first argument, and an input file as its second argument.
//  A concordance is built as a binary search tree, and the root node is returned.
const nodePTR buildtree(const nodePTR, FILE *);

// MAIN FUNCTION
int main(int argc, char** argv) {

    // FIRST OPEN INPUT FILE
    FILE * in_file = openfile(argv[1], setread());

    // THEN GET WORDS AND BUILD TREE
    nodePTR root = buildtree(NULL, in_file);

    // NEXT CLOSE INPUT FILE
    closefile(in_file);

    // NEXT MAKE OUTPUT
    FILE * out_file = openfile(outfilename(argv[1]), setwrite());
    printTree(root, out_file);
    closefile(out_file);

    // FINALLY DELETE TREE
    destroyTree(root);

    exit(EXIT_SUCCESS);
}


const char* outfilename(const char* ifname){
    char * ofname = (char*)malloc(sizeof(char)*strlen(ifname+4));
    char * sptr;
    sptr = strstr(ifname, "put");
    strcpy(ofname, "myout");
    strcat(ofname, sptr);
    return ofname;
}

FILE * openfile(const char* fName, const char* m){
    FILE * file = fopen(fName, m);
    if(file == NULL) {
        fileerror(fName);
    }
    return file;
}

void closefile(FILE *f){
    fclose(f);
}

void fileerror(const char *fName){
    char errMsg[36] = "ERROR! Cannot open the file: ";
    printf(strcat(errMsg, fName));
    exit(-1);
}

void readererror(FILE * f){
    printf("There was an error reading from the file");
    fclose(f);
    exit(-2);
}

const nodePTR buildtree(nodePTR n, FILE * f){
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