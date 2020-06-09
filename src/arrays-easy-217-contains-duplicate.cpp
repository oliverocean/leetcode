/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Contains Duplicate
 * @index: 217
 * @difficulty: easy
 * @topic: array, set, hashtable
 * @reqs: https://leetcode.com/problems/contains-duplicate/
 * @brief:
 *     Given an array of integers, find if the array contains any duplicates.
 *     Your function should return true if any value appears at least twice
 *     in the array, and it should return false if every element is distinct.
 * @example:
 *     Example 1:
 *         Input: [1,2,3,1]
 *         Output: true
 *     Example 2:
 *         Input: [1,2,3,4]
 *         Output: false
 *     Example 3:
 *         Input: [1,1,1,3,3,4,3,2,4,2]
 *         Output: true
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

/* ---[ function prototype ]--- */
bool containsDuplicate(std::vector<int>&);
bool containsDuplicateAltOne(std::vector<int>&);
bool containsDuplicateAltTwo(std::vector<int>&);
bool containsDuplicateAltThree(std::vector<int>&);
bool containsDuplicateAltFour(std::vector<int>&);

/* ---[ function test driver ]--- */
int main()
{
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

/* ---[ revised approach, fast and easy to understand ]--- */
/* runtime: 36ms @ 76%, memory: 14.9mb @ 79% */
bool containsDuplicate(std::vector<int>& nums)
{
    std::unordered_set<int> aSet;

    for (auto n : nums)
    {
        if (aSet.find(n) != aSet.end())
        {
            return true; // duplicate found in set, return early
        }
        else
        {
            aSet.insert(n);
        }
    }
    return false; // no duplicate found
}

/* ---[ pre-sort approach ]--- */
/* Using an adjacent_find() instead of for loop */
bool containsDuplicateAltOne(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end()); // n(log n) but modifying input likely suboptimal
    return nums.end() != std::adjacent_find(nums.begin(), nums.end());
}


/* ---[ revised brute force ]--- */
/* shorter version, initialize/eval set (vs vector) in return statement */
bool containsDuplicateAltTwo(std::vector<int>& nums)
{
    return nums.size() != std::unordered_set<int>(nums.begin(), nums.end()).size();
    //return std::unordered_set<int>{nums.begin(), nums.end()}.size() != nums.size();
}

/* ---[ brute force ]--- */
/* runtime: 44ms @ 46%, memory: 16.3mb @ 74% */
/* Notes: less efficient as it assesses entire vector without shortcutting if a duplicate is found */
bool containsDuplicateAltThree(std::vector<int>& nums)
{
    std::unordered_set<int> aSet;

    for (auto n : nums)
    {
        aSet.insert(n);
    }

    return nums.size() > aSet.size();
}

/* ---[ iterator approach ]--- */
/* using .second() iterator, which returns false if an element is already in a set.
 * I think booleans aren't as easy to understand in this specific situation
 * (function returns 'true' if there is a duplicate) so less optimal solution */
bool containsDuplicateAltFour(std::vector<int>& nums)
{
    std::unordered_set<int> aSet;

    for (auto n : nums)
    {
        if (aSet.insert(n).second) // false if element already in set
        {
            return true;
        }
    }
    return false;
}

// EOF
