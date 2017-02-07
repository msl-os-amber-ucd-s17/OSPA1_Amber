
# Operating Systems Concepts: Programming Assignment C1
###### Collaborators: Alex Foreman, Chris Lauber, Jian Peng, Michael Valdez

Description
---------------
The purpose of this assignment was to be an introduction to the C programming language. This introduction was  
achieved by writing a program in C to solve a relatively simple and familiar problem. We were tasked with  
reading input from a file, extracting unique words from the input, keeping count of the number of occurences  
of each word, and writing the results to an output file in sorted order.

Approach
---------------
######Pseudocode:  
***main(inputfile):***

1. openfile(inputfile)
2. while(getword returns true)
3. ---searchtree(root, word)
4. closefile(inputfile)
5. openfile(outputfile)
6. printTree(root)
7. closefile(outputfile)
8. destroyTree(root)  


***searchTree(node, word):***

1. if(word == node->word) ++count
2. else if (word < node->word)
3. ---if(node->leftchild == null) 
4. ------node->leftchild = addnode(word)
5. ---else searchTree(node->leftchild)
6. else
7. ---if(node->rightchild == null)
8. ------node->rightchild = addnode(word)
9. ---else searchTree(node->rightchild)


***addNode(word):***

1. node* newNode = (node*)alloc(***"enough space for newNode"***)
2. newNode->word = (char*)alloc(***"enough space for word"***)
3. newNode->word = word ***//use strcpy()***
4. newNode->count = 1
5. newNode-> leftchild, rightchild = null
6. return newNode


***printTree(node, outfile):***

1. if(node == null) return
2. printTree(node->leftchild, outfile)
3. print word, ':',  ' ', count, '\n'
4. printTree(node->rightchild, outfile)

***destroyTree(node):***

1. if(node == null) return
2. destroyTree(node->leftchild)
3. destroyTree(node->rightchild)
4. free(node->word)
5. free(node)


Data Structures
---------------
Because of the relatively simple nature of this program, there were really only two data structures worth note.  
The first of the two was the a binary tree. Although the prompt explicitly stated we were to use a binary tree, we  
would have used one regardless. This is because a binary tree can be searched in ***O(log(n))*** time. This time  
complexity will be maintained as long as the tree remains balanced, however in our case we do not have any  
balancing methods implemented.  

The second of the two data structures used in this program was a struct. The struct defined nodes of the tree  
and each instance of a node contained a dynamically allocated c-style string, an unsigned integer count, and two  
node pointers for each child node. Each node was also dynamically allocated.

Algorithms
---------------
The only algorithms in this project worth note are the traversal algorithms used for searching and destroying the  
binary tree. For searching, we implemented a standard in-order recursive traversal algorithm for processing binary  
tree; For freeing the space allocated to the tree we used a post-order (depth first) recursive traversal of the tree.  
There are two important things to note about these algorithms. The first was touched on in the Data Structures section  
of this document. Both these algorithms have an expected time complexity of ***O(log(n))***, but as mentioned earlier  
only if the tree remains relatively balanced. The second important thing to note is that due to the recursive  
implementation of the algorithms, stack overflow may become an issue on tree that are very deep. The chance of this  
occurring could be minimalized by ensuring the tree stays relatively balanced.
