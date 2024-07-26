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
|283|Move Zeroes|`Array` `Two Pointers`|Easy|Done|Done|
|322|Coin Change|`Breadth-First Search` `Array` `Dynamic Programming`|Medium|Delay| |
|434|Number of Segments in a String|`String`|Easy|Done|Done|
|518|Coin Change II|`Array` `Dynamic Programming`|Medium|Delay| |
|709|To Lower Case|`String`|Easy|Done| |
|771|Jewels and Stones|`Hash Table` `String`|Easy|Done| |
|1108|Defanging an IP Address|`String`|Easy|Done|Done|
|1342|Number of Steps to Reduce a Number to Zero|`Bit Manipulation` `Math`|Easy|Done| |
|1929|Concatenation of Array|`Array` `Simulation`|Easy|Done|Done|
|2011|Final Value of Variable After Performing Operations|`Array` `String` `Simulation`|Easy|Done|Done|
|2235|Add Two Integers|`Math`|Easy|Done| |
|2413|Smallest Even Multiple|`Math` `Number Theory`|Easy|Done| |
|2529|Maximum Count of Positive Integer and Negative Integer|`Array` `Binary Search` `Counting`|Easy| | |
|2651|Calculate Delayed Arrival Time|`Math`|Easy|Done| |
|2656|Maximum Sum With Exactly K Elements|`Greedy` `Array`|Easy|Done|Done|
|2744|Find Maximum Number of String Pairs|`Array` `Hash Table` `String` `Simulation`|Easy|Idle| |
|2769|Find the Maximum Achievable Number|`Math`|Easy|Done| |
|2798|Number of Employees Who Met the Target|`Array`|Easy|Done|Done|
|2864|Maximum Odd Binary Number|`Greedy` `Math` `String`|Easy|Done| |
|2894|Divisible and Non-divisible Sums Difference|`Math`|Easy|Done|Done|
|2942|Find Words Containing Character|`Array` `String`|Easy|Done|Done|
|3019|Number of Changing Keys|`String`|Easy|Done|Done|
|3028|Ant on the Boundary|`Array` `Prefix Sum` `Simulation`|Easy|Done| |
|3065|Minimum Operations to Exceed Threshold Value|`Array`|Easy|Done| |
|3110|Score of a String|`String`|Easy|Done|Done|

**Notice:** The difficulty listed here is sorted by LeetCode.

----

Optimization List:

|No.|Optimization|Status|Comment / Barrier|
|----|----|----|----|
|1|Two Sum|Haven't finished follow-up| |
|3|Use pointers and remove redundant code|Stucked in LeetCode test|**Access violation**<br>Even [./3/lengthOfLongestSubstring.c](./3/lengthOfLongestSubstring.c) can be compiled with GCC without warnings and run on my Ubuntu system in my virtual machine. But obviously, access violation is a big problem.<br>Even if I already know that, but it seems that I may write some wrong expressions in the 15th row. Maybe I shouldn use `if`, not ternary operator. But I don't think this change will solve access violation. Maybe I should malloc and maintain a place for `*(right-1)`? But that's weired...<br>I shouldn't write such a long comment in this table here XD|
|1929|Concatenation of Array|Decide use pointers to make the new numbers in the answer array point to the corresponding number in the original array|It may be unrealizable...|

## 1 Two Sum

Finished on March 16, 2024.

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

## 283 Move Zeroes

Finished on April 25, 2024.

### Answer

#### Two Pointers

Count the number of **non-zero** digits:

```c
void moveZeroes(int* nums, int numsSize) {
    int nonZero = 0, *l = nums, *ptr = nums;
    while (ptr < nums + numsSize) {
        if (*ptr != 0) {
            *l = *ptr;
            l++,nonZero++;
        }
        ptr++;
    }
    memset(nums+nonZero,0,sizeof(int)*(numsSize-nonZero));
}
```

If we remove `nonZero`, it means the 1st row would be `int *l = nums, *ptr = nums;`. `memset(nums+nonZero,0,sizeof(int)*(numsSize-nonZero));` can be changed into this:

```c
...
    while (l < nums + numsSize) {
        *l++ = 0;
    }
...
```

Just keep `l` pointer shifting forward until `l` reaches the end of `nums`.

Why don't I just replace that part? Hmmm... Actually, it's just because the first code block is my first submission XD.

### Reproduction

File: [./283/moveZeroes.c](./283/moveZeroes.c)

## 322 Coin Change

