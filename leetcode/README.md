# Notes for *LeetCode Problem Set*

At this directory, I will write my notes here.

These questions are machine-translated here, so there may be some texts confusing.

## Answer Status

|No.|Question|Tag|Difficulty|Status|Reproduction|
|----|----|----|----|----|----|
|1|Two Sum|`array` `hash-table`|Easy|Done|Done|
|709|To Lower Case|`string`|Easy|Done| |
|771|Jewels and Stones|`hash-table` `string`|Easy|Done| |
|1342|Number of Steps to Reduce A Number to Zero|`bit-manipulation` `math`|Easy|Done| |
|2235|Add Two Integers|`math`|Easy|Done| |
|2413|Smallest Even Multiple|`math` `number-theory`|Easy|Done| |
|2651|Calculate Delayed Arrival Time|`math`|Easy|Done| |
|2769|Find the Maximum Achievable Number|`math`|Easy|Done| |
|2864|Maximum Odd Binary Number|`greedy` `math` `string`|Easy|Done| |
|2942|Find Words Containing Character|`array` `string`|Easy|Done|Done|
|3028|Ant on the Boundary|`array` `prefix-sum` `simulation`|Easy|Done| |
|3065|Minimum Operations to Exceed Threshold Value|`array`|Easy|Done| |

**Notice:** The difficulty listed here is sorted by LeetCode.

## 1 Two Sum

Finished on March 16, 2024.

### Description

Given an array of integers `nums` and an integer target value `target`, find the **two** integers in the array that **sum up to the target value** and return their array indices.

You can assume that there will only be one answer for each input. However, the same array element cannot appear more than once in the answer.

You can return the answers in any order.

**Example 1:**

> **Input:** nums = [2,7,11,15], target = 9
> 
> **Output:** [0,1]
> 
> **Explanation:** Because nums[0] + nums[1] == 9, return [0, 1].

**Example 2:**

> **Input:** nums = [3,2,4], target = 6
> 
> **Output:** [1,2]

**Example 3:**

> **Input:** nums = [3,3], target = 6
> 
> **Output:** [0,1]


**Tips:**

* `2 <= nums.length <= 104`

* <code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code>

* <code>-10<sup>9</sup> <= target <= 10<sup>9</sup></code>

* **There will only be one valid answer**

**Advanced:** Can you think of an algorithm with a time complexity less than <code>O(n<sup>2</sup>)</code>?

### Answer

