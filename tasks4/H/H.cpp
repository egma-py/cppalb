#include <iostream>
#define left first
#define right second

using namespace std;

bool check_in(int* arr, int k, int x) {
    for (int i = 0; i < k; ++i) {
        if (arr[i] == x) {
            return true;
            break;
        }
    }
    return false;
}

int* del_elems(int* a, int k, int N) {
    int* new_a = new int[N - 2];
    int j = 0;
    for (int i = 1; i < N; ++i) {
        if (i != k) {
            new_a[i - j] = a[i];
        }
        else {
            ++j;
        }
    }
    delete[] a;
    return new_a;
}

pair<int, int> first_non_zero(int* a, int N) {
    pair<int, int> ans;
    for (int i = 0; i < N; ++i) {
        if (a[i] != 0) {
            ans.first = i; ans.second = a[i];
            break;
        }
    }
    return ans;
}

int minimal(pair<int, int>* pairs, int N) {
    int ans = N;
    for (int i = 0; i < N / 2; ++i) {
        if (pairs[i].right - pairs[i].left > 0) {
            if (pairs[i].right - pairs[i].left < N) {
                ans = pairs[i].right - pairs[i].left;
            }
        }
    }
    return ans;
}

int main() {
    int N; cin >> N;
    int* seq = new int[N];
    pair<int, int>* pairs = new pair<int, int>[N / 2];
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }
    pair<int, int> pos_size; int j;
    for (int i = 0; i < N / 2; ++i) {
        pos_size = first_non_zero(seq, N);
        j = pos_size.first;
        while (pos_size.second != -seq[pos_size.first]) {
            ++pos_size.first;
        }
        seq[j] = 0;
        seq[pos_size.first] = 0;
        if (pos_size.second > 0) {
            pairs[i].left = pos_size.first;
            pairs[i].right = j;
        }
        else {
            pairs[i].left = j;
            pairs[i].right = pos_size.first;
        }
    }
    delete[] seq;
    cout << minimal(pairs, N) % N;
    return 0;
}
