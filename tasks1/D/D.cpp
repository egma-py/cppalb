#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N % 2 == 0) {
        N = N / 2;
    }
    (N == 1) ? cout << "YES" : cout << "NO";
    return 0;
}
