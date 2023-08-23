#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int length;
} Queue;

void init(Queue *queue) {
    queue ->head = NULL;
    queue ->tail = NULL;
    queue ->length = 1;

}

void enqueue(Queue *queue, int value) {
    Node *new_element = (Node *)malloc(sizeof(Node));
    new_element ->value = value;
    new_element ->next = NULL;

    if ((queue -> head == NULL) && (queue -> head == NULL)){
        queue -> head = new_element;
        queue -> tail = new_element;
        return;

    }

    queue -> tail ->next = new_element;
    queue -> tail = new_element;

    queue -> length++;

}

int main() {
    Queue queue;

    init(&queue);
    enqueue(&queue, 2);
    enqueue(&queue, 5);
    enqueue(&queue, 4);
    enqueue(&queue, 3);
    printf("%i", queue.head->value);
    printf("\nlength: %i", queue.length);

}