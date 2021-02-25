#include <iostream>
#include <vector>
using namespace std;

int SimpleNumberTest(int number) {
    int answer = 1;
    int i = 2;
    while (i*i <= number && answer != 0) {
        (number % i == 0) ? answer = 0 : i++;
    }
    return answer;
}

int main() {
    int N;
    cin >> N;
    vector<int> divisors;
    int i = 2;
    while (N > 1 && i <= N) {
        if (SimpleNumberTest(i) == 1 && N % i == 0) {
            divisors.push_back(i);
            N /= i;
        }
        else {
            i++;
        }
    }
    for (int d : divisors) {
        cout << d << endl;
    }
    return 0;
}
