#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_stack(Stack *stack) {
        if (!stack) {
                printf("invalid stack\n");
                return;
        }
        Node *curr = stack->head;
        while (curr) {
                printf("%i ", *(int *)curr->data);
                if (!curr->next)
                        printf("\n");
                curr = curr->next;
        }
}

int main(void) {

        int i;
        int *j;

        // Test create_stack
        Stack *stack = create_stack();
        assert(stack != NULL);

        // Test push
        for (i = 0; i < 5; i++) {
                push(stack, &i, sizeof(int));
        }
        assert(stack->length == 5);

        // Test peek
        assert(*(int *)peek(stack) == 0);

        // Test pop
        for (i = 0; i < 2; i++) {
                j = (int *)pop(stack);
                assert(*j == i);
                free(j);
                j = NULL;
        }
        assert(stack->length == 3);

        free_stack(stack);

        return 0;
}
