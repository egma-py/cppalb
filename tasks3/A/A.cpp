#include <iostream>
using namespace std;

int* expand(int* A, int size_arr) {
    int* B = new int[size_arr + 1];
    for (int i = 0; i < size_arr; ++i) {
        B[i] = A[i];
    }
    delete[] A;
    return B;
}

int main() {
    int size_of_arr = 1;
    int* A = new int[size_of_arr];
    int i = 0; int N;
    do {
        cin >> N;
        A[i] = N;
        ++i;
        A = expand(A, size_of_arr);
        ++size_of_arr;
    } while(N != 0);
    --size_of_arr;
    int depth = 0; int top;
    int* stack_A = new int[size_of_arr];
    i = 0;
    while (A[i] != 0) {
        if (depth == 0) {
            if (A[i] > 0) {
                stack_A[depth] = A[i];
                ++depth;
                top = A[i];
            }
        }
        else {
            if (A[i] > 0) {
                stack_A[depth] = A[i];
                ++depth;
                top = A[i];
            }
            if (A[i] < 0) {
                if (-A[i] < top) {
                    top += A[i];
                    stack_A[depth-1] += A[i];
                }
                else {
                    --depth;
                    top = stack_A[depth-1];
                }
            }
        }
        ++i;
    }
    (depth == 0) ? top = -1 : false;
    cout << depth << ' ' << top;
    delete[] A;
    delete[] stack_A;
    return 0;
}
