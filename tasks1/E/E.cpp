#include <iostream>
using namespace std;

int main() {
    int maxEven = 0;
    int term;
    do {
        cin >> term;
        ((term % 2 == 0) && (term > maxEven)) ? maxEven = term : false;
    } while (term != 0);
    cout << maxEven;
    return 0;
}
