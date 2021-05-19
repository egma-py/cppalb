#include <iostream>

using namespace std;

int* put_in_middle(int* q, int N, int num) {
    int* new_q = new int[N + 1];
    if (N % 2 == 0) {
        int i = 0;
        while (i < N / 2) {
            new_q[i] = q[i];
            ++i;
        }
        new_q[i] = num;
        for (int j = N/2 + 1; j < N + 1; ++j) {
            new_q[j] = q[j - 1];
        }
    }
    else {
        int i = 0;
        while (i <= N / 2) {
            new_q[i] = q[i];
            ++i;
        }
        new_q[i] = num;
        for (int j = N/2 + 2; j < N + 1; ++j) {
            new_q[j] = q[j - 1];
        }
    }
    delete[] q;
    return new_q;
}

int* put_in_end(int* q, int N, int num) {
    int* new_q = new int[N + 1];
    for (int i = 0; i < N; ++i) {
        new_q[i] = q[i];
    }
    new_q[N] = num;
    delete[] q;
    return new_q;
}

int* next(int* q, int N) {
    int* new_q = new int[N - 1];
    for (int i = 1; i < N; ++i) {
        new_q[i - 1] = q[i];
    }
    delete[] q;
    return new_q;
}

int main() {
    int N; cin >> N;
    int am_in_ch = 0;
    int am_in_o = 0;
    int* seq = new int[am_in_ch];
    int* output = new int[am_in_o];
    pair<char, int> command;
    for (int i = 0; i < N; ++i) {
        cin >> command.first;
        if (command.first != '-') {
            cin >> command.second;
            if (command.first == '+') {
                seq = put_in_end(seq, am_in_ch, command.second);
                ++am_in_ch;
            }
            else {
                seq = put_in_middle(seq, am_in_ch, command.second);
                ++am_in_ch;
            }
        }
        else {
            output = put_in_end(output, am_in_o, seq[0]);
            ++am_in_o;
            seq = next(seq, am_in_ch);
            --am_in_ch;
        }
    }
    for (int i = 0; i < am_in_o; ++i) {
        cout << output[i] << endl;
    }
    return 0;
}
