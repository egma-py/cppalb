#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

pair<double, double> aver_n_sq(stack<double> data) {
    pair<double, double> ans;
    ans.first = 0; ans.second = 0;
    int data_size = data.size();
    while (data.size() != 0) {
        ans.first += data.top();
        ans.second += data.top() * data.top();
        data.pop();
    }
    ans.first /= data_size;
    ans.second /= data_size;
    ans.second = ans.second - ans.first * ans.first;
    ans.first = round(1000 * ans.first) / 1000;
    ans.second = round(1000 * ans.second) / 1000;
    return ans;
}

void valid_output(double num) {
    if (int(round(num * 1000)) % 10 != 0) {
        cout.precision(3);
        cout << num;
    }
    else if (int(round(num * 1000)) % 100 != 0 && int(round(num * 1000)) % 10 == 0) {
        cout.precision(2);
        cout << num;
    }
    else {
        cout.precision(1);
        cout << num;
    }
}

int main() {
    int num;
    stack<double> data;
    cin >> num; data.push(num);
    while (data.top() != 0) {
        cin >> num;
        data.push(num);
    }
    data.pop();
    pair<double, double> res = aver_n_sq(data);
    cout.setf(std::ios::fixed);
    valid_output(res.first);
    cout << ' ';
    valid_output(res.second);
    return 0;
}
