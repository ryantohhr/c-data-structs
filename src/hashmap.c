#include "hashmap.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int STARTING_CAPACITY = 16;
const unsigned long FNV_OFFSET = 14695981039346656037UL;
const unsigned long FNV_PRIME = 1099511628211UL;

HashMap *create_map() {
        HashMap *map = malloc(sizeof(HashMap));
        if (!map) {
                printf("out of memory\n");
                exit(EXIT_FAILURE);
        }
        map->data = calloc(STARTING_CAPACITY, sizeof(Entry));
        if (!map->data) {
                printf("out of memory\n");
                exit(EXIT_FAILURE);
        }
        map->length = 0;
        map->capacity = STARTING_CAPACITY;

        return map;
}

void free_map(HashMap *map) {
        if (!map || !map->data) {
                printf("invalid map\n");
                return;
        }

        free(map->data);
        free(map);
}

static uint64_t hash_key(char *key) {
        uint64_t hash = FNV_OFFSET;
        for (char *p = key; *p != '\0'; p++) {
                hash ^= (uint64_t)(*p);
                hash *= FNV_PRIME;
        }

        return hash;
}

static void expand(HashMap *map) {
        map->data = reallocarray(map->data, map->capacity * 2, sizeof(Entry));
        if (!map->data) {
                printf("out of memory\n");
                exit(EXIT_FAILURE);
        }

        map->capacity *= 2;
}

void set(HashMap *map, char *key, void *value, size_t size) {
        if (!map) {
                printf("invalid hash map\n");
                return;
        }

        if (map->length >= map->capacity / 2) {
                expand(map);
        }

        uint64_t hash = hash_key(key);
        size_t index = (size_t)(hash & (uint64_t)(map->capacity - 1));
        while (map->data[index].key) {
                if (strcmp(map->data[index].key, key) == 0) {
                        map->data[index].value = value;
                        printf("Index 1: %zu\n", index);
                        return;
                }
                printf("Index 2: %zu\n", index);
                index = (index + 1) % map->capacity;
        }

        map->data[index].key = key;
        map->data[index].value = value;
        map->length++;
}

void *get(HashMap *map, char *key) {
        if (!map) {
                printf("invalid hash map\n");
                return NULL;
        }

        uint64_t hash = hash_key(key);
        size_t index = (size_t)(hash & (uint64_t)(map->capacity - 1));
        while (map->data[index].key != key) {
                index = (index + 1) % 16;
        }

        return map->data[index].value;
}
