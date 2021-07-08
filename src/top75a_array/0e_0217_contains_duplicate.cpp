// 0217

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool contains_duplicate(vector<int>& nums) {

    unordered_set<int> cache;

    for (auto n : nums) {
        if (cache.find(n) != cache.end()) {
            return true; // found, return early
        } else {
            cache.insert(n);
        }
    }

    return false; // not found
}

//--[ pre-sort, std::adjacent_find() ]--//
bool contains_duplicate_a(vector<int>& nums) {

    sort(nums.begin(), nums.end()); // n(log n) but modifying input

    return nums.end() != adjacent_find(nums.begin(), nums.end());
}

//--[ brute force ]--//
bool contains_duplicate_b(vector<int>& nums) {

    return unordered_set<int>{ nums.begin(), nums.end() }.size() != nums.size();

}

//--[ test driver ]--//
int main() {
    //vector<int>input {1, 2, 3, 1}; // true
    //vector<int>input {1, 2, 3, 4}; // false
    vector<int>input {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}; // true
    cout << "---[ input ]---\n";
    cout << "vector: [ ";
    for (auto i: input) { cout << i << ", "; }
    cout << "]\n";

    int output = contains_duplicate(input);
    cout << "\n---[ output ]---\n";
    cout << "result: [ " << output << " ]\n";

    return 0;
}
// eof
