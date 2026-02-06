// example.cpp
#include <iostream>

int main() {
    int x;                  // 未初始化的变量
    if (x = 5) {            // 赋值而非比较（虽然逻辑上可能成立，但通常是个笔误）
        std::cout << "x is 5\n";
    }
    int y = 10;
    return y;               // main 函数返回非零值（虽然合法，但在某些上下文中可能提示“should return 0”）
}