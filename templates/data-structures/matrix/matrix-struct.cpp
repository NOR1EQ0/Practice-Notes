#include <limits>
#include <stdexcept>
#include <vector>

template <typename T>
struct matrix {
    std::vector<T> v;
    size_t col_size;
    size_t row_size;

    struct row_reference {
        std::vector<T>& origVec;
        size_t row_index;
        size_t col_size;

        T& operator[](size_t col_index) {
            return origVec[row_index + col_size * col_index];
        }

        T& at(size_t col_index) {
            if (col_index >= col_size)
                throw std::out_of_range("Column index out of range.");

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
        if (row >= row_size)
            throw std::out_of_range("Row index out of range.");

        return (*this)[row];
    }

    T& underlying(size_t index, bool check_flag = true) {
        if (index >= v.size() && check_flag)
            throw std::out_of_range("Underlying index our of range.");

        return v[index];
    }

    matrix() = delete;
    matrix(std::vector<T> val, size_t rows, size_t cols = std::numeric_limits<size_t>::max())
        : v(val), row_size(rows), col_size(cols) {
        if (cols == std::numeric_limits<size_t>::max()) {
            auto col_res = val.size() / cols, rest = val.size() % cols;
            if (rest) {
                throw std::invalid_argument("The number of elements in the matrix "
                                            "can not be exactly divided by the row number "
                                            "given.");
            } else {
                col_size = col_res;
            }
        } else {
            if (rows * cols != val.size()) {
                throw std::invalid_argument("The row number and column number given can not "
                                            "match the matrix's size.");
            }
        }
    }
    matrix(size_t rows, size_t cols) : v(rows * cols), row_size(rows), col_size(cols) {}
    matrix(size_t n) : v(n * n) {}
};