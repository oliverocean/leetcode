// 0001

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//--[ single pass, hash ]--//
vector<int> two_sum(vector<int>& nums, int target) {

    unordered_map<int, int> map;

    for (int n = 0; n < nums.size(); n++) {

        int match = target - nums[n];

        if (map.find(match) != map.end()) {
            return { n, map.at(match) };
        }

        map.insert(make_pair(nums[n], n));
    }

    return {}; // no match
}

//--[ single pass, hash ]--//
vector<int> two_sum_iter(vector<int>& nums, int target) {

    unordered_map<int, int> map;
    unordered_map<int, int>::iterator iter;

    for (int n = 0 ; n < nums.size() ; n++) {

        iter = map.find(target - nums[n]);

        if (iter != map.end() && iter->second != n) {
            return { n, iter->second };
        }

        map.insert(make_pair(nums[n], n));
    }

    return {}; // no match
}

//--[ two pass, hash ]--//
vector<int> two_sum_b(vector<int>& nums, int target) {

    unordered_map<int, int> map;
    vector<int> pair;

    for (int n = 0; n < nums.size(); n++) {
        map.insert(make_pair(nums[n], n));
    }

    for (int p = 0; p < nums.size(); p++) {

        int match = target - nums[p];

        if ((map.find(match) != map.end()) && (map.at(match) != p)) {
            pair.push_back(p);
            pair.push_back(map.at(match));
            return pair;
        }
    }

    return pair;
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
