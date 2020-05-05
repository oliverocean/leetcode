#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string);


int main() {

    std::string setA = "()";
    std::string setB = "()[]{}";
    std::string setC = "(]";
    std::string setD = "}";
    std::string setE = "([)]";
    std::string setF = "{[]}";
    std::string setG = " ";
    std::string setH = "asdf";
    std::string setI;
    std::string setJ = "[";

    std::cout << "\nSet A: " << setA << "\n" << isValid(setA) << "\n1? (true)\n-------\n";
    std::cout << "\nSet B: " << setB << "\n" << isValid(setB) << "\n1? (true)\n-------\n";
    std::cout << "\nSet C: " << setC << "\n" << isValid(setC) << "\n0? (false)\n-------\n";
    std::cout << "\nSet D: " << setD << "\n" << isValid(setD) << "\n0? (false)\n-------\n";
    std::cout << "\nSet E: " << setE << "\n" << isValid(setE) << "\n0? (false)\n-------\n";
    std::cout << "\nSet F: " << setF << "\n" << isValid(setF) << "\n1? (true)\n-------\n";
    std::cout << "\nSet G: " << setG << "\n" << isValid(setG) << "\n1? (true)\n-------\n";
    std::cout << "\nSet H: " << setH << "\n" << isValid(setH) << "\n1? (true)\n-------\n";
    std::cout << "\nSet I: " << setI << "\n" << isValid(setI) << "\n1? (true)\n-------\n";
    std::cout << "\nSet J: " << setJ << "\n" << isValid(setJ) << "\n0? (false)\n-------\n";

    return 0;
}

//// original submission with debug messages
//// 0ms runtime - faster than 100%, 8.6mb memory - better than 70.54%
bool isValid(std::string s) {

    if (s.empty()) {
        std::cout << "> input string is empty but no errors.\n";
        return true;
    }

    std::stack<char> aStack;

    for (int i = 0; i < s.length(); ++i ) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            std::cout << "push: " << s[i] << "\n";
            aStack.push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (aStack.empty()) {
                std::cout << "? eval: " << s[i] << "\n";
                std::cout << "rh value encountered, nothing in stack to match.\n";
                return false;
            } else if (aStack.top() == '(' && s[i] == ')') {
                std::cout << "?: " << aStack.top()<< " + " << s[i] << "\n";
                aStack.pop();
            } else if (aStack.top() == '{' && s[i] == '}') {
                std::cout << "?: " << aStack.top()<< " + " << s[i] << "\n";
                aStack.pop();
            } else if (aStack.top() == '[' && s[i] == ']') {
                std::cout << "?: " << aStack.top()<< " + " << s[i] << "\n";
                aStack.pop();
            } else {
                std::cout << "> mismatch found (stack not empty).\n";
                return false;
            }
        } else {
            std::cout << "> no errors but input string has no values to assess.\n";
            return true;
        }
    }
    std::cout << "> stack empty, no errors along the way.\n";
    return aStack.empty();
}


//// found a solution that used a dictionary to handle the pair lookup
//// (and reduce number of 'else if' statements). I tried it out below but
//// it doesn't handle edge cases as well as the solution that I submitted (above)
//// also the 'cleverness' might not be as clear to my future self (or others)
//bool isValid(std::string s) {
//
//    if (s.empty()) {
//        return true;
//    }
//
//    std::stack<char> aStack;
//    std::unordered_map<char, char> aMap {
//            {'(',')'},
//            {'{','}'},
//            {'[',']'}
//    };
//
//    for (int i = 0; i < s.length(); ++i) {
//        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
//            aStack.push(s[i]);
//        } else if (aStack.empty() || aMap[aStack.top()] != s[i]) {
//            return false;
//        } else {
//            aStack.pop();
//        }
//    }
//    return aStack.empty();
//}