Click [here](#518-coin-change-ii) to see the next part of **Coin Change**.

Haven't finished...

### Answer

*Empty*

### Reproduction

*Empty*

## 434 Number of Segments in a String

Finished on April 7, 2024.

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

## 1108 Defanging an IP Address

Finished on May 8, 2024.

### Answer

```c
char *defangIPaddr(char *address)
{
    char *ans = (char *)malloc(sizeof(char) * (strlen(address) + 7));
    memset(ans, '\0', sizeof(char) * strlen(address) + 7);
    char *p = ans, *s = address;
    while (s < address + (char)strlen(address))
    {
        if (*s >= '0' && *s <= '9')
        {
            *p = *s;
            p++;
        }
        else
        {
            memcpy(p, "[.]", sizeof(char) * 3);
            p += 3;
        }
        s++;
    }
    return ans;
}
```

### Reproduction

File: [./1108/defangIPaddr.c](./1108/defangIPaddr.c)

## 1342 Number of Steps to Reduce A Number to Zero

Finished on September 20, 2023.

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

## 1929 Concatenation of Array

Finished on April 24, 2024.

### Answer

Just copy `nums` twice:

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getConcatenation(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 2 * numsSize;
    int *ans = (int *)malloc(sizeof(int) * *returnSize);
    memcpy(ans, nums, sizeof(int) * numsSize);
    memcpy(ans + numsSize, nums, sizeof(int) * numsSize);
    return ans;
}
```

### Reproduction

Copy `nums` twice: [./1929/getConcatenation.c](./1929/getConcatenation.c)

### Misc

~~I'm thinking: can I just make `ans[i+n]` points to `ans[i]` (or `nums[i]`) ? But I met some barriers... So I will try to solve it in that way one day.~~ I give up XD

## 2011 Final Value of Variable After Performing Operations

Finished on May 8, 2024.

### Answer

```c
int finalValueAfterOperations(char **operations, int operationsSize)
{
    int ans=0;
    for (char i = 0; i < operationsSize; i++)
    {
        if (operations[i][1] == '+')
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }
    return ans;
}
```

### Reproduction

File: [./2011/finalValueAfterOperations.c](./2011/finalValueAfterOperations.c)

## 2235 Add Two Integers

Finished on June 13, 2023. ~~WTF? The number of this question should be exchanged with [the first one](https://leetcode.cn/problems/two-sum)!~~

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

### Answer

```c
int smallestEvenMultiple(int n){
    return n%2?n*2:n;
}
```

## 2529 Maximum Count of Positive Integer and Negative Integer

Haven't finished...

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

## 2656 Maximum Sum With Exactly K Elements 

Finished on May 7, 2024.

### Answer

```c
int maximizeSum(int *nums, int numsSize, int k)
{
    int *ptr = nums, max = *nums;
    while (ptr < nums + numsSize)
    {
        max = *ptr > max ? *ptr : max;
        ptr++;
    }
    free(ptr);
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += max;
        max++;
    }
    return ans;
}
```

### Reproduction

*Empty*

## 2744 Find Maximum Number of String Pairs

Haven't finished...

### Answer

### Reproduction

FIle: [./2744/maximumNumberOfStringPairs.c](./2744/maximumNumberOfStringPairs.c)

## 2769 Find the Maximum Achievable Number

Finished on March 10, 2024.

### Answer

```c
int theMaximumAchievableX(int num, int t){
    return num+t*2;
}
```

## 2798 Number of Employees Who Met the Target

Finished on May 7, 2024.

### Answer

```c
int numberOfEmployeesWhoMetTarget(int *hours, int hoursSize, int target)
{
    int *l = hours, ans = 0;
    while (l < hours + hoursSize)
    {
        ans = *l >= target ? ans + 1 : ans;
        l++;
    }
    return ans;
}
```

## 2864 Maximum Odd Binary Number

Finished on March 13, 2024.

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

## 3019 Number of Changing Keys

Finished on April 22, 2023.

### Answer

```c
int countKeyChanges(char *s)
{
    int ans = 0;
    char *l = s;
    if (s[0] == '\0')
    {
        return 0;
    }
    char *r = s + 1;
    while (*r)
    {
        if (!(*l == *r || *l + 32 == *r || *l - 32 == *r))
        {
            l = r;
            ans++;
        }
        r++;
    }
    return ans;
}
```

### Reproduction

File: [./3019/countKeyChanges.c](./3019/countKeyChanges.c)

## 3028 Ant on the Boundary

Finished on March 11, 2024.

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