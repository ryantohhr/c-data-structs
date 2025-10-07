#include "doublyll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DoublyLinkedList *create_dll() {
        DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
        if (!list) {
                printf("out of memory\n");
                return NULL;
        }

        list->head = NULL;
        list->tail = NULL;
        list->length = 0;

        return list;
}

void free_dll(DoublyLinkedList *list) {
        if (!list) {
                printf("invalid list\n");
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

void insert_at(DoublyLinkedList *list, int index, void *item, size_t size) {
        if (!list) {
                printf("invalid list\n");
                return;
        }

        if (!(index >= 0 && index <= list->length)) {
                printf("invalid index: out of bounds\n");
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

        if (index == 0) {
                if (list->head) {
                        list->head->prev = new;
                } else {
                        list->tail = new;
                }
                new->next = list->head;
                new->prev = NULL;
                list->head = new;
        } else if (index == list->length) {
                list->tail->next = new;
                new->next = NULL;
                new->prev = list->tail;
                list->tail = new;
        } else {
                Node *curr = list->head;
                Node *prev = NULL;
                for (int i = 0; i < index; i++) {
                        prev = curr;
                        curr = curr->next;
                }

                curr->prev = new;
                prev->next = new;
                new->next = curr;
                new->prev = prev;
        }

        list->length++;
}

void *remove_at(DoublyLinkedList *list, int index) {
        if (!list) {
                printf("invalid list\n");
                return NULL;
        }

        if (!(index >= 0 && index <= list->length)) {
                printf("invalid index: out of bounds\n");
                return NULL;
        }

        if (index == 0) {
                Node *old_head = list->head;
                void *data = old_head->data;
                list->head = old_head->next;
                list->head->prev = NULL;
                list->length--;
                free(old_head);

                return data;
        } else if (index == list->length) {
                Node *old_tail = list->tail;
                void *data = old_tail->data;
                list->tail = old_tail->prev;
                list->tail->next = NULL;
                list->length--;
                free(old_tail);

                return data;
        } else {
                Node *curr = list->head;
                Node *prev;
                for (int i = 0; i < index; i++) {
                        prev = curr;
                        curr = curr->next;
                }
                void *data = curr->data;
                Node *node_to_remove = curr;
                prev->next = node_to_remove->next;
                node_to_remove->next->prev = prev;
                list->length--;
                free(node_to_remove);

                return data;
        }
}

void *search(DoublyLinkedList *list, void *item, int *index_ptr) {
        if (!list) {
                printf("invalid list\n");
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
                while (curr) {
                        if (*(int *)curr->data == *(int *)item)
                                return (void *)index;
                        curr = curr->next;
                        *index += 1;
                }

                printf("item not found\n");
                free(index);
                return NULL;
        }

        if (index_ptr) {
                if (!(*index_ptr >= 0 && *index_ptr < list->length)) {
                        printf("invalid index: out of bounds\n");
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

void traverse(DoublyLinkedList *list, void (*callback)(void *)) {
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
