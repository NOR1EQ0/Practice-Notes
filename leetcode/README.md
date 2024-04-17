# Notes for *LeetCode Problem Set*

At this directory, I will write my notes here.

## Answer Status

|No.|Question|Tag|Difficulty|Status|Reproduction|
|----|----|----|----|----|----|
|1|Two Sum|`Array` `Hash Table`|Easy|Done|Done|
|3|Longest Substring Without Repeating Characters|`Hash Table` `String` `Sliding Window`|Medium|Done| |
|35|Search Insert Position|`Array` `Binary Search`|Easy|Done|Done|
|66|Plus One|`Array` `Math`|Easy|Idle| |
|256|Add Digits|`Math` `Number Theory` `Simulation`|Easy|Done|Done|
|322|Coin Change|`Breadth-First Search` `Array` `Dynamic Programming`|Medium|Delay| |
|434|Number of Segments in a String|`string`|Easy|Done|Done|
|518|Coin Change II|`Array` `Dynamic Programming`|Medium|Delay| |
|709|To Lower Case|`String`|Easy|Done| |
|771|Jewels and Stones|`Hash Table` `String`|Easy|Done| |
|1342|Number of Steps to Reduce a Number to Zero|`Bit Manipulation` `Math`|Easy|Done| |
|2235|Add Two Integers|`Math`|Easy|Done| |
|2413|Smallest Even Multiple|`Math` `Number Theory`|Easy|Done| |
|2529|Maximum Count of Positive Integer and Negative Integer|`Array` `Binary Search` `Counting`|Easy| | |
|2651|Calculate Delayed Arrival Time|`Math`|Easy|Done| |
|2744|Find Maximum Number of String Pairs|`Array` `Hash Table` `String` `Simulation`|Easy|Idle| |
|2769|Find the Maximum Achievable Number|`Math`|Easy|Done| |
|2864|Maximum Odd Binary Number|`Greedy` `Math` `String`|Easy|Done| |
|2894|Divisible and Non-divisible Sums Difference|`Math`|Easy|Done|Done|
|2942|Find Words Containing Character|`Array` `String`|Easy|Done|Done|
|3028|Ant on the Boundary|`Array` `Prefix Sum` `Simulation`|Easy|Done| |
|3065|Minimum Operations to Exceed Threshold Value|`Array`|Easy|Done| |
|3110|Score of a String|`String`|Easy|Done|Done|

**Notice:** The difficulty listed here is sorted by LeetCode.

----

Optimization List:

|No.|Optimization|Status|Comment / Barrier|
|----|----|----|----|
|3|Use pointers and remove redundant code|Stucked in LeetCode test|**Access violation**<br>Even [./3/lengthOfLongestSubstring.c](./3/lengthOfLongestSubstring.c) can be compiled with GCC without warnings and run on my Ubuntu system in my virtual machine. But obviously, access violation is a big problem.<br>Even if I already know that, but it seems that I may write some wrong expressions in the 15th row. Maybe I shouldn use `if`, not ternary operator. But I don't think this change will solve access violation. Maybe I should malloc and maintain a place for `*(right-1)`? But that's weired...<br>I shouldn't write such a long comment in this table here XD|

## 1 Two Sum

Finished on March 16, 2024.

### Description

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

**Example 1:**

> **Input:** nums = [2,7,11,15], target = 9
> 
> **Output:** [0,1]
> 
> **Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1].

**Example 2:**

> **Input:** nums = [3,2,4], target = 6
> 
> **Output:** [1,2]

**Example 3:**

> **Input:** nums = [3,3], target = 6
> 
> **Output:** [0,1]


**Constraints:**

* `2 <= nums.length <= 104`

* <code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code>

* <code>-10<sup>9</sup> <= target <= 10<sup>9</sup></code>

* **Only one valid answer exists.**

**Follow-up:** Can you come up with an algorithm that is less than <code>O(n<sup>2</sup>)</code> time complexity?

### Answer

Brute-force traversal

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

## 3 Longest Substring without Repeating Characters

Finished on March 23, 2024.

### Description

Given a string `s`, find the length of **longest substring** without repeating characters.

**Example 1:**

> **Input:** s = "abcabcbb"
> 
> **Output:** 3
> 
> **Explanation:** The answer is "abc", with the length of 3.

