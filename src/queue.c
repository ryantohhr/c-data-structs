#include "queue.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue *create_queue() {
        Queue *queue = malloc(sizeof(Queue));
        if (!queue) {
                printf("out of memory\n");
                return NULL;
        }

        queue->head = NULL;
        queue->tail = NULL;
        queue->length = 0;

        return queue;
}

void free_queue(Queue *queue) {
        if (!queue) {
                printf("invalid queue\n");
                return;
        }

        Node *curr = queue->head;

        while (curr) {
                Node *next = curr->next;
                free(curr->data);
                free(curr);
                curr = next;
        }

        free(queue);
}

void enqueue(Queue *queue, void *item, size_t size) {
        if (!queue) {
                printf("invalid queue\n");
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

        if (!queue->head) {
                queue->head = new;
                queue->tail = new;
                queue->length++;
                return;
        }

        queue->tail->next = new;
        queue->tail = new;
        queue->length++;
}

void *deque(Queue *queue) {
        if (!queue) {
                printf("invalid queue\n");
                return NULL;
        }

        Node *curr = queue->head;
        queue->head = curr->next;
        queue->length--;
        void *data = curr->data;

        free(curr);
        return data;
}

void *peek(Queue *queue) {
        if (!queue) {
                printf("invalid queue\n");
                return NULL;
        }

        return queue->head->data;
}
