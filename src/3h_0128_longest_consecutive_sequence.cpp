/* *
 * @author: Oliver Ocean <github@oliverocean.co>
 * @project: LeetCode
 * @title: Longest Consecutive Sequence
 * @index: 128
 * @difficulty: hard
 * @topic: arrays, graphs
 * @reqs: https://leetcode.com/problems/longest-consecutive-sequence/
 * @brief:
 *      Given an unsorted array of integers, find the length of the longest
 *      consecutive elements sequence. Your algorithm should run in O(n)
 * @ examples:
 *      Input: [ 100, 4, 200, 1, 3, 2 ]
 *      Output: 4
 *      Explain: The longest consecutive elements sequence is
 *        [ 1, 2, 3, 4 ], therefore its length is 4.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>

/* ---[ function prototypes ]--- */
int longestConsecutive(std::vector<int>& nums);
int longestConsecutiveDebug(std::vector<int>& nums);
int longestConsecutiveAltOne(std::vector<int>& nums);

/* ---[ function test driver ]--- */
int main()
{
    std::vector<int>setA {7, 25, 23, 20, 19, 3, 100, 20, 2, 100, 21, 18, 44, 22, 0, -11, 17};
    //std::vector<int>setA {100, 4, 200, 1, 3, 2};
    //std::vector<int>setA {30, 101, 14, 200, 11, 33, 12, 13, 32, 31, 29};
    //std::vector<int>setA{1, 2, 3, 4, 5};

    std::cout << "\ninput: [ ";
    for (const auto& i: setA)
    {
        std::cout << i << ", ";
    }
    std::cout << "]\n";

    int output = longestConsecutive(setA);
    std::cout << "output: [ " << output << " ]\n";

    return 0;
}

/* ---[ final approach ]--- */
/* runtime: 12ms @ 68.50%, memory: 8.9mb @ 100% */
int longestConsecutive(std::vector<int>& nums)
{
    std::unordered_set<int> theSet(nums.begin(),nums.end());
    int longest = 0;

    for (const auto& n : nums)
    {
        int forward = n + 1;
        int reverse = n - 1;

        while (theSet.find(forward) != theSet.end())
        {
            theSet.erase(forward++);
        }

        while (theSet.find(reverse) != theSet.end())
        {
            theSet.erase(reverse--);
        }

        longest = std::max(longest, forward - reverse - 1);
    }
    return longest;
}

/* ---[ final approach with debug output ]--- */
int longestConsecutiveDebug(std::vector<int>& nums)
{
    std::unordered_set<int> theSet(nums.begin(),nums.end());
    int longest = 0;

    // range loop corrects an off-by-one error in the result
    for (auto& n : nums)
    {
        std::cout << "\n--- Evaluate [ " << n << " ] ---\n";
        std::cout << "theSet [ ";
        std::copy(theSet.begin(), theSet.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "]\n";

        // initialize counters
        int forward = n + 1;
        int reverse = n - 1;

        std::cout << "[ ? ]<--[ " << n << " ]-->[ ? ]\n";

        while (theSet.find(forward) != theSet.end())
        {
            theSet.erase(forward++);
        }

        while (theSet.find(reverse) != theSet.end())
        {
            theSet.erase(reverse--);
        }

        std::cout << "[ " << reverse << " ]<--[ " << n << " ]-->[ " << forward << " ]\n";
        std::cout << "forward - reverse - 1\n= sequence length [ "
                    << forward - reverse - 1 << " ]\n";

        longest = std::max(longest, forward - reverse - 1);
    }
    return longest;
}


/* ---[ brute force approach ]--- */
/* runtime: 340ms @ 5.94% (very poor), memory: 8.1mb @ 100% (very good) */
int longestConsecutiveAltOne(std::vector<int>& nums)
{
    if (nums.empty()) return 0;

    // using sort() as there doesn't appear to be an efficient
    // way to evaluate an unordered list
    std::sort(nums.begin(), nums.end());

    std::cout << "\ninput: [ ";
    for (const auto& i: nums)
    {
        std::cout << i << ", ";
    }
    std::cout << " ]\n";

    int longestFound = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        int startingNum = nums[i] + 1;
        int longestSoFar = 1;

        std::cout << "start with " << nums[i] << "\n";
        std::cout << "seek " << startingNum << "\n";

        for (int j = 0; j < nums.size(); ++j)
        {
            std::cout << "> eval " << nums[j] << "?\n";
            if (nums[j] == startingNum)
            {
                std::cout << ">> found " << startingNum << "\n";
                ++startingNum;
                ++longestSoFar;
            }
        }
        std::cout << "longest this loop [ " << longestSoFar << " ]\n";
        std::cout << "---\n";
        longestFound = std::max(longestFound, longestSoFar);
    }

    return longestFound;
}

// EOF
