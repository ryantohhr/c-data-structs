#include <stddef.h>
#include <stdint.h>

typedef struct {
        const char *key;
        void *value;
} Entry;

typedef struct {
        Entry *data;
        size_t length;
        size_t capacity;
} HashMap;

HashMap *create_map();
void free_map(HashMap *map);

void set(HashMap *map, char *key, void *value, size_t size);
void *get(HashMap *map, char *key);
