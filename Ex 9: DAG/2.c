#include <stdio.h>
#include <stdlib.h>

struct Node {
    char label;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char label) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->label = label;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node* node, struct Node* leftChild, struct Node* rightChild) {
    node->left = leftChild;
    node->right = rightChild;
}

// Function to print the DAG
void printDAG(struct Node* node) {
    if (node != NULL) {
        printf("Label: %c\n", node->label);

        printf("Left child: ");
        if (node->left != NULL)
            printf("%c\n", node->left->label);
        else
            printf("NULL\n");

        printf("Right child: ");
        if (node->right != NULL)
            printf("%c\n", node->right->label);
        else
            printf("NULL\n");

        printf("\n");

        // Recursively print the left and right subtrees
        printDAG(node->left);
        printDAG(node->right);
    }
}

int main() {
    // Create nodes
    struct Node* nodeA = createNode('A');
    struct Node* nodeB = createNode('B');
    struct Node* nodeC = createNode('C');
    struct Node* nodeD = createNode('D');
    struct Node* nodeE = createNode('E');

    // Build the DAG
    addEdge(nodeA, nodeB, nodeC);
    addEdge(nodeB, nodeD, NULL);
    addEdge(nodeC, nodeD, nodeE);

    // Print the DAG
    printf("Directed Acyclic Graph (DAG):\n");
    printDAG(nodeA);

    return 0;
}
