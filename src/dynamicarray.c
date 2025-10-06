#include "dynamicarray.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int STARTING_CAPACITY = 8;

DynamicArray *create_array(size_t element_size) {
        DynamicArray *array = malloc(sizeof(DynamicArray));
        if (!array) {
                printf("out of memory\n");
                return NULL;
        }

        array->length = 0;
        array->capacity = STARTING_CAPACITY;
        array->element_size = element_size;
        array->data = malloc(STARTING_CAPACITY * element_size);
        if (!array->data) {
                printf("out of memory\n");
                return NULL;
        }

        return array;
}

void free_array(DynamicArray *array) {
        if (!array) {
                printf("invalid array\n");
                return;
        }

        free(array->data);
        free(array);
}

size_t get_length(DynamicArray *array) {
        if (!array) {
                printf("invalid array\n");
                return 1;
        }

        return array->length;
}

void *get(DynamicArray *array, int index) {
        if (!array) {
                printf("invalid array\n");
                return NULL;
        }

        if (index > array->length || index < 0) {
                printf("invalid index: out of bounds");
                return NULL;
        }

        void *result = (char *)array->data + index * array->element_size;
        return result;
}

void set(DynamicArray *array, int index, void *item, size_t size) {
        if (!array) {
                printf("invalid array\n");
                return;
        }

        if (index > array->length || index < 0) {
                printf("invalid index: out of bounds\n");
                return;
        }

        if (size != array->element_size) {
                printf("invalid element size. use the same size declared on "
                       "creation.\n");
                return;
        }

        void *copy_location = (char *)array->data + index * array->element_size;
        memcpy(copy_location, item, size);
}

void resize_array(DynamicArray *array) {
        if (!array) {
                printf("invalid array\n");
                return;
        }

        printf("--- RESIZING ARRAY ---\n");

        array->capacity *= 2;
        void *new_data =
            reallocarray(array->data, array->capacity, array->element_size);
        if (!new_data) {
                free_array(array);
                printf("out of memory\n");
                return;
        }
        array->data = new_data;
}

void push(DynamicArray *array, void *item, size_t size) {
        if (!array) {
                printf("invalid array\n");
                return;
        }

        if (size != array->element_size) {
                printf("invalid element size. use the same size declared on "
                       "creation.\n");
                return;
        }

        if (array->length == array->capacity) {
                resize_array(array);
        }

        char *base = (char *)array->data;
        void *copy_location = base + array->length * array->element_size;
        memcpy(copy_location, item, size);
        array->length++;
}
