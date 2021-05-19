#include <iostream>
using namespace std;

void printarr(int* arr, int arr_size) {
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i] << ' ';
    }
}

int power(int number, int deg) {
    int ans = 1;
    if (deg == 0) {
        false;
    }
    else {
        for (int i = 1; i <= deg; ++i) {
            ans *= 10;
        }
    }
    return ans;
}

int* add_to_middle(int number, int queue_size, int* queue_1) {
    int* queue_2 = new int[queue_size + 1];
    int k = 0;
    for (int i = 0; i <= queue_size; ++i) {
        if (queue_size % 2 == 0) {
            if (i != queue_size / 2) {
                queue_2[i] = queue_1[i - k];
            }
            else {
                queue_2[i] = number;
                ++k;
            }
        }
        else {
            if (i != queue_size / 2 + 1) {
                queue_2[i] = queue_1[i - k];
            }
            else {
                queue_2[i] = number;
                ++k;
            }
        }
    }
    delete[] queue_1;
    return queue_2;
}

int* pushback(int elem, int queue_size, int* queue_1) {
    int* queue_2 = new int[queue_size + 1];
    for (int i = 0; i <= queue_size; ++i) {
        if (i != queue_size) {
            queue_2[i] = queue_1[i];
        }
        else {
            queue_2[i] = elem;
        }
    }
    delete[] queue_1;
    return queue_2;
}

int* next(int queue_size, int* queue_1) {
    int* queue_2 = new int[queue_size - 1];
    for (int i = 1; i < queue_size; ++i) {
        queue_2[i - 1] = queue_1[i];
    }
    delete[] queue_1;
    return queue_2;
}

string to_do(string command) {
    string action;
    if (command[0] == '+') {
        action = "pushback";
    }
    else if (command[0] == '*') {
        action = "add_to_middle";
    }
    else if (command[0] == '-') {
        action = "next";
    }
    return action;
}

int new_number(string command) {
    int ans = 0;
    int deg = command.size() - 3;
    int i = 2;
    for (int i = 2; i < command.size(); ++i) {
        ans += ((int)command[i] - 48) * power(10, deg);
        --deg;
    }
    return ans;
}

int main()
{
    int queue_size = 0;
    int* queue_1 = new int[0];
    int row_size = 0;
    int* row = new int[0];
    int N; cin >> N;
    string command;
    for (int i = 0; i <= N; ++i)
    {
        getline(cin, command);
        if (to_do(command) == "next") {
            row = pushback(queue_1[0], row_size, row);
            ++row_size;
            queue_1 = next(queue_size, queue_1);
            --queue_size;
        }
        else if (to_do(command) == "pushback") {
            queue_1 = pushback(new_number(command), queue_size, queue_1);
            ++queue_size;
        }
        else if (to_do(command) == "add_to_middle") {
            queue_1 = add_to_middle(new_number(command), queue_size, queue_1);
            ++queue_size;
        }
    }
    delete[] queue_1;
    printarr(row, row_size);
    delete[] row;
    return 0;
}

