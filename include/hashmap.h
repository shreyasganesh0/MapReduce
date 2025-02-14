#ifndef HASHMAP_H
#define HASHMAP_H

#define BUCKET_COUNT 6
#define LOAD_FACTOR 0.75
#define INITIAL_CAPACITY 2000
#include <stdint.h>

typedef struct {
    char *key;
    int *value;
    int is_occupied;
} hash_node_t;

typedef struct {
    hash_node_t *nodes;
    int capacity;
    int size;
} hash_map_t;

unsigned long hash_function(const char *key);

hash_map_t *create_hashmap(int capacity);

void hashmap_iterate(hash_map_t *map, char *userID);

void hashmap_insert(hash_map_t *map, const char *key, int *value);

int *hashmap_get(hash_map_t *map, const char *key);

void hashmap_delete(hash_map_t *map, const char *key);

void free_hashmap(hash_map_t *map);

#endif
