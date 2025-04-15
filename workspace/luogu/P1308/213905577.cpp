#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string word;
    string article;
    string turn;
    int ptr = 0;
    int pos = INT_MAX;
    int matched = 0;
    getline(cin, word);
    transform(word.begin(), word.end(), word.begin(), [](string::value_type c) { return tolower(c);});
    getline(cin, article);
    for (auto& i : article) {
        if (__glibc_likely(i != ' ')) {
            turn.push_back(tolower(i)); // tolower from <cctype>
        } else {
            if (!turn.empty()) {
                if (turn == word) {
                    matched++;
                    pos = pos == INT_MAX ? min(pos, (int)(ptr - word.length())) : pos;
                }
                turn.erase();
            }
        }
        ptr++;
    }
    if (matched)
        cout << matched << ' ' << pos;
    else
        cout << -1;
    cout << '\n';
    return 0;
}