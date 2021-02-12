#include <iostream>
using namespace std;

int main() {
    int term, maximum, amount;
    cin >> term;
    maximum = term;
    (maximum == 0) ? amount = 0 : amount = 1;
    while (term != 0) {
        cin >> term;
        if (term > maximum) {
            maximum = term;
            amount = 1;
        }
        else if (term == maximum) {
            amount++;
        }
    }
    cout << amount;
    return 0;
}
