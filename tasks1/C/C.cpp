#include <iostream>
using namespace std;

int main() {
    int k = 0;
    int term;
    do {
        cin >> term;
        ((term % 2 == 0) && (term != 0)) ? k++ : false;
    } while (term != 0);
    cout << k;
    return 0;
}
