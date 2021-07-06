/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Missing Number
 * @index: 268
 * @difficulty: easy
 * @topic: array, math, bit manipulation
 * @reqs: https://leetcode.com/problems/missing-number/
 * @brief:
 *     Given an array containing n distinct numbers taken from
 *     [ 0, 1, 2, ..., n ], find the one that is missing from the array
 *
 * @note: I think the brief was poorly worded; here is more detail:
 *         - the length of the array is n items
 *         - there will be n items in the array from 0 to n
 *         - expect the items to be unordered
 *         - one item is missing; the function finds this missing item
 * @example:
 *     Example 1:
 *         Input: [3, 0, 1]
 *         Output: 2
 *         Explain:
 *             0 to n here is 0 to 3
 *             Given sequence is 0, 1, 3
 *             Missing item in sequence is 2
 *     Example 2:
 *         Input: [9, 6, 4, 2, 3, 5, 7, 0, 1]
 *         Output: 8
 *         Explain:
 *             0 to n here is 0 to 9
 *             Given sequence is 0, 1, 2, 3, 4, 5, 6, 7, 9
 *             Missing item in sequence is 8
 */

#include <iostream>
#include <vector>
#include <numeric> // used for Gauss' formula approach
#include <algorithm> // used for pre-sorted approach
#include <set> // used for hashset approach

/* ---[ function prototypes ]--- */
int missingNumber(std::vector<int>&);
int missingNumberAltOne(std::vector<int>&);
int missingNumberAltTwo(std::vector<int>&);

/* ---[ function test driver ]--- */
int main()
{
    std::vector<int> input{9, 6, 4, 2, 3, 5, 7, 0, 1};
    //std::vector<int> input{0};
    //std::vector<int> input{1};
    //std::vector<int> input{};
    //std::vector<int> input{0, 2};

    std::cout << "\n---[ input ]---\n";
    std::cout << "[ ";
    for (const auto& i: input) { std::cout << i << ", "; } std::cout << "]\n";

    std::cout << "\n---[ debug ]---\n";
    int output = missingNumber(input);

    std::cout << "\n---[ output ]---\n";
    std::cout << " [ " << output << " ]";

    return 0;
}

/* ---[ Gauss' formula approach ]--- */
/* runtime 24ms @ 73%, memory 7.8mb @ 100% */
/* *
 * Here the shortest approach also happens to be the most readable AND performant! :)
 * sum all numbers from 1 to n: [ n (n + 1) / 2 ]
 *  - line 1 makes n = highest number in the sequence 0 to n
 *  - line 2 subtracts the sum (accumulate) of given sequence from the result
 *    of Gauss' formula and returns the missing number
 */
int missingNumber(std::vector<int>& nums)
{
    long n = nums.size();
    return n * (n + 1) / 2 - std::accumulate(begin(nums), end(nums), 0); // accumulate uses <numeric>
}

/* ---[ 'brute force' presorted approach ]--- */
/* runtime: 52ms @ 7% (very poor), memory: 7.4mb @ 100% (very good) */
/* time complexity = O(log n) (due to sort) */
/* space complexity is 0(1) because sorted in place */
int missingNumberAltOne(std::vector<int>& nums)
{
    if (nums.empty()) { return 0; }

    std::sort(nums.begin(), nums.end());

    // make sure 0 is at beginning
    if (nums[0] != 0) { return 0; }

    // make sure n is at end
    if (nums[nums.size() - 1] != nums.size()) { return nums.size(); }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] + 1 != nums[i + 1])
        {
           return nums[i] + 1;
        }
    }
    return -1;
}

/* ---[ hashset approach ]--- */
/* runtime: 100ms @ 7% (very very poor), memory 15.4mb @ 6% (poor) */
int missingNumberAltTwo(std::vector<int>& nums)
{
    std::set<int> aSet;

    for (auto n : nums)
    {
        aSet.insert(n);
    }

    for (int i = 0; i <= nums.size(); ++i)
    {
        if (aSet.find(i) == aSet.end())
        {
            return i;
        }
    }
    return -1;
}

// EOF
