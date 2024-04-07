#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_LENGTH 25
#define MAX_NODES 25

struct Node {
    int ptr, left, right;
    char label;
};

int main() {
    char input[MAX_EXPRESSION_LENGTH];
    printf("Enter the expression (limit is %d characters):\n", MAX_EXPRESSION_LENGTH);
    // Using that experssion as a input ==>> ((a*b-c))+((b-c)*d)
    fgets(input, MAX_EXPRESSION_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    struct Node syntaxTree[MAX_NODES], DAG[MAX_NODES];
    int syntaxTreeIndex = 0, DAGIndex = 0;
    struct {
        char label;
        int ptr;
    } stack[MAX_NODES];
    int stackTop = -1;

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (isalpha(c) || isdigit(c)) {
            syntaxTree[syntaxTreeIndex].label = c;
            syntaxTree[syntaxTreeIndex].ptr = syntaxTreeIndex;
            syntaxTree[syntaxTreeIndex].left = -1;
            syntaxTree[syntaxTreeIndex].right = -1;
            if (stackTop >= 0 && stack[stackTop].label == '(') {
                syntaxTree[syntaxTreeIndex].left = stack[stackTop].ptr;
                stackTop--;
            }
            syntaxTreeIndex++;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            struct Node newNode;
            newNode.label = c;
            newNode.ptr = syntaxTreeIndex;
            newNode.left = -1;
            newNode.right = -1;
            if (stackTop >= 0 && stack[stackTop].label == '(') {
                newNode.left = stack[stackTop].ptr;
                stackTop--;
            } else {
                newNode.right = stack[stackTop--].ptr;
                newNode.left = stack[stackTop--].ptr;
            }
            syntaxTree[syntaxTreeIndex++] = newNode;
            // Only add unique nodes to DAG
            int found = 0;
            for (int j = 0; j < DAGIndex; j++) {
                if (DAG[j].ptr == newNode.ptr && DAG[j].label == newNode.label &&
                    DAG[j].left == newNode.left && DAG[j].right == newNode.right) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                DAG[DAGIndex++] = newNode;
            }
        } else if (c == '(') {
            stack[++stackTop].label = c;
            stack[stackTop].ptr = syntaxTreeIndex;
        } else if (c == ')') {
            while (stackTop >= 0 && stack[stackTop].label != '(') {
                stackTop--;
            }
            if (stackTop >= 0 && stack[stackTop].label == '(') {
                stackTop--;
            }
        }
    }

    printf("\nSyntax Tree for the given expression:\n");
    printf("\n PTR \t LEFT PTR \t RIGHT PTR \t LABEL\n\n");
    for (int i = 0; i < syntaxTreeIndex; i++) {
        printf("%d\t%d\t%d\t%c\n", syntaxTree[i].ptr, syntaxTree[i].left, syntaxTree[i].right, syntaxTree[i].label);
    }

    printf("\nDirected Acyclic Graph (DAG) for the given expression:\n");
    printf("\n PTR \t LEFT PTR \t RIGHT PTR \t LABEL\n\n");
    for (int i = 0; i < DAGIndex; i++) {
        printf("%d\t%d\t%d\t%c\n", DAG[i].ptr, DAG[i].left, DAG[i].right, DAG[i].label);
    }

/*  Explanation
    Syntax Tree:

 PTR    LEFT PTR    RIGHT PTR    LABEL
This line represents the header of the table, indicating the meaning of each column in the syntax tree representation.

 0      0           -1           a
Node 0: It represents the variable 'a'.
LEFT PTR: 0 indicates that there's no left child for this node.
RIGHT PTR: -1 indicates that there's no right child for this node.
LABEL: 'a' indicates the label of this node.

 1      0           -1           *
Node 1: It represents the multiplication operation '*'.
LEFT PTR: 0 indicates that the left child of this node is Node 0.
RIGHT PTR: -1 indicates that there's no right child for this node.
LABEL: '*' indicates the label of this node.

 2      -1          -1           b
Node 2: It represents the variable 'b'.
LEFT PTR: -1 indicates that there's no left child for this node.
RIGHT PTR: -1 indicates that there's no right child for this node.
LABEL: 'b' indicates the label of this node.

 3      -1          45           -
Node 3: It represents the subtraction operation '-'.
LEFT PTR: -1 indicates that there's no left child for this node.
RIGHT PTR: 45 indicates that the right child of this node is Node 45.
LABEL: '-' indicates the label of this node.

 4      -1          -1           c
Node 4: It represents the variable 'c'.
LEFT PTR: -1 indicates that there's no left child for this node.
RIGHT PTR: -1 indicates that there's no right child for this node.
LABEL: 'c' indicates the label of this node.

 5      0           0            +
Node 5: It represents the addition operation '+'.
LEFT PTR: 0 indicates that the left child of this node is Node 0.
RIGHT PTR: 0 indicates that the right child of this node is Node 0.
LABEL: '+' indicates the label of this node.

 6      -1          -1           b
Node 6: It represents the variable 'b'.
LEFT PTR: -1 indicates that there's no left child for this node.
RIGHT PTR: -1 indicates that there's no right child for this node.
LABEL: 'b' indicates the label of this node.

 7      6           6            -
Node 7: It represents the subtraction operation '-'.
LEFT PTR: 6 indicates that the left child of this node is Node 6.
RIGHT PTR: 6 indicates that the right child of this node is Node 6.
LABEL: '-' indicates the label of this node.

 8      -1          -1           c
Node 8: It represents the variable 'c'.
LEFT PTR: -1 indicates that there's no left child for this node.
RIGHT PTR: -1 indicates that there's no right child for this node.
LABEL: 'c' indicates the label of this node.

 9      0           32760        *
Node 9: It represents the multiplication operation '*'.
LEFT PTR: 0 indicates that the left child of this node is Node 0.
RIGHT PTR: 32760 indicates that the right child of this node is Node 32760.
LABEL: '*' indicates the label of this node.

10      -1          -1           d
Node 10: It represents the variable 'd'.
LEFT PTR: -1 indicates that there's no left child for this node.
RIGHT PTR: -1 indicates that there's no right child for this node.
LABEL: 'd' indicates the label of this node.



Directed Acyclic Graph (DAG):

 PTR    LEFT PTR    RIGHT PTR    LABEL
This line represents the header of the table, indicating the meaning of each column in the DAG representation.


 1      0           -1           *
Node 1: It represents the multiplication operation '*' between 'a' and the result of the expression within parentheses.
LEFT PTR: 0 indicates that the left child of this node is Node 0.
RIGHT PTR: -1 indicates that there's no right child for this node.
LABEL: '*' indicates the label of this node.

 3      -1          45           -
Node 3: It represents the subtraction operation '-' between 'b' and 'c'.
LEFT PTR: -1 indicates that there's no left child for this node.
RIGHT PTR: 45 indicates that the right child of this node is Node 45.
LABEL: '-' indicates the label of this node.

 5      0           0            +
Node 5: It represents the addition operation '+' between the results of two expressions.
LEFT PTR: 0 indicates that the left child of this node is Node 0.
RIGHT PTR: 0 indicates that the right child of this node is Node 0.
LABEL: '+' indicates the label of this node.

 7      6           6            -
Node 7: It represents the subtraction operation '-' between 'b' and 'c' in the second expression.
LEFT PTR: 6 indicates that the left child of this node is Node 6.
RIGHT PTR: 6 indicates that the right child of this node is Node 6.
LABEL: '-' indicates the label of this node.

 9      0           32760        *
Node 9: It represents the multiplication operation '*' between the result of the first expression and 'd'.
LEFT PTR: 0 indicates that the left child of this node is Node 0.
RIGHT PTR: 32760 indicates that the right child of this node is Node 32760.
LABEL: '*' indicates the label of this node.
    return 0;
}
*/