**Example 2:**

> **Input:** s = "bbbbb"
> 
> **Output:** 1
> 
> **Explanation:** The answer is "b", with the length of 1.

**Example 3:**

> **Input:** s = "pwwkew"
> 
> **Output:** 3
> 
> **Explanation:** The answer is "wke", with the length of 3.
> 
> Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

**Constraints:**

* <code>0 <= s.length <= 5 * 10<sup>4</sup></code>

* `s` consists of English letters, digits, symbols and spaces.

### Answer

First submission:

```c
int lengthOfLongestSubstring(char *s)
{
    int left = 0, right = 0, length = 0;
    while (s[right])
    {
        if (right - left >= length)
        {
            length = right - left;
        }
        int repeat = 0;
        for (int i = left; i < right; i++)
        {
            if (s[i] == s[right])
            {
                repeat = 1;
                break;
            }
        }
        if (repeat)
        {
            left++;
        }
        else if (s[left] == s[right] || s[right] == s[right - 1])
        {
            left = right++;
        }
        else
        {
            right++;
        }
    }
    if (right - left >= length)
    {
        length = right - left;
    }
    return length;
}
```

### Reproduction

First commission: [./3/firstSubmission.c](./3/firstSubmission.c)

## 35 Search Insert Position

Finished on March 20, 2024.

### Description

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

> **Input:** nums = [1,3,5,6], target = 5
> 
> **Output:** 2

**Example 2:**

> **Input:** nums = [1,3,5,6], target = 2
> 
> **Output:** 1

**Example 3:**

> **Input:** nums = [1,3,5,6], target = 7
> 
> **Output:** 4

**Constraints:**

* <code>1 <= nums.length <= 10<sup>4</sup></code>

* <code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code>

* `nums` contains **distinct** values sorted in **ascending** order.

* <code>-10<sup>4</sup> <= target <= 10<sup>4</sup></code>

### Answer

```c
int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1, mid;
    if (target > nums[numsSize - 1])
    {
        return numsSize;
    }
    while (left < right)
    {
        mid = (left + right) / 2;
        if (nums[mid] >= target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
```

### Reproduction

File: [./35/searchInsert.c](./35/searchInsert.c)

## 256 Add Digits

Finished on April 17, 2024.

### Description

Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.

**Example 1:**

> **Input:** num = 38
>
> **Output:** 2
>
> **Explanation:** The process is
>
> 38 --> 3 + 8 --> 11
>
> 11 --> 1 + 1 --> 2 
>
> Since 2 has only one digit, return it.

**Example 2:**

> Input: num = 0
>
> Output: 0

**Constraints:**

* <code>0 <= num <= 2<sup>31</sup> - 1</code>

## 322 Coin Change

