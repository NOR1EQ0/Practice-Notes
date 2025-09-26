#include <bits/stdc++.h>

using namespace std;

// Kato_Shoko
#define ok "YES "
#define no "NO\n"

char kato[] = "Kato_Shoko";
char str[(int)1e5 + 1];
int asciitable[256];
unordered_set<char> us;

void init() {
    for (char* ptr = kato; *ptr; ptr++) {
        us.emplace(*ptr);
        asciitable[*ptr]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n;
    cin >> n;
    cin >> str;
    for (char* ptr = str; *ptr; ptr++) {
        if (us.find(*ptr) == us.end()) {
            asciitable[*ptr]++;
        } else {
            asciitable[*ptr]--;
        }
    }
    for (char* ptr = kato; *ptr; ptr++) {
        if (asciitable[*ptr] > 0) {
            cout << no;
            return 0;
        }
    }
    cout << ok;
    int op = 0;
    for (int* tptr = +asciitable; tptr < asciitable + sizeof(asciitable) / sizeof(int); tptr++) {
        if (us.find(tptr - (+asciitable)) == us.end()) {
            op += *tptr;
        }
    }
    cout << op << '\n';
    return 0;
}