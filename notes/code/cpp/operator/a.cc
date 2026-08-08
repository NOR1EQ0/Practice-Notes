#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

class Wrapper {
public:
    using value_type = int;

    Wrapper& operator+=(const Wrapper& obj) {
    }

    friend Wrapper operator+(const Wrapper& lhs, const Wrapper& rhs) {
        auto res = lhs;
        return res += rhs;
    }

    friend Wrapper operator+(Wrapper&& lhs, const Wrapper& rhs) {
        return lhs += rhs;
    }

    friend Wrapper operator+(Wrapper&& lhs, Wrapper&& rhs) {
        return lhs += rhs;
    }

    friend Wrapper operator+(const Wrapper& lhs, Wrapper&& rhs) {
        return rhs += lhs;
    }

    Wrapper(const Wrapper&) noexcept(std::is_nothrow_constructible_v<value_type>) = default;

private:
    std::vector<value_type> m_storage;
};