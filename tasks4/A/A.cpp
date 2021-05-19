#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, ans;
    cin >> a >> b >> c >> d >> ans;
    if (ans == b - a && ans == d / c) {
        cout << 5;
    }
    else if (ans != b - a && ans != d / c && ans != 1024) {
        cout << 2;
    }
    else if (ans == b - a && ans != d / c) {
        cout << 4;
    }
    else if (ans != b - a && ans == d / c) {
        cout << 4;
    }
    else if (ans == 1024) {
        if (b - a == 1024 && d / c == 1024) {
            cout << 5;
        }
        else if (b - a != 1024 && d / c == 1024) {
            cout << 4;
        }
        else if (b - a == 1024 && d / c != 1024) {
            cout << 4;
        }
        else {
            cout << 3;
        }
    }
    return 0;
}