Click [here](#518-coin-change-ii) to see the next part of **Coin Change**.

Haven't finished...

### Description

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return *the fewest number of coins that you need to make up that amount*. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

**Example 1:**

> **Input:** coins = `[1, 2, 5]`, amount = `11`
> 
> **Output:** `3`
> 
> **Explanation:** 11 = 5 + 5 + 1

**Example 2:**

> **Input:** coins = `[2]`, amount = `3`
> 
> **Output:** -1

**Example 3:**

> **Input:** coins = [1], amount = 0
> 
> **Output:** 0

**Constraints:**

* `1 <= coins.length <= 12`

* <code>1 <= coins[i] <= 2<sup>31</sup> - 1</code>

* <code>0 <= amount <= 10<sup>4</sup></code>

### Answer

*Empty*

### Reproduction

*Empty*

## 434 Number of Segments in a String

Finished on April 7, 2024.

### Description

Given a string `s`, return *the number of segments in the string*.

A **segment** is defined to be a contiguous of **non-space characters**.

**Example 1:**

> **Input:** s = "Hello, my name is John"
> 
> **Output:** 5
> 
> **Explanation:** The five segments are ["Hello,", "my", "name", "is", "John"]

**Example 2:**

> **Input:** s = "Hello"
> 
> **Output:** 1

**Constraints:**

* `0 <= s.length <= 300`

* `s` consists of lowercase and uppercase English letters, digits, or one of the following characters `"!@#$%^&*()_+-=',.:"`.

* The only space character in `s` is `' '`.

### Answer

```c
int countSegments(char *s)
{
    int ans = 0;
    for (char *i = s; *i; i++)
    {
        if (*i != ' ' && (*(i + 1) == ' ' ^ !*(i + 1)))
        {
            ans++;
        }
        else
            continue;
    }
    return ans;
}
```

### Reproduction

File: [./434/countSegments.c](./434/countSegments.c)

## 518 Coin Change II

Click [here](#322-coin-change) to see the previous part of **Coin Change II**.

Havent't finished...

## 709 To Lower Case

Finshed on June 27, 2023.

### Description

Given a string `s`, return *the string after replacing every uppercase letter with the same lowercase letter*.

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

**Constraints:**

* `1 <= s.length <= 100`

* `s` consists of printable ASCII characters.

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

You're given strings `jewels` representing the types of stones that are jewels, and `stones` representing the stones you have. Each character in `stones` is a type of stone you have. You want to know how many of the stones you have are also jewels.

The letters are case sensitive, so `"a"` and `"A"` are different types of stones.

**Example 1:**

> **Input:** jewels = "aA", stones = "aAAbbbb"
> 
> **Output:** 3

**Example 2:**

> **Input:** jewels = "z", stones = "ZZ"
> 
> **Output:** 0

**Constraints:**

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

Given an integer `num`, return *the number of steps to reduce it to zero*.

In one step, if the current number is even, you have to divide it by `2`, otherwise, you have to subtract `1` from it.

**Example 1:**

> **Input:** num = 14
> 
> **Output:** 6
> 
> **Explanation:**
> 
> Step 1) 14 is even; divide by 2 and obtain 7. 
> 
> Step 2) 7 is odd; subtract 1 and obtain 6.
> 
> Step 3) 6 is even; divide by 2 and obtain 3. 
> 
> Step 4) 3 is odd; subtract 1 and obtain 2. 
> 
> Step 5) 2 is even; divide by 2 and obtain 1. 
> 
> Step 6) 1 is odd; subtract 1 and obtain 0.

**Example 2:**

> **Input:** num = 8
> 
> **Output:** 4
> 
> **Explanation:**
> 
> Step 1) 8 is even; divide by 2 and obtain 4. 
> 
> Step 2) 4 is even; divide by 2 and obtain 2. 
> 
> Step 3) 2 is even; divide by 2 and obtain 1. 
> 
> Step 4) 1 is odd; subtract 1 and obtain 0.

**Example 3:**

> **Input:** num = 123
> 
> **Output:** 12

**Constraints:**

* <code>0 <= num <= 10<sup>6</sup></code>

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

Given two integers `num1` and `num2`, return *the **sum** of those integers*.

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

**Constraints:**

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

Given a **positive** integer `n`, return *the smallest positive integer that is a multiple of **both** `2` and `n`*.

**Example 1:**

> **Input:** n = 5
>
> **Output:** 10
>
> **Explanation:** The smallest multiple of both 5 and 2 is 10.

**Example 2:**

> **Input:** n = 6
>
> **Output:** 6
>
> **Explanation:** The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.

**Constraints:**

* `1 <= n <= 150`

### Answer

```c
int smallestEvenMultiple(int n){
    return n%2?n*2:n;
}
```

## 2529 Maximum Count of Positive Integer and Negative Integer

Haven't finished...

### Description

Given an array `nums` sorted in **non-decreasing** order, return *the maximum between the number of positive integers and the number of negative integers*.

* In other words, if the number of positive integers in `nums` is `pos` and the number of negative integers is `neg`, then return the maximum of `pos` and `neg`.

**Note** that `0` is neither positive nor negative.

**Example 1:**

> **Input:** nums = [-2,-1,-1,1,2,3]
> 
> **Output:** 3
> 
> **Explanation:** There are 3 positive integers and 3 negative integers. The maximum count among them is 3.

**Example 2:**

> **Input:** nums = [-3,-2,-1,0,0,1,2]
> 
> **Output:** 3
> 
> **Explanation:** There are 2 positive integers and 3 negative integers. The maximum count among them is 3.

**Example 3:**

