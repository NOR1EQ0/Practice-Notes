# 踩过的坑和一些需要注意事项的汇总

~~虽然文件名写成了 `IMPORTANT.md`，但也不是那么 important。~~ 文件名起成这样主要方便自己注意，仅此而已。

## 按正常人的逻辑重新思考一遍函数的作用

这个其实就是纯粹我脑抽，之前做[洛谷 P1042](https://www.luogu.com.cn/problem/P1042) 的时候。我先贴出代码片段：

```cpp
string buffer;
buffer.reserve(26);
string record;
record.reserve((25 + 1) * 2502);
while (true) {
    cin >> buffer;
    auto e = buffer.find('E');
    if (e != buffer.npos) {
        if (e != 0)
            record += buffer.substr(e - 1);
        break;
    }
    record += buffer;
}
```

我不知怎的，把 `std::string::substr(std::size_t __pos, std::size_t __n) const` 的 `__pos` 记成了要截取的字串的最后一个字符的在父串中的索引（即使 GNU 的注释清楚的写着 `__pos – Index of first character (default 0).`，但是我没看，毕竟不是复杂功能），比如我要截取 `WWWWWWWWWWLLLLLLLLLLWLWLE` 中 `E` 前面的字串（其实就是把 `E` 丢了，嘛表现出来是截取，结果我的想法是：

```txt
WWWWWWWWWWLLLLLLLLLLWLWLE
^                      ^
__npos (RIGHT)         __npos (WRONG)
+----------------------+
          __n
```

不知怎得，我就把它想成了从后面开始截取 `__n` 个字符。所以写出了这个 `buffer.substr(e - 1)` 不明所以的东西，结果截取出了 `LE` ……

我在处理对局成绩的地方折腾了半天，最后还是看了题解才发现我读题不仔细，改完之后发现还是 WA，搞了好久最后编了一条 `WWWWWWWWWWLLLLLLLLLLWLWLE`，才发现读数据的代码写错了。

而且我这个读数据其实也挺挫的，先读行，再用 `std::string::find` 找 `E`。还不如一个字符一个字符读，读到 `E` 停止。

嘛其实说这个也没有太大用，脑子浆糊了估计也不会重新思考一遍（）说不定小黄鸭调试法还真是个法子。

## 创建多维数组数组时注意坐标系方向

之前做[洛谷 P5461](https://www.luogu.com.cn/problem/P5461) 的时候没太想起来，不过没一会儿就想起来，但保险起见还是写一下（）

在做普通数学题的时候一般想出的二维坐标系都应该是 `x` 非负半轴朝右，`y` 非负半轴朝上。这才是一般使用的二维直角坐标系，对吧？

但在上面提到的题目中，或者其他题目中的情况（接下来的说明建立在读者已阅读上面题目的前提下），`y` 非负半轴应该朝下，如下：

```txt
+---+---+---> x
|PAR|BAN|
|DON|NED|
+---+---+
|PAR|BAN|
|DON|NED|
+---+---+
|
v

y
```

_`PARDON` - 赦免 | `BANNED` - 处罚_

嘛只能说，打草稿的时候要注意一下，并且这样想代码好写（大概吧 ~~，其实我没仔细想过~~， 只是起始位置会变成 `n`）。

多维数组的话就不知道了，超过三维应该更是画不出来了（）应该用别的方式来表示。

## 注意有没有在循环的时候把读写或循环条件写串了

这个是我在做[洛谷 P1009](https://www.luogu.com.cn/problem/P1009) 的时候折腾了半天才发现的。

我原本之前已经做了个基础的高精度加法的题[（洛谷 P1601）](https://www.luogu.com.cn/problem/P1601)，但是原来的判断条件是有问题的。

读入两个数字，因为会有两个数字长度不一样的情况，所以其中一个数字字符串（A）读完之后，剩下的几位就都是 0 了。

那怎么判断 A 读完了？那当然是读取元素的迭代器已经指到 `std::string` 最后一个迭代器或者最后一个迭代器的后面。

那么我的[代码](../workspace/luogu/P1601/217396007-AC.cpp)如下：

```cpp
for (auto it_a = a.crbegin(), it_b = b.crbegin(); it_a < a.crend() || it_b < b.crendit_a++, it_b++) {
    auto num = carry +
        (it_a < a.crend() ? *it_a - '0' : 0) +
        (it_b < a.crend() ? *it_b - '0' : 0);
    carry = num / 10;
    num %= 10;
    ret.push_back(static_cast<char>(num) + '0');
}
```

我是从两个字符串尾部一起向前开始读数的，把进位和 `a` 和 `b` 同一位的数字加起来嘛。

我把这段代码提交到[洛谷 P1601](https://www.luogu.com.cn/problem/P1601) 之后，洛谷 5 个测试点过掉了。

但是，在这里 `it_b` 比较的条件搞错了，我把 `b` 的指针 `it_b` 拿去和 `a` 的最后一个只读反向迭代器去比较了，结果再[洛谷 P1009](https://www.luogu.com.cn/problem/P1009) 吃了亏。为什么呢？因为我把和先初始化为 `0` 了（`string sum = "0";`），调用 `add` 函数的代码如下：

```cpp
void solve(int n) {
    string res;
    res.reserve(4000);
    res = "1";
    string sum = "0";
    for (int i = 1; i <= n; ++i) {
        string now = to_string(i);
        res = times(res, now);
        sum = add(sum, res);
    }
    for (const auto i: sum) {
        cout << i;
    }
    cout << '\n';
}
```

结果，`0` 和 `1` 相加之后，拿回来了一个 0 回来……

毕竟 `it_b` 拿去和 `a` 的迭代器比较了。这样子比较返 `false` 啊，所以 `1` 作为 `add` 函数的 `b` 参数，就变成了 0 + 0 + 0，啥也没有。

嘛最后还是改好了，然后把改好的代码在[洛谷 P1601](https://www.luogu.com.cn/problem/P1601) 重新交了一遍：

```cpp
for (auto it_a = a.crbegin(), it_b = b.crbegin(); it_a < a.crend() || it_b < b.crendit_a++, it_b++) {
    auto num = carry +
        (it_a < a.crend() ? *it_a - '0' : 0) +
        (it_b < b.crend() ? *it_b - '0' : 0); // <-- 改
    carry = num / 10;
    num %= 10;
    ret.push_back(static_cast<char>(num) + '0');
}
```

当然，既然高精度加法那题改好了，[洛谷 P1009](https://www.luogu.com.cn/problem/P1009) 这题也顺利解决了。

由此，我得出一个结论：

**在做多个指针在多个容器同时移动的事情的时候，回过头来观察指针比较有没有写串了。**

嘛也是个相当潦草的结论了，理解万岁~
