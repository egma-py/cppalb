#include <iostream>
#include <vector>
using namespace std;

int Power(int number, int power) {
    int answer = 1;
    for (int i = 0; i < power; i++) {
        answer *= number;
    }
    return answer;
}

void Babylonian(int digit) {
    vector<char> digits;
    for (int i = 1; i <= digit / 10; i++) {
        digits.push_back('<');
    }
    for (int i = 1; i <= digit % 10; i++) {
        digits.push_back('v');
    }
    for (char d : digits) {
        cout << d;
    }
}

int main() {
    int N;
    cin >> N;
    int digit = 1;
    vector<int> digits;
    while (N / Power(60, digit - 1) != 0) {
        digits.push_back((N % Power(60, digit) - N % Power(60, digit - 1)) / Power(60, digit - 1));
        digit++;
    }
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (i != 0) {
            Babylonian(digits[i]);
            cout << ".";
        }
        else {
            Babylonian(digits[i]);
        }
    }
    return 0;
}
