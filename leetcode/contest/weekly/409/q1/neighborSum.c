#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int** grid;
    int gridSize;
    int gridColSize;
} neighborSum;

void position(neighborSum* obj, int** buf, int pos1, int pos2, int value) {
    pos1 = 0, pos2 = 0;
    for (int loop = 0; pos1 < obj->gridSize; ++pos1) {
        for (;pos2 < obj->gridColSize; ++pos2) {
            if (buf[pos1][pos2] == value) {
                loop = 1;
                break;
            }
        }
        if (loop)
            break;
    }
}

neighborSum* neighborSumCreate(int** grid, int gridSize, int* gridColSize) {
    neighborSum* obj = (neighborSum*)malloc(sizeof(neighborSum));
    obj->grid = grid;
    obj->gridSize = gridSize;
    obj->gridColSize = *gridColSize;
    return obj;
}

int neighborSumAdjacentSum(neighborSum* obj, int value) {
    int** buf = obj->grid;
    int pos1 = 0, pos2 = 0, ans = 0;
    position(obj, buf, pos1, pos2, value);
    if (pos1 > 0) {
        ans += buf[pos1 - 1][pos2];
    }
    if (pos1 < obj->gridSize - 1) {
        ans += buf[pos1 + 1][pos2];
    }
    if (pos2 > 0) {
        ans += buf[pos1][pos2 - 1];
    }
    if (pos2 < obj->gridColSize - 1) {
        ans += buf[pos1][pos2 + 1];
    }
    return ans;
}

int neighborSumDiagonalSum(neighborSum* obj, int value) {
    int** buf = obj->grid;
    int pos1 = 0, pos2 = 0, ans = 0;
    position(obj, buf, pos1, pos2, value);
    if (pos1 > 0 && pos2 > 0) {
        ans += buf[pos1 - 1][pos2 - 1];
    }
    if (pos1 > 0 && pos2 < obj->gridColSize - 1) {
        ans += buf[pos1 - 1][pos2 + 1];
    }
    if (pos1 < obj->gridSize - 1 && pos2 > 0) {
        ans += buf[pos1 + 1][pos2 - 1];
    }
    if (pos1 < obj->gridSize - 1 && pos2 < obj->gridColSize - 1) {
        ans += buf[pos1 + 1][pos2 + 1];
    }
    return ans;
}

void neighborSumFree(neighborSum* obj) {
    free(obj);
}

/**
 * Your neighborSum struct will be instantiated and called as such:
 * neighborSum* obj = neighborSumCreate(grid, gridSize, gridColSize);
 * int param_1 = neighborSumAdjacentSum(obj, value);

 * int param_2 = neighborSumDiagonalSum(obj, value);

 * neighborSumFree(obj);
*/