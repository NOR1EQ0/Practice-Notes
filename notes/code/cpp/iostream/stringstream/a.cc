#include <iostream>
#include <sstream>

using namespace std;

int main() {
    stringstream ss;
    ss << 1 << " Nigger";
    cout << "FIRST: ";
    cout << ss.rdbuf();
    cout << "\nSECOND: ";
    // ss.seekg(0);
    cout << ss.rdbuf();
    ss.seekg(0);
    cout << endl;
    int a;
    string s;
    ss >> a >> s;
    if (ss.fail()) {
        cout << "Failed to read. \n";
        return 0;
    }
    cout << a + 1 << " | " << s + "WhitePig" << endl;
}