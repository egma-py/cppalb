#include <iostream>
using namespace std;

void print_array(int* p) {
    for (int i = 0; i < 6; i++){
        (i != 6) ? cout << p[i] << " " : cout << p[i] << endl;
    }
}


int main() {
    int a[6];
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    print_array(a);
    return 0;
}
