#include <iostream>
#include <string>
#pragma GCC optimize(2)
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
#define pno std::cout << "NO" << '\n';
#define pok std::cout << "YES" << '\n';
using namespace std;

class Student {
public:
    string name;
    string id;
    int score;
    Student(string namein, string idin, int scorein);
};

Student::Student(string namein, string idin, int scorein): name(namein), id(idin), score(scorein){}

Student::~Student(void) {}

int main() {
    IOS;
    int n;
    cin >> n;
    while (n--) {

    }
    return 0;
}