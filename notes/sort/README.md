# 排序算法

## 冒泡排序 (Bubble Sort)

这应该是众多大学生在 C 语言课程上学习到的第一个排序算法。冒泡一词是因为经过内层循环时，元素向排序方向的反方向*浮动*，像气泡一样一点一点移动。

### 原理

在给定的序列中，每次执行一次如下的循环，直至排序正确为止：（以从小到大为例）

* 从序列第一个元素开始，逐步比较相邻的两个元素，若这两个元素中左边元素比右边元素大，则交换两边元素， 直至序列结尾。

* 但并非一定要检查到序列结尾，每一次循环之后，最后两个元素一定是右边的比左边的大，故下一次内层循环的结束位置将在这一次内层循环的结束位置减一。这应是*更优做法*。

### 时间复杂度

|最好|平均|最坏|
|:-:|:-:|:-:|
|n|n^2|n^2|

### 示例代码

C++：

* 以下代码是我尝试 `template` 关键字和模板特化 (`type_trait`) 的时候和冒泡一起写的，`ElemType` 即为元素类型。

* 从[这个代码](../../misc/oi-wiki/basic/sort/bubble-sort/a.cpp)截取出来的，加了一些注释。

```cpp
template<typename ElemType = int, typename = enable_if<is_arithmetic<ElemType>::value>>
void bubble_sort(vector<ElemType>& _vector, bool _greater = true) { // 默认从小到大排序
    bool flag = true;
    auto len = _vector.size(); 
    while (flag) {
        flag = false;
        for (int i = 0; i < len - 1; ++i)
            if ((_greater ? greater<ElemType>()(_vector[i], _vector[i + 1]) : less<ElemType>()(_vector[i], _vector[i + 1]))) 
            /**
             * 这个其实只是包装了标准库的比较函数
             * 写快点还是写成
             * _greater ? _vector[i] > _vector[i + 1] ? _vector[i] < _vector[i + 1] 
             */ 
                swap((flag = true, _vector[i]), _vector[i + 1]);
        len--; // 把 len 减一可以减少内层循环的次数
    }
}
```

## 选择排序（Selection Sort）

说实话我看到这个排序的时候，发现这个排序方法好像比冒泡还差？毕竟其时间复杂度无论如何都是 *O(n^2)*，那这个排序方法有在某些情况下更加适用的场景吗？

### 原理

在给定的序列中，每次执行一次如下的循环，直至排序正确为止：（以从小到大为例）

* 第一次循环位置从序列中第一个元素开始，接下来每进入下一次循环，其下一次循环的开始位置在本次循环的开始位置加一。当循环的开始位置为序列中的最后位置时，排序已完成，退出循环。

* 每次循环中，寻找最后一个小于在本循环的开始位置的元素的元素，交换两边元素。

### 时间复杂度

|最好|平均|最坏|
|:-:|:-:|:-:|
|n^2|n^2|n^2|

### 示例代码

C++

* 从[这个代码](../../misc/oi-wiki/basic/sort/selection-sort/example-Luogu-P1271-TLE.cpp)截取出来并稍作整理而得。

```cpp
void selection_sort(vector<int>& vec) {
    auto len = vec.size();
    for (int i = 0; i < len; ++i) {
        int ith = i;
        for (int j = i + 1; j < len; ++j) {
            if (vec[j] < vec[ith]) { ith = j; }
        }
        swap(vec[ith], vec[i]);
    }
}
```

---

写个奇奇怪怪的东西

## 睡觉排序（Sleeping Sort）

纯搞怪。如果真用还得处理负数和多线程等一些莫名其妙的事情，而且开线程还消耗系统资源。反正不是正经东西。

### 原理

在给定的序列中，创建*序列长度*个线程，在序列中将逐一元素的值设置为与之对应的线程的暂停时间。所有线程同时开始。每个线程在暂停相应时间后应将对应的元素的值打印出来，或者重新开一个数组，每个线程在暂停相应时间后分别将对应的元素的值加入数组后方。

### 时间复杂度

`O(max(array))`，`array` 为给定序列。

但鉴于它依赖于多线程，所以执行起来是十分不可控的。

### 示例代码

我自己没有特地写这个，遂放置通义 AI 生成的 Java 代码：

```java
import java.util.ArrayList;
import java.util.List;

public class SleepSort {
    public static void main(String[] args) throws InterruptedException {
        int[] array = {34, 7, 23, 32, 5, 62};
        List<Thread> threads = new ArrayList<>();
        for (final int num : array) {
            Thread thread = new Thread(() -> {
                try {
                    Thread.sleep(num);
                    System.out.print(num + " ");
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            });
            threads.add(thread);
            thread.start();
        }
        for (Thread thread : threads) {
            thread.join();
        }
    }
}
```