> **Input:** nums = [5,20,66,1314]
> 
> **Output:** 4
> 
> **Explanation:** There are 4 positive integers and 0 negative integers. The maximum count among them is 4.

**Constraints:**

* `1 <= nums.length <= 2000`

* `-2000 <= nums[i] <= 2000`

* `nums` is sorted in **a non-decreasing order**.

**Follow up:** Can you solve the problem in `O(log(n))` time complexity?

### Answer

`O(n)` time complexity:

```c
int maximumCount(int *nums, int numsSize)
{
    int positiveCount = 0, negativeCount = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            positiveCount++;
        }
        else if (nums[i] < 0)
        {
            negativeCount++;
        }
    }
    return positiveCount > negativeCount ? positiveCount : negativeCount;
}
```

`O(log(n))` time complexity:

*Empty*

### Reproduction

`O(n)` time complexity: [./2529/maximumCount.c](./2529/maximumCount.c)

`O(log(n))` time complexity: *Empty*

## 2651 Calculate Delayed Arrival Time

Finished on March 9, 2024.

### Description

You are given a positive integer `arrivalTime` denoting the arrival time of a train in hours, and another positive integer `delayedTime` denoting the amount of delay in hours.

Return *the time when the train will arrive at the station*.

Note that the time in this problem is in 24-hours format.

**Example 1:**

> **Input:** arrivalTime = 15, delayedTime = 5
> 
> **Output:** 20
> 
> **Explanation:** Arrival time of the train was 15:00 hours. It is delayed by 5 hours. Now it will reach at 15+5 = 20 (20:00 hours).

**Example 2:**

> **Input:** arrivalTime = 13, delayedTime = 11
> 
> **Output:** 0
> 
> **Explanation:** Arrival time of the train was 13:00 hours. It is delayed by 11 hours. Now it will reach at 13+11=24 (Which is denoted by 00:00 in 24 hours format so return 0).

**Constraints:**

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

## 2744 Find Maximum Number of String Pairs

Haven't finished...

### Description

You are given a **0-indexed** array `words` consisting of **distinct** strings.

The string `words[i]` can be paired with the string `words[j]` if:

* The string `words[i]` is equal to the reversed string of `words[j]`.

* `0 <= i < j < words.length`.

Return *the **maximum** number of pairs that can be formed from the array words*.

Note that each string can belong in **at most one** pair.

**Example 1:**

> **Input:** words = ["cd","ac","dc","ca","zz"]
> 
> **Output:** 2
> 
> **Explanation:** In this example, we can form 2 pair of strings in the following way:
> 
> \- We pair the 0<sup>th</sup> string with the 2<sup>nd</sup> string, as the reversed string of word[0] is "dc" and is equal to words[2].
> 
> \- We pair the 1<sup>st</sup> string with the 3<sup>rd</sup> string, as the reversed string of word[1] is "ca" and is equal to words[3].
> 
> It can be proven that 2 is the maximum number of pairs that can be formed.

**Example 2:**

> **Input:** words = ["ab","ba","cc"]
> 
> **Output:** 1
> 
> **Explanation:** In this example, we can form 1 pair of strings in the following way:
> 
> \- We pair the 0<sup>th</sup> string with the 1<sup>st</sup> string, as the reversed string of words[1] is "ab" and is equal to words[0].
> 
> It can be shown that the maximum number of matches is one.

**Example 3:**

> **Input:** words = ["aa","ab"]
> 
> **Output:** 0
> 
> **Explanation:** In this example, we are unable to form any pair of strings.


**Constraints:**

* `1 <= words.length <= 50`

* `words[i].length == 2`

* `words` consists of distinct strings.

* `words[i]` contains only lowercase English letters.

### Answer

### Reproduction

FIle: [./2744/maximumNumberOfStringPairs.c](./2744/maximumNumberOfStringPairs.c)

## 2769 Find the Maximum Achievable Number

Finished on March 10, 2024.

### Description

You are given two integers, `num` and `t`.

An integer `x` is called **achievable** if it can become equal to `num` after applying the following operation no more than `t` times:

* Increase or decrease `x` by `1`, and simultaneously increase or decrease `num` by `1`.

Return *the maximum possible achievable number*. It can be proven that there exists at least one achievable number.

**Example 1:**

