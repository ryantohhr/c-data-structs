#include "hashmap.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {

        int i;
        int j;

        // Test create_map
        HashMap *map = create_map();
        assert(map != NULL);

        // Test get and set
        i = 3;
        set(map, "hello", &i, sizeof(i));
        assert(*(int *)get(map, "hello") == i);

        // Test expand
        set(map, "queue", &i, sizeof(i));
        set(map, "stack", &i, sizeof(i));
        set(map, "node", &i, sizeof(i));
        set(map, "array", &i, sizeof(i));
        set(map, "linkedlist", &i, sizeof(i));
        set(map, "makefile", &i, sizeof(i));
        set(map, "cmake", &i, sizeof(i));
        set(map, "bye", &i, sizeof(i));
        assert(map->capacity == 32);
        assert(map->length == 9);

        free_map(map);
        printf("\nALL TESTS PASSED!\n");

        return 0;
}
