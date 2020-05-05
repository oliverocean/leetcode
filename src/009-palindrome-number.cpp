#include <iostream>

bool isPalindrome(int);

int main() {

    std::cout << "\n --- result --- \n";
    std::cout << isPalindrome(12321) << "\n";

    return 0;
}

bool isPalindrome(int x) {

    // per reqs: reject negative numbers and numbers that do not have symmetrical 0's
    if(x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversed{0};

    // exits loop when halfway through the reversal process (only half is needed for eval)
    while (x > reversed) {
        reversed = (reversed * 10) + (x % 10);
        x /= 10;
    }

    // if a palindrome with even # of digits, the left will be true
    // if a palindrome with odd # of digits, reversed/10 dumps middle number
    return x == reversed || x == reversed/10;

}