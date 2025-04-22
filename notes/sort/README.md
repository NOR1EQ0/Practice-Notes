# 排序算法

## 冒泡排序 (Bubble Sort)

这应该是众多大学生在 C 语言课程上学习到的第一个排序算法。冒泡一词是因为经过内层循环时，元素向一个方向

### 原理

在给定的序列中，每次执行一次如下的循环，直至排序结束：（以从小到大为例）

* 从序列第一个元素开始，逐步比较相邻的两个元素，若这两个元素中左边元素比右边元素大，则交换两边元素， 直至序列结尾。

* 但并非一定要检查到序列结尾，每一次循环之后，最后两个元素一定是右边的比左边的大，故下一次内层循环的结束位置将在这一次内层循环的结束位置减一。这应是*更优做法*。

### 复杂度

|最好|平均|最坏|
|-|-|-|
|n|n^2|n^2|

### 示例代码

C++:

```cpp
template<typename ElemType = int, typename = enable_if<is_arithmetic<ElemType>::value>>
void bubble_sort(vector<ElemType>& _vector, bool _greater = true) {
    bool flag = true;
    auto len = _vector.size();
    while (flag) {
        flag = false;
        for (int i = 0; i < len - 1; ++i)
            if ((_greater ? greater<ElemType>()(_vector[i], _vector[i + 1]) : less<ElemType>()(_vector[i], _vector[i + 1]))) 
            /**
             * 这个其实只是包装了标准库的比较函数
             * 正常写还是写成
             * _greater ? _vector[i] > _vector[i + 1] ? _vector[i] < _vector[i + 1] 
             */ 
                swap((flag = true, _vector[i]), _vector[i + 1]);
        len--; // 把 len 减一可以减少内层循环的次数
    }
}
```

## 选择排序

说实话我看到这个排序的时候，发现这个排序方法好像比冒泡还差？毕竟其时间复杂度无论如何都是 *O(n^2)*，那这个排序方法有在某些情况下更加适用的场景吗？

### 原理

*To be continued*