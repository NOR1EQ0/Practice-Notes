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