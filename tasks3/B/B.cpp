#include<iostream>
#include<stack>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::stoi;

int main() {
    string exp;
    stack <int> stack_1;
    int val1, val2, a;
    while (cin >> exp){
        if (exp == "+") {
            val1 = stack_1.top();
            stack_1.pop();
            val2 = stack_1.top();
            stack_1.pop();
            stack_1.push(val2 + val1);
        }
        else if (exp == "-"){
            val1 = stack_1.top();
            stack_1.pop();
            val2 = stack_1.top();
            stack_1.pop();
            stack_1.push(val2 - val1);
        }
        else if (exp == "*"){
            val1 = stack_1.top();
            stack_1.pop();
            val2 = stack_1.top();
            stack_1.pop();
            stack_1.push(val2 * val1);
        }
        else if (exp == "/"){
            val1 = stack_1.top();
            stack_1.pop();
            val2 = stack_1.top();
            stack_1.pop();
            stack_1.push(val2 / val1);
        }
        else {
            a = stoi(exp);
            stack_1.push(a);
        }

    }
    cout << stack_1.top();
    return 0;
}
