#include <bits/stdc++.h>

using namespace std;

#define wl(v) cout<<v<<endl;

int main() {
    string a = "WTF is this\0Hey!";
    string emptystr;
    cout << (void*)emptystr.data() << endl;
    cout << (void*)a.data() << endl;
    wl(emptystr.capacity())
    wl(a.capacity())
    cout << "The reserved space of a: " << endl;
    for (int i = 0; i < a.capacity(); ++i) {
        cout << i << " - " << hex << showbase << (void*)(a.data() + i) << ": " << *(a.data() + i) << " (" << dec << static_cast<int>(*(a.data() + i)) << ") " << endl;
        cout.unsetf(ios_base::showbase);
        cout.unsetf(ios_base::hex);
    }
    cout << "The reserved space of emptystr: " << endl;
    for (int i = 0; i < emptystr.capacity(); ++i) {
        cout << i << " - " << hex << showbase << (void*)(emptystr.data() + i) << ": " << *(emptystr.data() + i) << " (" << dec << static_cast<int>(*(emptystr.data() + i)) << ") " << endl;
        cout.unsetf(ios_base::showbase);
        cout.unsetf(ios_base::hex);
    }
    emptystr = "SKASJDLASJKDLKASJDKASLDJA";
    return 0;
}