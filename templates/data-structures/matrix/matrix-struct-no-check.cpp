#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

template <typename T>
struct matrix {
    std::vector<T> v;
    size_t col_size;

    struct row_reference {
        matrix& o;
        size_t idx;

        T& operator[](size_t col_index) {
            return o[idx + o.col_size * col_index];
        }
        row_reference(std::vector<T>& orig, size_t row)
            : o(orig), idx(row) {}
    };

    row_reference operator[](size_t row) {
        return row_reference(v, row);
    }

    void read() {
        for (auto& i : v) {
            std::cin >> i;
        }
    }

    static matrix create(size_t rows, size_t cols) {
        matrix ret(rows, cols);
        ret.read();
        return matrix;
    }
    matrix(std::vector<T> val, size_t rows, size_t cols = std::numeric_limits<size_t>::max())
        : v(val), col_size(cols) {
    }
    matrix(size_t rows, size_t cols) : v(rows * cols), col_size(cols) {}
    matrix(size_t n) : v(n * n) {}
};