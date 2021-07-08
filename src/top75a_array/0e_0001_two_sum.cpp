// 0001

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//--[ single pass, hash ]--//
vector<int> two_sum(vector<int>& nums, int target) {

    unordered_map<int, int> cache;

    for (int n = 0; n < nums.size(); n++) {

        int match = target - nums[n];

        if (cache.find(match) != cache.end()) {
            return { n, cache.at(match) };
        }

        cache.insert(make_pair(nums[n], n));
    }

    return {};
}

//--[ single pass, hash ]--//
vector<int> two_sum_iter(vector<int>& nums, int target) {

    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator iter;

    for (int n = 0; n < nums.size() ; n++) {

        iter = cache.find(target - nums[n]);

        if (iter != cache.end() && iter->second != n) {
            return { n, iter->second };
        }

        cache.insert(make_pair(nums[n], n));
    }

    return {};
}

//--[ two pass, hash ]--//
vector<int> two_sum_b(vector<int>& nums, int target) {

    unordered_map<int, int> cache;
    vector<int> result;

    for (int n = 0; n < nums.size(); n++) {
        cache.insert(make_pair(nums[n], n));
    }

    for (int p = 0; p < nums.size(); p++) {

        int match = target - nums[p];

        if ((cache.find(match) != cache.end()) && (cache.at(match) != p)) {
            result.push_back(p);
            result.push_back(cache.at(match));
            return result;
        }
    }

    return result;
}

//--[ function test driver ]--//
int main() {

    int target{95};
    vector<int> nums {2, 7, 11, 15, 42, 56, 77, 88, 33};
    vector<int> results{};

    results = two_sum(nums, target);

    cout << "> input:   [ ";
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << " ]";

    cout << "\n> target:  [ " << target << " ]";
    cout << "\n> values:  [ " << nums[results[0]] << " + " << nums[results[1]] << " ]";
    cout << "\n> indexes: [ " << results[0] << " + " << results[1] << " ]\n";

    return 0;
}

// eof
