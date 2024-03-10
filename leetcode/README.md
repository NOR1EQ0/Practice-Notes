# Notes for *LeetCode Problem Set*

At this directory, I will write my notes here.

These questions are machine-translated here, so there may be some texts confusing.

## 2413 Smallest Even Multiple

Finished on June 22, 2023.

### Description

Given a positive integer `n`, it returns the least common multiple of `2` and `n` (a positive integer).

**Example 1:**

> Input: n = 5
>
> Output: 10
>
> Explanation: The least common multiple of 5 and 2 is 10.

**Example 2:**

> Input: n = 6
>
> Output: 6
>
> Explanation: The least common multiple of 6 and 2 is 6. Note that a number will be a multiple of itself.

**Tips:**

* `1 <= n <= 150`

## 2651 Calculate Delayed Arrival Time

Finished on March 9, 2024.

### Description

You are given a positive integer `arrivalTime` that indicates how long (in hours) the train will arrive on time, and a positive integer `delayedTime` that indicates how many hours the train will be delayed.

Returns the actual arrival time of the train.

Note that the time in this problem is in the 24-hour system.

**Example 1:**

> Input: arrivalTime = 15, delayedTime = 5
> 
> Output: 20
> 
> Explanation: The train arrives on time at 15:00 and is delayed for 5 hours, so the actual arrival time of the train is 15 + 5 = 20 (20:00).

**Example 2:**

> Input: arrivalTime = 13, delayedTime = 11
> 
> Output: 0
> 
> Explanation: The train arrives on time at 13:00 and is delayed for 11 hours, so the actual arrival time is 13 + 11 = 24 (00:00 in the 24-hour system, so 0 is returned).

**Tips:**

* `1 <= arrivaltime < 24`
* `1 <= delayedTime <= 24`

### Answer

No.1

```c
int findDelayedArrivalTime(int arrivalTime, int delayedTime){
    return arrivalTime+delayedTime<24?arrivalTime+delayedTime:arrivalTime+delayedTime-24;
}
```

No.2

```c
int findDelayedArrivalTime(int arrivalTime, int delayedTime){
    return (arrivalTime + delayedTime) % 24;
}
```

## 3065 Minimum Operations to Exceed Threshold Value I

Finished on March 10, 2024.

### Description

You are given an array of integers `nums` with index 0 and an integer `k`.

You can remove the smallest element of `nums` in a single operation.

You need to make all the elements of the array greater than or equal to `k`. Please return the **minimum** number of operations required.

Tips:

* `1 <= nums.length <= 50`
* `1 <= nums[i] <= 109`
* `1 <= k <= 109`
* The input guarantees that at least one subscript `i` such that `nums[i] >= k` exists.

**Example 1:**

> Input: nums = [2,11,10,1,3], k = 10
>
> Output: 3
>
> Explanation: After the first operation, nums becomes [2, 11, 10, 3].
>
> After the second operation, nums becomes [11, 10, 3].
>
> After the third operation, nums becomes [11, 10].
>
> At this point, all elements in the array are greater than or equal to 10, so we stop the operation.
>
> The minimum number of operations required to make all elements of an array greater than or equal to 10 is three.

**Example 2:**
 
> Input: nums = [1,1,2,4,9], k = 1
> 
> Output: 0
> 
> Explanation: All the elements in the array are greater than or equal to 1, so there is no need to do anything with nums.

**Example 3:**

> Input: nums = [1,1,2,4,9], k = 9
> 
> Output: 4
> 
> Explanation: Only one element in nums is greater than or equal to 9, so four operations are performed.

### Answer

```c
int minOperations(int* nums, int numsSize, int k) {
    int a = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < k)
            a++;
    }
    return a;
}
```
