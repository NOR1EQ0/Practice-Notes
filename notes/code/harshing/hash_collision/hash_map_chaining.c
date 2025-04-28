#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    int key;
    char* val;
} Pair;

typedef struct Node
{
    Pair* pair;
    Node* next;
} Node;


typedef struct HashMapChaining
{
    int size;
    int capacity;
    double loadThres;
    int extendRatio;
    Node** buckets;
} HashMapChaining;

HashMapChaining* newHashMapChaining() {
    HashMapChaining* hmap = (HashMapChaining*)malloc(sizeof(HashMapChaining));
    hmap->size = 0;
    hmap->capacity = 4;
    hmap->loadThres = 2.0 / 3.0;
    hmap->extendRatio = 2;
    hmap->buckets = (Node**)malloc(sizeof(Node*) * hmap->capacity);
    for (int i = 0; i < hmap->capacity; ++i) {
        hmap->buckets[i] = NULL;
    }
    return hmap;
}

// 析构
void delHashMapChaining(HashMapChaining* hmap) {
    for (int i = 0; i < hmap->capacity; ++i) {
        Node* cur = hmap->buckets[i];
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
        }
    }
}

