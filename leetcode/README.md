# Notes for *LeetCode Problem Set*

At this directory, I will write my notes here.

These questions are machine-translated here, so there may be some texts confusing.

## 709 To Lower Case

Finshed on June 27, 2023.

### Description

You are given a string `s`, convert the uppercase letters in the string to the same lowercase letters, and return a new string.

**Example 1:**

> **Input:** s = "Hello"
> 
> **Output:** "hello"

**Example 2:**
 
> **Input:** s = "here"
> 
> **Output:** "here"

**Example 3:**

> **Input:** s = "LOVELY"
>
> **Output:** "lovely"

**Tips:**

* `1 <= s.length <= 100`
* `s` consists of printable characters from the ASCII character set

### Answer

```c
char * toLowerCase(char * s){
    char *i;
    for (i = s; *i; ++i)
        if (*i >= 'A' && *i <= 'Z')
            *i |= 32;
    return s;
}
```

## 2235 Add Two Integers

Finished on June 13, 2023. ~~WTF? The number of this question should be exchanged with [the first one](https://leetcode.cn/problems/two-sum)!~~

## Description

You are given two integers `num1` and `num2`, and you return the sum of those integers.

**Example 1:**

> **Input:** num1 = 12, num2 = 5
> 
> **Output:** 17
> 
> **Explanation:** num1 is 12, num2 is 5, and their sum is 12 + 5 = 17, so 17 is returned.

**Example 2:**

> **Input:** num1 = -10 and num2 = 4
> 
> **Output:** -6
> 
> **Explanation:** num1 + num2 = -6, so -6 is returned.

**Tips:**

* `-100 <= num1, num2 <= 100`

### Answer

Normal way

```c
int sum(int num1, int num2){
    return num1 + num2;
}
```

[Fancy ways from a comment from this question](https://leetcode.cn/problems/add-two-integers/description/comments/1524869)

## 2413 Smallest Even Multiple

Finished on June 22, 2023.

### Description

Given a positive integer `n`, it returns the least common multiple of `2` and `n` (a positive integer).

**Example 1:**

> **Input:** n = 5
>
> **Output:** 10
>
> **Explanation:** The least common multiple of 5 and 2 is 10.

**Example 2:**

> **Input:** n = 6
>
> **Output:** 6
>
> **Explanation:** The least common multiple of 6 and 2 is 6. Note that a number will be a multiple of itself.

**Tips:**

* `1 <= n <= 150`

### Answer

```c
int smallestEvenMultiple(int n){
    return n%2?n*2:n;
}
```

## 2651 Calculate Delayed Arrival Time

Finished on March 9, 2024.

### Description

You are given a positive integer `arrivalTime` that indicates how long (in hours) the train will arrive on time, and a positive integer `delayedTime` that indicates how many hours the train will be delayed.

Returns the actual arrival time of the train.

Note that the time in this problem is in the 24-hour system.

**Example 1:**

> **Input:** arrivalTime = 15, delayedTime = 5
> 
> **Output:** 20
> 
> **Explanation:** The train arrives on time at 15:00 and is delayed for 5 hours, so the actual arrival time of the train is 15 + 5 = 20 (20:00).

**Example 2:**

> **Input:** arrivalTime = 13, delayedTime = 11
> 
> **Output:** 0
> 
> **Explanation:** The train arrives on time at 13:00 and is delayed for 11 hours, so the actual arrival time is 13 + 11 = 24 (00:00 in the 24-hour system, so 0 is returned).

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
## 2769 Find the Maximum Achievable Number

Finished on March 10, 2024.

### Description

I give you two integers num and t.

An integer `x` is said to be reachable if it can be made equal to `num` no more than `t` times by performing the following operations:

* Each operation increments or decrements the value of `x` by one, and optionally increases or decreases the value of `num` by `1`.

Returns the maximum of all achievable numbers. It can be shown that there exists at least one achievable number.



**Example 1:**

> **Input:** num = 4, t = 1
> 
> **Output:** 6
> 
> **Explanation:** The largest achievable number is x = 6, which can be set to num by:
> 
> - x is decreased by 1 while num is increased by 1. In this case, x = 5 and num = 5.
> 
> It can be shown that there is no achievable number greater than 6.
>

**Example 2:**

> **Input:** num = 3, t = 2
> 
> **Output:** 7
>
> **Explanation:** The largest achievable number is x = 7, which can be set to num by doing the following:
>
> - x is decreased by 1 while num is increased by 1. In this case, x = 6 and num = 4.
>
> - x is decreased by 1 while num is increased by 1. In this case, x = 5 and num = 5.
>

It can be shown that there is no achievable number greater than 7.


Tips:

* `1 <= num, t <= 50`

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
