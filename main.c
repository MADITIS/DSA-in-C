#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

int peek(Stack *stack);
bool push(Stack *stack, int value);

void init_stack(Stack *stack);

int main() {
    Stack *stack;
    init_stack(&stack);
    push(&stack, 4);
    int value = peek(&stack);
    printf("%i", value);

}

void init_stack(Stack *stack) {
    stack -> top = NULL;
}

bool push(Stack *stack, int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Could not create memory");
        return false;
    }
    node -> value = value;
    node -> next = NULL;
    if (stack -> top == NULL) {
        stack -> top = node;
        return true;
    }
    Node *temp = stack -> top -> next;
    stack -> top = node;
    stack -> top -> next = temp;
    return true;
}

int peek(Stack *stack) {
    if (stack -> top == NULL) {
        printf("Empty stack");
        return 1;
    }
    int value = stack -> top -> value;
    return value;
}