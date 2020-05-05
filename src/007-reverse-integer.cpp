#include <iostream>

int reverse(int);

int main() {

    std::cout << "\n --- result --- \n";
    std::cout << reverse(1234) << "\n";

    return 0;
}

int reverse(int x) {

    int reversed{0};

    while (x != 0) {
        reversed = (reversed * 10) + (x % 10);
        x /= 10;
    }
    return (reversed > INT_MAX || reversed < INT_MIN)? 0 : reversed;


//  initial submission using the int_max and int_min from the given solution
//  above is a more elegant solution that filters via return statement
//
//    int reversed{0};
//
//    while (x != 0) {
//        int popped = x % 10;
//        if (reversed > INT_MAX/10 || (reversed == INT_MAX / 10 && popped > 7)) return 0;
//        if (reversed < INT_MIN/10 || (reversed == INT_MIN / 10 && popped < -8)) return 0;
//        reversed = reversed * 10 + popped;
//        x /= 10;
//    }
//    return reversed;

}