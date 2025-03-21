#include <iostream>
using namespace std;
int main()
{
    unsigned char flag[] = "flag{example_flag}";

    int i;

    // 加密算法
    for (i = 0; i < 35; i++)
    {
        flag[i] = flag[i] * 17;
        cout << static_cast<int>(flag[i]) << ",";
    }
    cout << endl;

    // 这一部分就是加密后得到的数据，要求就是把这些数据通过已知的加密算法逆向回去，得到正确的flag
    unsigned char cipher[] = {
        198, 44, 113, 215, 43, 231, 181, 44, 147, 95, 61, 181, 79, 180, 95, 79, 180, 232, 181, 79, 46,
        95, 231, 147, 95, 164, 181, 146, 79, 65, 63, 82, 116, 77, 0};
    cout << endl;
    return 0;
}