> **Input:** num = 4, t = 1
> 
> **Output:** 6
> 
> **Explanation:** The largest achievable number is x = 6, which can be set to num by:
> 
> 1- Decrease x by 1, and increase num by 1. Now, x = 5 and num = 5.
> 
> It can be proven that there is no achievable number larger than 6.

**Example 2:**

> **Input:** num = 3, t = 2
> 
> **Output:** 7
>
> **Explanation:** The maximum achievable number is x = 7; after performing these operations, x will equal num:
>
> 1- x is decreased by 1 while num is increased by 1. In this case, x = 6 and num = 4.
>
> 2- x is decreased by 1 while num is increased by 1. In this case, x = 5 and num = 5.
> 
> It can be shown that there is no achievable number greater than 7.


**Constraints:**

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

You have to **rearrange** the bits in such a way that the resulting binary number is the **the maximum binary odd number** that can be created from this combination.

Return *a string representing the maximum odd binary number that can be created from the given combination*.

**Note** that the result string **can** contain leading zeros.

**Example 1:**

> **Input:** s = "010"
> 
> **Output:** "001"
> 
> **Explanation:** Because there is just one '1', it must be in the last position. So the answer is "001".

**Example 2:**

> **Input:** s = "0101"
> 
> **Output:** "1001"
> 
> **Explanation:** One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".


**Constraints:**

* `1 <= s.length <= 100`

* `s` consists only of `'0'` and `'1'`

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

## 2894 Divisible and Non-Divisible Sums Difference

Finished on March 20, 2024.

### Description

You are given two positive integers `n` and `m`.

Define two integers, `num1` and `num2`, as follows:

* `num1`: he sum of all integers in the range `[1, n]` that are **not divisible** by `m`.

* `num2`: he sum of all integers in the range `[1, n]` that are **divisible** by `m`.

Returns *the integers* `num1-num2`.

**Example 1:**

> **Input:** n = 10, m = 3
>
> **Output:** 19
> 
> **Explanation:** In the given example:
> 
> \- Integers in the range [1, 10] that are not divisible by 3 are [1,2,4,5,7,8,10], num1 is the sum of those integers = 37.
>
> \- Integers in the range [1, 10] that are divisible by 3 are [3,6,9], num2 is the sum of those integers = 18.
>
> We return 37 - 18 = 19 as the answer.

**Example 2:**

> **Input:** n = 5, m = 6
> 
> **Output:** 15
> 
> **Explanation:** In the given example:
> 
> \- Integers in the range [1, 5] that are not divisible by 6 are [1,2,3,4,5], num1 is the sum of those integers = 15.
> 
> \- Integers in the range [1, 5] that are divisible by 6 are [], num2 is the sum of those integers = 0.
> 
> We return 15 - 0 = 15 as the answer.

**Example 3:**

> **Input:** n = 5, m = 1
>
> **Output:** -15
> 
> **Explanation:** In the given example:
> 
> \- Integers in the range [1, 5] that are not divisible by 1 are [], num1 is the sum of those integers = 0.
>
> \- Integers in the range [1, 5] that are divisible by 1 are [1,2,3,4,5], num2 is the sum of those integers = 15.
>
> We return 0 - 15 = -15 as the answer.

**Constraints:**

* `1 <= n, m <= 1000`

### Answer

```c
int differenceOfSums(int n, int m)
{
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i%m==0){
            num2+=i;
        }
        else
        {
            num1+=i;
        }
    }
    return num1-num2;
}
```

### Reproduction

File: [./2894/differentOfSums.c](./2894/differentOfSums.c)

## 2942 Find Words Containing Character

Finished on March 13, 2024.

### Description

You are given a **0-indexed** array of strings `words` and a character `x`.

Return *an **array of indices** representing the words that contain the character* `x`.

Note that the returned array may be in any order.

**Example 1:**

> **Input:** words = ["leet","code"], x = "e"
> 
> **Output:** [0,1]
> 
> **Explanation:** "e" occurs in both words: "l<u>**ee**</u>t", and "cod<u>**e**</u>". Hence, we return indices 0 and 1.

**Example 2:**

> **Input:** words = ["abc","bcd","aaaa","cbc"], x = "a"
> 
> **Output:** [0,2]
> 
> **Explanation:** "a" occurs in "<u>**a**</u>bc", and "<u>**aaaa**</u>". Hence, we return indices 0 and 2.

