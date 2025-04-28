#pragma once
#include <bits/stdc++.h>

using namespace std;

template<typename ContainerType>
void print_container_element(const ContainerType& container, const char Separate[] = " ", bool LF = true) {
    using ElementType = typename ContainerType::value_type;
    for (auto i = container.begin(); i != container.end() - 1; ++i)
        cout << *i << Separate;
    cout << *container.end();
    if (LF) cout << '\n';
}