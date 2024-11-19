#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// 键值对
typedef struct Pair
{
    int key;
    char* val;
} Pair;

// 基于数组实现
typedef struct ArrayHashMap {
    Pair* buckets[MAX_SIZE];
} ArrayHashMap;

// 构造
ArrayHashMap* newArrayHashMap() {
    ArrayHashMap* hmap = (ArrayHashMap*)malloc(sizeof(ArrayHashMap));
    // memset(map->buckets, NULL, sizeof(Pair*) * MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; ++i) {
        hmap->buckets[i] = NULL;
    }
    return hmap;
}

// 析构
void delArrayHashMap(ArrayHashMap* hmap) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (hmap->buckets[i]) {
            free(hmap->buckets[i]->val);
            free(hmap->buckets[i]);
        }
    }
    free(hmap);
}

// 添加
void put(ArrayHashMap* hmap, const int key, const char* val) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair->key = key;
    pair->val = (char*)malloc(strlen(val) + 1);
    strcpy(pair->val, val);

    int index = hashFunc(key);
    hmap->buckets[index] = pair;
}