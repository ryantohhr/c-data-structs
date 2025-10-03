#include <stddef.h>
#include <stdlib.h>

typedef struct Node {
        void *data;
        struct Node *next;
} Node;

typedef struct {
        Node *head;
        Node *tail;
        size_t length;
} Queue;

Queue *create_queue();
void free_queue(Queue *queue);

void enqueue(Queue *queue, void *item, size_t size);
void *deque(Queue *queue);
void *peek(Queue *queue);
