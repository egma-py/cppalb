#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int answer = 1;
    int i = 2;
    while (i*i <= N && answer != 0) {
        (N % i == 0) ? answer = 0 : i++;
    }
    cout << answer;
    return 0;
}
