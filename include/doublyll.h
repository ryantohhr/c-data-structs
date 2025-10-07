#include <stddef.h>

typedef struct Node {
        void *data;
        struct Node *next;
        struct Node *prev;
} Node;

typedef struct {
        Node *head;
        Node *tail;
        size_t length;
} DoublyLinkedList;

DoublyLinkedList *create_dll();
void free_dll(DoublyLinkedList *list);

void insert_at(DoublyLinkedList *list, int index, void *item, size_t size);
void *remove_at(DoublyLinkedList *list, int index);
void *search(DoublyLinkedList *list, void *item, int *index);
void traverse(DoublyLinkedList *list, void (*func)(void *));