Brute-force travesal

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *arr = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
                break;
            }
        }
    }
    *returnSize = 2;
    return arr;
}
```

### Reproduction

File: [./1/two-sum.c](./1/two-sum.c)

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

## 771 Jewels and Stones

Finished on March 11, 2024.

### Description

You are given the string `jewels` for the type of stones in the stone, and the string `stones` for the stones you own. Each character in `stones` represents a type of stone you have, and you want to know how many of the stones you have are gems.

The letters are case sensitive, so `"a"` and `"A"` are different types of stones.

**Example 1:**

> **Input:** jewels = "aA", stones = "aAAbbbb"
> 
> **Output:** 3

**Example 2:**

> **Input:** jewels = "z", stones = "ZZ"
> 
> **Output:** 0

**Tip:**

* `1 <= jewels.length, stones.length <= 50`
* `jewels` and `stones` are made up of English letters only
* All characters in `jewels` are **unique**

### Answer

```c
int numJewelsInStones(char* jewels, char* stones) {
    int a = 0;
    for (int i = 0; i < strlen(stones); i++) {
        for (int k = 0; k < strlen(jewels); k++) {
            if (stones[i] == jewels[k]) {
                a++;
            }
        }
    }
    return a;
}
```

## 1342 Number of Steps to Reduce A Number to Zero

Finished on September 20, 2023.

### Description

Given a non-negative integer `num`, return the number of steps needed to turn it into 0. If the current number is even, you need to divide it by 2; Otherwise, subtract 1.



**Example 1:**

> **Input:** num = 14
> 
> **Output:** 6
> 
> **Explanation:**
> 
> Step 1) 14 is an even number, divide by 2 to get 7.
> 
> Step 2) 7 is odd, subtract 1 to get 6.
> 
> Step 3) 6 is an even number, divide by 2 to get 3.
> 
> Step 4) 3 is odd, subtract 1 to get 2.
> 
> Step 5) 2 is an even number, divide by 2 to get 1.
> 
> Step 6) 1 is odd, subtract 1 to get 0.

**Example 2:**

> **Input:** num = 8
> 
> **Output:** 4
> 
> **Explanation:**
> 
> Step 1) 8 is an even number, divide by 2 to get 4.
> 
> Step 2) 4 is an even number, divide by 2 to get 2.
> 
> Step 3) 2 is an even number, divide by 2 to get 1.
> 
> Step 4) 1 is odd, subtract 1 to get 0.

**Example 3:**

> **Input:** num = 123
> 
> **Output:** 12

**Tip:**

* `0 <= num <= 10^6`

### Answer

```c
int numberOfSteps(int num){
    int i = 0;
        while (num != 0){
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else{
                num--;
            }
            i++;
        }
        return i;
}
```

## 2235 Add Two Integers

Finished on June 13, 2023. ~~WTF? The number of this question should be exchanged with [the first one](https://leetcode.cn/problems/two-sum)!~~

### Description

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

You are given two integers `num` and `t`.

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

### Answer

```c
int theMaximumAchievableX(int num, int t){
    return num+t*2;
}
```

## 2864 Maximum Odd Binary Number

Finished on March 13, 2024.

### Description

You are given a **binary** string `s` that contains at least one `'1'`.

You have to `rearrange` the bits of the string in some way so that the resulting binary number is **the maximum binary odd number** that can be generated from the combination.

A string that represents and returns the largest binary odd number that can be generated by a given combination.

**Note** that the result string **can** contain leading zeros.



**Example 1:**

> **Input:** s = "010"
> 
> **Output:** "001"
> 
> **Explanation:** Because there is only one '1' in the string s, it must appear in the last digit. So the answer is "001".

**Example 2:**

> **Input:** s = "0101"
> 
> **Output:** "1001"
> 
> **Explanation:** One of the '1's must appear on the last digit. The largest number that can be produced from the remaining numbers is "100". So the answer is "1001".


**Tips:**

* `1 <= s.length <= 100`

* `s` only consists of `'0'` and `'1'`

* `s` contains at least one `'1'`

### Answer

Pointer 

```c
char* maximumOddBinaryNumber(char* s) {
    char *c = s, *ptr = s;
    for (; *c!='\0'; ++c)
        if (*c == '1')
            *c = '0', *ptr++ = '1';
    ptr[-1] = '0', c[-1] = '1';
    return s;
}
```

Other (Not yet available)

```c
char* maximumOddBinaryNumber(char* s) {

}
```

Count the numbers of `1` and `0` and return a temporary array

```c
char* maximumOddBinaryNumber(char* s) {
    
}
```

## 2942 Find Words Containing Character

Finished on March 13, 2024.

### Description

You are given an array of strings, `words`, starting at index **0**, and a character, `x`.

You need to return **an array of indices** where the word in the array contains the character `x`.

**Note** that the returned array can be in **any** order.

**Example 1:**

> **Input:** words = ["leet","code"], x = "e"
> 
> **Output:** [0,1]
> 
> **Explanation:** "e" appears in both words: "l**ee**t" and "cod**e**". So we return the indices 0 and 1.

**Example 2:**

> **Input:** words = ["abc","bcd","aaaa","cbc"], x = "a"
> 
> **Output:** [0,2]
> 
> **Explanation:** "a" appears in "**a**bc" and "**aaaa**", so we return the indices 0 and 2.

**Example 3:**

> **Input:** words = ["abc","bcd","aaaa","cbc"], x = "z"
> 
> **Output:** []
> 
> **Explanation:** "z" does not appear in any of the words. So we return an empty array.


Tips:

* `1 <= words.length <= 50`

* `1 <= words[i].length <= 50`

* `x` is a lowercase English letter.

* `words[i]` contains only lowercase English letters.

### Answer

```c
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int* arr = malloc(wordsSize * sizeof(int));
    int index = 0;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            if (words[i][j] == x) {
                arr[index++] = i;
                break;
            }
        }
    }
    *returnSize = index;
    return arr;
}
```

### Reproduction

File: [./2942/find-words-containing-character.c](./2942/find-words-containing-character.c)

Normative Way: [./2942/normative-reproduction.c](./2942/normative-reproduction.c)

## 3028 Ant on the Boundary

Finished on March 11, 2024.

### Description

There is an ant on the boundary, which sometimes goes **left** and sometimes **right**.

You are given an array of nonzero integers `nums`. Ants will read the elements of `nums` in order, starting from the first element to the end. At each step, the ant moves according to the current value of the element:

* If `nums[i] < 0`, move **left** by `-nums[i]` units.
* If `nums[i] > 0`, move **right** by `nums[i]` units.

Returns the number of times the ant **returns** to the boundary.

**Notice:**

* There is infinite space on either side of the boundary.
* Only if the ants move `| nums [I] |` unit and to check if it is on the border. In other words, if the ant simply crossed the boundary during the movement, it would not be counted.


**Example 1:**

> **Input:** nums = [2,3,-5]
> 
> **Output:** 1
> 
> **Explanation:** After step 1, the ant is 2 units away from the right side of the boundary.
> 
> After step 2, the ant is 5 units away from the right side of the boundary.
> 
> After step 3, the ant is located on the boundary.
> 
> So the answer is 1.

**Example 2:**

> **Input:** nums = [3,2,-3,-4]
> 
> **Output:** 0
> 
> **Explanation:** After step 1, the ant is 3 units away from the right side of the boundary.
> 
> After step 2, the ant is 5 units away from the right side of the boundary.
> 
> After step 3, the ant is 2 units away from the right side of the boundary.
> 
> After step 4, the ant is 2 units away from the left side of the boundary.
> 
> The ant never returns to the boundary, so the answer is 0.


**Tips:**

* `1 <= nums.length <= 100`

* `-10 <= nums[i] <= 10`

* `nums[i] ! = 0`

### Answer

```c
int returnToBoundaryCount(int* nums, int numsSize) {
    int a=0,k=0;
    for(int i=0;i<numsSize;i++){
        a+=nums[i];
        if(a==0)
        k++;
    }
    return k;
}
```

## 3065 Minimum Operations to Exceed Threshold Value I

Finished on March 10, 2024.

### Description

You are given an array of integers `nums` with index 0 and an integer `k`.

You can remove the smallest element of `nums` in a single operation.

You need to make all the elements of the array greater than or equal to `k`. Please return the **minimum** number of operations required.

**Tips:**

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