**Example 3:**

> **Input:** words = ["abc","bcd","aaaa","cbc"], x = "z"
> 
> **Output:** []
> 
> **Explanation:** "z" does not occur in any of the words. Hence, we return an empty array.


**Constraints:**

* `1 <= words.length <= 50`

* `1 <= words[i].length <= 50`

* `x` is a lowercase English letter.

* `words[i]` consists only of lowercase English letters.

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

An ant is on the boundary. It sometimes goes **left** and sometimes **right**.

You are given an array of **non-zero** integers `nums`. The ant starts reading `nums` from the first element of it to its end. At each step, it moves according to the value of the current element:

* If `nums[i] < 0`, it moves **left** by `-nums[i]` units.

* If `nums[i] > 0`, it moves **right** by `nums[i]` units.

Returns *the number of times the ant **returns** to the boundary*.

**Notes:**

* There is an infinite space on both sides of the boundary.

* We check whether the ant is on the boundary only after it has moved `| nums [I] |` units. In other words, if the ant crosses the boundary during its movement, it does not count.


**Example 1:**

> **Input:** nums = [2,3,-5]
> 
> **Output:** 1
> 
> **Explanation:** After the first step, the ant is 2 steps to the right of the boundary.
> 
> After the second step, the ant is 5 steps to the right of the boundary.
> 
> After the third step, the ant is on the boundary.
> 
> So the answer is 1.

**Example 2:**

> **Input:** nums = [3,2,-3,-4]
> 
> **Output:** 0
> 
> **Explanation:** After the first step, the ant is 3 steps to the right of the boundary.
> 
> After the second step, the ant is 5 steps to the right of the boundary.
> 
> After the third step, the ant is 2 steps to the right of the boundary.
> 
> After the fourth step, the ant is 2 steps to the left of the boundary.
> 
> The ant never returned to the boundary, so the answer is 0.


**Constraints:**

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

You are given a **0-indexed** integers array `nums`, and an integer `k`.

In one operation, you can remove one occurrence of the smallest element of `nums`.

Return *the **minimum** number of operations needed so that all elements of the array are greater than or equal to `k`*.

**Example 1:**

> **Input:** nums = [2,11,10,1,3], k = 10
>
> **Output:** 3
>
> **Explanation:** After one operation, nums becomes equal to [2, 11, 10, 3].
>
> After two operations, nums becomes equal to [11, 10, 3].
>
> After three operations, nums becomes equal to [11, 10].
>
> At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
>
> It can be shown that 3 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.

**Example 2:**
 
> **Input:** nums = [1,1,2,4,9], k = 1
> 
> **Output:** 0
> 
> **Explanation:** All elements of the array are greater than or equal to 1 so we do not need to apply any operations on nums.

**Example 3:**

> **Input:** nums = [1,1,2,4,9], k = 9
> 
> **Output:** 4
> 
> **Explanation:** only a single element of nums is greater than or equal to 9 so we need to apply the operations 4 times on nums.


**Constraints:**

* `1 <= nums.length <= 50`

* `1 <= nums[i] <= 109`

* `1 <= k <= 109`

* The input is generated such that there is at least one index `i` such that `nums[i] >= k`.

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

## 3110 Score of a String

Finished on April 17, 2024.

### Description

You are given a string `s`. The **score** of a string is defined as the sum of the absolute difference between the **ASCII** values of adjacent characters.

Return the **score** of `s`.

**Example 1:**

> **Input:** s = "hello"
> 
> **Output:** 13
> 
> **Explanation:**
>
> The **ASCII** values of the characters in `s` are: `'h' = 104`, `'e' = 101`, `'l' = 108`, `'o' = 111`. So, the score of `s` would be `|104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13`.

**Example 2:**

> **Input:** s = "zaz"
>
> **Output:** 50
>
> **Explanation:**
>
> The **ASCII** values of the characters in `s` are: `'z' = 122`, `'a' = 97`. So, the score of `s` would be `|122 - 97| + |97 - 122| = 25 + 25 = 50`.

 

**Constraints:**

* `2 <= s.length <= 100`

* `s` consists only of lowercase English letters.