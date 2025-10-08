#include "dynamicarray.h"
#include <stdio.h>

void print_array(DynamicArray *array) {
        if (!array) {
                printf("invalid array\n");
                return;
        }

        for (int i = 0; i < array->length; i++) {
                void *ptr_to_print =
                    (char *)array->data + i * array->element_size;
                printf("%d ", *(int *)ptr_to_print);
        }
        printf("\n");
}

int main(void) {

        int i;

        printf("\n--- CREATING ARRAY ---\n");
        DynamicArray *array = create_array(sizeof(int));

        printf("\n--- PUSHING ITEMS ---\n");
        for (i = 0; i < 5; i++) {
                push(array, &i, sizeof(int));
        }
        printf("Array after pushing: ");
        print_array(array);
        printf("Length of array: %zu\n", get_length(array));
        printf("Capacity of array: %zu\n", array->capacity);
        printf("Element at position 3: %d\n", *(int *)get(array, 2));

        printf("\n--- SETTING ELEMENT 3 to 21 ---\n");
        i = 21;
        set(array, 2, &i, sizeof(int));
        printf("Array after setting: ");
        print_array(array);

        printf("\n--- PUSHING ITEMS PAST CAPACITY ---\n");
        for (i = 5; i < 10; i++) {
                printf("push %d\n", i);
                push(array, &i, sizeof(int));
        }
        printf("Array after pushing: ");
        print_array(array);
        printf("Length of array: %zu\n", get_length(array));
        printf("Capacity of array: %zu\n", array->capacity);

        printf("\n--- POPPING ITEM ---\n");
        for (i = 0; i < 5; i++) {
                printf("Popped: %d\n", *(int *)pop(array));
        }
        printf("Array after popping: ");
        print_array(array);
        printf("Length of array: %zu\n", get_length(array));
        printf("Capacity of array: %zu\n", array->capacity);

        printf("\n--- FREEING ARRAY ---\n");
        free_array(array);

        return 0;
}
