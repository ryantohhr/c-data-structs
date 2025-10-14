#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
        assert(*(int *)peek(stack) == 4);

        // Test pop
        for (i = 0; i < 2; i++) {
                j = (int *)pop(stack);
                assert(*j == 4 - i);
                free(j);
                j = NULL;
        }
        assert(stack->length == 3);

        free_stack(stack);
        printf("\nALL TESTS PASSED!\n");

        return 0;
}
