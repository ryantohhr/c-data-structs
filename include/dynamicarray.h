#include <stddef.h>

typedef struct {
        void *data;
        size_t length;
        size_t capacity;
        size_t element_size;
} DynamicArray;

DynamicArray *create_array(size_t element_size);
void free_array(DynamicArray *array);

void *get(DynamicArray *array, int index);
void set(DynamicArray *array, int index, void *item, size_t size);
void push(DynamicArray *array, void *item, size_t size);
void *pop(DynamicArray *array);
