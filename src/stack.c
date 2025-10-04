#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack *create_stack() {
        Stack *stack = malloc(sizeof(Stack));
        if (!stack) {
                printf("out of memory\n");
                return NULL;
        }

        stack->head = NULL;
        stack->tail = NULL;
        stack->length = 0;

        return stack;
}

void free_stack(Stack *stack) {
        if (!stack) {
                printf("invalid stack\n");
                return;
        }

        Node *curr = stack->head;

        while (curr) {
                Node *next = curr->next;
                free(curr->data);
                free(curr);
                curr = next;
        }

        free(stack);
}

void push(Stack *stack, void *item, size_t size) {
        if (!stack) {
                printf("invalid stack\n");
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
        new->next = stack->head;

        if (!stack->head) {
                stack->head = new;
                stack->tail = new;
                stack->length++;
                return;
        }

        stack->head = new;
        stack->length++;
}

void *pop(Stack *stack) {
        if (!stack) {
                printf("invalid stack\n");
                return NULL;
        }

        Node *curr = stack->head;
        stack->head = curr->next;
        stack->length--;
        void *data = curr->data;

        free(curr);
        return data;
}

void *peek(Stack *stack) {
        if (!stack) {
                printf("invalid stack \n");
                return NULL;
        }

        return stack->head->data;
}
