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

int GetSimpleNumber(int position) {
    int order = 0;
    int number = 2;
    while (order < position) {
        if (SimpleNumberTest(number) == 1) {
            order++;
            (order == position) ? false : number++;
        }
        else {
            number++;
        }
    }
    return number;
}

int main() {
    int N;
    cin >> N;
    vector<int> divisors;
    int order = 1;
    while (N > 1) {
        int divisor = GetSimpleNumber(order);
        if (N % divisor == 0) {
            N /= divisor;
            divisors.push_back(divisor);
        }
        else {
            order++;
        }
    }
    for (int d : divisors) {
        cout << d << endl;
    }
    return 0;
}
