#include <iostream>
#include <string>
using namespace std;

int Power(int number, int power) {
    int answer = 1;
    for (int i = 1; i <= power; i++) {
        answer *= number;
    }
    return answer;
}

string GetNumber(string data) {
    string number = "000000";
    int data_size = data.size();
    int i = data_size - 1;
    int j = 1;
    while (data[i] != ' ') {
        number[6-j] = data[i];
        i--;
        j++;
    }
    return number;
}

int GetSpeed(string data) {
    int speed = 0;
    int size_of_arr = 0;
    int i = 0;
    while (data[i] != ' ') {
        size_of_arr++;
        i++;
    }
    for (i = 0; i < size_of_arr; i++) {
        speed = speed + ((int) data[i] - 48)*Power(10, size_of_arr - i - 1);
    }
    return speed;
}

int SameNumbers(int digits[3]) {
    int amount;
    if (digits[0] == digits[1] && digits[1] == digits[2]) {
        return 3;
    }
    else if (digits[0] == digits[1] && digits[1] != digits[2]) {
        return 2;
    }
    else if (digits[0] == digits[2] && digits[1] != digits[2]) {
        return 2;
    }
    else if (digits[2] == digits[1] && digits[1] != digits[0]) {
        return 2;
    }
    else {
        return 1;
    }
}

int GetFine(string number) {
    int Fine;
    int digits[3] = {(int) number[1], (int) number[2], (int) number[3]};
    if (SameNumbers(digits) == 3) {
        Fine = 1000;
    }
    else if (SameNumbers(digits) == 2) {
        Fine = 500;
    }
    else {
        Fine = 100;
    }
    return Fine;
}

int main() {
    int sum = 0;
    string data;
    getline(cin, data);
    string number = GetNumber(data);
    int speed = GetSpeed(data);
    while (number != "A999AA") {
        (speed > 60) ? sum += GetFine(number) : false;
        getline(cin, data);
        number = GetNumber(data);
        speed = GetSpeed(data);
    }
    cout << sum;
    return 0;
}
