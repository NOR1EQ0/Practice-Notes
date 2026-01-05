#include <limits>
#include <stdexcept>
#include <vector>

template <typename T>
struct matrix {
    std::vector<T> v;
    size_t col_size;

    struct row_reference {
        std::vector<T>& origVec;
        size_t row_index;
        size_t col_size;

        T& operator[](size_t col_index) {
            return origVec[row_index + col_size * col_index];
        }

        T& at(size_t col_index) {
            return (*this)[col_index];
        }

        row_reference() = delete;
        row_reference(std::vector<T>& orig, size_t row, size_t cols)
            : origVec(orig), row_index(row), col_size(cols) {}
    };

    row_reference operator[](size_t row) {
        return row_reference(v, row, col_size);
    }

    row_reference at(size_t row) {
        return (*this)[row];
    }

    T& underlying(size_t index, bool check_flag = true) {
        return v[index];
    }

    matrix() = delete;
    matrix(std::vector<T> val, size_t rows, size_t cols = std::numeric_limits<size_t>::max())
        : v(val), col_size(cols) {
    }
    matrix(size_t rows, size_t cols) : v(rows * cols), col_size(cols) {}
    matrix(size_t n) : v(n * n) {}
};