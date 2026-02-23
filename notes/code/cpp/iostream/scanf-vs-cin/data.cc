#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    random_device rd;
    mt19937_64 mt(rd());
    ofstream ofs("data.txt");
    for (int i = 0; i < 1000000; i++) {
        ofs << mt << ' ';
    }
    ofs.flush();
    ofs.close();
}