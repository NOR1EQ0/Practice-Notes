#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <type_traits>

constexpr char HELP1[] = "--help";
constexpr char HELP2[] = "-h";
constexpr uint32_t const_table[] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
constexpr size_t s_rotate_table[4][4] = {
    {7, 12, 17, 22},
    {5, 9, 14, 20},
    {4, 11, 16, 23},
    {6, 10, 15, 21}};

char message[512 / CHAR_BIT];

uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | (~x & z);
}

uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & ~z);
}

uint32_t H(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

uint32_t I(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (x | ~z);
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
T rotl(const T x, size_t n) {
    constexpr size_t width = sizeof(T) * CHAR_BIT;
    n %= width;
    return n ? (x << n) | (x >> (width - n)) : x;
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
T rotr(const T x, size_t n) {
    constexpr size_t width = sizeof(T) * CHAR_BIT;
    n %= width;
    return n ? (x >> n) | (x << (width - n)) : x;
}

void print_help() {
    std::cout << "Usage: md5pp [FILE]...\n"
                 "       md5pp --help, -h\n"
                 "\n"
                 "With no FILE, or when FILE is -, read standard input.\n";
    std::exit(EXIT_SUCCESS);
}

uint32_t load_le32(const char* ptr) {
    return static_cast<uint32_t>(
        (static_cast<uint32_t>(static_cast<uint8_t>(ptr[0])) << 0) |
        (static_cast<uint32_t>(static_cast<uint8_t>(ptr[1])) << 8) |
        (static_cast<uint32_t>(static_cast<uint8_t>(ptr[2])) << 16) |
        (static_cast<uint32_t>(static_cast<uint8_t>(ptr[3])) << 24));
}

void process_block(std::array<uint32_t, 4>& state) {
    std::cout << __FUNCTION__ << " ";
    std::cout.flush();
    uint32_t* u32_ptr = reinterpret_cast<uint32_t*>(message);
    for (size_t i = 0; i < sizeof(message) / sizeof(uint32_t); ++i) {
        u32_ptr[i] = load_le32(message + i * sizeof(uint32_t));
    }

    std::array<uint32_t, 4> tmpreg = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
    std::array<uint32_t, 4> backup = tmpreg;
    auto& [a, b, c, d] = tmpreg;
    /* Rond 1 */
    for (size_t i = 0; i < 16; ++i) {
        a += F(b, c, d) + u32_ptr[i] + const_table[i];
        a = rotl(a, s_rotate_table[0][i % 4]);
        a += b;
        std::rotate(tmpreg.begin(), std::prev(tmpreg.end()), tmpreg.end());
    }

    /* Round 2 */
    for (size_t i = 16; i < 32; ++i) {
        const auto m_index = (5 * i + 1) % 16;
        a += G(b, c, d) + u32_ptr[m_index] + const_table[i];
        a = rotl(a, s_rotate_table[1][i % 4]);
        a += b;
        std::rotate(tmpreg.begin(), std::prev(tmpreg.end()), tmpreg.end());
    }

    /* Round 3 */
    for (size_t i = 32; i < 48; ++i) {
        const auto m_index = (3 * i + 5) % 16;
        a += H(b, c, d) + u32_ptr[m_index] + const_table[i];
        a = rotl(a, s_rotate_table[2][i % 4]);
        a += b;
        std::rotate(tmpreg.begin(), std::prev(tmpreg.end()), tmpreg.end());
    }

    /* Round 4 */
    for (size_t i = 48; i < 64; ++i) {
        const auto m_index = (7 * i) % 16;
        a += I(b, c, d) + u32_ptr[m_index] + const_table[i];
        a = rotl(a, s_rotate_table[3][i % 4]);
        a += b;
        std::rotate(tmpreg.begin(), std::prev(tmpreg.end()), tmpreg.end());
    }

    for (size_t i = 0; i < 4; ++i) {
        state[i] += tmpreg[i];
    }
}

void process_istream(std::istream& is) {
    std::array<uint32_t, 4> state = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
    int cnt = 0;
    size_t block_count = 0;
    while (!is.read(message, sizeof(message)).eof()) {
        block_count++;
        process_block(state);
    }
    auto gcnt = is.gcount();
    message[gcnt] = 0x80; // append bit 1
}

int main(int argc, const char* argv[]) {
    if (argc > 1) {
        if (std::strcmp(argv[1], HELP1) == 0 ||
            std::strcmp(argv[1], HELP2) == 0) {
            print_help();
        }
        if (std::strcmp(argv[1], "-") == 0) {
            goto RD_STDIN;
        }
        for (size_t i = 1; i < argc; ++i) {
            const char* fpath = argv[i];
            std::ifstream ifs(fpath, std::ios::binary | std::ios::in);
            if (!ifs) {
                std::cerr << "md5pp: failed to open '" << fpath << "': "
                          << std::strerror(errno) << "\n";
                continue;
            }
            process_istream(ifs);
        }
    } else {
    RD_STDIN:
        process_istream(std::cin);
    }
    return EXIT_SUCCESS;
}