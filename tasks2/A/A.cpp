#include <iostream>
#include <vector>
using namespace std;

double AverageInt(vector<int> sequence) {
    int sum = 0;
    int length = 0;
    for (int number : sequence) {
        sum += number;
        length++;
    }
    return sum / length;
}

int main() {
    int N;
    cin >> N;
    vector<int> sequence;
    int number;
    for (int i = 0; i < N; i++) {
        cin >> number;
        sequence.push_back(number);
    }
    double average = AverageInt(sequence);
    int sum = 0;
    for (int number : sequence) {
        (number > average) ? sum += number : false;
    }
    cout << sum;
    return 0;
}
