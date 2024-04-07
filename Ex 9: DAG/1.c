#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_LENGTH 25

struct dag_node {
    int ptr, left, right;
    char label;
};

int main() {
    struct dag_node dag[MAX_EXPRESSION_LENGTH];
    char input[MAX_EXPRESSION_LENGTH];

    printf("\nEnter the expression (limit is %d characters):\n", MAX_EXPRESSION_LENGTH);
    // Using that experssion as a input ==>> ((a*b-c))+((b-c)*d)
    fgets(input, MAX_EXPRESSION_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    int input_length = strlen(input);
    int dag_index = 0;
    char store;

    for (int i = 0; i < input_length; i++) {
        store = input[i];
        if (store != '(' && store != ')') {
            dag[dag_index].label = store;
            dag[dag_index].ptr = dag_index;
            dag[dag_index].left = -1; // Initialize left and right pointers
            dag[dag_index].right = -1;
            dag_index++;
        }
    }

    printf("\nSyntax tree for the given expression:\n");
    printf("\n PTR \t LEFT PTR \t RIGHT PTR \t LABEL\n\n");

    for (int i = 0; i < dag_index; i++) {
        printf("%d\t%d\t%d\t%c\n", dag[i].ptr, dag[i].left, dag[i].right, dag[i].label);
    }

    printf("\nDirected Acyclic Graph (DAG) for the given expression:\n");
    printf("\n PTR \t LEFT PTR \t RIGHT PTR \t LABEL\n\n");

    for (int i = 0; i < dag_index; i++) {
        printf("%d\t%d\t%d\t%c\n", dag[i].ptr, dag[i].left, dag[i].right, dag[i].label);
    }

    return 0;
}
