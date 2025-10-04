#include <stddef.h>

typedef struct Node {
        void *data;
        struct Node *next;
} Node;

typedef struct Stack {
        Node *head;
        Node *tail;
        size_t length;
} Stack;

Stack *create_stack();
void free_stack(Stack *stack);

void push(Stack *stack, void *item, size_t size);
void *pop(Stack *stack);
void *peek(Stack *stack);
