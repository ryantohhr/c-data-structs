#include "dynamicarray.h"
#include <assert.h>
#include <stdio.h>

int main(void) {

        int i;

        // Test create_array
        DynamicArray *array = create_array(sizeof(int));
        assert(array != NULL);

        // Test push
        for (i = 0; i < 5; i++) {
                push(array, &i, sizeof(int));
        }
        assert(array->length == 5);
        assert(array->capacity == 8);

        // Test get
        assert(*(int *)get(array, 2) == 2);

        // Test set
        i = 21;
        set(array, 2, &i, sizeof(int));
        assert(*(int *)get(array, 2) == 21);

        // Test resize
        for (i = 5; i < 10; i++) {
                push(array, &i, sizeof(int));
        }
        assert(array->capacity == 16);

        // Test pop
        for (i = 0; i < 5; i++) {
                assert(*(int *)pop(array) == 9 - i);
        }

        free_array(array);
        printf("\nALL TESTS PASSED!\n");

        return 0;
}
