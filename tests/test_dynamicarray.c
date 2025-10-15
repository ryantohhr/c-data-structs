#include "dynamicarray.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

        int i;
        int *j;

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
        j = (int *)get(array, 2);
        assert(*j == 2);
        free(j);

        // Test set
        i = 21;
        set(array, 2, &i, sizeof(int));
        j = (int *)get(array, 2);
        assert(*j == 21);
        free(j);

        // Test resize
        for (i = 5; i < 10; i++) {
                push(array, &i, sizeof(int));
        }
        assert(array->capacity == 16);

        // Test pop
        for (i = 0; i < 5; i++) {
                j = (int *)pop(array);
                assert(*j == 9 - i);
                free(j);
        }

        free_array(array);
        printf("\nALL TESTS PASSED!\n");

        return 0;
}
