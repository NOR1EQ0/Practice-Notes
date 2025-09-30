#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <cinttypes>

using namespace std;

char buffer[512];
char md5sum_buffer[128 / __CHAR_BIT__];

// CONSTANT
uint32_t reg[4] = {
    #ifdef BIG_ENDIAN
    0x01234567, 0x89ABCDEF,
    0xFEDCBA98, 0x76543210
    #endif
};

char padding_head = 0x80;

void calc_md5sum(std::ifstream& ifs) {
    while (ifs.read(buffer, sizeof(buffer))) {
        auto gcnt = ifs.gcount();
        if (gcnt == 512) {

        } else {
            char* padptr = buffer + gcnt + 1;
            *padptr = padding_head;
            int padend = 512 - gcnt - 64;
        }
    }
}

int print_help() noexcept {
    return EXIT_SUCCESS;
}

int main(int argc, const char* argv[]) {
    if (argc > 2) {
        if (std::strncmp(argv[1], "--help", sizeof("--help")) == 0) {
            return print_help();
        }
        for (const char* fpath = argv[0]; fpath; fpath++) {
            std::ifstream ifs(fpath, std::ios::in | std::ios::binary);
            if (ifs.fail()) {
                std::cout << "Failed to open " << fpath << std::endl;
                continue;
            }
            ifs.close();
        }
    }
    return 0;
}
