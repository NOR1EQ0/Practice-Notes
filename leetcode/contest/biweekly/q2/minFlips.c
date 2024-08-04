int minFlips(int** grid, int gridSize, int* gridColSize) {
    int ans0 = 0, ans1 = 0;
    for (int i = 0; i < gridSize; ++i) {
        int headPos = 0, tailPos = gridColSize - 1;
        int head = grid[i][0], tail = grid[i][tailPos];
        for (;tailPos - headPos < 1; ) {
            if (head != tail) {
                head = tail;
                ++ans0;
            }
            ++headPos, --tailPos;
            head = grid[i][headPos], tail = grid[i][tailPos];
        }
    }

    for (int i = 0; i < gridColSize; ++i) {
        int headPos = 0, tailPos = gridSize - 1;
        int head = grid[0][i], tail = grid[tailPos][i];
        for (;tailPos - headPos < 1; ) {
            if (head != tail) {
                head = tail;
                ++ans0;
            }
            ++headPos, --tailPos;
            head = grid[headPos][i], tail = grid[tailPos][i];
        }
    }

    return ans0 < ans1 ? ans0 : ans1;
}