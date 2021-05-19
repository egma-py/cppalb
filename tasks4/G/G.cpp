#include <iostream>

using namespace std;

float find_root(function f, float a, float b, float tol) {
    float ans = (b - a) / 2;
    if (f(ans) < tol) {
        return int(ans * 1000000) / 1000000;
    }
    else {
        c = (b - a) / 2;
        if ((f(c) > 0 && f(b) > 0) || (f(c) < 0 && f(b) < 0)) {
            return int(find_root(f, a, c, tol) * 1000000) / 1000000;
        }
        else if ((f(c) > 0 && f(a) > 0) || (f(c) < 0 && f(a) < 0)) {
            return int(find_root(f, c, b, tol) * 1000000) / 1000000;
        }
    }
}


int main() {

    return 0;
}
