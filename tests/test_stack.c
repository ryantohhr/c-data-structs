#include "stack.h"
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

        printf("\n--- CREATING STACK ---\n");
        Stack *stack = create_stack();

        printf("\n--- PUSHING ITEMS ---\n");
        for (i = 0; i < 5; i++) {
                push(stack, &i, sizeof(int));
        }

        printf("Stack after pushing: ");
        print_stack(stack);
        printf("Length: %zu nodes\n", stack->length);
        printf("Peek first item: %d\n", *(int *)peek(stack));

        printf("\n--- POPPING ITEMS ---\n");
        for (i = 0; i < 2; i++) {
                j = (int *)pop(stack);
                printf("Popped: %d\n", *j);
                free(j);
        }

        printf("Stack after popping: ");
        print_stack(stack);
        printf("Length: %zu nodes\n", stack->length);
        printf("Peek first item: %d\n", *(int *)peek(stack));

        printf("\n--- FREEING QUEUE ---\n");
        free_stack(stack);

        printf("END\n");
        return 0;
}
