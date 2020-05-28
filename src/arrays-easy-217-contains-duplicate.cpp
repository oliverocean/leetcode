#include <iostream>
#include <vector>
#include <unordered_set>

// function prototypes
bool containsDuplicate(std::vector<int>&);


int main() {

    //std::vector<int>input {1, 2, 3, 1}; // true
    //std::vector<int>input {1, 2, 3, 4}; // false
    std::vector<int>input {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}; // true

    std::cout << "\n---[ input ]---\n";
    std::cout << "vector: [ ";
    for (const auto& i: input) {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    //std::cout << "\n---[ debug ]---\n";
    int output = containsDuplicate(input);

    std::cout << "\n---[ output ]---\n";
    std::cout << "result: [ " << output << " ]\n";

    return 0;
}

// best (second) approach, eval returns early if dupe found
// (recall that search/insert unordered set/map is O(1) on average)
// runtime: 36ms @ 75.83%, memory: 14.9mb @79.12%
bool containsDuplicate(std::vector<int>& nums) {

    std::unordered_set<int> aSet;

    for (auto n : nums) {
        if (aSet.find(n) != aSet.end()) {
            return true; // duplicate found in set, return early
        } else {
            aSet.insert(n);
        }
    }
    return false; // no duplicate found
}

// another approach is sort, then look for consecutive items
// NOTE: using adjacent_find() instead of for loop, which is quite interesting
// sort is n(log n) but this modifies the input so not optimal
//bool containsDuplicate(std::vector<int>& nums) {
//    std::sort(nums.begin(), nums.end());
//    return nums.end() != std::adjacent_find(nums.begin(), nums.end());
//}

// initial attempt
// less efficient as it assesses entire vector
// without shortcutting if a duplicate is found
// runtime: 44ms @ 46.24%, memory: 16.3mb @ 73.63%
//bool containsDuplicate(std::vector<int>& nums) {
//
//    std::unordered_set<int> aSet;
//
//    for (auto n : nums) {
//        aSet.insert(n);
//    }
//
//    return nums.size() > aSet.size();
//}

// here is a shorter version of my initial attempt
// initializes and evaluates unordered_set (vs vector) in the return statement
//bool containsDuplicate(std::vector<int>& nums) {
//    //return std::unordered_set<int>{nums.begin(), nums.end()}.size() != nums.size();
//    return nums.size() != std::unordered_set<int>(nums.begin(), nums.end()).size();
//}

// another approach using the .second() interator, which returns
// false if an element is already in a set
// I think the booleans aren't as easy to understand in this
// situation (function returns 'true' if there is a duplicate) so not optimal
//bool containsDuplicate(std::vector<int>& nums) {
//
//    std::unordered_set<int> aSet;
//
//    for (auto n : nums) {
//        if (aSet.insert(n).second) { // false if element already in set
//            return true;
//        }
//    }
//    return false;
//}
