#include <bits/stdc++.h>

using namespace std;

class CSquare {
private:
    int side;
public:
    void set_side(int a) { side = a; }
    friend class CRectangle;
};

class CRectangle {
    int width, height;
public:
    void set_values(int, int);
    int area(void) {
        return width * height;
    }
    friend CRectangle duplicate(CRectangle);
    void convert(CSquare a);
};

void CRectangle::convert(CSquare a) {
    width = a.side;
    height = a.side;
}

void CRectangle::set_values(int a, int b) {
    width = a, height = b;
}

// Because duplicate(CRectangle) is a friend of CRectangle so this function can see any CRectangle's private? Kinda weirdo XD
CRectangle duplicate(CRectangle rect) {
    CRectangle ret;
    ret.width = rect.width * 2;
    ret.height = rect.height * 2;
    return ret;
}

int main() {
    CRectangle rect, rectb;
    rect.set_values(2, 3);
    rectb = duplicate(rect);
    cout << rectb.area() << endl;
    CSquare sqr;
    sqr.set_side(4);
    rect.convert(sqr);
    cout << rect.area() << endl;
    return 0;
}