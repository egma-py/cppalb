#include <iostream>
using namespace std;

bool test4(int num) {
    if (num % 4 == 0) {
        if (num / 1000 == 4 || num / 1000 == 5) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

bool test7(int num) {
    if (num % 7 == 0) {
        if (num / 1000 == 7 || num / 1000 == 1) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

bool test9(int num) {
    if (num % 9 == 0) {
        if (num / 1000 == 8 || num / 1000 == 9) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

int main() {
    int N; cin >> N;
    int k = 0;
    int* seq = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }
    for (int i = 0; i < N; ++i) {
        if (test4(seq[i]) == 1 || test7(seq[i]) == 1 || test9(seq[i]) == 1) {
            cout << seq[i] << ' ';
        }
        ++k;
    }
    if (k == 0) {
        cout << 0;
    }
    delete[] seq;
    return 0;
}
