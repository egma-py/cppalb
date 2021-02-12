#include <iostream>
using namespace std;

void writeGcd(int maximum, int minimum)
{
    while (minimum > 0) {
        int c = minimum;
        minimum = maximum % minimum;
        maximum = c;
    }
    cout << maximum;
}

int main() {
    int a, b;
    cin >> a >> b;
    (a > b) ? writeGcd(a, b) : writeGcd(b, a);
    return 0;
}
