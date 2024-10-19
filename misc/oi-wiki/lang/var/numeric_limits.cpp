#include <limits>
#include <cinttypes>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::cout << std::numeric_limits<uint32_t>::max() << std::endl;
    return 0;
}
