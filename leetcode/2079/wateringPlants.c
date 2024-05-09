#include <stdio.h>

int wateringPlants(int *plants, int plantsSize, int capacity)
{
    int tank = capacity, steps = 1;
    for (int pos = 0; plants[plantsSize - 1] != 0;)
    {
        if (tank < plants[pos])
        {
            tank = capacity;
            steps += pos * 2 + 1;
        }
        else
        {
            tank -= plants[pos];
            plants[pos] = 0;
            pos++, steps++;
        }
    }
    return steps;
}

int main()
{
    int plants[] = {2, 2, 3, 3};
    int capacity = 5;
    printf("%d", wateringPlants(plants, 4, capacity));
    return 0;
}