// 0020
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// map solution
bool is_valid(string s) {

    if (s.empty()) { return true; }
    stack<char> stk;
    unordered_map<char, char> cache { {'(',')'}, {'{','}'}, {'[',']'} };

    for (auto i : s) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stk.push(s[i]);
        } else if (stk.empty() || cache[stk.top()] != s[i]) {
            return false;
        } else {
            stk.pop();
        }
    }
    return stk.empty();
}

// stack solution
bool is_valid_(string s) {

    if (s.empty()) { return true; }
    stack<char> stk;

    for (auto i : s) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stk.push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stk.empty()) {
                return false;
            } else if (stk.top() == '(' && s[i] == ')') {
                stk.pop();
            } else if (stk.top() == '{' && s[i] == '}') {
                stk.pop();
            } else if (stk.top() == '[' && s[i] == ']') {
                stk.pop();
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
    return stk.empty();
}

//--[ test driver ]--//
int main() {
    string setA = "()";
    string setB = "()[]{}";
    string setC = "(]";
    string setD = "}";
    string setE = "([)]";
    string setF = "{[]}";
    string setG = " ";
    string setH = "asdf";
    string setI;
    string setJ = "[";

    cout << "\nSet A: " << setA << "\n" << is_valid(setA) << "\n1? (true)\n-------\n";
    cout << "\nSet B: " << setB << "\n" << is_valid(setB) << "\n1? (true)\n-------\n";
    cout << "\nSet C: " << setC << "\n" << is_valid(setC) << "\n0? (false)\n-------\n";
    cout << "\nSet D: " << setD << "\n" << is_valid(setD) << "\n0? (false)\n-------\n";
    cout << "\nSet E: " << setE << "\n" << is_valid(setE) << "\n0? (false)\n-------\n";
    cout << "\nSet F: " << setF << "\n" << is_valid(setF) << "\n1? (true)\n-------\n";
    cout << "\nSet G: " << setG << "\n" << is_valid(setG) << "\n1? (true)\n-------\n";
    cout << "\nSet H: " << setH << "\n" << is_valid(setH) << "\n1? (true)\n-------\n";
    cout << "\nSet I: " << setI << "\n" << is_valid(setI) << "\n1? (true)\n-------\n";
    cout << "\nSet J: " << setJ << "\n" << is_valid(setJ) << "\n0? (false)\n-------\n";

    return 0;
}
// eof
