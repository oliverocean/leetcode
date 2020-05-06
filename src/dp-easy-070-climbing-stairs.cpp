#include <iostream>
#include <vector>

// function prototype
int climbStairs(int n);

int main() {

    std::vector<int> testSet{12};
    //std::vector<int> testSet{1, 2, 3, 4, 5, 6, 7};
    //std::vector<int> testSet{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    std::cout << "\nTest Set: [ ";
    for (auto i: testSet) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    std::cout << "\n------ Debug ------\n";
    for (int i{0}; i < testSet.size(); ++i) {
        std::cout << "[ " << testSet[i] << " ] >> ";
        std::cout << "[ " << climbStairs(testSet[i]) << " ]\n\n";
    }
    return 0;
}

// my submission (see debug below for notes)
// runtime: 0ms - 100%, memory: 7.4mb - 100%
int climbStairs(int n) {

    std::vector<int>result(n + 1, 1);

    // start from two, the first two indexes are already initialized to 1
    for(int i = 2; i < n + 1; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }

    return result[n];
}


//// with debug messages
//int main() {
//
//    std::vector<int> testSet{12};
//    //std::vector<int> testSet{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//
//    std::cout << "\nTest Set: [ ";
//    for (auto i: testSet) {
//        std::cout << i << ", ";
//    }
//    std::cout << "]\n";
//
//    std::cout << "\n------ Debug ------\n";
//    for (int i{0}; i < testSet.size(); ++i) {
//        std::cout << "[ " << testSet[i] << " ] >> ";
//        climbStairs(testSet[i]);
//        std::cout << "\n\n";
//    }
//
//    return 0;
//}
//
//int climbStairs(int n) {
//
//    // note that dp values don't each map literally
//    // here, the first two indexes are initialized to 1 to
//    // properly start the fibonacci sequence.
//    // the 'result' vector is an intermediate tool and
//    // the only valid value is the last one returned
//
//    //vector needs to be n + 1 size to avoid overflow
//    std::vector<int>result(n + 1, 1);
//
//    std::cout << "\nn is: " << n;
//    std::cout << "\nsize of vector (n + 1): " << result.size();
//    std::cout << "\ninitialize vec [i]: [ ";
//    for (auto& i : result) {
//        std::cout << i << ", ";
//    }
//    std::cout << "]\n";
//
////    result[0] = 1;
////    result[1] = 1;
//
//    for(int i = 2; i < n + 1; i++) { // start
//
//        std::cout << "\n>>> loop: " << i << "\n";
//
//        std::cout << "vec vals [i]: [ ";
//        for (auto& i : result) {
//            std::cout << i << ", ";
//        }
//        std::cout << "]\n";
//
//        std::cout << "set vec val: [i - 1] + [i - 2] = " << result[i - 1] << " + " << result[i - 2] << "\n";
//        result[i] = result[i - 1] + result[i - 2];
//        std::cout << "vec index " << i << " is now the value [i]: " << result[i];
//
//        std::cout << "\nvec vals [i]: [ ";
//        for (auto& i : result) {
//            std::cout << i << ", ";
//        }
//        std::cout << "]\n";
//
//        std::cout << "\n-----\n";
//
//    }
//    return result[n];
//}


// also found this one - interesting and succinct but not as intuitive to the problem description
//int climbStairs(int n) {
//    int a = 1;
//    int b = 1;
//
//    for (int i = 1; i < n; i++) {
//        b += a;
//        a = b - a;
//    }
//    return b;
//}