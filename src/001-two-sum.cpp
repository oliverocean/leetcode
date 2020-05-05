#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target);

int main() {

    int target{95};
    std::vector<int> nums {2, 7, 11, 15, 42, 56, 77, 88, 33};
    std::vector<int> results{};

    results = twoSum(nums, target);

    std::cout << "\n> input:   [ ";
    for (const auto& i : nums) {
        std::cout << i << " ";
    }
    std::cout << " ]";

    std::cout << "\n> target:  [ " << target << " ]";
    std::cout << "\n> values:  [ " << nums[results[0]] << " + " << nums[results[1]] << " ]";
    std::cout << "\n> indexes: [ " << results[0] << " + " << results[1] << " ]\n";

    return 0;
}

std::vector<int> twoSum(std::vector<int>& nums, int target) {

//    // --------- single pass hash method ----------- //
//    // --------- 8ms, 10.1mb memory ----------- //
    std::unordered_map<int, int> map;

    for (int i{0}; i < nums.size(); ++i) {
        int complement = target - nums[i]; // interestingly, this is faster than computing in find() and at()
        if (map.find(complement) != map.end()) {
            return {i, map.at(complement)};
        }
        map.insert(std::make_pair(nums[i], i));
    }
    return {}; // <- return empty vector if no match is found

    // -------- alternative single pass method found online - i prefer mine above -------- //
//    std::unordered_map<int, int>::iterator theIterator;
//    std::unordered_map<int, int> theMap;
//    for (int i = 0 ; i < nums.size() ; i++) {
//        theIterator = theMap.find(target - nums[i]);
//        if (theIterator != theMap.end() && theIterator->second != i) {
//            return {i, theIterator->second};
//        }
//        theMap.insert(std::pair<int,int>(nums[i],i));
//    }
//    return {};


//    // --------- two pass hash method ----------- //
//    // --------- 12ms, 10.4mb memory ----------- //
//
//    std::vector<int> pair;
//
//    std::unordered_map<int, int> map;
//    for (int i{0}; i < nums.size(); ++i) {
//        map.insert(std::make_pair(nums[i], i));
//    }
//
////    std::cout << "map contains: \n";
////    for (auto item: map) {
////        std::cout << item.first << ":\t" << item.second << "\n";
////    }
//
//    for (int j{0}; j < nums.size(); ++j) {
//        int complement = target - nums[j];
//        if ((map.find(complement) != map.end()) && (map.at(complement) != j)) {
//            pair.push_back(j);
//            pair.push_back(map.at(complement));
//            return pair;
//        }
//    }
//    return pair;


//    // --------- brute force method ----------- //
//    // --------- 152ms, 9.3mb memory ----------- //
//
//    std::vector<int> pair{0, 0};
//
//    for (int x{0}; x < nums.size(); ++x) {
//        int candidate = target - nums[x];
//        for (int y{x+1}; y < nums.size(); ++y) {
//            if (nums[y] == candidate) {
//                pair[0] = x;
//                pair[1] = y;
//            }
//        }
//    }
//    return pair;
}
