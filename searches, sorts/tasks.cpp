#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int *generate_arr(int N) {
    int *ans = new int[N];
    for (int i = 0; i < N; ++i) {
        ans[i] = rand() % 100;
    }
    return ans;
}

int *search_elem(int* a, int N, int x) {
    int *ans = nullptr;
    for (int i = 0; i < N; ++i) {
        if (a[i] == x) {
            ans = &a[i];
        }
    }
    return ans;
}

int *bin_search(int *start, int *stop, int x) {
    int *ans = nullptr;
    int *m = start + (stop - start) / 2;
    if (stop - start == 2) {
        if (*start == x) {
            ans = start;
        }
        else if (*(start + 1) == x) {
            ans = start + 1;
        }
    }
    else if (stop - start == 1) {
        if (*start == x) {
            ans = start;
        }
    }
    else {
        if (x >= *m) {
            ans = bin_search(m, stop, x);
        }
        else {
            ans = bin_search(start, m, x);
        }
    }
    return ans;
}

int *minimal(int *start, int *stop) {
    int *ans = start;
    for (int i = 0; i < stop - start; ++i) {
        if (*ans > *(start + i)) {
            ans = start + i;
        }
    }
    return ans;
}

int *maximal(int *start, int *stop) {
    int *ans = start;
    for (int i = 0; i < stop - start; ++i) {
        if (*ans < *(start + i)) {
            ans = start + i;
        }
    }
    return ans;
}

void selection_sort(int *start, int *stop) {
    int *begin_ptr = start;
    for (int i = 0; i < stop - start; ++i) {
        int *minimum = minimal(begin_ptr, stop);
        int c = *(begin_ptr);
        *(begin_ptr) = *(begin_ptr + (minimum - begin_ptr));
        *(begin_ptr + (minimum - begin_ptr)) = c;
        ++begin_ptr;
    }
}

void merge_parts(int *start, int *mid, int *stop) {
    int *minimum_1 = start;

}

int main() {
    srand(time(0));
    int N; cin >> N;
    int *A = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    selection_sort(A, A + N);
    for (int i = 0; i < N; ++i) {
        cout << A[i] << ' ';
    }
    return 0;
}
