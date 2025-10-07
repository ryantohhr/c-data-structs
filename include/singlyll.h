#include <stddef.h>

typedef struct Node {
        void *data;
        struct Node *next;
} Node;

typedef struct {
        Node *head;
        size_t length;
} SinglyLinkedList;

SinglyLinkedList *create_sll();
void free_sll(SinglyLinkedList *list);

void insert_front(SinglyLinkedList *list, void *item, size_t size);
void insert_back(SinglyLinkedList *list, void *item, size_t size);
void *remove_front(SinglyLinkedList *list);
void *remove_back(SinglyLinkedList *list);
void *search(SinglyLinkedList *list, void *item, int *index);
void traverse(SinglyLinkedList *list, void (*func)(void *item));
