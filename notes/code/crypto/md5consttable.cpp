#include <cinttypes>
#include <climits>
#include <cmath>
#include <iostream>
#include <cstdint>

using namespace std;
uint32_t sine_constant[64];

void init_sine_constant() {
    for (int i = 0; i < sizeof(sine_constant) / sizeof(*sine_constant); i++) {
        sine_constant[i] = static_cast<uint32_t>(
            std::floor(std::abs(std::sin(static_cast<long double>(i + 1))) * (1L << 32))
        );
    }
}

int main() {
    init_sine_constant();
    for (int i = 0; i < sizeof(sine_constant) / sizeof(*sine_constant); i += 4) {
        for (int j = 0; j < 4; j++) {
            printf("0x%08x, ", sine_constant[i + j]);
        }
        cout << endl;
    }
}