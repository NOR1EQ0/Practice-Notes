#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// 简易Hash
int hash(const int key) { return key % MAX_SIZE; }

// 键值对
typedef struct Pair {
    int key;
    char* val;
} Pair;

// 集合
typedef struct MapSet {
    void* set;
    int len;
} MapSet;


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

    int index = hash(key);
    hmap->buckets[index] = pair;
}

// 删除元素
void removeItem(ArrayHashMap* hmap, const int key) {
    int index = hash(key);
    free(hmap->buckets[index]->val);
    free(hmap->buckets[index]);
    hmap->buckets[index] = NULL;
}

// 获取所有键值对
void pairSet(ArrayHashMap* hmap, MapSet* set) {
    int total = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (hmap->buckets[i]) {
            ++total;
        }
    }
    Pair* entries = (Pair*)malloc(sizeof(Pair));
    for (int i = 0, index = 0; i < MAX_SIZE; ++i) {
        if (hmap->buckets[i]) {
            entries[index].key = hmap->buckets[i]->key;
            entries[index].val = (char*)malloc(strlen(hmap->buckets[i]->val) + 1);
            strcpy(entries[index].val, hmap->buckets[i]);
            index++;
        }
    }
    set->set = entries;
    set->len = total;
}

// 获取所有键
void keySet(ArrayHashMap* hmap, MapSet* set) {
    int total = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (hmap->buckets[i]) {
            total++;
        }
    }
    int* keys = (int*)malloc(sizeof(int)*total);
    for (int i = 0, index = 0; i < MAX_SIZE; ++i) {
        if (hmap->buckets[i]) {
            keys[index] = hmap->buckets[i]->key;
        }
    }
    return keys;
}

