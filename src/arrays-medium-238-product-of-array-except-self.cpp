#include <iostream>
#include <vector>

// function prototypes
std::vector<int> productExceptSelf(std::vector<int>& nums);


int main() {

    std::vector<int>input {1, 2, 3, 4, 5, 6, 7};

    std::cout << "\n---[ input ]---\n";
    std::cout << "[ ";
    for (const auto& i: input) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    std::cout << "\n---[ debug ]---\n";
    std::vector<int> output = productExceptSelf(input);

    std::cout << "\n---[ output ]---\n";
    std::cout << "[ ";
    for (const auto& i: output) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    return 0;
}

//// submitted, runtime: 36ms @ 97%, memory: 12.2mb @ 100%
//// This approach uses separate vectors for lh and rh cumulative products
//// then aggregates both at the end. I think this one is more readable than the one below.
std::vector<int> productExceptSelf(std::vector<int>& nums) {

    // each item equals the product of all items to the left of that element
    // initialize first item to 1 (at first pivot there are no items to left), work forward
    std::vector<int> lh(nums.size());
    lh[0] = 1;
    for (int i = 1; i < nums.size(); ++i) {
        lh[i] = lh[i - 1] * nums[i - 1];
    }

    // each item equals the product of all items to the right of that element
    // initialize last item to 1 (at last pivot there are no items to the right), work backward
    std::vector<int> rh(nums.size());
    rh[nums.size() - 1] = 1;
    for (int j = static_cast<int>(nums.size() - 2); j >= 0; --j) {
        rh[j] = rh[j + 1] * nums[j + 1];
    }

    // the product of each lh and rh item results in total product sans pivot value
    std::vector<int> result(nums.size());
    for (int k = 0; k < nums.size(); ++k) {
        result[k] = lh[k] * rh[k];
    }

    return result;
}

//// additional submission, runtime: 36ms @ 97%, memory: 11.9mb @ 100%
//// this approach uses a single 'result' vector, first populating with lh products
//// then calculating rh product and evaluating against lh products along the way
//// Yes, a little more space efficient but I think it's not as easy to understand
//std::vector<int> productExceptSelf(std::vector<int>& nums) {
//
//    std::vector<int> result(nums.size());
//    result[0] = 1;
//    for (int i = 1; i < nums.size(); ++i) {
//        result[i] = result[i - 1] * nums[i - 1];
//    }
//
//    int rh = 1;
//    for (int j = static_cast<int>(nums.size() - 1); j >= 0; --j) {
//        result[j] = result[j] * rh;
//        rh *= nums[j];
//    }
//
//    return result;
//}


//// two vector approach with debug messages
//std::vector<int> productExceptSelf(std::vector<int>& nums) {
//
//    std::vector<int> result(nums.size());
//
//    std::vector<int> lh(nums.size());
//    lh[0] = 1;
//
//    std::vector<int> rh(nums.size());
//    rh[nums.size() - 1] = 1; // set value of last element
//
//    std::cout << "[ start ]\n";
//    std::cout << "nums [ "; for (const auto& x: nums) { std::cout << x << ", "; } std::cout << "]\n";
//    std::cout << "> lh [ "; for (const auto& y: lh) { std::cout << y << ", "; } std::cout << "]\n";
//    std::cout << "> rh [ "; for (const auto& z: rh) { std::cout << z << ", "; } std::cout << "]\n---\n";
//
//    for (int i = 1; i < nums.size(); ++i) {
//        lh[i] = lh[i - 1] * nums[i - 1];
//        std::cout << "> lh [ "; for (const auto& y: lh) { std::cout << y << ", "; } std::cout << "]\n";
//    }
//
//    std::cout << "---\n";
//
//    for (int j = static_cast<int>(nums.size() - 2); j >= 0; --j) {
//        rh[j] = rh[j + 1] * nums[j + 1];
//        std::cout << "> rh [ "; for (const auto& z: rh) { std::cout << z << ", "; } std::cout << "]\n";
//    }
//
//    for (int k = 0; k < nums.size(); ++k) {
//        result[k] = lh[k] * rh[k];
//    }
//
//    return result;
//}
