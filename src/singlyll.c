#include "singlyll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SinglyLinkedList *create_sll() {
        SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));
        if (!list) {
                printf("out of memory\n");
                return NULL;
        }

        list->head = NULL;
        list->length = 0;

        return list;
}

void free_sll(SinglyLinkedList *list) {
        if (!list) {
                printf("out of memory\n");
                return;
        }

        Node *curr = list->head;
        while (curr) {
                Node *next = curr->next;
                free(curr->data);
                free(curr);
                curr = next;
        }

        free(list);
}

void insert_front(SinglyLinkedList *list, void *item, size_t size) {
        if (!list) {
                printf("invalid list\n");
                return;
        }

        Node *new = malloc(sizeof(Node));
        if (!new) {
                printf("out of memory\n");
                return;
        }
        new->data = malloc(size);
        if (!new->data) {
                printf("out of memory\n");
                return;
        }
        memcpy(new->data, item, size);
        new->next = list->head;

        list->head = new;
        list->length++;
}

void insert_back(SinglyLinkedList *list, void *item, size_t size) {
        if (!list) {
                printf("invalid list\n");
                return;
        }

        Node *new = malloc(sizeof(Node));
        if (!new) {
                printf("out of memory\n");
                return;
        }
        new->data = malloc(size);
        if (!new->data) {
                printf("out of memory\n");
                return;
        }
        memcpy(new->data, item, size);
        new->next = NULL;

        if (!list->head) {
                list->head = new;
        } else {
                Node *curr = list->head;
                while (curr->next) {
                        curr = curr->next;
                }
                curr->next = new;
        }
        list->length++;
}

void *remove_front(SinglyLinkedList *list) {
        if (!list) {
                printf("invalid list\n");
                return NULL;
        }

        if (!list->head) {
                printf("no elements to remove\n");
                return NULL;
        }

        if (!list->head->next) {
                void *data = list->head->data;
                free(list->head);
                list->head = NULL;
                list->length--;

                return data;
        }

        Node *tmp = list->head;
        void *data = tmp->data;
        list->head = tmp->next;
        free(tmp);
        list->length--;
        return data;
}

void *remove_back(SinglyLinkedList *list) {
        if (!list) {
                printf("invalid list\n");
                return NULL;
        }

        if (!list->head) {
                printf("no elements to remove\n");
                return NULL;
        }

        if (!list->head->next) {
                void *data = list->head->data;
                free(list->head);
                list->head = NULL;
                list->length--;
                return data;
        }

        Node *curr = list->head;
        Node *prev;
        while (curr->next) {
                prev = curr;
                curr = curr->next;
        }

        void *data = curr->data;
        if (prev) {
                free(prev->next);
                prev->next = NULL;
        }
        list->length--;

        return data;
}

void *search(SinglyLinkedList *list, void *item, int *index_ptr) {
        if (!list) {
                printf("invalid list \n");
                return NULL;
        }

        if (item) {
                Node *curr = list->head;
                int *index = malloc(sizeof(int));
                if (!index) {
                        printf("out of memory\n");
                        return NULL;
                }
                *index = 0;
                if (*(int *)curr->data == *(int *)item)
                        return (void *)index;
                while (curr->next) {
                        if (*(int *)curr->data == *(int *)item) {
                                return (void *)index;
                        }
                        curr = curr->next;
                        *index += 1;
                }
                printf("item does not exist in array");
                free(index);
                return NULL;
        }

        if (index_ptr) {
                if (!(*index_ptr >= 0 && *index_ptr < list->length)) {
                        printf("invalid index: out of bounds");
                        return NULL;
                }
                Node *curr = list->head;
                for (int i = 0; i < *index_ptr; i++) {
                        curr = curr->next;
                }
                return curr->data;
        }

        printf("invalid usage: pass in pointer to an item in the list or to a "
               "valid index");
        return NULL;
}

void traverse(SinglyLinkedList *list, void (*callback)(void *item)) {
        if (!list) {
                printf("invalid list\n");
                return;
        }

        if (!callback) {
                printf("invalid callback function\n");
                return;
        }

        Node *curr = list->head;
        while (curr) {
                callback(curr->data);
                curr = curr->next;
        }
}
