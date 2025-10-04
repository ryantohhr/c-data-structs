#include "stack.h"
#include <stdio.h>

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

        printf("--- CREATING STACK ---\n");
        Stack *stack = create_stack();

        printf("--- PUSHING ITEMS ---\n");
        for (int i = 0; i < 5; i++) {
                push(stack, &i, sizeof(int));
        }

        printf("Stack after pushing: ");
        print_stack(stack);
        printf("Length: %zu nodes\n", stack->length);
        printf("Peek first item: %d\n", *(int *)peek(stack));

        printf("--- POPPING ITEMS ---");
        pop(stack);
        pop(stack);

        printf("Stack after popping: ");
        print_stack(stack);
        printf("Length: %zu nodes\n", stack->length);
        printf("Peek first item: %d\n", *(int *)peek(stack));

        printf("--- FREEING QUEUE ---\n");
        free_stack(stack);

        printf("END\n");
        return 0;
}
