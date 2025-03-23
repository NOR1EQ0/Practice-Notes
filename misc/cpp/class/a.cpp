#include <bits/stdc++.h>

class Rectangle {
public:
    int getArea() {
        return width * height;
    }
    Rectangle() {
        this->width = 1;
        this->height = 1;
    }
    Rectangle(int arg1, int arg2) : width(arg1), height(arg2) {}
private:
    int width = 0;
    int height = 0;
};

class Square : public Rectangle {
public:
    Square() {}
    Square(int arg) : Rectangle(arg, arg) {}
};

int main() {
    
    return 0;
}