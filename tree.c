#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;

} Node;


void inorder_traversal(Node* root);
void postorder(Node* root);
void preorder(Node* root);

Node* create_node(int value) {
    Node *node = malloc(sizeof(Node));
    // node -> value = value;
    if (node != NULL) {
        (*node).value = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    return 1;
 }

int main() {
    Node *n1 = create_node(12);
    Node *n6 = create_node(15);
    Node *n5 = create_node(14);
    Node *n7 = create_node(13);
    Node *n4 = create_node(16);
    Node *n3 = create_node(17);
    Node *n2 = create_node(18);

    n1 -> left = n2;
    n1 -> right = n3;
    n2 -> left = n4;
    n2 -> right = n5;
    n4 -> left = n6;
    n6 -> right = n7;
    inorder_traversal(n1);
    preorder(n1);
    postorder(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);

}

void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root -> left);
        printf("%i\n", root -> value);
        inorder_traversal(root -> right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        inorder_traversal(root -> left);
        inorder_traversal(root -> right);
        printf("%i\n", root -> value);
    }
}


void preorder(Node* root) {
    if (root != NULL) {
        printf("%i\n", root -> value);
        inorder_traversal(root -> left);
        inorder_traversal(root -> right);
    }
}

